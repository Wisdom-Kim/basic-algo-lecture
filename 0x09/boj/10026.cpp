//
// Created by wisdom99 on 2024-01-17.
//
#include<iostream>
#include <queue>
#define Y first
#define X second

using namespace std;

int n,cnt1=0,cnt2=0;
int dist1[101][101]; //비적록색약
int dist2[101][101]; //적록색약
string maze[101]; //그림

int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        fill(dist1[i],dist1[i]+n,-1);
        fill(dist2[i],dist2[i]+n,-1);
        cin>>maze[i];
    }
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(dist1[i][j]==-1){
                //방문 안한 곳일때만
            q.push({i,j});
            while (!q.empty()) {
                auto cur = q.front();q.pop();

                for (int k = 0; k < 4; k++) {
                    int newX = cur.X + dx[k];
                    int newY = cur.Y + dy[k];
                    if (newX < 0 || newX >= n || newY < 0 || newY >= n) continue; //범위 밖
                    if (maze[newY][newX] != maze[cur.Y][cur.X]) continue;//글자 다름
                    if (dist1[newY][newX] != -1) continue; //방문한 곳 제외
                    dist1[newY][newX] = 1;//방문처리
                    q.push({newY, newX});
                }
            }
            cnt1++;}

            if(dist2[i][j]==-1){
                //방문 안한 곳일때만
                q.push({i,j});
                while (!q.empty()) {
                    auto cur = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int newX = cur.X + dx[k];
                        int newY = cur.Y + dy[k];
                        if (newX < 0 || newX >= n || newY < 0 || newY >= n) continue; //범위 밖
                        if (maze[newY][newX]=='B'&&maze[newY][newX] != maze[cur.Y][cur.X]) continue;//글자 다름
                        if (maze[cur.Y][cur.X]=='B'&&maze[newY][newX] != maze[cur.Y][cur.X]) continue;//글자 다름
                        if (dist2[newY][newX] != -1) continue; //방문한 곳 제외
                        dist2[newY][newX] = 1;//방문처리
                        q.push({newY, newX});
                    }
                }
                cnt2++;}
        }

    }
    cout<<cnt1<<" "<<cnt2;


}