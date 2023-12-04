//minimum spaning tree
 #include<bits/stdc++.h>
 using namespace std;

struct node{
    int u;
    int v;
    int wt;
    node (int first,int second,int wgt){
        u=first;
        v=second;
        wt=wgt;
    }
};

bool cmp(node a,node b){
    return a.wt<b.wt;
}

int findpar(int u,vector<int> &parent){
    if(u==parent[u])
    return u;
    return parent[u]=findpar(parent[u],parent);
}
void union1(int u,int v,vector<int> &parent,vector<int> &rank){
    u=findpar(u,parent);
    v=findpar(v,parent);
    if(rank[u]<rank[v]){
        parent[u]=v;
    }else if(rank[v]<rank[u]){
        parent[v]=u;
    }else{
        parent[v]=u;
        rank[u]++;
    }

}
 int main(){
    int V,E;
    cin>>V>>E;
    vector<node> edges;
    for(int i=0;i<E;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back(node(u,v,w));
    }

    sort(edges.begin(),edges.end(),cmp);
    vector<int> parent(V);
    for(int i=0;i<V;i++)
    parent[i]=i;
    vector<int> rank(V,0);
    int cost=0;
    vector<pair<int,int>> mst;
    for(auto x: edges){
        if(findpar(x.v,parent)!=findpar(x.u,parent)){
            cost+=x.wt;
            mst.push_back({x.u,x.v});
            union1(x.u,x.v,parent,rank);
        }
    }
    cout<<cost<<endl;
    for(auto x: mst){
        cout<<x.first<<"   "<<x.second<<endl;
    }
    return 0;
 }