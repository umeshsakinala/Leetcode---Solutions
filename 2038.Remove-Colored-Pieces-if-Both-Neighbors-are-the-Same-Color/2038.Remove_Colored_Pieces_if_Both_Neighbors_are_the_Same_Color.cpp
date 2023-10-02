class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice = 0;
        int bob = 0;
        for(int i = 1; i < colors.size() - 1; i++)
        {
            char current = colors[i];
            char prev = colors[i - 1];
            char next = colors[i + 1];
            if(prev == 'A' && current == 'A' && next == 'A')
            {
                alice++;
            }
            else if(prev == 'B' && current == 'B' && next == 'B')
            {
                bob++;
            }
        }
        return alice > bob;
    }
};