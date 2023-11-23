class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size();
           int m = l.size();
           vector<bool>pre(m, false);
           for(int i=0; i<m; i++)
           {
               int s = l[i];
               int e = r[i];
               vector<int>temp;
               for(int j=s; j<=e; j++)
               {
                   temp.push_back(nums[j]);
               }
               sort(temp.begin(), temp.end());
               if(temp.size()==1)
               {
                   pre[i] = true;
                   continue;
                }
               bool check = false;
               int diff = temp[1]-temp[0];
               
               for(int i=1; i<temp.size(); i++)
               {
                   if(temp[i] == temp[i-1]+diff)
                      check = true;
                   else{
                       check = false;
                       break;
                   }   
               }

               if(check)
                pre[i] = true;
               else
                pre[i] = false;
           }
        return pre;
    }
};