class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int current = 0;
        for(int i=0;i<k;i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                current += 1;
            }
        }

        int ans = current; //intially

        for(int i=k;i<n;i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){ //new window 
                current += 1;
            }
            if(s[i-k] == 'a' || s[i-k] == 'e' || s[i-k] == 'i' || s[i-k] == 'o' || s[i-k] == 'u'){ //old window
                current -= 1;
            }
            ans = max(ans,current);
        }
        return ans;
    }
};