class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
         unordered_map<char,int> mp;

        for(auto &x:magazine){
            mp[x]++;
        }

        for(auto &y : ransomNote) {
            if(mp[y] <=0){
                return false;
            }
        
            mp[y]--;
        }
        return true;

    }
};
