class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end());
        salary.pop_back();
        salary.erase(salary.begin());
        double a = accumulate(salary.begin(), salary.end(), 0);
        double b = salary.size();
        return a/b;
    }
};
