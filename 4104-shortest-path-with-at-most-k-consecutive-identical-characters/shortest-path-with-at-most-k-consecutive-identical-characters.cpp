class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> grid(n);

        for (int i = 0; i < edges.size(); i++) {
            grid[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        vector<vector<int>> minDistance(n, vector<int>(k + 1, INT_MAX));

        minDistance[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            int wt = pq.top()[0], node = pq.top()[1], occ = pq.top()[2];
            pq.pop();

            if (wt != minDistance[node][occ]) continue;

            for (int i = 0; i < grid[node].size(); i++) {
                int newNode = grid[node][i].first;
                int dist = grid[node][i].second;

                int newOcc = 1;
                if (labels[node] == labels[newNode]) newOcc += occ;

                if (newOcc > k) continue;

                if (wt + dist < minDistance[newNode][newOcc]) {
                    pq.push({wt + dist, newNode, newOcc});
                    minDistance[newNode][newOcc] = wt + dist;
                }
            }
        }

        int ans = INT_MAX;

        for (int i = 1; i <= k; i++)
            ans = min(ans, minDistance[n - 1][i]);

        return ans == INT_MAX ? -1 : ans;
    }
};