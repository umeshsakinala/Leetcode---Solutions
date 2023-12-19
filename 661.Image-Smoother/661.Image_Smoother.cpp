vector<vector<int>> g;
bool check(int i, int j)
{
    if(i<0 || i==g.size())
        return false;

    if(j<0 || j==g[0].size())
        return false;

    return true;
}

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> res;
        res = img;
        g = img;
        int sum,count;
        for(int i=0; i<img.size(); ++i)
        {
            for(int j=0; j<img[0].size(); ++j)
            {
                count=1;
                sum=img[i][j];

                if(check(i-1,j))
                {
                    ++count;
                    sum+=img[i-1][j];
                }
                if(check(i+1,j))
                {
                    ++count;
                    sum+=img[i+1][j];
                }
                if(check(i,j-1))
                {
                    ++count;
                    sum+=img[i][j-1];
                }
                if(check(i,j+1))
                {
                    ++count;
                    sum+=img[i][j+1];
                }
                if(check(i-1,j-1))
                {
                    ++count;
                    sum+=img[i-1][j-1];
                }
                if(check(i+1,j-1))
                {
                    ++count;
                    sum+=img[i+1][j-1];
                }
                if(check(i-1,j+1))
                {
                    ++count;
                    sum+=img[i-1][j+1];
                }
                if(check(i+1,j+1))
                {
                    ++count;
                    sum+=img[i+1][j+1];
                }
                res[i][j] = sum/count;
            }
        }
        return res;
    }
};