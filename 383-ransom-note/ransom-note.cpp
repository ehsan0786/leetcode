class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp1,mp2;
        for(auto &x:ransomNote){
            mp1[x]++;
        }

        for(auto &x:magazine){
            mp2[x]++;
        }

        for(auto &y : mp1) {
            if(mp2[y.first] < y.second) {
                return false;
            }
        }
        return true;
    }
};