#include<iostream>
#include<queue>
#include<cstring>
#define SIZE 100
#define CONNECTED 1

using namespace std;

int arr[SIZE][SIZE]={0};
bool checked[SIZE] = {false};
int n;

void getInput(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cin>>arr[i][j];
    }
}
void printResult(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
}
void BFS(int index){
    memset(checked,false,SIZE*sizeof(bool));
    queue<int> q;
    for(int i=0; i<n; i++){
        if(arr[index][i]==CONNECTED) {
            q.push(i);
            checked[i] = true;
        }
    }

    while(!q.empty()){
        int target = q.front();
        q.pop();

        for(int i=0; i<n; i++){
            if(arr[target][i]==CONNECTED && checked[i]==false){
                arr[index][i]=CONNECTED;
                q.push(i);
                checked[i]=true;
            }
        }
    }
}
void process(){
    for(int i=0; i<n; i++){
        BFS(i);
    }
}
int main(){
    getInput();
    process();
    printResult();
    return 0;
}
