//
// Created by wisdom99 on 2024-01-10.
//
#include <iostream>
#include <stack>
#include <list>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int arr[n]; //입력 받을 배열
    list<char> C;//+ - 등을 담아둘 리스트
    stack<int> S; //실제 검증할 스택
    list<int> L;
    for(int i=n-1;i>=0;i--){
        int num;
        cin>>num;
        arr[i]=num;
    }
    int base=1; //시작점
    for(int i=n-1;i>=0;i++){
        
        if(arr[i]!=base){
            while(base<arr[i]) {
                C.push_back('+');
                C.push_back('-');
                L.push_back(base++);
            }
        }
        else {
            //arr[i]==base일 경우
            S.push(base++);
            C.push_back('+');
        }
    }
}