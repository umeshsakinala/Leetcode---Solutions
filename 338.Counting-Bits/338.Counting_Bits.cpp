class Solution {
public:
    vector<int> countBits(int n) {
        int count = 0;
        vector<int> flag;
        // flag.push_back(0);
        // flag.push_back(1);
        int i=0;
        int temp;
        while(i <= n)
        {
            int temp = i;
            while(temp)
            {
                int rem = temp%2;
                temp = temp/2;
                if(rem == 1)
                {
                    count++;
                }
            }
            flag.push_back(count);
            count = 0;
            i++;
        }
        return flag;
    }
};