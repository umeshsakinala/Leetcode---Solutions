class Solution {
public:
    int partitionString(string s) {
        int count = 1;
        set<char> temp;
        for(auto ch:s)
        {
            if(temp.find(ch) != temp.end())
            {
                count++;
                temp.clear();
            }
            temp.insert(ch);
        }
        return count;
    }
};
