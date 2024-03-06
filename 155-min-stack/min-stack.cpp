class MinStack {
public:
    int arr[30000];
    int mn[30000];
    int tp;
    MinStack() {
        tp=-1;
    }
    
    void push(int val) {
        
        arr[++tp]=val;
        
        if(tp!=0)
        mn[tp]=min(val, mn[tp-1]);
        else
        mn[0]=val;
    }
    
    void pop() {
        tp--;
    }
    
    int top() {
        return arr[tp];
    }
    
    int getMin() {
        return mn[tp];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */