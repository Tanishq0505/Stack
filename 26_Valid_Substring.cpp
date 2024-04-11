// Valid Substring gfg
//   https://youtu.be/ULLkiR8xxUk
// see video to understand 

class Solution {
  public:

    int findMaxLen(string s) {
        // code here
    // Check if the input string s is empty or its length is less than 2. 
    // If so, return 0 because there cannot be a valid substring with less than two characters.

        if (s.empty() || s.length() < 2) {
        return 0;
    }
    stack<int> st;
         for (int i = 0; i < s.length(); i++) {
    //  If the current character is an opening parenthesis '(', push its index onto the stack.

        if (s[i] == '(') {
            st.push(i);
        }
        // If the current character is a closing parenthesis ')', check if the stack is not empty and 
        // the top of the stack contains an opening parenthesis. If true, pop the index from the stack.
// If the stack is empty or the top of the stack does not contain an opening parenthesis, push the index of the current closing parenthesis onto the stack.
        else {
            if (!st.empty() && s[st.top()] == '(') {
                st.pop();
            } else {
                st.push(i);
            }
        }
    }

    int max = 0;
    int end = s.length();
// While the stack is not empty, pop elements from the stack, calculate the length of the 
// valid substring, and update max with the maximum length found so far.

    while (!st.empty()) {
        int ele = st.top();
        st.pop();
        max = std::max(max, end - ele - 1);
        end = ele;
    }
    // Return the maximum of end (which represents the length of the prefix of the string
    // that has been checked for validity) and max (the maximum length of a valid substring).

 return std::max(end, max);
    }
};
