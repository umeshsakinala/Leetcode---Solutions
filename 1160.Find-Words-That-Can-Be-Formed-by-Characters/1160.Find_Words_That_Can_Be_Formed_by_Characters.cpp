class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<int,int>m;
        for(auto ch: chars)
        {
            m[ch]++;
        }
        int ans = 0;
        for(auto word: words)
        {
            unordered_map<int,int> temp;
            for(auto w: word)
            {
                temp[w]++;
            }
            bool flag = false;
            for(auto w: word)
            {
                if(m.find(w) == m.end() || temp.find(w) == temp.end() || m[w] < temp[w])
                {
                    flag = true;
                    break;
                }
            }
            if(flag == false)
            {
                ans = ans + word.length();
            }
        }
        return ans;
    }
};