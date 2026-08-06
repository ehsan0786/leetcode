class Solution {
public:
    bool topologicalSortCheck(unordered_map<int,vector<int>> &adj,int n,vector<int> &indegree){
        queue<int> que;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                que.push(i);
                cnt++;
            }
        }
        while(!que.empty()){
            int u = que.front();
            que.pop();
            for(int &v:adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    que.push(v);
                    cnt++;
                }
            }
        }
        if(cnt == n) return true;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(numCourses,0); //kahns algo
        for(auto &vec:prerequisites){
            int u = vec[0];
            int v = vec[1];
            //u ---> v
            adj[v].push_back(u); //arrow goes to u
            indegree[u]++;
        }

        return topologicalSortCheck(adj,numCourses,indegree);
    }
};