class Solution {
public:
    string addBinary(string a, string b) {
        
        int carry = 0;
        
        int i = a.size() -1;
        int j  = b.size() -1;
        string ans;
        while(i >= 0 || j >= 0 || carry > 0) {
            int temp = 0;
            if(i >= 0) {
                
                temp = temp + int(a[i--] - '0');
            }
            
            if(j >= 0) {
                temp = temp + int(b[j--] - '0');
            }
            
            temp = temp + carry;
            int added = temp % 2;
            cout << added << " ";
            ans = ans + char(added + 48);
            
            carry = temp / 2;
           
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
