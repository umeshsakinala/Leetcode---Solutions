class Solution {
public:
    int numberOfWays(string corridor) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        const int MOD = 1e9+7;
        const int n = corridor.size();
        if(n == 1) return 0;
        vector<pair<int, int>> seats;
        int s1 = -1, s2 = -1;
        for(int i = 0; i < n; i++)
        {
            if(corridor[i] == 'S')
            {
                if(s1 == -1)
                {
                    s1 = i;
                }
                else if(s2 == -1)
                {
                    s2 = i;
                    seats.push_back({s1, s2});
                    s1 = -1;
                    s2 = -1;
                }
            }
        }
        if(s1 != -1 && s2 == -1)
        {
            return 0;
        }
        if(seats.size() == 0) return 0;
        if(seats.size() == 1) return 1;
        long long answer = 1;
        for(int i = 0; i < seats.size()-1; i++)
        {
            int num = seats[i+1].first - seats[i].second;
            answer = (answer * num) % MOD;
        }
        return answer % MOD;
    }
};