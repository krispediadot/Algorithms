#include<iostream>
#include<string>

using namespace std;

int main(){
    string s; cin>>s;

    int c1=0, c2=0;
    while(s.length()>2){
        string sub = s.substr(0,3);
        if(sub=="JOI")
            c1++;
        if(sub=="IOI")
            c2++;
        s = s.substr(1);
    }
    cout<<c1<<endl<<c2<<endl;

    return 0;
}
