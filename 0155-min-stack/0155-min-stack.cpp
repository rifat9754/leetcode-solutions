class MinStack {
public:
    stack<long long int> s;
    long long int minval;
    MinStack() {
        
    }
    
    void push(int value) {
        if(s.empty()){
            s.push(value);
            minval = value;
        }
        else{
            if(minval>value){
                s.push((long long int)2*value-minval);
                minval = value;
            }
            else{
                s.push(value);
            }
        }
    }
    
    void pop() {
        if(s.top()<minval){
            minval = (long long int)2*minval - s.top();
        }
        s.pop();
    }
    
    int top() {
        if(s.top()<minval){
            return minval;
        }
        return s.top();
    }
    
    int getMin() {
        return minval;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */