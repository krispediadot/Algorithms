// 9625. BABBA
//
// 상근이는 화면의 모든 B는 BA로 바뀌고, A는 B로 바뀐다는 사실을 알게되었다.
// 버튼을 K번 눌렀을 때, 화면에 A와 B의 개수는 몇 개가 될까?
//
// input
// 1
//
// output
// 0 1
//

#include<iostream>

using namespace std;

int main(){
    int n; cin>>n;
    int a = 0;
    int b = 1;
    int idx = 1;
    while(idx<n){
        int newa = b;
        int newb = a+b;
        a = newa;
        b = newb;

        idx++;
    }
    cout<<a<<" "<<b;
}
