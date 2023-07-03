//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &a, vector<int> &b) {
        sort(a.begin(),a.end(),greater<int>());
        sort(b.begin(),b.end(),greater<int>());
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<a.size();i++)
        {
            for(int j=0;j<b.size();j++)
            {
                int curr=a[i]+b[j];
                if(pq.empty())
                {
                    pq.push(curr);
                }
                else
                {
                    if(pq.top()>curr && pq.size()==K)
                    {
                        break;
                    }
                    pq.push(curr);
                    if(pq.size()>K)pq.pop();
                }
                
            }
            // cout<<pq.size()<<endl;
        }
        vector<int> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
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
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends