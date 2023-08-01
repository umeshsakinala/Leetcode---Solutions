class Solution {
public:
void combinations(int n, int k, int num, vector<int>& temp, vector<vector<int>>& ans)
{
    if(k == 0)
    {
        ans.push_back(temp);
        return;
    }
    if(num == n+1)
    {
        return;
    }
    combinations(n, k, num+1, temp, ans);
    temp.push_back(num);
    combinations(n, k-1, num+1, temp, ans);
    temp.pop_back();
}
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> ans;
        combinations(n, k, 1, temp, ans);
        return ans;
    }
};