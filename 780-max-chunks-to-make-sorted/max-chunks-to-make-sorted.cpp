class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int max_values = 0;
        int chunks = 0;

        for(int i=0;i<n;i++){
            max_values = max(max_values,arr[i]);
            if(max_values == i) chunks++;
        }
        return chunks;
    }
};