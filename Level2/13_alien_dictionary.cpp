#include<bits/stdc++.h>
using namespace std;

string alienOrder(vector<string> word,int n){
   unordered_map<char,unordered_set<char>> map;
   unordered_map<char,int> degree;
   int flag=0;
   for(int i=0;i<n-1;i++){
     string s1=word[i];
     string s2=word[i+1];
     for(int j=0;j<min(s1.length(),s2.length());j++){
        if(s1[j]!=s2[j]){
                if(degree.find(s1[j])==degree.end()){
                  degree[s1[j]]=0;
                }
                degree[s2[j]]++;
                map[s1[j]].insert(s2[j]);
                flag=1;
                break;
        }
     }
     if(flag==0){
        return "";
     }
   }
   queue<char> q;
   string ans="";
   for(auto x:degree){
    cout<<x.first<<" : "<<x.second<<endl;
      if(x.second==0){
        q.push(x.first);
      }
   }

   int count=0;
   while(!q.empty()){
      char temp=q.front();
      q.pop();
      ans+=temp;
      count++;

      if(map.find(temp)!=map.end()){
         for(char x: map[temp]){
            degree[x]--;
            if(degree[x]==0){
                q.push(x);
            }
         }
      }
   }

   if(count==degree.size()){
    return ans;
   }else{
    return "";
   }

}
int main(){
    int n;
    cin>>n;
    vector<string> word(n);

   for(int i=0;i<n;i++){
    cin>>word[i];
   }
   
   cout<<alienOrder(word,n)<<endl;
   return 0;
}