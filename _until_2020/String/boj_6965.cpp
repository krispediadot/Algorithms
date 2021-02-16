#include<iostream>
#include<string>

using namespace std;

int main(){
    int n; cin>>n;
    cin.ignore();
    for(int i=0; i<n; i++){
        string s; getline(cin,s);
        int p=0;

        while(p<=s.length()-4){
            string sub = s.substr(p);
            int index=sub.find(" ");
            if(index==string::npos && (s.length()-p)==4) {
                s.replace(p, 4, "****");
                break;
            }
            if(index==string::npos)
                break;
            if(index==4)
                s.replace(p, 4, "****");
            p += index+1;
        }
        cout<<s<<endl;
        if(i!=n-1)
            cout<<endl;
    }

    return 0;
}