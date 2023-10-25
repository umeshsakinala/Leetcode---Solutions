class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1) {
            return 0;
        }
        bool change = true;
        for(int i = n ; i>1 ; i--) {
            if(!(k%2)) {
                change = (!change);
                k = k/2;
                continue;
            }
            k=(k+1)/2;
        }
        return change ? 0 : 1;
    }
};