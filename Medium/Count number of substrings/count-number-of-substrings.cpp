//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long find_Atmost_k_distinct(string &s,int k)
    {
        long long ans=0;
        int left=0;
        int cnt=0;
        vector<int> mp(26,0);
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]-'a']++;
            if(mp[s[i]-'a']==1) cnt++;
            while(cnt>k)
            {
                mp[s[left]-'a']--;
                
                if(mp[s[left]-'a']==0)
                {
                    cnt--;
                }
                left++;
            }
            ans+=i-left+1;
        }
        return ans;
    }
    long long int substrCount (string s, int k) {
    	return find_Atmost_k_distinct(s,k)-find_Atmost_k_distinct(s,k-1);
    	
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends