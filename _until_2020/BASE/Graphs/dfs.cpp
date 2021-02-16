#include<iostream>
#include<string>
#include<vector>

using namespace std;

const int dirX[] = {0,1,0,-1};
const int dirY[] = {1,0,-1,0};

int arr[4][4]= {{0,0,0,0},
                {0,1,0,1},
                {0,1,0,0},
                {0,0,0,0}
                };

bool visited[4][4] = {false,};
void dfs_recursive(int i, int j, string res){
    if(i==3 && j==3){ // 목표지점 도착하면 끝
        cout<<res<<endl;
        return;
    }
    visited[i][j] = true;
    for(int dir=0; dir<4; dir++){
        int nx = i+dirX[dir];
        int ny = j+dirY[dir];
        if(nx>=0 && nx<4 && ny>=0 && ny<4 && arr[nx][ny] == 0 && !visited[nx][ny])
            dfs_recursive(nx,ny,res+("{"+to_string(nx)+","+to_string(ny)+"}"));
    }
    visited[i][j] = false;
}

void dfs_stack(){
    /***** 필요 자료구조 생성 ***********************************/
    struct Loc{
        int x;
        int y;
        Loc(int x, int y):x(x),y(y){}
        void print(){
            cout<<"{"<<x<<","<<y<<"}";
        }
    };
    struct sItem{
        Loc loc;
        bool doneDir[4]; // 이전에 이동한 방향을 기록하고 있어야 함. 중복 제거를 위해
        sItem(int x, int y):loc(Loc(x,y)){
            for(int i=0; i<4; i++) doneDir[i] = false;
        }
    };
    /************************************************************/
    vector<sItem> stk;
    bool done[4][4] = {false,};
    // 스택 초기 값 넣기
    stk.push_back(sItem(0,0));
    done[0][0] = true;
    // 모든 경우의 수 살펴 보기
    while(stk.size()>0){
        sItem target = stk.back();

        bool able = false; // 이동 가능한지 확인하는 변수. 이동 안되면 stack에서 제거
        for(int dir=0; dir<4; dir++){
            if(target.doneDir[dir] == false) { // 이전에 살펴본 방향이 아니라면
                stk.back().doneDir[dir] = true; // 살펴봄.
                int nx = target.loc.x + dirX[dir];
                int ny = target.loc.y + dirY[dir];
                if (nx == 3 && ny == 3) { // 목표지점 도착하면 끝
                    for (int idx = 0; idx < stk.size(); idx++) stk[idx].loc.print();
                    cout << "{3,3}" << endl;
                    continue;
                }
                if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4 && arr[nx][ny] == 0 && !done[nx][ny]) {
                    able = true;
                    stk.push_back(sItem(nx,ny));
                    done[nx][ny] = true;
                    break; // dfs로 구현하기 위해 스택에 새로운 값이 들어가면 그 값을 살펴보도록 이동
                }
            }
        }
        if(!able) { // 이동할 수 없으면 스택에서 제거
            stk.pop_back();
            done[target.loc.x][target.loc.y] = false;
        }
    }
}
int main(){
    dfs_recursive(0,0,"{0,0}");
    cout<<endl;
    dfs_stack();
}