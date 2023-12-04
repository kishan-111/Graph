//Bellman ford
//updation in Vth iteration show negative weight cycle in graph

#include<bits/stdc++.h>
using namespace std;

int main(){
    int V,E;
    cin>>V>>E;
    vector<vector<int>> edges;
    for(int i=0;i<E;i++){
        int x,y,w;
        cin>>x>>y>>w;
        edges.push_back({x,y,w});
    }

    vector<int> path(V,INT_MAX);
    path[0]=0;

    for(int i=0;i<V-1;i++){
        for(int j=0;j<E;j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int w=edges[j][2];
            if(path[u]==INT_MAX){
                continue;
            }
            if(path[u]+w<path[v]){
                path[v]=path[u]+w;
            }
        }
    }

    int flag=0;
    for(int j=0;j<E;j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int w=edges[j][2];
            if(path[u]==INT_MAX){
                continue;
            }
            if(path[u]+w<path[v]){
               flag=1;
               break;
            }
    }
    cout<<flag<<endl;
}
 