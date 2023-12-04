#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

class x{
public:
  int v;
  int time;
  x(int vt,int timet){
    v=vt;
    time=timet;
  }
};
int count_infected(vector<int> adj[],int src,int t,int V){
    vector<int> visited(V,0);
    queue<x> q;
    q.push(x(src,1));
    int count=0;
    while(!q.empty()){
        x temp=q.front();
        q.pop();
        if(visited[temp.v]>0){
            continue;
        }
        visited[temp.v]=temp.time;
        if(temp.time>t){
            break;
        }else{
            count++;
        }

        for(auto node: adj[temp.v]){
            if(visited[node]==0){
                q.push(x(node,temp.time+1));
            }
        }
    }
    return count;
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
    int src,t;
    cin>>src>>t;

    cout<<count_infected(adj,src,t,V)<<endl;
}