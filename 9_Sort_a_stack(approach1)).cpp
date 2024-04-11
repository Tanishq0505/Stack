// Sort a stack gfg

// see code and do dry run to understand 
void SortedStack :: sort()
{
    vector<int> arr;
    
    // Move elements from stack to vector
    while (!s.empty()) {
        arr.push_back(s.top());
        s.pop();
    }
    
    // Sort the vector
    std::sort(arr.begin(), arr.end());
    
    // Push elements from vector back to stack
    for (int i = 0; i < arr.size(); i++) {
        s.push(arr[i]);
    }
    
   
   
}
