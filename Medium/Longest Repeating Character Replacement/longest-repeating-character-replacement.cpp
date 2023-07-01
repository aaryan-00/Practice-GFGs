//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int characterReplacement(string s, int k) {
        vector<int> mp(26,0);
        int start=0,maxFreq=0,ans=0;
        for(int i=0;i<s.size();i++)
        {
            int curr=s[i]-'A';
            mp[curr]++;
            maxFreq=max(maxFreq,mp[curr]);
            while(i-start+1 - maxFreq>k)
            {
                mp[s[start]-'A']--;
                start++;
                maxFreq=0;
                for(int i=0;i<26;i++)
                {
                    maxFreq=max(maxFreq,mp[i]);
                }
            }
            ans=max(ans,i-start+1);

        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;

        Solution obj;
        cout << obj.characterReplacement(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends