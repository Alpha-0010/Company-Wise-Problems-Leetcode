class MinStack {
public:
    /** initialize your data structure here. */
    // Here we will maintain 2 stacks. S1 and min_stack. We will use S1 for normal stack
    // operations and min_stack will have the smallest element at its top.
    stack<int>s1;
    stack<int>min_stack;
    MinStack() {
        
    }
    
    void push(int x) {
        if(min_stack.size()==0 or min_stack.top()>=x){
            min_stack.push(x);
        }
        s1.push(x);
    }
    
    void pop() {
        if(min_stack.top()==s1.top()){
            min_stack.pop();
        }
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */