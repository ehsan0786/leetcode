class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        //graph - adjacency list
        vector<vector<int>> adj(n); //u -> {ngbr1,ngbr2}
        vector<int> inDegree(n,0);
        vector<int> suspicious(n,false);

        for(auto &edge :invocations){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }

        //BFS
        queue<int> q;
        q.push(k);
        suspicious[k] = true;

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(auto &ngbr : adj[curr]){
                inDegree[ngbr]--;
                if(!suspicious[ngbr]){
                    q.push(ngbr);
                    suspicious[ngbr] = true;
                }
            }
        }

        vector<int> result;
        bool cannotRemove = false;

        for(int i=0;i<n;i++){
            if(suspicious[i] && inDegree[i]>0){
                cannotRemove=true;
                break;
            }
            if(!suspicious[i]){
                result.push_back(i);
            }
        }

        if(cannotRemove){
            vector<int> vec(n); //0,1,2,3,...n-1
            for(int i=0;i<n;i++){
                vec[i] = i;
            }
            return vec;
        }
        return result;
    }
};