//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int recur(int ind,int w,int val[],int wt[],vector<vector<int>> &dp)
    {
        if(ind<0 || w==0)
        {
            return 0;
        }
        if(dp[ind][w]!=-1)
        {
            return dp[ind][w];
        }
        //not taken;
        int ntkn=recur(ind-1,w,val,wt,dp);
        //tkn;
        int tkn=0;
        if(wt[ind]<=w)
        {
            tkn= val[ind]+max(recur(ind-1,w-wt[ind],val,wt,dp),recur(ind,w-wt[ind],val,wt,dp));
        }
        return dp[ind][w]=max(tkn,ntkn);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N,vector<int>(W+1,-1));
        return recur(N-1,W,val,wt,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends