class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string b = s + s;
        string ans = b.substr(1, b.size() - 2);
        return ans.find(s) != string::npos;
    }
};
