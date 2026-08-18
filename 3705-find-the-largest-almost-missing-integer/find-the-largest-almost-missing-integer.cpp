class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int i=0;
        int j=k-1;
        map<int,int>mp;
       
        int largest=INT_MIN;
        while(j<nums.size()){
            set<int>st;
            for(int start=i;start<=j;start++){
              st.insert(nums[start]);
        }
        for(auto x:st){
            mp[x]++;
        }
          i++;
          j++;

        }

        for(auto x:mp){
             if(x.second==1){
                largest=max(largest,x.first);
             }
        }
        return largest==INT_MIN ? -1:largest;
    }
};