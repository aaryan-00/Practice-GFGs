//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int memo(int i,int j,int arr[],vector<vector<int>> &dp)
    {
        if(i==j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int steps=INT_MAX;
        for(int k=i;k<=j-1;k++)
        {
            int curr=memo(i,k,arr,dp)+memo(k+1,j,arr,dp)+arr[i-1]*arr[k]*arr[j];
            steps=min(steps,curr);
        }
        return dp[i][j]=steps;
    }
    int matrixMultiplication(int n, int arr[])
    {
        vector<vector<int>> dp(n,vector<int>(n,-1));
        // return memo(1,n-1,arr,dp);
        
        //tabulation
        for(int i=0;i<n;i++)
        {
            dp[i][i]=0;
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                int steps=INT_MAX;
                for(int k=i;k<=j-1;k++)
                {
                    int curr=memo(i,k,arr,dp)+memo(k+1,j,arr,dp)+arr[i-1]*arr[k]*arr[j];
                    steps=min(steps,curr);
                }
                dp[i][j]=steps;
            }
        }
        return dp[1][n-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends