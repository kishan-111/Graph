#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printpaths(vector<int> adj[],int src,int des,vector<bool> visited,string path){
    if(src==des){
        cout<<path<<endl;
        return;
    }
    visited[src]=true;
    for(auto node: adj[src]){
        if(visited[node]==false){
        printpaths(adj,node,des,visited,path+"->"+to_string(node));
        }
    }
   visited[src]=false;
}
int main(){
    int V,E;
    cin>>V>>E;
    vector<int> adj[V];
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        addEdge(adj,u,v);
    }

    int start,end;
    cin>>start>>end;
    
    vector<bool> visited(V,false);
    // first check if path exist by using haspath function in previous ques
    printpaths(adj,start,end,visited,to_string(start));
}
