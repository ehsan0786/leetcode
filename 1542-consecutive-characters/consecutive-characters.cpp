class Solution {
public:
    int maxPower(string s) {
        int curr_count = 0;
        int max_count = 0;
        char character;
        for(int i=0;i<s.size();i++){
            if(i==0 || s[i] == s[i-1]) curr_count += 1;
            else curr_count = 1;
            if(curr_count > max_count){
                max_count = curr_count;
                // character = s[i];
            }
        }
        //cout << character << " " << max_count " ";
        return max_count;

    }
};