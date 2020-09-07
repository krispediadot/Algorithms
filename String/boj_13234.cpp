#include<string>
#include<iostream>

using namespace std;

int main(){
    string a,b,op; cin>>a>>op>>b;

    if(op.compare("AND")==0){
        if(a.compare("true")==0 && b.compare("true")==0)
            cout<<"true"<<endl;
        else
            cout<<"false"<<endl;
    }
    else if(op.compare("OR")==0){
        if(a.compare("true")==0||b.compare("true")==0)
            cout<<"true"<<endl;
        else
            cout<<"false"<<endl;
    }

    return 0;
}