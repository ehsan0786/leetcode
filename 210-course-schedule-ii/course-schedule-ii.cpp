class Solution {
public:
    bool hasCycle;
    void DFS(unordered_map<int,vector<int>> &adj,int u,vector<bool> &visited,stack<int> &st,vector<bool> &inRecursion){
        visited[u]=true;
        inRecursion[u] = true;
        for(auto &v:adj[u]){
            if(inRecursion[v] == true){
                hasCycle = true;
                return;
            }
            if(!visited[v]){
                DFS(adj,v,visited,st,inRecursion);
            }
        }
        st.push(u);
        inRecursion[u]=false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        hasCycle = false;
        for(auto &vec : prerequisites){
            int a = vec[0];
            int b = vec[1];
            adj[b].push_back(a);
        }
        vector<bool> visited(numCourses,false);
        vector<bool> inRecursion(numCourses,false);
        stack<int> st;
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                DFS(adj,i,visited,st,inRecursion);
            }
        }
        if(hasCycle == true) return {};
        vector<int> result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};