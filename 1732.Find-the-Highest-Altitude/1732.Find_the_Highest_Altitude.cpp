class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        stack<int> st;
        int a = 0;
        st.push(0);
        for(int i=0; i<gain.size(); i++)
        {
            cout << gain[i] << " ";
            st.push(gain[i] + st.top());
            a = max(a, st.top());
        }
        return a;
    }
};