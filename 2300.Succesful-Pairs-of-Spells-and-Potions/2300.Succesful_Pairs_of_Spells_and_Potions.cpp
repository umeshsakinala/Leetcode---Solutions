class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int m=potions.size();
        vector<int>ans;
        for(auto it: spells)
        {
            long long find;
            if(success%(long long)it ==0)
            {
                find=success/(long long)it;
            }
            else 
            {
                find=success/(long long)it;
                find++;
            }
            int index=lower_bound(potions.begin(),potions.end(),find)-potions.begin();
            ans.push_back(m-index);
        }
        return ans;
    }
};
