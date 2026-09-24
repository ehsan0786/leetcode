class Solution {
public:
    typedef pair<int,int> p;
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<p>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int xi = points[i][0];
                int yi = points[i][1];
                int xj = points[j][0];
                int yj = points[j][1];
                int dist = abs(xi-xj)+abs(yi-yj);
                adj[i].push_back({j,dist});
                adj[j].push_back({i,dist});
            }
        }

        priority_queue<p,vector<p>,greater<p>> pq;
        int sum = 0;
        vector<bool> inMST(n,false);
        pq.push({0,0}); //dist,node
        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(inMST[node]==true) continue;
            inMST[node] = true;
             sum += wt;
            for(auto &x : adj[node]){
                int dist = x.second;
                int neighnode = x.first;
               if(inMST[neighnode] == false){
                    pq.push({dist,neighnode});
               }
            }
        }
        return sum;
    }
};