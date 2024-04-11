// Insert an Element at the Bottom of a Stack
// gfg
class Solution{
public:

// https://youtu.be/BmZnJehDzyU?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA
// see from 27 min  Q4 
void solve(stack<int>& s, int x) {
    //base case
    if(s.empty()) {
        s.push(x);
        return ;
    }
    
    int num = s.top();
    s.pop();
    
    //recursive call
    solve(s, x);
    
    s.push(num);
}
    stack<int> insertAtBottom(stack<int> st,int x){
        
         solve(st, x);
    return st;
    }
};
