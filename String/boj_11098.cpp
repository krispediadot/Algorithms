#include<iostream>
#include<string>

using namespace std;

int main(){
    int t; cin>>t;
    for(int tt=0; tt<t; tt++){
        int n;cin>>n;
        int cost;
        string name;
        cin>>cost>>name;
        for(int i=0; i<n-1; i++){
            int c;cin>>c;
            string cn; cin>>cn;
            if(c>cost) {
                name = cn;
                cost = c;
            }
        }
        cout<<name<<endl;
    }

}