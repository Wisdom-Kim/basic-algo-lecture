//
// Created by wisdom99 on 2024-01-11.
//
#include<iostream>

using namespace std;

const int MX = 1000001;
int dat[2*MX+1];
int head= MX;
int tail = MX;

void push_back(int x){
    dat[tail++]=x;
}
void push_front(int x){
    dat[--head]=x;}

void pop_back(){
    tail--;
}
void pop_front(){
    head++;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    bool isLeft;

    int n;
    cin>>n;

    int m;
    cin>>m;
    //덱에 1~N 넣기
    for(int i=1;i<=n;i++) push_back(i);
    int cnt=0; //2,3번 연산의 횟수

    //1번 연산 - q.pop_front();
    //2번 연산 - q.push_back(q.front()); q.pop_front();
    //3번 연산 - q.push_front(q.back()); q.pop_back();
    //pop_back()은 3번 연산 후 1번 연산 => cnt 1 증가 처리
    //걍 순서대로 앞뒤에 가까운 쪽으로 계속 옮기면 된다

    while(m--){
        isLeft=false;
        int center = head+(tail-head)/2 ; //중간점. 앞뒤 거리 측정
        int target;
        cin>>target;

        //앞뒤 중 가까운 쪽으로 이동하기
        for(int i=head;i<=center;i++){
            //왼쪽끝에서 중앙까지 탐색 => 원소 발견 시 2번 연산
            if(dat[i]==target){
                isLeft=true;
                break;
            }
        }

        if(isLeft){
            while(dat[head]!=target){
                cnt++; //2번 연산 증가
                push_back(dat[head]);
                pop_front();
            }
            pop_front();
        }
        else{
            while(dat[tail-1]!=target){
                cnt++; //3번 연산 증가
                push_front(dat[tail-1]);
                pop_back();
            }
            cnt++; //오른쪽 끝 원소 빼내는 것도 cnt증가시킴
            pop_back();
        }

    }
    cout<<cnt;
}