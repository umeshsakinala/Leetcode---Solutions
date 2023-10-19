class Solution {
public:
    string compare(string temp) {
        string flag;
        for(int i=0; i<temp.size(); i++)
        {
            if(temp[i] == '#')
            {
                if(flag.size() > 0)
                {
                    flag.pop_back();
                }
            }
            else
            {
                flag.push_back(temp[i]);
            }
        }
        return flag;
    }
    bool backspaceCompare(string s, string t) {
        return compare(s) == compare(t);
    }
};