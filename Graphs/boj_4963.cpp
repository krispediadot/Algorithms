#include<iostream>
#include<cstring>
#include<queue>
#define SIZE 50
#define LAND 1
#define VISITED -1
using namespace std;

struct Node{
    int x;
    int y;
    Node(int x, int y): x(x), y(y){}
};

int dirX[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dirY[] = {0, 1, 1, 1, 0, -1, -1, -1};
int arr[SIZE][SIZE] = {0};
int w,h;
queue<Node*> q;

void visitIsland(int x, int y){
    while(!q.empty()){
        Node* target = q.front();
        q.pop();

        for(int i=0; i<8; i++){
            int newX = target->x+dirX[i];
            int newY = target->y+dirY[i];

            if(newX>=0 && newX<h && newY>=0 && newY<w && arr[newX][newY]==LAND) {
                arr[newX][newY] = VISITED;
                q.push(new Node(newX, newY));
            }
        }
    }
}

int main(){
    while(1){
        int count=0;
        memset(arr, 0, sizeof(int)*SIZE*SIZE);
        cin>>w>>h;
        if(w==0 || h==0)
            break;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin>>arr[i][j];
            }
        }

        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(arr[i][j]==LAND) {
                    count++;
                    arr[i][j] = VISITED;
                    q.push(new Node(i,j));
                    visitIsland(i, j);
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
