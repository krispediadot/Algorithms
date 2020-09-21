#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n; cin>>n;
    vector<int> a;
    for(int i=0; i<n; i++) {int num;cin>>num; a.push_back(num);}
    int b,c; cin>>b>>c;
    long long count=0;

    for(int i=0; i<n; i++){
        // 총 감독
        a[i] = a[i]-b;
        count++;

        if(a[i]>0){
            count+=a[i]/c;
            if(a[i]%c>0) count++;
        }
    }
    cout<<count;

}