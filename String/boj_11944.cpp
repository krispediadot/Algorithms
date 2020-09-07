#include<iostream>
#include<string>

using namespace std;

int main(){
    string a; cin>>a;
    int n;cin>>n;

    if(stoi(a)*a.length()>n) {
        for (int i = 0; i < n; i++) {
            cout << a[i % a.length()];
        }
    } else{
        for(int i=0; i<stoi(a); i++)
            cout<<a;
    }

    return 0;
}