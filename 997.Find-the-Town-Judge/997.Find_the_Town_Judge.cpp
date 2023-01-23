class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> arr(n+1, 0);
        for(auto i: trust)
        {
            arr[i[0]]--;
            arr[i[1]]++;
        }
        for(int i=1; i<n+1; i++)
        {
            if(arr[i] == n-1)
            {
                return i;
            }
        }
        return -1;
    }
};
