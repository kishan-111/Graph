#include<bits/stdc++.h>
using namespace std;

int main(){
    int V,E;
    cin>>V>>E;
    vector<pair<int,int>> adj[V];
    for(int i=0;i<V;i++){
        int temp;
        cin>>temp;
        adj[0].push_back(make_pair(temp,i+1));
        adj[i+1].push_back(make_pair(temp,0));
    }
    for(int i=0;i<E;i++){
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back(make_pair(w,y));
        adj[y].push_back(make_pair(w,x));
    }
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> vis(V+1,0);
    pq.push(make_pair(0,0));
    int ans=0;
    while(!pq.empty()){
        pair<int,int> temp=pq.top();
        pq.pop();
        if(vis[temp.second]){
            continue;
        }
        vis[temp.second]=1;
        ans+=temp.first;
        for(auto x: adj[temp.second]){
            if(!vis[x.second]){
                pq.push(make_pair(x.first,x.second));
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}