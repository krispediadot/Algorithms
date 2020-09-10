#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    string a; cin>>a;
    bool correct = true;
    while(1){
        string b; cin>>b;
        if(a=="#" && b=="#") break;
        if(a=="#") {
            a = b;
            continue;
        }
        if(b=="#") {
            if(correct) cout<<"Correct"<<endl;
            else cout<<"Incorrect"<<endl;
            a = b;

            correct = true;
            continue;
        }
        if(!correct) continue;

        if(a.length()!=b.length())
            correct = false;
        else{
            int count = 0;
            for(int i=0; i<a.length(); i++){
                if(a[i]!=b[i])
                    count++;
            }
            if(count!=1)
                correct = false;
        }
        a = b;
    }
}