class Solution {
public:
    bool checkduplicate(vector<int>&freq){
        for(int i=0;i<26;i++)
            if(freq[i]>1)
                return true;
        return false;
    }
    bool buddyStrings(string s, string goal) {
        if(goal.length()!=s.length()) return false;
        vector<int> freq(26,0);
        vector<pair<char,char>> v;
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
            if(s[i]!=goal[i])
                v.push_back({s[i],goal[i]});
        }
        if(v.size()==0)
            if(checkduplicate(freq)) return true;
        if(v.size()==2&&v[0].first==v[1].second&&v[1].first==v[0].second)
            return true;
        return false;
    }
};