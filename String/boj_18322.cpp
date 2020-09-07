#include<iostream>
#include<string>

using namespace std;

int main(){
    int n, k; cin>>n>>k;

    string line = "";
    for(int i=0; i<n; i++){
        string s; cin>>s;
        if((line.length()+s.length())<=k) {
            if(line.length()!=0)
                line += " ";
            line += s;
        }
        else{
            cout<<line<<endl;
            line = s;
        }
    }
    if(line.length()!=0)
        cout<<line<<endl;

    return 0;
}