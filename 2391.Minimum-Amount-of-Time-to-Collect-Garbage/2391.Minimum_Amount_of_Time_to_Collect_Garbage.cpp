class Solution {
public:
    int garbageCollection(std::vector<std::string>& garbage, std::vector<int>& travel) {
        int tempG = 0;
        int tempP = 0;
        int tempM = 0;
        std::string str = "";
        for( int i = garbage.size() - 1; i >= 0; i--) {
            str = garbage[i];
            for(char ch : str) {
                if(ch == 'G')
                    tempG++;
                if(ch == 'P')
                    tempP++;
                if(ch == 'M')
                    tempM++;
            }
            if(i == 0) break;
            if(tempG > 0)
                tempG += travel[i - 1];
            if(tempP > 0)
                tempP += travel[i - 1];
            if(tempM > 0)
                tempM += travel[i - 1];
        }

    return tempG + tempP + tempM;
}
};