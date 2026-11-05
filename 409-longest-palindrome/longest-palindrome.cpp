class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(auto &ch:s){
            mp[ch]++;
        }

        int length = 0;
        bool has_odd = false;

        for(auto &ch:mp){
            if (ch.second % 2 == 0){
                length += ch.second;
            }
            else{
                length += ch.second - 1;
                has_odd = true;
            }
        }
        if (has_odd) length += 1;
        return length;
    }
};