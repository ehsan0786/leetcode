class Solution {
public:
    int n;
    void BFS(unordered_map<int,vector<int>> &adj,int u,vector<bool> &visited){
        queue<int> que;
        visited[u]=true;
        que.push(u);
        while(!que.empty()){
            int u = que.front();
            que.pop();
            for(int &v:adj[u]){
                if(!visited[v]){
                    BFS(adj,v,visited);
                }
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> visited(n,false);
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                BFS(adj,i,visited);
                cnt++;
            }
        }
        return cnt;
    }
};