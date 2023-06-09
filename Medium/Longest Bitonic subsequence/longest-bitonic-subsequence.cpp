//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    int n=nums.size();
	    vector<int> front(n,1);
	    vector<int> back(n,1);
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<i;j++)
	        {
	            if(nums[j]<nums[i] && front[j]+1>front[i])
	            {
	                front[i]=front[j]+1;
	            }
	        }
	    }
	    for(int i=n-1;i>=0;i--)
	    {
	        for(int j=n-1;j>i;j--)
	        {
	            if(nums[j]<nums[i] && back[j]+1>back[i])
	            {
	                back[i]=back[j]+1;
	            }
	        }
	    }
	    vector<int> biotonic(n,0);
	    int ans=-1;
	    for(int i=0;i<n;i++)
	    {
	        biotonic[i]=front[i]+back[i]-1;
	        ans=max(ans,biotonic[i]);
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends