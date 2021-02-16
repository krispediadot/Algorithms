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
            // 방향의 왼쪽 보기 
            int dir = (curDir+3)%4;
            // a.왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한칸 이동  
            if(arr[curX+dirX[dir]][curY+dirY[dir]]==NOTCLEAN){
                arr[curX+dirX[dir]][curY+dirY[dir]]=CLEAN;
                count++;
                curDir = dir;
                curX += dirX[dir];
                curY += dirY[dir];
            }
            // c. 4방향 모두 청소가 되어 있거나 벽인 경우, 바라보는 방향 유지 및 한칸 후진  
            else if(check4dirCleanWall(curX, curY)){
                int backDir = (curDir+2)%4;
                // d. 뒤쪽이 벽이라 후진할 수 없는 경우, 종료  
                if(arr[curX+dirX[backDir]][curY+dirY[backDir]]==WALL)
                    break;
                curX += dirX[backDir];
                curY += dirY[backDir];
            }
            // b. 왼쪽 방향에 청소할 공간이 없다면, 왼쪽 방향으로 회전  
            else{
                curDir = dir;
            }
            //printArr();
        }

    cout<<count<<endl;

    return 0;
}
