class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> cities;
        for(const auto& pair : paths)
        {
            cities.insert(pair.front());
        }
        for(const auto& pair : paths)
        {
            if(cities.find(pair.back()) == cities.end()) return pair.back();
        }
        return "";
    }
};