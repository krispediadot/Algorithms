#include<iostream>
#include<stack>
#define MAX 1000
#define TAKEN 1

using namespace std;

struct Loc{
    int x;
    int y;
    Loc(int x, int y):x(x), y(y){}
};

int dirX[] = {-1, 0, 1, 0};
int dirY[] = {0, 1, 0, -1};
int R, C;

Loc* convertLocForOutput(Loc* origin){
    return new Loc(origin->y+1, R-origin->x);
}
int main(){
    int pIndex, count=0;
    stack<Loc*> s;
    int arr[MAX][MAX] = {0};

    cin >> C >> R >> pIndex;

    arr[R - 1][0] = TAKEN;
    count++;
    s.push(new Loc(R - 1, 0));
    int dirIndex = 0;
    Loc* lastTakenLoc= nullptr;
    while(!s.empty()){
        if(count == pIndex||count == R * C)
            break;

        Loc* target = s.top();

        int nextX = target->x+dirX[dirIndex];
        int nextY = target->y+dirY[dirIndex];

        if(nextX>=0 && nextX < R && nextY >= 0 && nextY < C && arr[nextX][nextY] == 0){
            s.pop();
            count++;
            arr[nextX][nextY] = count;
            lastTakenLoc = new Loc(nextX, nextY);
            s.push(lastTakenLoc);
        }
        else{
            dirIndex = (dirIndex+3)%4;
        }
    }
    if(pIndex==1){
        cout<<1<<" "<<1<<endl;
    }
    else if(arr[lastTakenLoc->x][lastTakenLoc->y]==pIndex){
        Loc* conv = convertLocForOutput(lastTakenLoc);
        cout<<conv->x<<" "<<conv->y<<endl;
    }
    else{
        cout<<0<<endl;
    }

    return 0;
}
