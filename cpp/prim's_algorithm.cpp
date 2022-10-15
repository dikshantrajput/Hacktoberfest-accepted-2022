#include<bits/stdc++.h>
using namespace std;


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        bool visited[V]={false};
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p;
        p.push({0,0});
        int ans=0;
        while(p.empty()!=true){
            
            int u=p.top().second;
            int plus=p.top().first;

            p.pop();
            if(visited[u]==true){
                continue;
            }
            ans+=plus;
            for(vector<int> x:adj[u]){
                if(visited[x[0]]==false){
                    p.push({x[1],x[0]});
                }
            }
            visited[u]=true;
            
        }
        return ans;
    }
};




int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


