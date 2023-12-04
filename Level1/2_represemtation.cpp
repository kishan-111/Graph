#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int,int>> adj[],int u,int v,int wt){
    adj[u].push_back(make_pair(v,wt));
    adj[v].push_back(make_pair(u,wt));
}

void print(vector<pair<int,int>> g[],int v){
    for(int i=0;i<v;i++){
        cout<<i<<endl;
        for(auto it=g[i].begin();it!=g[i].end();it++){
           cout<<it->first<<"->"<<it->second<<endl;
        }
        cout<<"\n====================="<<endl;
    }
}
int main(){
    int V=5;
    vector<pair<int,int>> adj[V];
    addEdge(adj,0,4,20);
    addEdge(adj,0,1,10);
    addEdge(adj,1,4,50);
    addEdge(adj,1,3,40);
    addEdge(adj,1,2,30);
    addEdge(adj,3,4,70);
    addEdge(adj,2,3,60);
    
    print(adj,V);
}
