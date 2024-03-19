//
// Created by wisdom99 on 2024-01-18.
//
//불의 거리+1 > 상근이의 거리
// Created by wisdom99 on 2024-01-17.
//
#include <iostream>
#include <queue>
#include <vector>

#define Y first
#define X second

using namespace std;

int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin>>n;
    int depth[n][n]; //입력받을 거
    int map[n][n];//탐색할 거
    for(int i=0;i<n;i++) {
        fill(map[i],map[i]+n,0);
        for(int j=0;j<n;j++) cin>>depth[i][j];
    }

    queue<pair<int,int>> q1; //탐색용 큐
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(depth[i][j])
            while(!q1.empty()){
                auto cur=q1.front();q1.pop();
                for(int i=0;i<4;i++){
                    int newY=cur.Y+dy[i];
                    int newX=cur.X+dx[i];
                    if(newY<0||newY>=h||newX<0||newX>=w) continue;
                    if(fire[newY][newX]=='#') continue;
                    if(dist1[newY][newX]!=-1) continue;//가본곳이면 패스
                    dist1[newY][newX]=dist1[cur.Y][cur.X]+1;
                    q1.push({newY,newX});
                }
            }
        }
    }
        //불의 위치별 시간 계산

        //상근이의 탈출 시간 계산
        while(!q2.empty()){
            auto cur=q2.front();q2.pop();
            for(int i=0;i<4;i++){
                int newY=cur.Y+dy[i];
                int newX=cur.X+dx[i];
                if(newY<0||newY>=h||newX<0||newX>=w) {
                    //탈출
                    possible=true;
                    cout<<dist2[cur.Y][cur.X]+1<<"\n";
                    break;
                }
                if(fire[newY][newX]=='#') continue;
                if(dist2[newY][newX]!=-1) continue;//가본곳이면 패스
                if(dist1[newY][newX]!=-1 && dist1[newY][newX]-1<=dist2[cur.Y][cur.X]) continue;//불난곳 패스
                dist2[newY][newX]=dist2[cur.Y][cur.X]+1;
                q2.push({newY,newX});
            }
            if(possible) break;
        }
        if(!possible) cout<<"IMPOSSIBLE\n";

}