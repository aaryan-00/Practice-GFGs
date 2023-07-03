//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to insert heap.
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
    void insertHeap(int &x)
    {
        if(maxheap.empty() || x<maxheap.top()) maxheap.push(x);
        else minheap.push(x);
        if(maxheap.size()>minheap.size()+1)
        {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if(maxheap.size()+1<minheap.size())
        {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        // if(maxheap.size()>minheap.size()+1)
        // {
        //     minheap.push(maxheap.top());
        //     maxheap.pop();
        // }
        // else if(maxheap.size()+1<minheap.size())
        // {
        //     maxheap.push(minheap.top());
        //     minheap.pop();
        // }
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(minheap.size()==maxheap.size())
        {
            if(minheap.size()==0) return 0;
            else return (maxheap.top()+minheap.top())/2.0;
        }
        else if(minheap.size()>maxheap.size()) return minheap.top();
        else return maxheap.top();
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends