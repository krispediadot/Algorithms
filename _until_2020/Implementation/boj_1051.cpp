#include<iostream>
#include<string>
#define SIZE 50

using namespace std;

int main(void) {
    int N,M;
    int arr[SIZE][SIZE] ={0};

    cin>>N>>M;

    for(int n=0; n<N; n++){
        string s;
        cin>>s;
        for(int i=0; i<M; i++) {
            arr[n][i] = s[i] -'0';
        }
    }

    int size;
    if(N<M) size = N;
    else size=M;

    bool found = false;
    while(size>0){
        int l = size-1;
        for(int r=0; r<N-l; r++){
            for(int c=0; c<M-l; c++){
                // 4 꼭지점 값 확인하기
                if((arr[r][c] == arr[r+l][c]) && (arr[r][c+l] == arr[r+l][c+l]) && (arr[r][c] == arr[r+l][c+l])) {
                    found = true;
                    break;
                }
            }
            if(found==true) break;
        }
        if(found==true) break;
        size -= 1;
    }
    if(size==0) size = 1;
    cout<<size*size<<endl;

    return 0;
}
