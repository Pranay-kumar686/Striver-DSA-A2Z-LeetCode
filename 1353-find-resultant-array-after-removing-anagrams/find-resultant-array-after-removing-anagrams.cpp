class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;// res=[...]
        string prev="";// ""
        for(string word : words){
            string temp = word;// temp = word i.e 1st string "abba"
            sort(temp.begin(), temp.end()); // sorting the char in the word
            if(temp != prev){
                res.push_back(word); // res = "abba"
                prev=temp; // prev = abba
            } 
        }
        return res;
    }
};