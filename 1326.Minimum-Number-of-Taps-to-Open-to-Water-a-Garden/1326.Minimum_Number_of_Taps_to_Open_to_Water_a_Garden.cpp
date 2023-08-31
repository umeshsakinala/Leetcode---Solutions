class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> reach(n+1, 0);
        for(int i=0; i<ranges.size(); i++)
        {
            int s = max(0, i-ranges[i]);
            int e = i+ranges[i];
            reach[s] = e;
        }
        int tap=0;
        int curr=0;
        int next=0;
        for(int i=0; i<=n; i++)
        {
            if(i>next)
            {
                return -1;
            }
            if(i>curr)
            {
                tap++;
                curr = next;
            }
            next = max(next, reach[i]);
        }
        return tap;
    }
};