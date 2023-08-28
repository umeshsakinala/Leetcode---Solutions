\class MyStack {
public:
    queue<int> q1;
    MyStack() {
        
    }
    
    void push(int x) {
        queue<int> q2;
        int n= q1.size();
        for(int i=0; i<n; i++)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        for(int i=0; i<n; i++)
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {
        auto temp = q1.front();
        q1.pop();
        return temp;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        if(q1.size() == 0) return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */