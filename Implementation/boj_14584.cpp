#include<iostream>
#include<string>

using namespace std;

int pIndex=0;
string dict[20];
int n;

bool foundInDict(string result){
    for(int i=0; i<n; i++){
        if(result.find(dict[i])!=string::npos)
            return true;
    }
    return false;
}
int main(){
    string alphabet[26] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
    int gap[100]={0};
    string result="";
    bool found=false;
    string s;
    cin>>s;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>dict[i];
    }

    // gap 계산
    for(int i=0; i<s.size(); i++){
        gap[i] = s[i]-'a';
    }

    while(!found){
        result="";
        for(int i=0; i<s.size(); i++){
            result.append(alphabet[(pIndex+gap[i])%26]);
        }
        //cout<<result<<endl;
        if(foundInDict(result))
            break;
        pIndex = (pIndex+1)%26;
    }

    cout<<result<<endl;
    return 0;
}
