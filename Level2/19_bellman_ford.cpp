//work for negative weight as well
//shortest path from source to rest vertices  
//doesn't work for negative weight cycle
//shortest path can't be defined for negative cycle 
//V-1 iteration with relaxation of each V
//ith iteration -> shotest path of length less than or equal to i
#include<bits/stdc++.h>
using namespace std;

int main(){
    int V,E;
    cin>>V>>E;
    vector<vector<int>> edges;
    for(int i=0;i<E;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
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

    for(int i=0;i<V;i++){
        cout<<path[i]<<endl;
    }

}