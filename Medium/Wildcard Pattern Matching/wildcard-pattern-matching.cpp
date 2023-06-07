//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    bool memo(string &s,string &p,int i,int j,vector<vector<int>> &dp)
    {
        if(i<0 && j<0)
        {
            return true;
        }
        if(i>=0 && j<0)
        {
            return false;
        }
        if(i<0 && j>=0)
        {
            for(int k=j;k>=0;k--)
            {
                if(p[k]!='*')
                {
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        //if equal
        if(s[i]==p[j])
        {
            return dp[i][j]=memo(s,p,i-1,j-1,dp);
        }
        //if ?
        if(p[j]=='?')
        {
            return dp[i][j]=memo(s,p,i-1,j-1,dp);
        }
        //if *
        else if(p[j]=='*')
        {
            bool zeroo=memo(s,p,i,j-1,dp);
            bool many=memo(s,p,i-1,j,dp);
            return dp[i][j]=zeroo||many;
        }
        else
        {
            return dp[i][j]=false;
        }
    }
    int wildCard(string pattern,string str)
    {
        int n=str.size(),m=pattern.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return memo(str,pattern,n-1,m-1,dp);
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends