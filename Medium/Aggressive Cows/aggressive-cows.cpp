//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool isPossible(vector<int> &stalls, int n,int k,int mid)
    {
        int cnt=1;
        int prev=stalls[0];
        for(int i=1;i<n;i++)
        {
            if(stalls[i]>=prev+mid)
            {
                cnt++;
                prev=stalls[i];
            }
        }
        // cout<<cnt<<endl;
        return cnt>=k;
        
    }

    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
    
        int s=1,e=1e9;
        int ans=0;
        while(s<=e)
        {
            int mid=s+e>>1;
            // cout<<mid<<" ";
            if(isPossible(stalls,n,k,mid))
            {
                ans=mid;
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends