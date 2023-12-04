#include<bits/stdc++.h>
using namespace std;

void markisland(vector<vector<int>> v,int i,int j,int n,int m,vector<vector<int>> &visited){
    if(i>=n ||j>=m||i<0||j<0||visited[i][j]==true||v[i][j]==1){
        return;
    }
    visited[i][j]=1;
    markisland(v,i-1,j,n,m,visited);
    markisland(v,i,j+1,n,m,visited);
    markisland(v,i+1,j,n,m,visited);
    markisland(v,i,j-1,n,m,visited);
}
int find_no_of_islands(vector<vector<int>> v,int n,int m){
    vector<vector<int>> visited(n,vector<int> (m,0));
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j]==false and v[i][j]==0){
                count++;
                markisland(v,i,j,n,m,visited);
            }
        }
    }
    return count;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n,vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        cin>>v[i][j];
    }
    cout<<find_no_of_islands(v,n,m)<<endl;
    return 0;
}