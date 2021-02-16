#include<iostream>
#define MAX 1000000

using namespace std;

int cache[MAX];

void printCache(int n){
    for(int i=0; i<=n; i++)
        cout<<cache[i]<<" ";
    cout<<endl;
}
void checkPrep(){
    cache[1] = 0;
    cache[2] = 1;
    cache[3] = 1;
}

void check(int checkIndex, int n) {
    if(checkIndex > n)
        return;
    else{
        if(checkIndex%3 == 0 && checkIndex%2 == 0){
            cache[checkIndex] = 1 + min(min(cache[checkIndex/3], cache[checkIndex/2]), cache[checkIndex-1]);
        }
        else if(checkIndex%3 == 0)
            cache[checkIndex] = 1 + min(cache[checkIndex/3], cache[checkIndex-1]);
        else if(checkIndex%2 == 0)
            cache[checkIndex] = 1 + min(cache[checkIndex/2], cache[checkIndex-1]);
        else
            cache[checkIndex] = 1 + cache[checkIndex-1];

        return check(checkIndex+1, n);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;

    checkPrep();
    check(4, n);

    //printCache(n);
    cout<<cache[n]<<'\n';
    return 0;
}
