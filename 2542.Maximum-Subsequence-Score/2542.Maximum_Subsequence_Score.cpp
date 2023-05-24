class Solution {
public:
    using int2=pair<int, int>;
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<int2> p(n);
        for(int i = 0; i < n; i++){
            p[i]={nums2[i],nums1[i]};
        }
        priority_queue<int,vector<int>,greater<int>> pq;

        sort(p.begin(),p.end(), [](int2& x, int2&y){
            if(x.first==y.first)
                return x.second<y.second;
            return x.first<y.first;
        });

        long long  ans = 0, sum = 0;

        for(int i = n-1; i >= 0; i--){
            auto& [x,y]=p[i];
            sum += y;
            pq.push(y);
            if(i < n-k+1){     
                if(pq.size()>k){
                    sum -= pq.top();
                    pq.pop();
                }
                ans = max(ans,sum*x);
            }
        }
        return ans;
    }
};
