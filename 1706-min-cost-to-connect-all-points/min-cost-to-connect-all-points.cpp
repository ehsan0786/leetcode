class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    
    int find(int x){
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    
    void Union(int x,int y){
        int x_parent = find(x);
        int y_parent = find(y);
        
        if(x_parent == y_parent) return;
        
        if(rank[x_parent] > rank[y_parent]){
            parent[y_parent] = x_parent;
        }
        
        else if(rank[x_parent] < rank[y_parent]){
            parent[x_parent] = y_parent;
        }
        else{
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    int kruskal(vector<vector<int>> &edges){
        int sum = 0;
        
        for(auto &temp : edges){
            int u = temp[0];
            int v = temp[1];
            int wt = temp[2];
            
            int parent_u = find(u);
            int parent_v = find(v);
            
            
            if(parent_u != parent_v){
                Union(u,v);
                sum += wt;
            }
        }
        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();

        parent.resize(V);
        rank.resize(V);
        
        for(int i=0;i<V;i++){
            parent[i] = i;
        }
        vector<vector<int>> vec;

        for(int i=0;i<V;i++){
            for(int j=i+1;j<V;j++){
                int xi = points[i][0];
                int yi = points[i][1];
                int xj = points[j][0];
                int yj = points[j][1];
                int dist = abs(xi-xj)+abs(yi-yj);
                
                vec.push_back({i,j,dist});
            }
        }

        auto comparator = [&](vector<int> &v1,vector<int> &v2){
                return v1[2] < v2[2];
        };

        sort(vec.begin(),vec.end(),comparator);

        return kruskal(vec);
    }
};