//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubstring(string s) {
        int ans=0;
        int n=s.size();
        int start=0;
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
            while(mp['a'] && mp['b'] && mp['c'])
            {
                ans+=n-i;
                mp[s[start]]--;
                start++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution obj;
        cout << obj.countSubstring(s) << endl;
    }
    return 0;
}
// } Driver Code Ends