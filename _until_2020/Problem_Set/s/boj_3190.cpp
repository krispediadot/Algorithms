#include<iostream>
#include<vector>
#define SNAKE 1
#define APPLE 2
using namespace std;

int dirX[] = {0,1,0,-1};
int dirY[] = {1,0,-1,0};

vector<vector<int>> arr;
vector<pair<int, char>> turn;

int n;
void printArr(int t){
    cout<<"==========["<<t<<"]"<<endl;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<'\n';
    }
}
int play(){
    vector<pair<int, int>> snake;
    int time = 0;
    int dir = 0;
    int turnIndex = 0;
    pair<int,int> cur(1,1);
    arr[1][1] = SNAKE;
    snake.push_back(cur);
    while(1){
        time++;
        int nextX = cur.first+dirX[dir];
        int nextY = cur.second+dirY[dir];

        if(nextX<=0 || nextX>n || nextY<=0 || nextY>n || arr[nextX][nextY]==SNAKE)
            break;
        if(arr[nextX][nextY] == APPLE) arr[nextX][nextY] = 0;
        else{
            pair<int,int> tail = snake.front();
            arr[tail.first][tail.second] = 0;
            snake.erase(snake.begin());
        }
        cur.first = nextX;
        cur.second = nextY;
        snake.push_back(cur);
        arr[cur.first][cur.second] = SNAKE;

        if(time == turn[turnIndex].first){
            // 오른쪽 회전
            if(turn[turnIndex].second=='D') dir = (dir+1)%4;
            // 왼쪽 회전
            else dir = (dir+3)%4;
            turnIndex++;
        }
        //printArr(time);
    }
    return time;
}

int main(){
    // 맵 생성
    cin>>n;
    for(int i=0; i<=n; i++){
        vector<int> tmp;
        for(int j=0; j<=n; j++) tmp.push_back(0);
        arr.push_back(tmp);
    }
    // 사과 놓기
    int k; cin>>k;
    for(int i=0; i<k; i++) {
        int x,y; cin>>x>>y;
        arr[x][y] = APPLE;
    }
    // 회전 정보
    int l; cin>>l;
    for(int i=0; i<l; i++){
        int t;
        char c;
        cin>>t>>c;
        turn.push_back(make_pair(t,c));
    }
    cout<<play();
}