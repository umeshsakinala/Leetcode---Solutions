class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size()==1)
        return 1;
        int n=chars.size();
        int count=1;
        char prev=chars[0];
        int j=0;
        for(int i=1;i<n;i++)
        {
            if(chars[i]==prev)
            {
                count++;
                continue;
            }
            else
            {
                if(count==1)
                {
                    chars[j++]=prev;
                    prev=chars[i];
                    continue;
                }
                chars[j]=prev;j++;
                string c=to_string(count);
                for(int k=0;k<c.length();k++,j++)
                {
                    chars[j]=c[k];
                }
                count=1;
                prev=chars[i];
            }
        }
        chars[j]=prev;j++;
        if(count>1)
        {
            string c=to_string(count);
            for(int k=0;k<c.length();k++,j++)
            {
                chars[j]=c[k];
            }
        }
        chars.erase(chars.begin()+j,chars.end());
        return chars.size();
    }
};
