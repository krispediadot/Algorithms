#include<iostream>
#define SIZE 15
#define MIN(X,Y)(((X)<(Y))?(X):(Y))
using namespace std;

long long calculate(long long sub[SIZE][SIZE], int startX, int startY, int endX, int endY){
    for(int i=startX; i<=endX; i++){
        for(int j=startY; j<=endY; j++){
            if(i==startX && j==startY) continue;
            if(i==startX) sub[i][j] = 1;
            if(j==startY) sub[i][j] = 1;
            if(i>startX && j>startY) sub[i][j] = sub[i-1][j]+sub[i][j-1];
        }
    }

    return sub[endX][endY];
}

int main() {
    int arr[SIZE][SIZE] = {0};
    long long sub[SIZE][SIZE] = {0};
    int n, m, k, result=1;
    cin >> n >> m >> k;

    if (k != 0){
        int kX = k / m;
        int kY = k % m - 1;
        if (kY == -1) {
            kX -= 1;
            kY = m - 1;
        }
        result *= calculate(sub, 0, 0, kX, kY);
        //cout<<result<<endl;
        if (!(kX == n - 1 && kY == m - 1)) {
            sub[kX][kY] = 0;
            result *= calculate(sub, kX, kY, n - 1, m - 1);
        }
    }
    else{
        result *= calculate(sub, 0, 0, n-1, m-1);
    }
    cout << result << endl;


    return 0;
}
