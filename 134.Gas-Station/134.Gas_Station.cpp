class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank = 0;
        int station_number = 0;
        int remaining = 0;
        for(int i=0; i<gas.size(); i++)
        {
            remaining = remaining + gas[i] - cost[i];
            if(remaining < 0)
            {
                station_number = i+1;
                remaining = 0;
            }
            tank = tank + gas[i] - cost[i];
        }
        return tank >= 0 ? station_number : -1;
    }
};
