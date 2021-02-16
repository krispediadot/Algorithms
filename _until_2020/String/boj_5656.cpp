#include<string>
#include<iostream>

using namespace std;

int main(){
    int count=1;
    while(true){
        int a,b;
        string comp;
        cin>>a>>comp>>b;
        if(comp.compare("E")==0)
            break;

        if(comp.compare("==")==0)
            cout<<"Case "<<count<<": "<<boolalpha<<(a==b?true:false)<<endl;
        else if(comp.compare("!=")==0)
            cout<<"Case "<<count<<": "<<boolalpha<<(a!=b?true:false)<<endl;
        else if(comp.compare("<=")==0)
            cout<<"Case "<<count<<": "<<boolalpha<<(a<=b?true:false)<<endl;
        else if(comp.compare("<")==0)
            cout<<"Case "<<count<<": "<<boolalpha<<(a<b?true:false)<<endl;
        else if(comp.compare(">=")==0)
            cout<<"Case "<<count<<": "<<boolalpha<<(a>=b?true:false)<<endl;
        else if(comp.compare(">")==0)
            cout<<"Case "<<count<<": "<<boolalpha<<(a>b?true:false)<<endl;

        count++;
    }

    return 0;
}