class Solution {
public:
    pair<int,int> BFS(unordered_map<int,vector<int>> &adj,int u){
        queue<int>que;
        que.push(u);
        unordered_map<int,bool> visited;
        visited[u] = true;
        int farthestNode = u;
        int distance = 0; 
        while(!que.empty()){
            int size = que.size(); //current size of node 
            while(size--){
                int currNode = que.front();
                que.pop();
                farthestNode = currNode;
                for(auto &v : adj[currNode]){
                    if(!visited[v]){
                        visited[v] = true;
                        que.push(v);
                    }
                }
            }
            if(!que.empty()) distance++; //level
        }
        return {farthestNode,distance};
    }

    int findDiameter(unordered_map<int,vector<int>> &adj){
        auto[farthestNode,firstDiameter] = BFS(adj,0);
        auto[endNode,diameter] = BFS(adj,farthestNode);
        return diameter;
    }

    unordered_map<int,vector<int>> adj(vector<vector<int>>& edges){
        unordered_map<int,vector<int>> adj;
        for(auto &edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int,vector<int>> adj1 = adj(edges1);
        unordered_map<int,vector<int>> adj2 = adj(edges2);

        int d1 = findDiameter(adj1);
        int d2 = findDiameter(adj2);

        int combined = (d1+1)/2 + (d2+1)/2 + 1;

        return max({d1,d2,combined});
    }
};