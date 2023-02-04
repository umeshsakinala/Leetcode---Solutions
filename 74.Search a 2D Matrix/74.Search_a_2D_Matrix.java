class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int rows = matrix.length;
        int columns = matrix[0].length;
        int start = 0;
        int end = rows*columns-1;
        int middle = start + (end-start)/2;
        int temp;
        while(start <= end)
        {
            int element = matrix[middle/columns][middle%columns];
            if(element == target) return true;
            if(element < target) start = middle+1;
            else end = middle-1;
            middle = start + (end-start)/2;
        }
        return false;
    }
}
