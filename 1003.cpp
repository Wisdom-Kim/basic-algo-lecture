//
// Created by wisdom99 on 2024-03-25.
//
#define MOD 10007
#include <iostream>

using namespace std;
int temp;

int dp[1001];

int fibonacci(int n){
    if(n==1) return dp[1];
    if (n==2) return dp[2];
    if(dp[n]!=0){
        return dp[n];
    }
    //여기까지 온 얘들은 아직 dp[n]이 할당 안 됨
    //c= a+b일 때, c%d = a%d + b%d 이므로
    dp[n] = (fibonacci(n-1)+fibonacci(n-2))%MOD;

    return  dp[n];
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    dp[1]=1; dp[2]=2;

    cin>>temp;
    cout<<fibonacci(temp);


}