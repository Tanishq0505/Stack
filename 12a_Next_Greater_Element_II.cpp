//  503. Next Greater Element II Leetcode
// https://leetcode.com/problems/next-greater-element-ii/
// https://youtu.be/Du881K7Jtk8
// see video to understand

class Solution {
public:
// https://youtu.be/Du881K7Jtk8
// see video to understand
    vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans;
    stack<int> st;
// Iterate through the elements of nums in reverse order, 
// considering each element twice (due to circular property).
    for (int i = 2 * n - 1; i >= 0; i--)
    {
// While the stack st is not empty and the top element of the stack is 
// less than or equal to the current element of nums, pop elements from 
// the stack.
        while (!st.empty() and st.top() <= nums[(i % n)])
        {
            st.pop();
        }
// If the current index i is less than n, it means we are processing elements from the original nums vector.

// If the stack st is empty, push -1 to ans (indicating that there is no 
// greater element).
// Otherwise, push the top element of the stack (which is the next greater
//  element) to ans.
        if (i < n)
        {
            if (st.empty())
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(st.top());
            }
        }
// Push the current element of nums (indexed by i % n) onto the stack.

        st.push(nums[i % n]);
    }
//  Reverse the ans vector since we inserted elements from the end
//  (due to the circular property) but we want the result in the original order of nums.


    reverse(ans.begin(), ans.end());
    return ans;
}
};
