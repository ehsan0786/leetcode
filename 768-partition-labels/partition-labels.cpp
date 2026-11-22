class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp; // we r storing last_position of each chr
        for(int i=0;i<s.size();i++){
            mp[s[i]] = i;
        }

        int start = 0;
        int end = 0;
        vector<int>ans;

        for(int i=0;i<s.size();i++){
            end = max(end,mp[s[i]]); //we go to end index of each window
            if(i==end){
                ans.push_back(end-start+1);
                start = i+1; //We are starting a new window 
            }
        }
        return ans;
    }
};