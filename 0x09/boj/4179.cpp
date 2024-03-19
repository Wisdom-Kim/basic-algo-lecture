//
// Created by wisdom99 on 2024-01-15.
// 지훈이가 불보다 먼저 이동한다.
#include <iostream>
#include <queue>

#define Y first
#define X second

int dist1[1002][1002]; //불의 전파 시간
int dist2[1002][1002]; //지훈이의 이동 시간. 전역변수 초기화 귀찮아서

using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int r,c;
    cin>>r>>c;
    queue<pair<int,int>> ji;//지훈
    queue<pair<int,int>> fire;//불
    for(int i=0;i<r;i++){
        fill(dist1[i],dist1[i]+c,-1);
        fill(dist2[i],dist2[i]+c,-1);
    }
    char maze[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>maze[i][j];
            if(maze[i][j]=='J') {ji.push({i,j});dist2[i][j]=0;}
            else if(maze[i][j]=='F') {fire.push({i,j});dist1[i][j]=0;}
       }
    }
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};

    while(!fire.empty()){
        auto a=fire.front();
        fire.pop();
        for(int i=0;i<4;i++){
            int newY=a.Y+dy[i];
            int newX=a.X+dx[i];

            if(newY<0 || newY>=r||newX<0||newX>=c) continue;
            if(dist1[newY][newX]>=0 || maze[newY][newX]=='#') continue;
            dist1[newY][newX]=dist1[a.Y][a.X]+1;
            fire.push({newY,newX});
        }
    }

    while(!ji.empty()){
        auto a=ji.front();
        ji.pop();
        for(int i=0;i<4;i++){
            int newY=a.Y+dy[i];
            int newX=a.X+dx[i];
            if(newY<0 || newY>=r||newX<0||newX>=c) {
                //범위 밖 -> 탈출함
                cout<<dist2[a.Y][a.X]+1;
                return 0;
            }
            if(dist2[newY][newX]>=0 || maze[newY][newX]=='#') continue;
            if(dist1[newY][newX]!=-1 && dist1[newY][newX]<=dist2[a.Y][a.X]+1) continue;
            dist2[newY][newX]=dist2[a.Y][a.X]+1;
            ji.push({newY,newX});
        }
    }
    cout<<"IMPOSSIBLE";

}