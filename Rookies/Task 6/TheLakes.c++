#include <bits/stdc++.h>
#define ll long long
const int N=1e3+5;
int n ,m ,ans ; bool  vis[N][N];
int depth[N][N];
using namespace std;
bool IsValid(int x , int y ){
    return (x>=0 && x<n && y>=0 && y<m &&!vis[x][y] && depth[x][y] > 0) ;
}

void dfs(int x , int y){
    vis[x][y]=true;
    ans+=depth[x][y];
    if(IsValid(x+1,y)){    dfs(x+1,y); }   
    if(IsValid(x-1,y)){    dfs(x-1,y); }
    if(IsValid(x,y+1)){    dfs(x,y+1) ; }
    if(IsValid(x,y-1)){    dfs(x,y-1) ;  }

}
int main()
{
    ios:: sync_with_stdio(false);
    cin.tie(nullptr);
   int t;
   cin>>t;
   while(t--){
   cin>>n>>m;
   for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
     cin>>depth[i][j];
     vis[i][j]=false;
    }
   }
    ans=0;
    int maxvolume=0;
   for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
        if(depth[i][j] > 0 && !vis[i][j]){
            ans=0;
             dfs(i,j);
        if(ans>maxvolume)
          maxvolume=ans;
     }
    }
    }
   
   cout<<maxvolume<<endl;
   }
  

    return 0;
}