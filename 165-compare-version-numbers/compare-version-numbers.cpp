class Solution {
public:
    vector<string> solve(string version){
        stringstream ss(version);
        string words;
        vector<string> word;
        while(getline(ss,words,'.')){
            word.push_back(words);
        }
        return word;
    }
    int compareVersion(string version1, string version2) {
        vector<string>v1 = solve(version1);
        vector<string>v2 = solve(version2);

        int m = v1.size();
        int n = v2.size();

        int i = 0;
        int j = 0;

        while(i<m || j<n){
            int x = i<m ? stoi(v1[i]):0;
            int y = j<n ? stoi(v2[j]):0;
            if(x<y){
                return -1;
            }else if(x>y){
                return 1;
            }else{ //x==y
                i++;
                j++;
            }
        }
        return 0;

    }
};