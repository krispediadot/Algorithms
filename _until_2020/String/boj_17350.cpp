#include<iostream>
#include<string>

using namespace std;

int main(){
    int n; cin>> n;
    bool exist = false;
    for(int i=0; i<n; i++){
        string s; cin>>s;
        if(s.compare("anj")==0) {
            exist = true;
            break;
        }
    }
    if(exist) cout<<"뭐야;"<<endl;
    else cout<<"뭐야?"<<endl;

    return 0;
}