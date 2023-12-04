#include<bits/stdc++.h>
using namespace std;

int main(){
    int V,E;
    cin>>V>>E;

    vector<vector<int>> adj[V];
    for(int i=0;i<E;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    vector<int> vis(V,0);
    q.push({0,0});
    int sum=0;
    while(!q.empty()){
        pair<int,int> temp=q.top();
        q.pop();
        int x=temp.second;
        int wt=temp.first;

        if(vis[x]==1){
            continue;
        }
        vis[x]=1;
        sum+=wt;
        for(auto nbr: adj[x]){
            if(!vis[nbr[0]]){
                q.push({nbr[1],nbr[0]});
            }
        }
    }
    cout<<sum<<endl;
    
}