// 496. Next Greater Element I (Leet code ) 
 
// https://youtu.be/CzBVZPDo1HI 
// see video to understand 

class Solution {
public:
// https://youtu.be/CzBVZPDo1HI
// see video to understand 
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>umap;
        stack<int>s;
        int n=nums2.size();
                // Iterate through nums2 from right to left
        for(int i=n-1;i>=0;i--){
           int ele=nums2[i];
 // Pop elements from the stack until it's empty or we find an element greater than the current element
           while(!s.empty()&&s.top()<=ele){
            s.pop();
           }
 // Store the next greater element in the result then in the  map
           int res=(s.empty())?-1:s.top();
           umap.insert({ele,res});
                     // Push the current element into the stack
           s.push(nums2[i]);


        }
        vector<int> ans;
// Iterate through nums1 to get the next greater element for each element
        for(auto x:nums1){
            ans.push_back(umap[x]);

        }
        return ans;
    }
};
