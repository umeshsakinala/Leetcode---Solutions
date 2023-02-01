class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string gcd="",str="";
        for(int i=0;i<str1.size();i++)
        {
            str+=str1[i];
            string s1="",s2="";
            while(s1.size()<str1.size() && s1!=str1)
            s1+=str;
            while(s2.size()<str2.size() && s2!=str2)
            s2+=str;
            if(s1==str1 && s2==str2)
            gcd=str;
        }
        return gcd;
    }
};
