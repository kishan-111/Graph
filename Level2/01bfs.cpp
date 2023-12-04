//find the minimu flip required to find out path from 0 to end

#include<bits/stdc++.h>
using namespace std;
//Hint: 1.) join given edge with 0 wgt and join opposite edge with 1 wgt
//2.) use linked list in place of queue as only two weight is possible
//3.) 1- based indexing
int main(){
    int V,E;
    cin>>V>>E;

    vector<pair<int,int>> adj[V];
    for(int i=1;i<=E;i++){ //1 base indexing of graph
        int u,v;
        cin>>u>>v;
        adj[u].push_back(make_pair(v,0));
        adj[v].push_back(make_pair(u,1));
    }

    list<pair<int,int>> q;
    vector<int> vis(V,0);
    q.push_back(make_pair(0,0));

    while(!q.empty()){
       pair<int,int> rem=q.front();
       q.pop_front();
       if(rem.first==V-1){
           cout<<rem.second<<endl;
           return 0;
       }
       vis[rem.first]=1;
      
      for(auto x: adj[rem.first]){
         if(vis[x.first]==1){
            continue;
         }
         if(x.second==0){
            q.push_front(make_pair(x.first,x.second+0));
         }else{
            q.push_back(make_pair(x.first,x.second+1));
         }
      }
    }
    cout<<"-1"<<endl;
}
