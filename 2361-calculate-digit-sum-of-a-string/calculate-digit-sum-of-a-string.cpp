class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size() > k){
            string temp = "";
            for(int i=0;i<s.size();i+=k){
                int curr_sum = 0;
                for(int j=i;j<s.size()&&j<i+k;j++){
                    curr_sum += s[j] - '0';
                }
                temp += to_string(curr_sum);
            }
            s = temp;
        }
        return s;
    }
};