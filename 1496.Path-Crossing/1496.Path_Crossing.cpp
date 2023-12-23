class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>>s;
        int x=0,y=0;
        for(int i=0;i<path.length()+1;i++)
        {
            if(s.count({x,y})==0)
            {
                s.insert({x,y});
            }
            else
            {
                return true;
            }
            if(path[i]=='N')
            {
                y++;
            }
            else if(path[i]=='S')
            {
                y--;
            }
            else if(path[i]=='E')
            {
                x++;
            }
            else
            {
                x--;
            }
        }
        return false;
    }
};