class MinStack {
    stack<int> st;
    stack<int> minSt;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            minSt.push(val);
        }else{
            st.push(val);
            if(val < minSt.top()){
                minSt.push(val);
            }else{
                int t = minSt.top();
                minSt.pop();
                minSt.push(val);
                minSt.push(t);
            }
        }
    }
    
    void pop() {
        if(st.size()){
            int t = st.top();
            if(t == minSt.top())
                minSt.pop();
            st.pop();
        }
    }
    
    int top() {
        if(st.size())
            return st.top();

        return -1;
    }
    
    int getMin() {
        if(minSt.size())
            return minSt.top();

        return -1;
    }
};