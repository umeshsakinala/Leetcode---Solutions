class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=1; i<words.size(); i++)
        {
            string word1 = words[i-1];
            string word2 = words[i];
            int a = 0;
            while(word1[a] == word2[a])
            {
                a++;
                if(a >= word1.size())
                {
                    break;
                }
                else if(a >= word2.size())
                {
                    return false;
                }
            }
            if(a < word1.size())
            {
                char c1 = word1[a];
                char c2 = word2[a];
                for(int j=0; j<order.size(); j++)
                {
                    if(c2 == order[j])
                    {
                        return false;
                    }
                    if(c1 == order[j])
                    {
                        break;
                    }
                }
            }
        }
        return true;
    }
};
