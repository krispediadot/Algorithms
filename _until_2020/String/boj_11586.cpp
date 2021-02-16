#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    int n; cin>>n;
    vector<string> arr;
    for(int i=0; i<n; i++) {
        string s;cin>>s;
        arr.push_back(s);
    }
    int stat; cin>>stat;
    if(stat==1){
        for(int i=0; i<n; i++)
            cout<<arr[i]<<endl;
    }
    else if(stat==2){
        for(int i=0; i<n; i++){
            for(int index=n-1; index>=0; index--)
                cout<<arr[i][index];
            cout<<endl;
        }
    }
    else if(stat==3){
        for(int i=n-1; i>=0; i--){
            cout<<arr[i]<<endl;
        }
    }
}