#include<iostream>
#include<string>
 
using namespace std;
 
bool deliTobi(int n, int m){
    int count = 1;
    int begin=1;
    while(begin<=n){
        begin *= 2;
        count++;
    }
    begin /= 2;
    count--;
    if(count<m)
        return false;
 
    for(int i=begin; i>0; i/=2){
        int num = n>=i?1:0;
        if(count<=m && num!=1) return false;
        if(num==1) n -= i;
        count--;
    }
    return true;
}
 
int main(){
    int t; cin>>t;
    for(int tt=1; tt<=t; tt++){
        string res = "OFF";
        int n, m; cin>>n>>m;
 
        bool bi = deliTobi(m, n);
        if(bi) res="ON";
 
        cout<<"#"<<tt<<" "<<res<<endl;
    }
 
    return 0;
}
