//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int mod=1e9+7;
//   int mod=1000000007
  int f(vector<vector<int>>& grid,int i,int j,vector<vector<int>>&mat){
        if(i<0||j<0||grid[i][j]==1){
            return 0;
        }
      
        if(i==0 && j==0){
            if(grid[i][j]) return 0;
             else return 1;
        }
        if(mat[i][j]!=-1){
            return mat[i][j];
        }
        int a= f(grid,i-1,j,mat)%mod;
        int b= f (grid,i,j-1,mat)%mod;
        mat[i][j]=(a+b)%mod;
        return mat[i][j];
    }
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        // Code here
        vector<vector<int>>mat(n+1,vector<int>(m+1,-1));
        
        return f(grid,n-1,m-1,mat);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends