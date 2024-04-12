// Number of NGEs to the right (gfg)
class Solution{
public:
// see code and do dry run to understand 
    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        //write your code here
        vector<int>ans;
    stack<int>st;
    for(int i=0;i<queries;i++){
        int count=0;                    //intialise the count to 0 for every iteration
        st.push(arr[indices[i]]);         //push all the query elements


        for(int j=indices[i]+1;j<n;j++){
            if(arr[j]>st.top()){    //if current element is greater than the top element of the stack
                count++;            //update the count
            }
        }
        ans.push_back(count);       //store the count in the ans variable
    }
    return ans;
    }

};
