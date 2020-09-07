#include<iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

int main(){
    int n; cin>>n; cin.ignore();

    for(int t=0; t<n; t++){
        string s; getline(cin, s);
        vector<string> split;
        stringstream ss(s);
        string tmp;
        while(getline(ss,tmp, ' ')){
            split.push_back(tmp);
        }
        string ans = "god";
        for(int i=1; i<split.size(); i++){
            ans+=split[i];
        }
        cout<<ans<<endl;
    }

    return 0;
}