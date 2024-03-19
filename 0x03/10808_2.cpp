// http://boj.kr/d7178d89538a42ababf4455443e60fe2
#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    for (char alp='a';alp<='z';alp++){
        int cnt=0;
        for(char c:s)
            if(c==alp)
                cnt++;
        cout<<cnt<<" ";
    }
}