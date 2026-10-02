class Solution {
public:
    vector<string> res;
    string current;

    void backtrack(int openN, int closeN, int n) {
        if (openN == closeN && openN == n) {
            res.push_back(current);
            return;
        }

        if (openN < n) {
            current.push_back('(');
            backtrack(openN + 1, closeN, n);
            current.pop_back();  // backtrack
        }

        if (closeN < openN) {
            current.push_back(')');
            backtrack(openN, closeN + 1, n);
            current.pop_back();  // backtrack
        }
    }

    vector<string> generateParenthesis(int n) {
        backtrack(0, 0, n);
        return res;
    }
};