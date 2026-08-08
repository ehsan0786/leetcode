class Solution {
public:
    vector<int> topologocalSort(unordered_map<int,vector<int>> &adj,int n,vector<int> &indegree){
        queue<int> que;
        vector<int> result;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                que.push(i);
                cnt++;
                result.push_back(i);
            }
        }
        while(!que.empty()){
            int u = que.front();
            que.pop();
            for(auto &v : adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    que.push(v);
                    cnt++;
                    result.push_back(v);
                }
            }
        }
        if(cnt == n) return result;
        //means we had a cycle and we couldn't complete all courses
        return {};
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(numCourses,0);
        for(auto &vec :prerequisites){
            int u = vec[0];
            int v = vec[1];
            //{a,b}
            //b-->a
            adj[v].push_back(u);
            indegree[u]++;
        }
        return topologocalSort(adj,numCourses,indegree);
    }
};