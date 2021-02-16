#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    int n;
    int step=0, pre=0;
    int mol, deno;    //mol = 분자, deno = 분모
    
    cin>>n;
    
    while(n>0){
        step++;
        pre = n;
        n -= step;
    }
    
    if(step%2 == 0){
        mol = pre;
        deno = step+1-mol;
    }
    else{
    
        deno = pre;
        mol = step+1-deno;
    }
    
    cout<<mol<<'/'<<deno<<endl;
    
    return 0;
    
}
