/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;
// float b = 1.0, c = 2.0;
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include <algorithm>

using namespace std;


int map[200][2]={0}; //층,[왼쪽,오른쪽]

int get_floor(int x){
    //x가 위치한 층을 반환하는 함수
    for(int i=1;i<200;i++){
        if(x>=map[i][0]&& x<=map[i][1]) return i;
    }
    return 0;
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int floor=1;
    int test_case;
    int left=1; int right=1;

    for(int i=1;i<200;i++){
        //삼각 김밥 탑 정보 기록

        if(left>10000) break;
        map[i][0]=left;
        map[i][1]=right;

        left+=floor;
        right+=floor+1;

        floor++;
    }
    int T,s,e,ans,s_floor,e_floor ;
    int cnt=1;
    cin>>T;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin>>s>>e;
        if(s>e) swap(s,e);
        left=s; right =s;
        s_floor = get_floor(s);
        e_floor = get_floor(e);

        if(s_floor==e_floor) ans = abs(s-e);//같은 층에 s,e위치
        else{
            for(int i=s_floor;i<e_floor;i++){
                left+=i;
                right+=i+1;
            }

            if(left<=e &&right>=e) ans=e_floor - s_floor;
            else if(left>e) ans = e_floor-s_floor+(left-e);
            else ans = e_floor-s_floor+(right-e);
        }
        cout<<"#"<<cnt++<<" "<<ans<<"\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}