#include<iostream>
#include<string>
#include<map>

using namespace std;

map<string,string> m;

int main(){
    int n; cin>>n;

    for(int i=0; i<n; i++){
        string a,b,eq; cin>>a>>eq>>b;
        m.insert(make_pair(a,b));
    }
    int t; cin>>t;
    for(int tt=0; tt<t; tt++){
        string ans = "";
        int k; cin>>k;
        for(int i=0; i<k; i++){
            string in; cin>>in;
            ans += m[in];
            if(i<k-1)
                ans += ' ';
        }
        cout<<ans<<endl;
    }

    return 0;
}