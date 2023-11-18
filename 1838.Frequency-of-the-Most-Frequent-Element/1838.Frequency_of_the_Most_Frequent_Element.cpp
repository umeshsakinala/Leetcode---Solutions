class Solution {
public:
    bool posb(int freq,vector<int>&a,int op){
        int n=a.size();
        int cnt=1;
        long long sum=0;
        for(int i=0;i<freq-1;i++){
            sum+=a[i];
        }
        for(int i=freq-1;i<n;i++){
            if(sum+(long long)op>=(long long)(freq-1)*(a[i])){
                return true;
            }
            sum-=a[i-(freq-1)];
            sum+=a[i];
        }
        return false;
    }
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        int s=1,e=n;
        int maxi=1;
        sort(nums.begin(),nums.end());
        while(s<=e){
            int mid=s+(e-s)/2;
            if(posb(mid,nums,k)){
                maxi=mid;
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return maxi;
    }
};