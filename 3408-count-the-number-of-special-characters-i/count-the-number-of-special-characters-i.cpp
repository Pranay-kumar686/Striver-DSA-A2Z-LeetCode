class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<char> a, b;

        for(char c : word) {
            if(islower(c)) a.insert(c);
            else b.insert(tolower(c));
        }

        int ans = 0;

        for(char c : a)
            if(b.count(c)) ans++;

        return ans;
    }
};