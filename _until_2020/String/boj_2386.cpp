#include<iostream>
#include<string>

using namespace std;

int main(){
    while(1) {
        char index;
        cin >> index;
        if(index=='#')
            break;
        int a[26] = {0};
        cin.ignore();
        string s;
        getline(cin, s);

        for(int i=0; i<s.length(); i++){
            if(s[i]==' ')
                continue;
            if(s[i]<'a')
                s[i] += 32;
            a[s[i]-'a']++;
        }
        cout<<index<<" "<<a[index-'a']<<endl;
    }
    return 0;
}