class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> mp;

        // Count frequency of each character in s
        for (char ch : s) {
            mp[ch]++;
        }

        string ans = "";

        // Add characters according to order
        for (char ch : order) {
            while (mp[ch] > 0) {
                ans += ch;
                mp[ch]--;
            }
        }

        // Add remaining characters
        for (auto &it : mp) {
            while (it.second > 0) {
                ans += it.first;
                it.second--;
            }
        }

        return ans;
    }
};