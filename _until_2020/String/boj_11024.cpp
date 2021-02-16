#include<iostream>
using namespace std;

int main(){
    int T; cin>>T;

    for(int t=0; t<T; t++){
        int num=0;
        cin.ignore();
        while(cin.peek()!='\n'){
            int n;
            cin>>n;
            num+=n;
        }
        cout<<num<<endl;
    }

    return 0;
}
