class Solution {
public:
int util(vector<int> &nums,int k){
    bool allneg=true;int maxx=INT_MIN;
            for(int i=0;i<nums.size();i++){
                maxx=max(maxx,nums[i]);
                if(nums[i]>0) allneg=false;
            }
            if(allneg) return maxx;
            int ans=0;
            int gap=0;int sum=0;int currmax=-1;
            for(int i=0;i<nums.size();i++){
                if(nums[i]>=0){
                    gap=0;currmax=-1;
                 sum+=nums[i];
                 ans=max(ans,sum);
                }
                else{
                gap++;
                if(currmax==-1||nums[currmax]<=nums[i]) currmax=i;
                if(gap==k){
                    if(sum+nums[currmax]>0){
                        sum+=nums[currmax];
                        gap=i-currmax;
                    }
                    else {sum=0;gap=0;}
                    currmax=-1;
                }
                }
            }
            return ans;
}
    int constrainedSubsetSum(vector<int>& nums, int k) {
            int ans=util(nums,k);
            reverse(nums.begin(),nums.end());
            return max(ans,util(nums,k));
    }
};