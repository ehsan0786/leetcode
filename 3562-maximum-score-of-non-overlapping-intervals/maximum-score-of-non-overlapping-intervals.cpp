class Solution {
public:
    vector<vector<int>> intervals;

    // dp[i][k] stores the BEST result starting from i
    // when we can still select at most k intervals.
    //
    // first  = maximum score
    // second = indices producing that score
    vector<vector<pair<long long, vector<int>>>> dp;

    vector<vector<bool>> visited;

    // ---------------------------------------------------------
    // Compare two possible answers.
    //
    // First priority:
    //      Larger score
    //
    // If score is equal:
    //      Lexicographically smaller index list
    // ---------------------------------------------------------
    pair<long long, vector<int>> better(pair<long long, vector<int>> a,
                                        pair<long long, vector<int>> b) {

        if (a.first != b.first) {

            // Higher score is better.
            return (a.first > b.first) ? a : b;
        }

        // Scores are equal.
        //
        // Choose lexicographically smaller list.
        if (lexicographical_compare(a.second.begin(), a.second.end(),
                                    b.second.begin(), b.second.end())) {

            return a;
        }

        return b;
    }

    // ---------------------------------------------------------
    // solve(i, k)
    //
    // Starting from interval i,
    // choose at most k intervals.
    // ---------------------------------------------------------
    pair<long long, vector<int>> solve(int i, int k) {

        // Nothing left to choose.
        if (i >= intervals.size() || k == 0) {
            return {0, {}};
        }

        // Already calculated.
        if (visited[i][k]) {
            return dp[i][k];
        }

        visited[i][k] = true;

        // =====================================================
        // OPTION 1: SKIP interval i
        // =====================================================

        auto skip = solve(i + 1, k);

        // =====================================================
        // OPTION 2: TAKE interval i
        // =====================================================

        int next = findNext(i);

        auto take = solve(next, k - 1);

        // Add current interval's score.
        take.first += intervals[i][2];

        // Add current interval's ORIGINAL index.
        take.second.push_back(intervals[i][3]);

        // -----------------------------------------------------
        // IMPORTANT:
        //
        // We need the indices sorted for lexicographical
        // comparison.
        // -----------------------------------------------------
        sort(take.second.begin(), take.second.end());

        // Pick whichever is better:
        //
        // 1. Higher score
        // 2. If equal score -> lexicographically smaller indices
        dp[i][k] = better(skip, take);

        return dp[i][k];
    }

    // ---------------------------------------------------------
    // Find the first interval whose START is strictly greater
    // than the current interval's END.
    //
    // Intervals are sorted by START.
    // ---------------------------------------------------------
    int findNext(int i) {

        int end = intervals[i][1];

        int lo = i + 1;
        int hi = intervals.size() - 1;

        int ans = intervals.size();

        while (lo <= hi) {

            int mid = lo + (hi - lo) / 2;

            if (intervals[mid][0] > end) {

                // Compatible.
                //
                // Try finding an even earlier compatible one.
                ans = mid;
                hi = mid - 1;

            } else {

                // This interval starts too early.
                lo = mid + 1;
            }
        }

        return ans;
    }

    vector<int> maximumWeight(vector<vector<int>>& iv) {

        intervals.clear();

        // Save the ORIGINAL index.
        for (int i = 0; i < iv.size(); i++) {

            intervals.push_back({
                iv[i][0], // start
                iv[i][1], // end
                iv[i][2], // score
                i         // original index
            });
        }

        // Sort by start time.
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] != b[0])
                     return a[0] < b[0];

                 if (a[1] != b[1])
                     return a[1] < b[1];

                 return a[2] < b[2];
             });

        int n = intervals.size();

        // k can be 0,1,2,3,4.
        dp.resize(n, vector<pair<long long, vector<int>>>(5));

        visited.assign(n, vector<bool>(5, false));

        // At most 4 intervals.
        auto answer = solve(0, 4);

        return answer.second;
    }
};