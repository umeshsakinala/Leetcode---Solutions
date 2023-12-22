class Solution {
public:
    int maxScore(string s) {
        int answer = 0;
        for(int i=1;i<s.length();i++)
        {
            int score=count(s.begin(),s.begin()+i,'0') + count(s.begin()+i,s.end(),'1');
            answer= max(score,answer);
        }
        return answer;
    }
};