#include<iostream>
#include<string>

using namespace std;

string arr[8] = {"1QAZ",
                 "2WSX",
                 "3EDC",
                 "4RFV5TGB",
                 "6YHN7UJM",
                 "8IK,",
                 "9OL.",
                 "0P;/-=[]'"
                 };
int res[8] = {0,};

int main(){
    string s; cin>>s;

    for(int i=0; i<s.length(); i++){
        for(int index=0; index<8; index++){
            if(arr[index].find(s[i])!=string::npos)
                res[index]++;
        }
    }
    for(int i=0; i<8; i++)
        cout<<res[i]<<endl;

    return 0;
}