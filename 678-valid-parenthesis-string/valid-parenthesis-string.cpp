class Solution {
public:
    bool checkValidString(string s) {
        stack<int> opening;
        stack<int> star;

        for(int i=0;i<s.size(); i++){
            if(s[i] == '(')
             opening.push(i);
            else if(s[i] == '*')
              star.push(i);
            else{
                if(!opening.empty())
                 opening.pop();
                else if(!star.empty())
                  star.pop();
                else return false;
            }
        }

        while(!opening.empty() && !star.empty()){
            if(opening.top() < star.top()){
                opening.pop();
                star.pop();
            }
            else return false;
        }

        if(opening.empty()) return true;
        else return false;

    }
};