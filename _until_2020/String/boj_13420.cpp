#include<iostream>
#include<string>

using namespace std;

int main(){
    int n; cin>>n;

    for(int t=0; t<n; t++){
        long long a, b, res, cor;
        string op, eq;
        cin>>a>>op>>b>>eq>>res;

        if(op=="+") cor = a+b;
        else if(op=="-") cor = a-b;
        else if(op=="*") cor = a*b;
        else if(op=="/") cor = a/b;

        if(res == cor)
            cout<<"correct"<<endl;
        else
            cout<<"wrong answer"<<endl;
    }

    return 0;
}