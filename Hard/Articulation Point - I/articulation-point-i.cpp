//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<bool> vis,markArti;
    int timer=0;
    void dfs(int node,int par,vector<int>&timeIn,vector<int>&timeLow,vector<int> adj[])
    {
        vis[node]=true;
        timeIn[node]=timeLow[node]=timer;
        timer++;
        int child=0;
        for(auto it:adj[node])
        {
            if(it==par) continue;
            if(vis[it]==false)
            {
                dfs(it,node,timeIn,timeLow,adj);
                timeLow[node]=min(timeLow[node],timeLow[it]);
                if(timeLow[it]>=timeIn[node] && par!=-1)
                {
                    markArti[node]=true;
                }
                child++;
            }
            else
            {
                timeLow[node]=min(timeLow[node],timeIn[it]);
            }
        }
        if(child >1  && par==-1)
        {
            markArti[node]=true;
        }
    }
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        vector<int> timeIn(n),timeLow(n);
        vis.resize(n,false);
        markArti.resize(n,false);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==false)
            {
                dfs(0,-1,timeIn,timeLow,adj);
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(markArti[i])
            {
                ans.push_back(i);
            }
        }
        if(ans.size()==0) return {-1};
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends