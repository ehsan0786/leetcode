class Solution {
public:
    bool isCycleDFS(unordered_map<int,vector<int>> &adj,int u,vector<int> &visited,vector<int> &inRecursion){
        visited[u] = true;
        inRecursion[u] = true;
        for(auto &v : adj[u]){
            if(!visited[v] && isCycleDFS(adj,v,visited,inRecursion)){
                return true;
            }else if(inRecursion[v]==true){
                return true;
            }
        }
        inRecursion[u]=false;
        return false; //no cycle
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) { 
        //DFS
        unordered_map<int,vector<int>> adj;
        vector<int> visited(numCourses,false);
        vector<int> inRecursion(numCourses,false);
        for(auto &vec : prerequisites){
            int a = vec[0];
            int b = vec[1];
            adj[b].push_back(a);
        }
        for(int i=0;i<numCourses;i++){
            if(!visited[i] && isCycleDFS(adj,i,visited,inRecursion)){
                return false; //course complete nahi kar sakte 
            }
        }
        return true; //complete kar sakte hain saare courses
        
    }
};