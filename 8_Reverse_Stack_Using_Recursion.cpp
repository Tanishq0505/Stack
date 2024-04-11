// Reverse a Stack
// gfg
// https://youtu.be/BmZnJehDzyU?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA
// 33 min 30 sec lec 55 Q5

class Solution{
public:
// https://youtu.be/BmZnJehDzyU?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA
// 33 min 30 sec lec 55 Q5
void insertAtBottom(stack<int> &s, int element) {
    //basecase
    if(s.empty()) {
        s.push(element);
      	return ;
    }
    
    int num = s.top();
    s.pop();
    
    //recursive call
    insertAtBottom(s, element);
    
    s.push(num);
}
    void Reverse(stack<int> &St){
         if(St.empty()) {
        return ;
    }
    
    int num = St.top();
    St.pop();
    
    //recursive call
    Reverse(St);
    
    insertAtBottom(St,num);
    }
};
