class Solution {
public:
    string removeOuterParentheses(string s) {
        string answer;
        int depth = 0;

        for (auto &c : s) {
            if (c == '(') {
                if (depth > 0) {
                    answer.push_back(c);
                }
                depth++;
            } else {
                depth--;
                if (depth > 0) {
                    answer.push_back(c);
                }
            }
        }

        return answer;
    }
};