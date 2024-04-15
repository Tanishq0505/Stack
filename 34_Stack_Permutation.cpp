// Stack Permutations GFG
// https://youtu.be/q4CbTMLogyk
// see video to understand

class Solution{
public:
// https://youtu.be/q4CbTMLogyk
// see video to understand 
    int isStackPermutation(int N,vector<int> &A,vector<int> &B){
    
        stack<int> s;
    int j = 0;
    
    for (int i = 0; i < N; i++) {
        s.push(A[i]);
        while (!s.empty() && s.top() == B[j]) {
            s.pop();
            j++;
        }
    }
    
    if (s.empty()) { 
        return true;
    }
    return false;
    
    }
};
