//
// Created by wisdom99 on 2024-01-11.
//3:35
#include <iostream>

using namespace std;

const int MX=100000;
int dat[2*MX+1];
int head;
int tail;
bool isReversed;
bool isError;

void push_front(int x){
    dat[--head]=x;
}
void parse(string list, int n){
    int temp=0;
    int ten=1;//자릿 수
    for(int i=list.length()-2;i>=0;i--){
        if(list[i]==',' || list[i]=='[') {
            //[]인 상황이라면 dat를 빈 배열로 둔다
            if(list[i+1]!=']')push_front(temp);
            temp=0;
            ten=1;
        }
        else {
            temp+=((list[i]-'0')*ten);
            ten*=10;
        }
    }
}

void init(){
    head=MX;
    tail=MX;
    isReversed=false;
    isError=false;
}
void R(){
    int tmp=head;
    if(!isReversed)
    {   //원상태에서 뒤집기
        head=tail-1;
        tail=tmp-1;
    }
    else{
        head=tail+1;
        tail=tmp+1;
    }
    isReversed=!isReversed;
}

void D(){
    if(head==tail) isError=true;
    else isReversed ? head-- : head++;
};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    while(t--){
        init();
        string strBuffer;
        string cmd;
        cin>>cmd; //함수 명령 입력

        int n;
        cin>>n; //배열 개수
        string l1;//리스트
        cin>>l1;
        parse(l1,n);
        for(auto c:cmd){
            if(c=='D'){
                if(head==tail){
                    isError=true;
                    break;
                }
                else D();
            }
            else if(c=='R') R();
        }

        if(isError) cout<<"error\n";
        else if(head==tail) cout<<"[]\n";
        else{
            cout<<"[";
            if(isReversed) {
                for(int i=head;i>tail+1;i--)
                    cout<<dat[i]<<",";
                cout<<dat[tail+1];
            }
            else {
                for(int i=head;i<tail-1;i++)
                    cout<<dat[i]<<",";
                cout<<dat[tail-1];
            }
            cout<<"]\n";
        }
    }
}