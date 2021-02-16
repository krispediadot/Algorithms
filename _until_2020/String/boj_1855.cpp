#include<iostream>
#include<string>
#define MAX 20

using namespace std;

int main(){
    char arr[MAX][MAX];
    int c; cin>>c;
    string s; cin>>s;
    int r = s.length()/c;

    int p = 0;
    for(int i=0; i<r; i++){
        if(i%2==0){
            for(int j=0; j<c; j++)
                arr[i][j] = s[p++];
        }
        else{
            for(int j=c-1; j>=0; j--)
                arr[i][j] = s[p++];
        }
    }

    string res = "";
    for(int j=0; j<c; j++){
        for(int i=0; i<r; i++){
            res += arr[i][j];
        }
    }
    cout<<res<<endl;

    return 0;
}