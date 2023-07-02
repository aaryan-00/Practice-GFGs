//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string minWindow(string s, string t) {
        // Write your Code here
        int i=0;
        int ans=INT_MAX;
        int minPos=0;
        
        while(i<s.size())
        {
            if(s[i]==t[0])
            {
                int s_iter=i;
                int t_iter=0;
                while(s_iter<s.size() && t_iter<t.size())
                {
                    if(s[s_iter]==t[t_iter])
                    {
                        s_iter++;
                        t_iter++;
                    }
                    else
                    {
                        s_iter++;
                    }
                }
                if(t_iter==t.size() && ans>s_iter-i)
                {
                    ans=s_iter-i;
                    minPos=i;
                }
            }
            i++;
        }
        if(ans!=INT_MAX) return s.substr(minPos,ans);
        return "";
        
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string str1, str2;
        cin >> str1 >> str2;

        Solution obj;
        cout << obj.minWindow(str1, str2) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends