#include<iostream>
#include<string>
#include<map>
#define MAX 1001

using namespace std;

int main(){
    map<string, int> m;
    int outIndex[MAX]={0};
    int n;
    cin>>n;

    for(int i=1; i<=n; i++){
        string input;
        cin>>input;

        m.insert(make_pair(input,i));
    }
    for(int i=1; i<=n; i++) {
        string input;
        cin>>input;
        outIndex[i] = m.find(input)->second;
        //cout<<outIndex[i]<<endl;
    }

    int count=0;
    int minNum = outIndex[n];
    for(int i=n-1; i>0; i--){
        if(outIndex[i]<minNum)
            minNum = outIndex[i];
        else{
            count++;
        }
    }

    cout<<count<<endl;

    return 0;
}
