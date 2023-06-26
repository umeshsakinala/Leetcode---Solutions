class Solution
{
public:
    long long totalCost(vector<int> &costs, int k, int m)
    {
        long long ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;
        int n = costs.size();
        int i = 0, j = n - 1;
        while (i < n && i < m)
        {
            pq1.push(costs[i++]);
        }
        while (j >= i && j >= n - m)
        {
            pq2.push(costs[j--]);
        }
        while (k--)
        {
            if (!pq1.empty() && !pq2.empty())
            {
                if (pq1.top() < pq2.top())
                {
                    ans += pq1.top();
                    pq1.pop();
                    if (i <= j)
                    {
                        pq1.push(costs[i++]);
                    }
                }
                else if (pq1.top() > pq2.top())
                {
                    ans += pq2.top();
                    pq2.pop();
                    if (i <= j)
                    {
                        pq2.push(costs[j--]);
                    }
                }
                else
                {
                    ans += pq1.top();
                    pq1.pop();
                    if (i <= j)
                    {
                        pq1.push(costs[i++]);
                    }
                }
            }
            else if (pq1.empty())
            {
                ans += pq2.top();
                pq2.pop();
                if (i <= j)
                {
                    pq2.push(costs[j--]);
                }
            }
            else
            {
                ans += pq1.top();
                pq1.pop();
                if (i <= j)
                {
                    pq1.push(costs[i++]);
                }
            }
        }
        return ans;
    }
};