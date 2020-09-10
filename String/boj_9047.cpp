#include<iostream>
#include<string>

using namespace std;

int main(){
    int t; cin>>t;
    for(int tt=0; tt<t; tt++){
        string n; cin>>n;
        int count=0;
        while(stoi(n)!=6174){
            int a[10]={0,};
            for(int i=0; i<4; i++)
                a[n[i]-'0']++;
            string max = "", min = "";
            for(int i=0; i<10; i++) {
                if (a[i] != 0) {
                    while (a[i] != 0) {
                        min += to_string(i);
                        a[i]--;
                    }
                }
            }
            for(int i=3; i>=0; i--){
                max += min[i];
            }
            n = to_string(stoi(max) - stoi(min));
            while(n.length()<4){
                n.insert(0,1,'0');
            }

            count++;
        }
        cout<<count<<endl;
    }

    return 0;
}