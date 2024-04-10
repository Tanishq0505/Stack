// 344. Reverse String
// leetcode

class Solution {
public:
// see code and do dry run to undeerstand
    void reverseString(vector<char>& s) {
        
  stack<char>st;
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        st.push(ch);
    }
// Initialize an index i 
// to keep track of the current position in the string s. Start from index 0.
int i=0;
// While the stack is not empty, perform the following steps:
// Pop the top character from the stack.
// Assign the popped character to the current position s[i] in the original string s.
// Increment the index i to move to the next position in the string.

   while(!st.empty()){
           s[i]=st.top();
           st.pop();
           i++;
    }
    }
};
