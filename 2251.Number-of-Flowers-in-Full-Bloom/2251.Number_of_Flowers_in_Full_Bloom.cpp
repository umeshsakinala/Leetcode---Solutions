class Solution {
    int bloomIn(vector<int> &start,int p){
        int ans=-1;
        int i=0; int e=start.size()-1;
        while(i<=e){
            int m=i+(e-i)/2;
            if(start[m]<=p){
                ans=m;
                i=m+1;
            }
            else e=m-1;
        }
        return ans;
    }
    int bloomOut(vector<int> &finish,int p){
        int ans=-1;
        int i=0; int e=finish.size()-1;
        while(i<=e){
            int m=i+(e-i)/2;
            if(finish[m]<p){
                ans=m;
                i=m+1;
            }
            else e=m-1;
        }
        return ans;
    }
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> ans(people.size());
        vector<int> start;
        vector<int> finish;
        for(int i=0;i<flowers.size();i++){
            start.push_back(flowers[i][0]);
            finish.push_back(flowers[i][1]);
        }
        sort(begin(start),end(start));
        sort(begin(finish),end(finish));
        // how many flowers are bloomedIn - bloomedOut
        for(int i=0;i<people.size();i++){
            int in=bloomIn(start,people[i]);
            int out=bloomOut(finish,people[i]);
            if(in==-1) continue;
            ans[i]=in-out;
        }
        return ans;
    }
};