class Solution {

    int index = 0;

public:

    vector<string> braceExpansionII(string expression) {

        set<string> result = parse(expression);

        vector<string> ans(result.begin(), result.end());

        return ans;
    }

    set<string> parse(string& s) {

        set<string> result;

        set<string> current;
        current.insert("");

        while (index < s.length() && s[index] != '}') {

            char ch = s[index];
            if (ch == ',') {

                result.insert(current.begin(), current.end());

                current.clear();
                current.insert("");

                index++;
            }

            // Concatenation
            else {

                set<string> next = getNext(s);

                set<string> combined;

                for (string a : current) {
                    for (string b : next) {
                        combined.insert(a + b);
                    }
                }

                current = combined;
            }
        }
        result.insert(current.begin(), current.end());

        return result;
    }

    set<string> getNext(string& s) {

        char ch = s[index];

        if (isalpha(ch)) {

            set<string> result;

            result.insert(string(1, ch));

            index++;

            return result;
        }
        if (ch == '{') {

            index++; // skip '{'

            set<string> result = parse(s);

            index++; // skip '}'

            return result;
        }

        return {};
    }
};