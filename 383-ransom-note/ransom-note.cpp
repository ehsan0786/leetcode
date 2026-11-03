class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int m = ransomNote.size();
        int n = magazine.size();
        vector<int> freq(26,0);

        for(auto &x: ransomNote){
            freq[x-'a'] -= 1;
        }

        for(auto &x: magazine){
            freq[x-'a'] += 1;
        }
        
        for(int i=0;i<26;i++){
            if(freq[i] < 0){
                return false;
            }
        }
        return true;

    }
};
