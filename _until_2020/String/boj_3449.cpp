#include<iostream>
#include<string>

using namespace std;

int main(){
    int T; cin>>T;

    for(int t=0; t<T; t++){
        string a, b; cin>>a>>b;

        int count=0;
        for(int i=0; i<a.length(); i++){
            if(a[i]!=b[i]) count++;
        }
        cout<<"Hamming distance is "<<count<<"."<<endl;
    }

    return 0;
}