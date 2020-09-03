#include<string>
#include<iostream>

using namespace std;

int main(){
    while(true){
        int n; cin>>n; cin.ignore();
        if(n==0)
            break;

        int p=0;
        for(int i=0; i<n; i++){
            string s; getline(cin, s);
            if(s.length()<p)
                continue;
            if(s.substr(p).find(' ')==string::npos) {
                p = s.length();
                continue;
            }
            p += s.substr(p).find(' ');
        }
        cout<<p+1<<endl;
    }

    return 0;
}