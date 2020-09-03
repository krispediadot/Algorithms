#include<string>
#include<iostream>

using namespace std;

int main(){
    int n;cin>>n;
    string a,b;cin>>a>>b;

    if(n%2==0){
        if(a.compare(b)==0)
            cout<<"Deletion succeeded"<<endl;
        else
            cout<<"Deletion failed"<<endl;
    }

    else if(n%2==1){
        bool done = false;
        for(int i=0; i<a.length(); i++){
            if(a[i]==b[i]){
                cout<<"Deletion failed"<<endl;
                done = true;
                break;
            }
        }
        if(!done)
            cout<<"Deletion succeeded"<<endl;
    }

    return 0;
}