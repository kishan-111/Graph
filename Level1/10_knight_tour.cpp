#include<bits/stdc++.h>
using namespace std;

void paths(int r,int c,int n,vector<vector<int>> &chess,int move){
    if(r<0||c<0||r>=n||c>=n||chess[r][c]>0){
        return;
    }else if(move==n*n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            cout<<chess[i][j]<<" ";
            cout<<endl;
        }
    }
    chess[r][c]=move;
    paths(r-2,c+1,n,chess,move+1);
    paths(r-1,c+2,n,chess,move+1);
    paths(r+1,c+2,n,chess,move+1);
    paths(r+2,c+1,n,chess,move+1);
    paths(r+2,c-1,n,chess,move+1);
    paths(r+1,c-2,n,chess,move+1);
    paths(r-1,c-2,n,chess,move+1);
    paths(r-2,c-1,n,chess,move+1);
    chess[r][c]=0;
}
void knight_tour(int r,int c,int n,vector<vector<int>> chess){
    paths(r,c,n,chess,1);
    return ;
}
int main(){
    int n,r,c;
    cin>>n>>r>>c;

    vector<vector<int>> chess(n,vector<int> (n,0));
    knight_tour(r,c,n,chess);
}