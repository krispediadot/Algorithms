#include<iostream>
#include<string>
using namespace std;

int main(){
    string in1, in2;
    cin>>in1>>in2;
    long long sum=0;

    for(int i=0; i<in1.length(); i++){
        long long t1 = int(in1[i])-'0';
        for(int j=0; j<in2.length(); j++){
            sum+=t1*(int(in2[j])-'0');
        }
    }
    cout<<sum<<endl;

    return 0;
}
