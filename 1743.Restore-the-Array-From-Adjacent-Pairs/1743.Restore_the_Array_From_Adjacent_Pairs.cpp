class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adjacentMap;
        unordered_set<int> uniqueSet;
        vector<int> result;
        for(const auto& pair : adjacentPairs)
        {
            adjacentMap[pair[0]].push_back(pair[1]);
            adjacentMap[pair[1]].push_back(pair[0]);
        }
        int start = 0;
        for(const auto& entry : adjacentMap)
        {
            if(entry.second.size() == 1)
            {
                start = entry.first;
                break;
            }
        }
        while(true)
        {
            result.push_back(start);
            uniqueSet.insert(start);

            if(adjacentMap[start].empty())
            {
                break;
            }
            int next = adjacentMap[start][0];
            adjacentMap[next].erase(std::remove(adjacentMap[next].begin(), adjacentMap[next].end(), start), adjacentMap[next].end());
            if(uniqueSet.find(next) == uniqueSet.end())
            {
                start = next;
            }
        }
        return result;
    }
};