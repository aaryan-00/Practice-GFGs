//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> LargestSubset(int n, vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1);
        vector<int> hash(n);
        for(int i=1;i<n;i++)
        {
            hash[i]=i;
            for(int j=i-1;j>=0;j--)
            {
                if((nums[i]%nums[j]==0) && 1+dp[j]>dp[i])
                {
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }
        }
        int maxi=-1;
        int maxInd=-1;

        for(int i=0; i<=n-1; i++){
            if(dp[i]>maxi)
            {
                maxi=dp[i];
                maxInd=i;
            }
        }
        vector<int> ans;
        ans.push_back(nums[maxInd]);
        while(hash[maxInd]!=maxInd)
        {
            maxInd=hash[maxInd];
            ans.push_back(nums[maxInd]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        vector<int> res = obj.LargestSubset(n, arr);
        int isValidSeq = 1, sz = res.size();
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                if ((res[i] % res[j]) == 0 || (res[j] % res[i]) == 0)
                    continue;
                else {
                    isValidSeq = 0;
                    break;
                }
            }
        }
        cout << isValidSeq << " " << sz << endl;
    }
    return 0;
}
// } Driver Code Ends