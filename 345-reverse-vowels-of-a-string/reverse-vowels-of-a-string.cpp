class Solution {
public:
    string reverseVowels(string s) {
        string temp = s;
        string vowels = "aeiouAIEOU";
        int left = 0;
        int right = s.size()-1;

        while(left < right){
            if(vowels.find(temp[left]) == string::npos) left++;
            else if(vowels.find(temp[right]) == string::npos) right--;
            else{
                swap(temp[left],temp[right]);
                left++;
                right--;
            }
        }
        return temp;
    }
};