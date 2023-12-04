#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int,int>> adj[],int u,int v,int wt){
    adj[u].push_back(make_pair(v,wt));
    adj[v].push_back(make_pair(u,wt));
}
//smallest path
int s_wt=INT_MAX;
string s_path="";
void smallest(vector<pair<int,int>> adj[],int src,int des,string psf,int wt,vector<bool> visited){
   if(src==des and wt<s_wt){
     s_wt=wt;
     s_path=psf;
     return;
   }
   visited[src]=true;
   for(auto node:adj[src] ){
    if(visited[node.first]==false){
        smallest(adj,node.first,des,psf+to_string(node.first),wt+node.second,visited);
    }
   }
   visited[src]=false;
}
//largest path

int l_wt=INT_MIN;
string l_path="";
void largest(vector<pair<int,int>> adj[],int src,int des,string psf,int wt,vector<bool> visited){
    if(src==des and wt>l_wt){
        l_wt=wt;
        l_path=psf;
        return;
    }
    visited[src]=true;
    for(auto node: adj[src]){
        if(visited[node.first]==false){
          largest(adj,node.first,des,psf+to_string(node.first),wt+node.second,visited);
        }
    }
    visited[src]=false;
}
//kth largest
//floor 
int f_wt=INT_MAX;
string f_path="";

void floor(vector<pair<int,int>> adj[],int src,int des,string psf,int wt,int criteria,vector<bool> visited){
    if(src==des){
        if(wt<f_wt and wt>criteria){
            f_wt=wt;
            f_path=psf;
            return;
        }
    }
    visited[src]=true;
    for(auto node: adj[src]){
        if(visited[node.first]==false){
            floor(adj,node.first,des,psf+to_string(node.first),wt+node.second,criteria,visited);
        }
    }
    visited[src]=false;
}
//ceil
string c_path="";
int c_wt=INT_MIN;
void ceil(vector<pair<int,int>> adj[],int src,int des,string psf,int wt,int criteria,vector<bool> visited){
    if(src==des){
        if(wt>c_wt and wt<criteria){
            c_wt=wt;
            c_path=psf;
            return;
        }
    }
    visited[src]=true;
    for(auto node: adj[src]){
        if(visited[node.first]==false){
            floor(adj,node.first,des,psf+to_string(node.first),wt+node.second,criteria,visited);
        }
    }
    visited[src]=false;
}
int main(){
    int V,E;
    cin>>V>>E;
    vector<pair<int,int>> adj[V];
    for(int i=0;i<E;i++){
        int u,v,w;
        cin>>u>>v>>w;
        addEdge(adj,u,v,w);
    }
    vector<bool> visited(V,false);
    smallest(adj,0,6,"0",0,visited);
    cout<<s_path<<"------->"<<s_wt<<endl;
    for(int i=0;i<V;i++){
        visited[i]=false;
    }
    largest(adj,0,6,"0",0,visited);
    cout<<l_path<<"------->"<<l_wt<<endl;
    for(int i=0;i<V;i++){
        visited[i]=false;
    }
    floor(adj,0,6,"0",0,30,visited);
    cout<<f_path<<"------->"<<f_wt<<endl;
    for(int i=0;i<V;i++){
        visited[i]=false;
    }
    ceil(adj,0,6,"0",0,30,visited);
    cout<<c_path<<"------->"<<c_wt<<endl;
}