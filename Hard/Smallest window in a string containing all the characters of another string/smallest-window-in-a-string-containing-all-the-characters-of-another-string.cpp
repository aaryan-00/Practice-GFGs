//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string t)
    {
        vector<int> mp(128,0);
        for(auto i:t)
        {
            mp[i]++;
        }
        int cnt=t.size();
        int minPos=0,ans=INT_MAX,start=0;
        for(int end=0;end<s.size();end++)
        {
            if(mp[s[end]]>0) cnt--;
            mp[s[end]]--;
            while(cnt==0)
            {
                if(ans>end-start+1)
                {
                    ans=end-start+1;
                    minPos=start;
                }
                mp[s[start]]++;
                if(mp[s[start]]>0) cnt++;
                start++;
            }
        }
        if(ans!=INT_MAX) return s.substr(minPos,ans);
        return "-1";

    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends