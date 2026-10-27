class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m,string(n,'#'));

        for(int i=0;i<n;i++){ //first row fill
            grid[0][i] = '.';
        }

        for(int j=0;j<m;j++){ //fill last column
            grid[j][n-1] = '.';
        }
        return grid;
    }
};