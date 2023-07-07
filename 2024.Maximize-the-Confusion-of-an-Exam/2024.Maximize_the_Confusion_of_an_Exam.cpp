class Solution {
public:
int window(string& key, int k, char ans)
{
    int j = 0;
    for(int i=0; i<key.size(); i++)
    {
        k -= key[i] != ans;
        if(k < 0)
        {
            k += key[j++] != ans;
        }
    }
    return key.size()-j;
}
    int maxConsecutiveAnswers(string answerKey, int k) {
        int a = window(answerKey, k, 'T');
        int b = window(answerKey, k, 'F');
        return max(a, b);
    }
};