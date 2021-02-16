#include<iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

int main(){
    int t; cin>>t;cin.ignore();
    for(int tt=0; tt<t; tt++){
        string s; getline(cin, s);
        stringstream ss(s);
        string tmp;
        vector<string> split;

        while(getline(ss,tmp, ' ')){
            split.push_back(tmp);
        }

        for(int i=0; i<split.size(); i++){
            //cout<<split[i];
            int sum=0;
            for(int index=0; index<split[i].length(); index++){
                sum += (split[i][index]-'a');
            }
            sum %= 27;
            if(sum==26) cout<<" ";
            else cout<<char(sum+'a');
        }
        cout<<endl;
    }
}