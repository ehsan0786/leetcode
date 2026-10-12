class Solution {
public:
    void DFS(int u,unordered_map<int,vector<int>> &adj,vector<int> &Eulerpath){
        while(!adj[u].empty()){
            int v = adj[u].back();
            adj[u].pop_back();
            DFS(v,adj,Eulerpath);
        }
        Eulerpath.push_back(u);
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>> adj;
        unordered_map<int,int>indegree,outdegree;
        for(auto &edge : pairs){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v); // u -- > v
            outdegree[u]++;
            indegree[v]++;
        }

        int startNode = pairs[0][0];
        for(auto &it:adj){
            int node = it.first;
            if(outdegree[node] - indegree[node] == 1){
                startNode = node;
                break;
            }
        }
        vector<int> Eulerpath;
        DFS(startNode,adj,Eulerpath);
        reverse(Eulerpath.begin(),Eulerpath.end());

       vector<vector<int>> result;
        for(int i=0;i<Eulerpath.size()-1;i++){
            result.push_back({Eulerpath[i],Eulerpath[i+1]});
        }
        return result;
    }
};