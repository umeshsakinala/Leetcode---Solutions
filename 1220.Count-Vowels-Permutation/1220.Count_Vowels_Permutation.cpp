class Solution {
public:
    int countVowelPermutation(int n) {
        int a=1,e=1,i=1,o=1,u=1;
        int mod = 1e9+7;
        for(int x=2;x<=n;x++)
        {
            int temp_a = a,temp_e= e, temp_i=i, temp_o=o, temp_u=u;
            a = ((temp_e + temp_i) % mod + temp_u) % mod;
            e = (temp_a +temp_i) % mod;
            i = (temp_e + temp_o) % mod;
            o = temp_i;
            u = (temp_i + temp_o) % mod;
        }
        return ((((a+e)%mod+i)%mod+o)%mod+u)%mod;
    }
};