class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int n = s.size();
       unordered_set<char> st;
       int ans = 0;
       int i = 0;
       for(int j=0;j<n;j++){
            while(st.count(s[j])){
                st.erase(s[i]);
                i += 1;
            }
            st.insert(s[j]);
            ans = max(ans,j-i+1);
       }
       return ans;
    }
};