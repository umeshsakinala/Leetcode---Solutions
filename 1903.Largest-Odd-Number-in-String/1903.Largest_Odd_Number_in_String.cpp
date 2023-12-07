class Solution {
public:
    string largestOddNumber(string num) {
        for(int i=num.size()-1; i>=0; i--)
        {
            if(num[i]%2 == 1)
            {
                return num;
            }
            num.pop_back();
        }
        return num;
    }
};