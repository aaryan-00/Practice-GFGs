//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int recur(int ind,int curr,int price[],vector<vector<int>> &dp)
    {
        if(ind<0 || curr==0)
        {
            return 0;
        }
        if(dp[ind][curr]!=-1)
        {
            return dp[ind][curr];
        }
        //not taken;
        int ntkn=recur(ind-1,curr,price,dp);
        //tkn;
        int tkn=-1;
        if(ind+1<=curr)
        {
            tkn = price[ind]+recur(ind,curr-ind-1,price,dp);
        }
        return dp[ind][curr]=max(tkn,ntkn);
    }
    int cutRod(int price[], int n) {
        // for(int i=0;i<n;i++)
        // {
        //     cout<<price[i]<<" ";
        // }
        // return -6;
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return recur(n-1,n,price,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends