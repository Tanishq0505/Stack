// 155. Min Stack (leetcode)

// https://youtu.be/wePWCZjtrOo
// see video to understand

class MinStack {
public:

stack<int>st,s2;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s2.empty()||val<=s2.top()){
            s2.push(val);
        }
        st.push(val);
    }
    
    void pop() {
        if(st.top()==s2.top()){
            s2.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
          return s2.top();
    }
};

