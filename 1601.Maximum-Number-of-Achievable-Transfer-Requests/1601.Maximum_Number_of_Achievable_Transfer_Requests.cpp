class Solution {
public:
void totalcount(vector<vector<int>>& requests, int index, vector<int>& count, int current, int& max_count)
{
    if(index == requests.size())
    {
        for(int i=0; i<count.size(); i++)
        {
            if(count[i]  != 0)
            {
                return ;
            }
        }
        max_count = max(max_count, current);
        return ;
    }
    int from = requests[index][0];
    int to = requests[index][1];
    count[from]--;
    count[to]++;
    totalcount(requests, index+1, count, current+1, max_count);
    count[from]++;
    count[to]--;
    totalcount(requests, index+1, count, current, max_count);
}
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> count(n);
        int max_count = 0;
        totalcount(requests, 0, count, 0, max_count);
        return max_count;
    }
};