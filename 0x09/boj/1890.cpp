//
// Created by wisdom99 on 2024-01-23.
//
#include <iostream>
#include <queue>

#define X second
#define Y first

using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,ny,nx;
    cin>>n;
    int maze[n][n];
    long long int dist[n][n];

    for(int i=0;i<n;i++){
        {
            fill(dist[i],dist[i]+n,0); //초기화
            for (int j = 0; j < n; j++) cin >> maze[i][j];
        }
    }

    queue<pair<int,int>> q;
    dist[0][0]=1;//방문처리
    q.push({0,0});
    while(!q.empty()){
        auto a=q.front(); q.pop();
        for(int i=0;i<2;i++){
            int jump = maze[a.Y][a.X];
            if(i==0){ //아래
                ny=a.Y+jump;
                nx=a.X;
            }
            else{//오른쪽
                ny=a.Y;
                nx=a.X+jump;
            }
            if(ny<0||ny>n||nx<0||nx>n) continue;
            dist[ny][nx]+=dist[a.Y][a.X];
            q.push({ny,nx});
        }
    }
    cout<<dist[n-1][n-1];



}