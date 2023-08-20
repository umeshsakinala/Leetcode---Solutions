class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& back) {
        
        vector<vector<int>> a(2*n),b(2*n),gp(2*n),grp(2*n);
        vector<int> ind(2*n,0),indg(2*n,0);
        for(int i=0;i<n;i++)
        {
            if(group[i]!=-1)
            grp[group[i]].push_back(i);
            else
            {
                grp[m+i].push_back(i);
                group[i]=m+i;
            }
        }
        
        for(int i=0;i<back.size();i++)
        {
            for(auto it:back[i])
            {
                if(group[i]==group[it])
                {
                   b[it].push_back(i);
                   indg[i]++;
                   continue;
                }
                else
                {
                    a[group[it]].push_back(group[i]);
                    ind[group[i]]++;
                }
            }
        }

        for(int i=0;i<2*n;i++)
        {
            deque<int> q;
            for(auto it:grp[i])
            {
                if(indg[it]==0)
                {
                    q.push_back(it);
                }
            }
            while(!q.empty())
            {
                int t=q.front();
               // cout<<t<<endl;
                q.pop_front();
                gp[i].push_back(t);
                for(auto it:b[t])
                {
                    indg[it]--;
                    if(indg[it]==0)
                    {
                        q.push_back(it);
                    }
                }
            }
        }

        deque<int> q;
        vector<int> res,ans;

        for(int i=0;i<2*n;i++)
        {
            if(ind[i]==0)
            {
                 q.push_back(i);
            }
        }

        while(!q.empty())
            {
                int t=q.front();
               // cout<<t<<endl;
                q.pop_front();
                ans.push_back(t);
                for(auto it:a[t])
                {
                    ind[it]--;
                    if(ind[it]==0)
                    {
                        q.push_back(it);
                    }
                }
            }

    for(int i=0;i<ans.size();i++)
    {
        for(auto x:gp[ans[i]])
        {
            res.push_back(x);
        }
    }

        if(res.size()!=n)
        {
            return {};
        }
        return res;
    }
};  