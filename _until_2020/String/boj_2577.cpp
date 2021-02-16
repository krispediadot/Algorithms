#include<string>
#include<iostream>

using namespace std;

int main(){
    int a,b,c;cin>>a>>b>>c;
    int res = a*b*c;
    string r = to_string(res);
    int arr[10]={0};

    for(int i=0; i<r.length(); i++){
        arr[r[i]-'0']++;
    }
    for(int i=0; i<10; i++){
        cout<<arr[i]<<endl;
    }

    return 0;
}