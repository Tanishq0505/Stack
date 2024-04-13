// 22b) Infix to Postfix GFG  

// https://youtu.be/mg9yi6YuAVk 
// see video to understand 

class Solution {
  public:

// Define a function precidence to determine the precedence of operators.
// Higher precedence corresponds to higher return values.

int precidence(char sym)
{
    if(sym=='^')
    return 3;
    else if(sym=='*'||sym=='/')
    return 2;
    else if(sym=='+'||sym=='-')
    return 1;
    else
    return -1;
}
    string infixToPostfix(string infix) {
        stack<char> st;
        string res="";
   for(int i=0;i<infix.size();i++)
   {
    //   If the current character is an operand (a lowercase letter, uppercase letter, or digit), append it to the res string.
         if((infix[i]>='a'&&infix[i]<='z')||(infix[i]>='A'&&infix[i]<='Z')||(infix[i]>='0'&&infix[i]<='9'))
         res+=infix[i];
//   If the current character is a closing parenthesis ')', pop operators from the stack 
// and append them to the res string until an opening parenthesis '(' is encountered. Pop the
// opening parenthesis as well.
       
         else if(infix[i]=='(')
         st.push(infix[i]);
         
         else if(infix[i]==')')
         {
            while(st.size()>0&&st.top()!='(')
            {
                res+=st.top();
                st.pop();
                
            }
            if(st.top()=='(')
            st.pop();
         }
// If the current character is an operator (+, -, *, /), compare its precedence with the top operator on the stack.
// If the precedence of the current operator is less than or equal to the precedence of the top operator on the stack, pop the top operator from the stack and append it to the res string. Continue this process until the stack is empty or the top operator has lower precedence than the current operator.
// Finally, push the current operator onto the stack.         
         else
         {
            while(st.size()>0&&(precidence(st.top())>=precidence(infix[i])))
           { 
               res+=st.top();
           st.pop();
               
           }
           st.push(infix[i]);
         }
   }
//   After processing all characters of the infix expression, pop any remaining operators
// from the stack and append them to the res string.

     while(st.size()!=0)
     {
        res+=st.top();
        st.pop();
     }
     return res;
    }
};
