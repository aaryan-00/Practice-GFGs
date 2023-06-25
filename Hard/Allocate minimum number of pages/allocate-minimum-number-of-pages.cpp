//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isPossible(int a[], int n,int m,int mid)
    {
        int cnt=0;
        long temp=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]>mid) return false;
            temp+=a[i];
            if(temp>mid)
            {
                cnt++;
                temp=a[i];
            }
        }
        if(temp>0) cnt++;
        // cout<<cnt<<endl;
        
        return cnt<=m;
        
    }
    int findPages(int a[], int n, int m) 
    {
        // sort(a,a+n);
        if(m>n) return -1;
        long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
        }
        // cout<<sum<<endl;
        int s=1,e=sum;
        int ans=-1;
        while(s<=e)
        {
            int mid=s+e>>1;
            // cout<<mid<<" ";
            if(isPossible(a,n,m,mid))
            {
                ans=mid;
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends