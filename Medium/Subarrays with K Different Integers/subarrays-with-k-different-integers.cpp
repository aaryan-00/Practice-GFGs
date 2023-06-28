//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int find_Atmost_k_distinct(vector<int>& nums,int k,int n)
    {
        vector<int> hashh(n+1,0);
        int ans=0;
        int left=0;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            hashh[nums[i]]++;
            if(hashh[nums[i]]==1) cnt++;
            
            while(cnt>k)
            {
                hashh[nums[left]]--;
                if(hashh[nums[left]]==0)
                {
                    cnt--;
                }
                left++;
            }
            ans+=i-left+1;
        }
        return ans;
    }
    int subarrayCount(vector<int> &arr, int N, int k) {
        return find_Atmost_k_distinct(arr,k,N)-find_Atmost_k_distinct(arr,k-1,N);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.subarrayCount(arr, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends