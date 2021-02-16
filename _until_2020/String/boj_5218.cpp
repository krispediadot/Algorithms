#include<iostream>
#include<string>

using namespace std;

int main(){
    int n;cin>>n;

    for(int i=0; i<n; i++){
        string a,b;cin>>a>>b;
        cout<<"Distances: ";
        for(int index=0; index<a.length(); index++){
            int diff = int(b[index]) - int(a[index]);
            if(diff<0) diff+=26;
            cout<<diff<<" ";
        }
        cout<<endl;
    }

    return 0;
}