class Solution {
public:
int mod=1e9+7;
int total(vector<vector<int>>& memoi, vector<int>& locations, int start, int &finish, int fuel, int n)
{
    if(fuel < 0)
    {
        return 0;
    }
    if(memoi[start][fuel] != -1)
    {
        return memoi[start][fuel];
    }
    int ans = 0;
    if(start == finish)
    {
        ans++;        
    }
    for(int i=0; i<n; i++)
    {
        if(i!=start)
        {
            ans = (ans%mod + total(memoi, locations, i, finish, fuel - abs(locations[start] - locations[i]), n)%mod)%mod;
        }
    }
    return memoi[start][fuel] = ans%mod;
}
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>> memoi(n, vector<int>(fuel+1, -1));
        return total(memoi, locations, start, finish, fuel, n);
    }
};