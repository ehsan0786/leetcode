class Solution {
public:
    string arrangeWords(string text) {

        stringstream ss(text);
        string word;
        vector<string>words;

        while(ss >> word){
            words.push_back(word);
        }

        stable_sort(words.begin(),words.end(),[](string a,string b){
                return a.size() < b.size();
        });

        string ans;

        for(int i=0;i<words.size();i++){
            if(i>0) ans += " ";
            ans += words[i];
        }


        ans[0] = toupper(ans[0]);

        for(int i=1;i<ans.size();i++){
            ans[i] = tolower(ans[i]);
        }

        return ans;

    }
};

