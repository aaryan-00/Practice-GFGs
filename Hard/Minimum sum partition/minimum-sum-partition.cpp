//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
    bool recur(int i, int arr[],int sum,vector<vector<int>> &dp)
    {
        if(sum==0)
        {
            return dp[i][sum]=true;
        }
        if(i==0)
        {
            return dp[i][sum]=arr[0]==sum;
        }
        if(dp[i][sum]!=-1)
        {
            return dp[i][sum];
        }
        //taken
        bool tkn=false;
        if(arr[i]<=sum)
        {   
            tkn=recur(i-1,arr,sum-arr[i],dp);
        }
        //not taken
        bool ntkn=recur(i-1,arr,sum,dp);
        return dp[i][sum] = tkn||ntkn;
    }
	int minDifference(int arr[], int n)  { 
	    int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
        }
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        for(int i=0;i<=sum;i++)
        {
            bool dummy=recur(n-1,arr,i,dp);
        }
        
        int ans=1e9;
        for(int i=0;i<=sum;i++)
        {
            if(dp[n-1][i])
            {
                ans=min(ans,abs(sum-2*i));
            }
        }
        return ans;
        
        
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends