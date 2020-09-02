#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int c[26]={0};
    string s;
    while(cin>>s){
        for(int i=0; i<s.length(); i++){
            int index = int(s[i])-'a';
            c[index]++;
        }
    }
    int max=0;
    vector<int> res;
    for(int i=0; i<26; i++){
        if(c[i]>max) {
            max = c[i];
            res.clear();
            res.push_back(i);
        }
        else if(c[i]==max){
            res.push_back(i);
        }
    }
    for(int i=0; i<res.size(); i++) {
        cout << char('a' + res[i]);
    }

    return 0;
}