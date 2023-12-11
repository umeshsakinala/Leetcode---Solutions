class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int, int> map;
        for(int i=0; i<arr.size(); i++)
        {
            map[arr[i]]++;
        }
        unordered_map<int, int>::iterator it;
        int answer;
        for(it = map.begin(); it!=map.end(); it++)
        {
            if(it->second > arr.size()/4)
            {
                answer = it->first;
            }
        }
        return answer;
    }
};