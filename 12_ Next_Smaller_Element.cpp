 // Next Smaller Element (code studio)
// https://www.naukri.com/code360/problems/next-smaller-element_1112581

// https://youtu.be/lJLcqDsmYfg?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA
// see from starting Q1 (Approach 2) LEC 56

#include<stack>

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    
    for(int i=n-1; i>=0 ; i--) {
        int curr = arr[i];
        while(s.top() >= curr)
        {
            s.pop();
        }
        //ans is stack ka top
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}
