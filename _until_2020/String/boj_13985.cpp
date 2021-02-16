#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    int num=0;
    int res=0;
    bool done = false;
    string in; getline(cin, in);

    int p=0;
    while(p<in.size()){
        if(done && in[p]>='0' && in[p]<='9'){
            res = int(in[p])-'0';
        }
        else if(in[p]>='0' && in[p]<='9'){
            num+=int(in[p])-'0';
        }
        else if(in[p]=='='){
            done = true;
        }
        p++;
    }

    if(res==num)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}
