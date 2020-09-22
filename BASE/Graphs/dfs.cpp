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
void dfs(int i, int j, string res){
    if(i==3 && j==3){
        cout<<res<<endl;
        return;
    }
    visited[i][j] = true;
    for(int dir=0; dir<4; dir++){
        int nx = i+dirX[dir];
        int ny = j+dirY[dir];
        if(nx>=0 && nx<4 && ny>=0 && ny<4 && arr[nx][ny] == 0 && !visited[nx][ny])
            dfs(nx,ny,res+("{"+to_string(nx)+","+to_string(ny)+"}"));
    }
    visited[i][j] = false;
}

void dfs_stack(){
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
        bool doneDir[4];
        sItem(int x, int y):loc(Loc(x,y)){
            for(int i=0; i<4; i++) doneDir[i] = false;
        }
    };
    vector<sItem> stk;
    bool done[4][4] = {false,};
    stk.push_back(sItem(0,0));
    done[0][0] = true;
    while(stk.size()>0){
        sItem target = stk.back();

        bool able = false;
        for(int dir=0; dir<4; dir++){
            if(target.doneDir[dir] == false) {
                stk.back().doneDir[dir] = true;
                int nx = target.loc.x + dirX[dir];
                int ny = target.loc.y + dirY[dir];
                if (nx == 3 && ny == 3) {
                    for (int idx = 0; idx < stk.size(); idx++) stk[idx].loc.print();
                    cout << "{3,3}" << endl;
                    continue;
                }
                if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4 && arr[nx][ny] == 0 && !done[nx][ny]) {
                    able = true;
                    stk.push_back(sItem(nx,ny));
                    done[nx][ny] = true;
                    break;
                }
            }
        }
        if(!able) {
            stk.pop_back();
            done[target.loc.x][target.loc.y] = false;
        }
    }
}
int main(){
    dfs(0,0,"{0,0}");
    cout<<endl;
    dfs_stack();
}