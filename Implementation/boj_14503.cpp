#include<iostream>
#define SIZE 50
#define NOTCLEAN 0
#define WALL 1
#define CLEAN 2
using namespace std;

int arr[SIZE][SIZE];
int curX, curY, curDir;
int n, m;
int dirX[4] = {-1, 0, 1, 0};
int dirY[4] = {0, 1, 0, -1};

bool check4dirCleanWall(int x, int y){
    bool blank = false;

    for(int i=0; i<4; i++){
        if(arr[curX+dirX[i]][curY+dirY[i]]!=CLEAN && arr[curX+dirX[i]][curY+dirY[i]]!=WALL)
            blank = true;
    }
    if(!blank) return true;
    return false;
}
void printArr() {
    cout << "=== arr ===" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    int count = 0;
    cin>>n>>m;

    cin>>curX>>curY>>curDir;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    if(arr[curX][curY]==NOTCLEAN)
        arr[curX][curY]=CLEAN;
        count++;

        while(1){
            int dir = (curDir+3)%4;
            if(arr[curX+dirX[dir]][curY+dirY[dir]]==NOTCLEAN){
                arr[curX+dirX[dir]][curY+dirY[dir]]=CLEAN;
                count++;
                curDir = dir;
                curX += dirX[dir];
                curY += dirY[dir];
            }
            else if(check4dirCleanWall(curX, curY)){
                int backDir = (curDir+2)%4;
                if(arr[curX+dirX[backDir]][curY+dirY[backDir]]==WALL)
                    break;
                curX += dirX[backDir];
                curY += dirY[backDir];
            }
            else{
                curDir = dir;
            }
            //printArr();
        }

    cout<<count<<endl;

    return 0;
}
