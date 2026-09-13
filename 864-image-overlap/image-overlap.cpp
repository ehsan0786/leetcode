class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        vector <pair <int,int>> Coordinates_img1;
    vector <pair <int,int>> Coordinates_img2;
    for(int i=0;i<n;i++){
        for(int k=0;k<img1[0].size();k++){
            if(img1[i][k]==1){
                int y= n-1-i;
                int x= k;
                Coordinates_img1.push_back({x,y});
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int k=0;k<img2[0].size();k++){
            if(img2[i][k]==1){
                int y= n-1-i;
                int x= k;
                Coordinates_img2.push_back({x,y});
            }
            
        }
    }
    vector<vector<int>> cnt(2 * n, vector<int>(2 * n, 0));
        int best = 0;
        for (auto& a : Coordinates_img1) {
            for (auto& b : Coordinates_img2) {
                int dx = b.first - a.first + n;
                int dy = b.second - a.second + n;
                best = max(best, ++cnt[dx][dy]);
            }
        }

    
    return best;

    }
};