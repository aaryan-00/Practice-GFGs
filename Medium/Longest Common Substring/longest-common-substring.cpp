//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int maxi;
    int memo(string &s,string &t,int i, int j,vector<vector<int>> &dp)
    {
        if(i<0||j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(s[i]==t[j])
        {
            ans=1+memo(s,t,i-1,j-1,dp);
        }
        memo(s,t,i,j-1,dp);
        memo(s,t,i-1,j,dp);
        
        // maxi=max(maxi,ans);
        return dp[i][j]=ans;
        
    }
    int longestCommonSubstr (string s, string t, int n, int m)
    {
        vector<vector<int>> dp(n,vector<int>(m,-1));
        // maxi=-1;
        memo(s,t,n-1,m-1,dp);
        // return maxi;
        
        // or
        int ans=-1;
        for(auto x: dp){
            for(auto y : x){
              ans = max(ans,y);
            }
        }
        return ans;
        
        //tabulation
        // vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        // int maxi=0;
        // for(int i=1;i<=n;i++)
        // {
        //     for(int j=1;j<=m;j++)
        //     {
        //         if(s[i-1]==t[j-1])
        //         {
        //             dp[i][j]=1+dp[i-1][j-1];
        //             maxi=max(maxi,dp[i][j]);
        //         }
        //         // else
        //         // {
        //         //     dp[i][j]=0;
        //         // }
        //         //no need
        //     }
        // }
        // return maxi;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
