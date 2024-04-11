// Redundant Brackets gfg 
  // https://youtu.be/BmZnJehDzyU?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA
// see from 54 min lec 55 Q7

class Solution {
  public:
  // https://youtu.be/BmZnJehDzyU?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA
// see from 54 min lec 55 Q7
    int checkRedundancy(string s) {
        // code here
         stack<char> st;
    for(int i=0; i<s.length(); i++) {
        char ch =s[i];
        // If the current character is an opening parenthesis '(' or an operator (+, -, *, /), push it onto the stack.
        if(ch == '(' || ch == '+' ||ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        }
//         If the current character is a closing parenthesis ')', check for redundancy.
// Initialize a boolean variable isRedundant as true.
// Pop elements from the stack until an opening parenthesis '(' is encountered.
// If any operator (+, -, *, /) is encountered while popping, set isRedundant to false.
// If isRedundant remains true after popping all elements until the opening parenthesis, it indicates redundant brackets.
// Pop the opening parenthesis from the stack.
// If the current closing parenthesis was redundant, return 1 to indicate redundancy.
        else
        {
            //ch ya toh ')' hai or lowercase letter
            
            if(ch == ')') {
                bool isRedundant = true;
                
                while(st.top() != '(') {
                    char top = st.top();
                    if(top == '+' ||top == '-' || top == '*' || top == '/') {
                        isRedundant = false;
                    }
                    st.pop();
                }
                
                if(isRedundant == true)
                    return 1;
                st.pop();
            }
            
        } 
    }
    return 0;
    }
};
