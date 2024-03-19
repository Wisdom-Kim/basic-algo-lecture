#include <iostream>
#include <list>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    list<int> L;
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) L.push_back(i);
    auto t = L.begin();
    cout<<"<";
    while(--n){
        for(int i=1;i<k;i++){
            t!=--L.end() ? t++:t=L.begin();
        }
        cout<<*t<<", ";
        t=L.erase(t);
        if(t==L.end()) t=L.begin();
    }
    cout<<*t<<">";

}