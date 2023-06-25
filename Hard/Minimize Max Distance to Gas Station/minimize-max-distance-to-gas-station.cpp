//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool isPossible(double mid,vector<int> &stations, int K)
    {
        int cnt=0;
        for(int i=1;i<stations.size();i++)
        {
            int diff=stations[i]-stations[i-1];
            cnt+=(int)diff/mid;
        }
        return cnt<=K;
    }
    double findSmallestMaxDist(vector<int> &stations, int K){
      double s=0,e=stations[stations.size()-1]-stations[0];
      double ans;
    //   while(s<=e)
    //   {
    //       double mid=(s+e)/2;
    //       if(isPossible(mid,stations,K))
    //       {
    //           ans=mid;
    //           e=mid-1e-6;
    //       }
    //       else
    //       {
    //           s=mid+1e-6;
    //       }
    //   }
    while(e-s>1e-6)
      {
          double mid=(s+e)/2;
          if(isPossible(mid,stations,K))
          {
              ans=mid;
              e=mid;
          }
          else
          {
              s=mid;
          }
      }
      return ans;
      
      
    }
};

//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> stations(n);
    for (int i = 0; i < n; i++)
    {
      cin >> stations[i];
    }
    int k;
    cin >> k;
    Solution obj;
    cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k) << endl;
  }
  return 0;
}
// } Driver Code Ends