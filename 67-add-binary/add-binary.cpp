class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1;
        int j = b.size()-1;
        string ans;
        int carry = 0;

        while(i>=0 || j>=0 || carry){
            int digit1 = i>=0 ? a[i]-'0' : 0;
            int digit2 = j>=0 ? b[j]-'0' : 0;
            int sum = digit1+digit2+carry;
            ans += to_string(sum%2);
            carry = sum/2;
            i--;
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};