class BrowserHistory {
public:
    vector<string> V;
    int count = 0;
    int current;
    BrowserHistory(string homepage) {
        V.push_back(homepage);
        current = 0;
    }
    
    void visit(string url) {
        current++;
        V.resize(current);
        V.push_back(url);
    }
    
    string back(int steps) {
        current = max(0, current-steps);
        return V[current];
    }
    
    string forward(int steps) {
        int N = V.size();
        current = min(N-1, current+steps);
        return V[current];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
