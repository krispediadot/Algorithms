#include<iostream>
#include<string>
#include<regex>
#include<sstream>
#include<vector>

using namespace std;

int main(){
    int n; cin>>n; cin.ignore();

    for(int i=0; i<n; i++){
        string s; getline(cin, s);
        stringstream ss(s);
        string temp;
        vector<string> v;
        while(getline(ss, temp, ' ')){
            v.push_back(temp);
        }
        regex re("lol");
        int count=0;
        for(int index=0; index<v.size(); index++){
            if(v[index]=="u" || v[index]=="ur")
                count+=10;
            else if(v[index].compare("lol")==0 || regex_search(v[index], regex("lol")))
                count+=10;
            else if(index<v.size()-1 && ((v[index].compare("should")==0 || v[index].compare("would")==0) && v[index+1].compare("of")==0))
                count+=10;
        }
        cout<<count<<endl;
    }
    return 0;
}