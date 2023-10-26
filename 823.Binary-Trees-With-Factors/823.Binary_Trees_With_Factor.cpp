class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        if(arr.empty()){
          return 0;
        }
        sort(arr.begin(), arr.end());
        unordered_map<int, long long> map;
        for(int i=0;i<arr.size();i++){
          long long count=1;
          for(int j=0;j<i;j++){
            if(arr[i]%arr[j]==0 && map.count(arr[i]/arr[j])){
              count+=map[arr[j]]*map[arr[i]/arr[j]];
            }
          }
          map[arr[i]]=count;
        }
        long long totalcount=0;
        for(auto entry : map){
          totalcount+=entry.second;
        }
        return totalcount % (1000000000+7);
    }
};