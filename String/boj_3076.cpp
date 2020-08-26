#include<iostream>
#include<string>
#define BLACK 'X'
#define WHITE '.'

using namespace std;

int main(){
    int r,c,a,b; cin>>r>>c>>a>>b;

    int w = b*c;
    int h = r*a;

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if((i/a+j/b)%2==0)
                cout<<BLACK;
            else
                cout<<WHITE;
        }
        cout<<endl;
    }

    return 0;
}