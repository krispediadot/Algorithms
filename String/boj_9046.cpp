#include<iostream>
#include<string>

using namespace std;

int main(){
    int n; cin>>n;
    cin.ignore();
    for(int t=0; t<n; t++){
        int arr[26]={0,};
        string s;getline(cin,s);

        for(int i=0; i<s.length(); i++){
            if(s[i]==' ')
                continue;
            arr[int(s[i])-'a']++;
        }
        int maxIndex = 0;
        int max = arr[0];
        bool multi = false;
        for(int i=1; i<26; i++){
            if(arr[i]==max)
                multi = true;
            else if(arr[i]>max){
                max = arr[i];
                maxIndex = i;
                multi = false;
            }
        }
        if(multi)
            cout<<"?"<<endl;
        else
            cout<<char(maxIndex+int('a'))<<endl;
    }

    return 0;
}
