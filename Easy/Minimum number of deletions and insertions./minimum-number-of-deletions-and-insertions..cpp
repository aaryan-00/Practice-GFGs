//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int lcs(string &s, string &t,int i,int j,vector<vector<int>> &dp)
    {
        if(i<0 || j<0)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s[i]==t[j])
        {
            return dp[i][j]=1 + lcs(s,t,i-1,j-1,dp);
        }
        return dp[i][j]= max(lcs(s,t,i,j-1,dp),lcs(s,t,i-1,j,dp));

    }
	int minOperations(string s, string t) 
	{ 
	    int n=s.size(),m=t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int len=lcs(s,t,n-1,m-1,dp);
        //delete=n-len
        //insert=m-len
        return (n-len)+(m-len);
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends