//불의 거리+1 > 상근이의 거리
// Created by wisdom99 on 2024-01-17.
//
#include <iostream>
#include <queue>
#define Y first
#define X second

using namespace std;

string fire[1002];
int dist1[1002][1002]; //불의 시간 기록
int dist2[1002][1002]; // 상근이의 시간 기록

int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};

int t,w,h;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        cin>>w>>h;
        bool possible=false;

        queue<pair<int,int>> q1; //불 큐
        queue<pair<int,int>> q2; //상근이 큐

        for(int i=0;i<h;i++) {
            fill(dist1[i],dist1[i]+w,-1);
            fill(dist2[i],dist2[i]+w,-1);
            cin>>fire[i];
            for(int j=0;j<w;j++){
                if(fire[i][j]=='@') {
                    q2.push({i,j});
                    dist2[i][j]=0;
                } //상근이 초기 위치
                else if(fire[i][j]=='*') {
                    q1.push({i,j});
                    dist1[i][j]=0;
                }
            }
        }
            //불의 위치별 시간 계산
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


}