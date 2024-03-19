#include <iostream>
#include <queue>

#define Y first
#define X second

using namespace std;

int step[8][2]={{-2,-1},{-1,-2},{-2,1},{-1,2},{2,1},{1,2},{1,-2},{2,-1}};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;// 테케
    int l;//체크판 너비
    cin>>t;
    int x,y;//처음 위치
    int a,b;//목표
    while(t--){
        cin>>l;
        int dist[l][l];
        for(int i=0;i<l;i++){
            fill(dist[i],dist[i]+l,-1); //안가본 곳 -1로 초기화
        }

        cin>>y>>x;
        dist[y][x]=0;//나이트의 초기 위치 초기화
        queue<pair<int,int>> q;
        q.push({y,x});
        cin>>a>>b; //나이트의 목표 위치

        while(!q.empty()){
            auto c=q.front();q.pop();

            for(int i=0;i<8;i++){
                int newY=c.Y+step[i][1];
                int newX=c.X+step[i][0];

                if(newY<0||newY>=l||newX<0||newX>=l) continue;
                if(dist[newY][newX]!=-1) continue;//이미 방문한 곳이면 패스
                dist[newY][newX]=dist[c.Y][c.X]+1;

                q.push({newY,newX});
            }
        }
        cout<<dist[a][b]<<"\n";
    }

    return 0;
}
