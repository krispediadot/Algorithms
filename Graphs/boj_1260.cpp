#include<iostream>
#include<queue>
#define SIZE 1001
#define CONNECTED 1
#define VISITED -1

using namespace std;
int N, M, startIndex;
int adjArr[SIZE][SIZE]={0};

void getInput(){
    cin>>N>>M>>startIndex;

    for(int i=0; i<M; i++){
        int node1, node2;
        cin>>node1>>node2;
        adjArr[node1][node2] = CONNECTED;
        adjArr[node2][node1] = CONNECTED;
    }
}
void BFS(int startIndex){
    queue<int> q;
    q.push(startIndex);
    adjArr[startIndex][0] = VISITED;

    while(!q.empty()){
        int checkIndex = q.front();
        q.pop();

        cout<<checkIndex<<" ";
        for(int i=1; i<=N; i++){
            if(adjArr[checkIndex][i]==CONNECTED && adjArr[i][0]!=VISITED){
                adjArr[i][0] = VISITED;
                q.push(i);
            }
        }
    }
}
void DFS(int startIndex){
    adjArr[0][startIndex] = VISITED;
    cout<<startIndex<<" ";
    for(int i=1; i<=N; i++){
        if(adjArr[startIndex][i]==CONNECTED && adjArr[0][i]!=VISITED){
            DFS(i);
        }
    }
}
int main(){
    getInput();
    DFS(startIndex);
    cout<<endl;
    BFS(startIndex);

    return 0;
}
