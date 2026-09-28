class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int i=0;
        int cnt=0;
        int cnt1 = 0;
        while(i<n){
            if(s[i] == '('){
                cnt++;
                cnt1 = max(cnt1,cnt);
            }else if(s[i] == ')'){
                cnt--;
            }
            i++;
        }
        return cnt1;
    }
};