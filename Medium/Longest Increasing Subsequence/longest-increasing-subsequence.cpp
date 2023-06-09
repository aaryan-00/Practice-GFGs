//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int len;
    int recur(int nums[],int i,int prev,vector<int> &dp)
    {
        if(i==len)
        {
            return 0;
        }
        if(dp[prev+1]!=-1)
        {
            return dp[prev+1];
        }
        int tkn=0;
        if(prev==-1 || nums[i]>nums[prev])
        {
            tkn = 1+recur(nums,i+1,i,dp);
        }
        int ntkn=recur(nums,i+1,prev,dp);
        return dp[prev+1]=max(tkn,ntkn);
    }
    int longestSubsequence(int n, int arr[])
    {
        // len=n;
        // vector<int> dp(n+1,-1);
        // return recur(arr,0,-1,dp);
        
        //tabulation
        // vector<int> dp(n+1,0);
        // for(int i=n-1;i>=0;i--)
        // {
        //     for(int prev=i-1;prev>=-1;prev--)
        //     {
        //         int tkn=0;
        //         if(prev==-1 || arr[i]>arr[prev])
        //         {
        //             tkn = 1+dp[i+1];
        //         }
        //         int ntkn=dp[prev+1];
        //         dp[prev+1]=max(tkn,ntkn);
        //     }
        // }
        // return dp[0];
        
        // vector<int> dp(n,1);
        // for(int i=0; i<=n-1; i++){
        //     for(int prev_index = 0; prev_index <=i-1; prev_index ++){
                
        //         if(arr[prev_index]<arr[i] && 1+dp[prev_index]>dp[i]){
        //             dp[i] =1 + dp[prev_index];
        //         }
        //     }
        // }
        // int ans = -1;
        // for(int i=0; i<=n-1; i++){
        //     ans = max(ans, dp[i]);
        // }
        
        // return ans;
        vector<int> temp;
        temp.push_back(arr[0]);
        for(int i=1;i<n;i++)
        {
            if(temp.back()<arr[i])
            {
                temp.push_back(arr[i]);
            }
            else
            {
                int ind=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
                temp[ind]=arr[i];
            }
        }
        return temp.size();
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends