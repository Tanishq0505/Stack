// 85 Max rectangle GFG & Leetcode  
// before solving this question see Largest Rectangle in Histogram
// https://youtu.be/9u2BJfmWNEg?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA
// lec 57 Q2  see from 25 min 43 sec 

class Solution {
private:

vector<int> nextsmallelement(vector<int>& arr , int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i = n-1; i>=0; i--)
    {
        int curr = arr[i];

        while(s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}

vector<int> prevsmallelement(vector<int>& arr , int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i = 0 ; i < n; i++)
    {
        int curr = arr[i];

        while(s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}

int MaxAreaHistogram(vector<int>& nums, int size)
{
    vector<int> next(size);
    next = nextsmallelement(nums,size);

    vector<int> prev(size);
    prev = prevsmallelement(nums,size);

    int maxanswer = INT_MIN;

    for(int i=0;i<size;i++)
    {
        if(next[i]==-1)
        {
            next[i] = size;
        }

        int width = next[i] - prev[i] - 1;

        int area = nums[i]*width;

        maxanswer = max(area,maxanswer);
    }

    return maxanswer;
}

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        if(matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int row = matrix.size();
        int col = matrix[0].size();

        vector<vector<int>> intMatrix(row, vector<int>(col, 0));

        // Convert char matrix to int matrix
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                intMatrix[i][j] = matrix[i][j] - '0';
            }
        }
        //compute area for first row
        int area = MaxAreaHistogram(intMatrix[0],col);

        for(int i=1;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
       //row udpate: by adding previous row's value            
                if(intMatrix[i][j] != 0)
                {
                    intMatrix[i][j] = intMatrix[i][j] + intMatrix[i-1][j];
                }
                else
                {
                    intMatrix[i][j] = 0;
                }
            }

           area = max(area,MaxAreaHistogram(intMatrix[i],col));
        }
        return area;
    }
};
