#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int,int>> adj[],int u,int v,int w){
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}

bool haspath(vector<pair<int,int>> adj[],int src,int des,vector<bool> visited){
    if(src==des){
       return true;
    }
    visited[src]=true;
    for(auto x: adj[src]){
       if(visited[x.first]==false){
         bool temp=haspath(adj,x.first,des,visited);
        if(temp){
            return temp;
        }
       }
    }
    return false;
}
int main(){
    int V,E;
    cin>>V>>E;

    vector<pair<int,int>> adj[V];
    for(int i=0;i<E;i++){
        int s,d,w;
        cin>>s>>d>>w;
        addEdge(adj,s,d,w);
    }
    int start,end;
    cin>>start>>end;
    vector<bool> visited(V,false);
    cout<<haspath(adj,start,end,visited)<<endl;;
}