class Solution {
public:
    int ways(vector<string>& p, int c) {
        int row = p.size();
        int m = 1000000007;
        int col = p[0].size();
        
        vector<vector<int>> cup = vector<vector<int>>(row+1, vector<int>(col + 1, 0));
        for(int i = row-1; i >= 0; i--){
            for(int j = col-1; j >= 0; j--){
                cup[i][j] = cup[i+1][j] + cup[i][j+1] - cup[i+1][j+1];
                if(p[i][j] == 'A'){
                    cup[i][j] += 1;
                }
            }
        }
        
        
        vector<vector<int>> d = vector<vector<int>>(row+1, vector<int>(col + 1, 0));
        
        
        for(int i = row-1; i >= 0; i--){
            for(int j = col-1; j >= 0; j--){
                if(cup[i][j] > 0){
                    d[i][j] = 1;
                }
            }
        }

        vector<vector<int>> dprev = d;
        d = vector<vector<int>>(row+1, vector<int>(col + 1, 0));
        
        for(int k = 1; k < c; k++){
            for(int i = row - 1; i >= 0; i--){
                for(int j = col-1; j >= 0; j--){
                    d[i][j] = 0;
                    
                    //possible horizontal cuts
                    for(int a = i; a <= row; a++)
                    {
                        if(cup[i][j] > cup[a][j] && cup[a][j] > 0)
                        {
                                d[i][j] = (d[i][j]%m + dprev[a][j] %m)%m;
                        }
                    }
                    //possible verticle cuts
                    for(int b = j; b <= col; b++)
                    {
                        if(cup[i][j] > cup[i][b] && cup[i][b] > 0)
                        {
                                d[i][j] = (d[i][j]%m + dprev[i][b] %m)%m;
                        }     
                    }
                }
                
            }
            
            dprev = d;
        }     
        return dprev[0][0];
    }
};
