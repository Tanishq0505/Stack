// Evaluation of Postfix Expression
   // see code and do dry run to understand 

class Solution
{
    // see code and do dry run to understand 
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int> st;
        for(int i=0;i<S.length();i++)
        {
            if(S[i]=='+'|| S[i]=='-'|| S[i]=='*'|| S[i]=='/')
            {
             

// Pop the top two elements from the stack as operands.
// Perform the operation based on the current operator.
// Push the result back onto the stack.
                int p=st.top();
                st.pop();
                int q=st.top();
                st.pop();
                int res;
                if(S[i]=='+')
                res=q+p;
                else if(S[i]=='-')
                res=q-p;
                else if(S[i]=='*')
                res=q*p;
                else res=q/p;
                st.push(res);
            
            }
// Convert the character representing the operand to an integer by subtracting the ASCII value of '0'.
// Push the integer value onto the stack.
            else{
                st.push(S[i]-'0');
            } 
        
        }
            return st.top();
    }
};
