#include<iostream>
#define SIZE 501

using namespace std;

int main(void){
    int arr[SIZE][SIZE] = {0,};
    int n,m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    for(int i=1; i<=n; i++){
        // 상근이 친구
        if(arr[1][i] == 1){
            arr[0][i] = 1;
            for(int j=1;j<=n;j++){
                if(arr[i][j] == 1)
                    arr[0][j] = 1;
            }
        }
    }

    int count=0;
    for(int i=1; i<=n; i++){
        if(arr[0][i] == 1) count++;
    }

    cout<<count-1<<endl;

    return 0;
}
