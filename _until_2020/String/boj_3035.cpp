#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    int r,c,zr,zc; cin>>r>>c>>zr>>zc;
    vector<string> arr;

    for(int i=0; i<r; i++){
        string s; cin>>s;
        arr.push_back(s);
    }

    for(int i=0; i<r; i++){
        string s="";
        for(int j=0; j<c; j++){
            for(int zzc=0; zzc<zc; zzc++)
                s+=arr[i][j];
        }
        for(int zzr=0; zzr<zr; zzr++)
            cout<<s<<endl;
    }

    return 0;
}