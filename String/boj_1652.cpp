#include<iostream>
#include<string>
#include<vector>

using namespace std;

int countSpace(string s){
    int p=0, count=0;

    while(p<s.length()-1){
        if(s.substr(p,2).compare("..")==0){
            count++;
            while(s[p]=='.' && p<s.length())
                p += 1;
        } else
            p += 1;
    }
    return count;
}

int main(){
    int n; cin>>n;
    vector<string> colString;
    for(int i=0; i<n; i++) colString.push_back("");
    int r=0, c=0;
    for(int i=0; i<n; i++){
        string s; cin>>s;
        r += countSpace(s);
        //cout<<r<<endl;

        for(int index=0; index<s.length(); index++){
            colString[index]+=s[index];
        }
    }
    for(int i=0; i<n; i++){
        //cout<<colString[i]<<endl;
        c += countSpace(colString[i]);
    }
    cout<<r<<" "<<c<<endl;

    return 0;
}