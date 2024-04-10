// 20. Valid Parentheses.(Leet code ) 
// https://leetcode.com/problems/valid-parentheses/description/

class Solution {
public:
// https://youtu.be/BmZnJehDzyU?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA
// see from 17 min lec 55
bool isValid(string s)
{
  	 stack<char> st;
    //  The code uses a for loop to iterate over each character of the input string s. 
    // It starts from index 0 and iterates until the end of the string (s.length()).
     for(int i=0; i<s.length(); i++) {
         
         char ch = s[i];
         
// If the current character ch is an opening bracket ('(', '{', '['), it is pushed onto the stack st
         
         if(ch == '(' || ch == '{' || ch == '['){
             st.push(ch);
         }
         else
         {
       //for closing bracket
     //  If the current character ch is not an opening 
     //  bracket (i.e., it's a closing bracket), the code checks if the stack is not empty.
             if(!st.empty()) {

    //If the stack is not empty, it retrieves the top element of the stack (top) without removing it.
// It then checks whether the current closing bracket ch matches the corresponding opening bracket top.
// If there's a match (e.g., ch is ')' and top is '('), the top element is popped from the stack.
// If there's no match, it means that there's an invalid sequence of parentheses, so the function returns false immediately.
// If the stack is empty when encountering a closing bracket, it means there's no matching 
// opening bracket for the current closing bracket, so the function returns false
//  immediately.
                  char top = st.top();
                  if( (ch == ')' && top == '(') || 
                     ( ch == '}' && top == '{') || 
                     (ch == ']' && top == '[') ) {
                      st.pop();
                  }
                 else
                 {
                     return false;
                 }
             }
             else
             {
                 return false;
             } 
         }  
     }
//      After iterating through the entire string, the code checks whether the stack is empty.
// If the stack is empty, it indicates that all opening brackets have been matched with their corresponding closing brackets, 
// so the function returns true, indicating valid parentheses.
// If the stack is not empty, it means there are unmatched opening brackets, so the function returns false, indicating invalid parentheses.
    
    if(st.empty())
        return true;
    else
        return false;
}
   
};
