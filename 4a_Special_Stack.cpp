// Special Stack gfg
// see code and do dry run to understand

void push(stack<int>& s, int a){
// Your code goes here
s.push(a);
}
 
bool isFull(stack<int>& s,int n){
// Your code goes here
if(s.size()==n)
{
    return true;
}
return false;
}
 
bool isEmpty(stack<int>& s){
// Your code goes here
if(s.empty())
{
    return true;
}
return false;
}
 
int pop(stack<int>& s){
// Your code goes here
s.pop();
}

int getMin(stack<int>& s){
	// Your code goes here
	int mini=s.top();
	while(!s.empty())
	{
	    mini=min(mini,s.top());
	    s.pop();
	}
	return mini;
}
