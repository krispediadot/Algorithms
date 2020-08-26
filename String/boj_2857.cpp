#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    vector<int> r;

    for(int i=1; i<=5; i++) {
        string s;
        cin >> s;
        if(s.find("FBI")!=string::npos)
            r.push_back(i);
    }
    if(r.size()==0)
        cout<<"HE GOT AWAY!"<<endl;
    else {
        for (int i = 0; i < r.size(); i++)
            cout << r[i] << " ";
    }

    return 0;
}