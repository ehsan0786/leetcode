class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        vector<int> first(26, n);
        vector<int> last(26, -1);

        // Find first and last occurrence of every character
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';

            first[c] = min(first[c], i);
            last[c] = i;
        }

        vector<pair<int, int>> intervals;

        // Try every character as the starting character
        for (int c = 0; c < 26; c++) {
            if (last[c] == -1)
                continue;

            int left = first[c];
            int right = last[c];

            bool valid = true;

            // Expand the interval if necessary
            for (int i = left; i <= right; i++) {
                int x = s[i] - 'a';

                // This character appeared before 'left',
                // so we cannot make a valid substring starting at left
                if (first[x] < left) {
                    valid = false;
                    break;
                }

                // Need to include all occurrences of this character
                right = max(right, last[x]);
            }

            if (valid) {
                intervals.push_back({left, right});
            }
        }

        // Choose maximum number of non-overlapping intervals
        // by earliest ending position.
        sort(intervals.begin(), intervals.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.second < b.second;
             });

        vector<string> ans;
        int prevEnd = -1;

        for (auto [left, right] : intervals) {
            if (left > prevEnd) {
                ans.push_back(s.substr(left, right - left + 1));
                prevEnd = right;
            }
        }

        return ans;
    }
};