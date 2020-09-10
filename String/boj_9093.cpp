#include<iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

int main(){
    int n; cin>>n; cin.ignore();
    for(int i=0; i<n; i++){
        string s; getline(cin, s);
        stringstream ss(s);
        string tmp;
        vector<string> split;
        while(getline(ss,tmp, ' ')){
            split.push_back(tmp);
        }

        for(int i=0; i<split.size(); i++){
            for(int index=split[i].length()-1; index>=0; index--)
                cout<<split[i][index];
            cout<<" ";
        }
        cout<<endl;
    }


    return 0;
}