class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.size();
        unordered_map<string,string> mp;
        for(auto &x:knowledge){
            mp[x[0]] = x[1];
        }
        string result;
        int i=0;
        while(i<n){
            if(s[i]!='('){
                result += s[i];
                i++;
            }else{ //'('
                i++; //skip '('
                string temp;
                while(s[i]!=')'&&i<n){
                    temp += s[i];
                    i++;
                }
                //skip ')'
                i++;
                result += mp.count(temp)?mp[temp]:"?";
            }
        }
        return result;
    }
};