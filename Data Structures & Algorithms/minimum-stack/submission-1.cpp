class MinStack {
    stack<int> st;
    stack<int> minSt;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);

        if(minSt.empty() || val <= minSt.top()){
            minSt.push(val);
        } else {
            minSt.push(minSt.top());
        }
    }
    
    void pop() {
        if(!st.empty()){
            st.pop();
            minSt.pop();
        }
    }
    
    int top() {
        return st.empty() ? -1 : st.top();
    }
    
    int getMin() {
        return minSt.empty() ? -1 : minSt.top();
    }
};