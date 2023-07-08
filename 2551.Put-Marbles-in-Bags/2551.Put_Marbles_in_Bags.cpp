class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<long long> store;
        for(int i=1; i<weights.size(); i++)
        {
            store.push_back(weights[i] + weights[i-1]);
        }
        sort(store.begin(), store.end());
        int n = store.size();
        long long min = 0;
        for(int i=0; i<k-1; i++)
        {
            min = min+store[i];
        }
        long long max = 0;
        for(int i=0; i<k-1; i++)
        {
            max = max+store[n-1-i];
        }
        return max-min;
    }
};