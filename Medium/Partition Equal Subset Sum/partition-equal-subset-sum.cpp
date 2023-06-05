//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool recur(int i, int arr[],int sum,vector<vector<int>> &dp)
    {
        if(sum==0)
        {
            return true;
        }
        if(i==0)
        {
            return arr[0]==sum;
        }
        if(dp[i][sum]!=-1)
        {
            return dp[i][sum];
        }
        //taken
        bool tkn=recur(i-1,arr,sum-arr[i],dp);
        //not taken
        bool ntkn=recur(i-1,arr,sum,dp);
        return dp[i][sum] = tkn||ntkn;
    }
    int equalPartition(int n, int arr[])
    {
        int sum=0;
        for(int i=0;i<n;i++ )
        {
            sum+=arr[i];
        }
        if(sum&1) return false;
        sum=sum/2;
        // int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return recur(n-1,arr,sum,dp);
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
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends