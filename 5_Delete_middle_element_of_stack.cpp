// Delete middle element of a stack
// gfg

// https://youtu.be/BmZnJehDzyU?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA
// see from 7 min 30 sec 
class Solution
{
    public:
    //Function to delete middle element of a stack.
    void solve(stack<int>&s, int count, int sizeOfStack) {
    //base case
    if(count == sizeOfStack/2) {
        s.pop();
        return ;
    }
    
    int num = s.top();
    s.pop();
    
	//RECURSIVE CALL
    solve(s, count+1, sizeOfStack);
    
    s.push(num);
    
}
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
        	int count = 0;
    solve(s, count,sizeOfStack);
    }
};
