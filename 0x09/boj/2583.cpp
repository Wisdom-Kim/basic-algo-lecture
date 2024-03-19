//
// Created by wisdom99 on 2024-01-17.
//
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector> //정렬하려고

#define Y first
#define X second

using namespace std;
int m,n,k;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>m>>n>>k;

    int map[m][n];
    int dist[m][n];
    for(int i=0;i<m;i++) {
        fill(map[i],map[i]+n,0);
        fill(dist[i],dist[i]+n,0);
    }

    //좌표처리: x좌표 n-x y좌표 m-y
    while(k--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        for(int i=y1;i<y2;i++){
            for(int j=x1;j<x2;j++) {
                map[i][j]=1;
            }
        }
    }

    vector<int> ans;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if (dist[i][j] == 1 || map[i][j] == 1) continue;
            queue <pair<int,int>> q;
            int cnt=1;
            q.push({i,j});
            dist[i][j]=1;//방문
            while(!q.empty()){
                auto cur=q.front();q.pop();
                for(int i=0;i<4;i++){
                    int nx=cur.X+dx[i];
                    int ny=cur.Y+dy[i];
                    if(nx<0||nx>=n||ny<0||ny>=m) continue;
                    if(dist[ny][nx]==1 ||map[ny][nx]==1) continue;
                    cnt++;
                    dist[ny][nx]=1;//방문처리
                    q.push({ny,nx});
                }
            }
            ans.push_back(cnt);



        }
    }

    sort(ans.begin(), ans.end());
    cout<<ans.size()<<"\n";
    for(auto c:ans) cout<<c<<" ";

}