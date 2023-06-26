//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        vector<int> dist(1e5,1e9);
        queue<int> q;
        q.push(start);
        dist[start]=0;
       
       while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(int i=0;i<arr.size();i++)
            {
                int new_node=(node*arr[i])%(100000);
                if(dist[node]+1<dist[new_node])
                {
                   dist[new_node]=dist[node]+1; 
                   q.push(new_node);
                }
            }
        }
        if(dist[end]==1e9) return -1;
        return dist[end];
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends