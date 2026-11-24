class Solution {
public:
    string addStrings(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();

        int i = m-1;
        int j = n-1;
        int carry = 0;
        string ans;
    
        while(i>=0 || j>=0 || carry > 0){
            int digit1;
            int digit2;
            if(i>=0){
                digit1 = num1[i]-'0';
            }else{
                digit1 = 0;
            }
            if(j>=0){
                digit2 = num2[j]-'0';
            }else{
                digit2 = 0;
            }
            int sum = digit1+digit2+carry;
            ans += to_string(sum%10);
            carry = sum/10;
            i--;
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};