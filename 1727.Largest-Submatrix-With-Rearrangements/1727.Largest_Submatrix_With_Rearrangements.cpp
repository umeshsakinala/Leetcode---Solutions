class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int ans = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();

        for(int j=0; j<cols; j++) {
            for(int i=1; i<rows; i++) {
                if(matrix[i][j] == 1) {
                    matrix[i][j] += matrix[i-1][j];
                }
            }
        }

        for(int i=0; i<rows; i++) {
            sort(matrix[i].begin(), matrix[i].end());
            reverse(matrix[i].begin(), matrix[i].end());
            
            for(int j=0; j<cols; j++) {
                int area = matrix[i][j] * (j+1);
                ans = max(ans,area);
            }
        }
        
        return ans;
    }
};