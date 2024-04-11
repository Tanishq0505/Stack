// 150. Evaluate Reverse Polish Notation (Leet code ) 
  // see code and do dry run to understand 
class Solution {
    // see code and do dry run to understand 
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        int ans=0, num;
       for( int i=0; i<tokens.size(); i++ ){
           string temp = tokens[i];
           if( temp == "+" || temp == "-" || temp == "*" || temp == "/" ){
// If the token is an operator:
// Pop the top two elements from the stack as operands (num2 and num1).
// Perform the corresponding arithmetic operation based on the operator.
// Push the result back onto the stack.
            int num2=s.top();
            s.pop();
            int num1=s.top();
            s.pop();
            if(temp=="+")
                ans=num1+num2;
                else if(temp=="-")
                ans=num1-num2;
                 else if( temp == "*" )
                    ans = num1 * num2;
                else if( temp == "/" )
                    ans = num1 / num2;
                
                s.push(ans);
           }else{
// If the current token is not an operator (i.e., it's an operand):
// Convert the string token to an integer using stoi.
// Push the integer onto the stack.

            // stoi convert string to integer
                num = stoi(tokens[i]);
                s.push(num);
           }
       } 
       return s.top();
              
            
    }
};
