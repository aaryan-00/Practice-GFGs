//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    #define ll long long
    typedef vector<int> vi;
    typedef vector<vi> vvi;
    int Memo(string &s,string &t,int i,int j,vvi &dp)
    {
        if(i==0||j==0)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s[i-1]==t[j-1])
        {
            return dp[i][j]= 1 + Memo(s,t,i-1,j-1,dp);
        }
        return dp[i][j]= max(Memo(s,t,i,j-1,dp),Memo(s,t,i-1,j,dp));

    }
    int lcs(int n, int m, string s, string t)
    {
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return Memo(s,t,n,m,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends