//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int recur(int i,int nums[],vector<int> &dp)
    {
        if(i<0) return 0;
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        return dp[i]=max(nums[i]+recur(i-2,nums,dp),recur(i-1,nums,dp));
    }
    int FindMaxSum(int arr[], int n)
    {
        vector<int> dp(n,-1);
        return recur(n-1,arr,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends