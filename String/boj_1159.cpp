#include<iostream>
#include<string>
using namespace std;

int main(){
    bool exist = false;
    int arr[30] ={0};
    int N;cin>>N;

    for(int i=0; i<N; i++){
        string name; cin>>name;
        int index = int(name[0])-'a';
        arr[index]++;
    }
    for(int i=0; i<28; i++){
        if(arr[i]>=5) {
            exist = true;
            cout << char('a' + i);
        }
    }
    if(!exist)
        cout<<"PREDAJA"<<endl;

    return 0;
}