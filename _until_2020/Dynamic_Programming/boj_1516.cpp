#include<iostream>
#include<queue>
#define SIZE 501
#define PREBUILD 1

using namespace std;

int arr[SIZE][SIZE]={0};
int singleBuildTime[SIZE] = {0};
int DP[SIZE] = {0};
int N;

queue<int> q;

int* getPreBuildIndexList(int a[], int index){
    int count = 0;
    for(int preBuildIndex=1; preBuildIndex<=N; preBuildIndex++){
        if(arr[index][preBuildIndex]==PREBUILD){
            count++;
            a[count] = preBuildIndex;
        }
    }
    a[0] = count;

    return a;
}
int* getNextBuildIndexList(int a[], int index){
    int count=0;
    for(int nextBuildIndex=1; nextBuildIndex<=N; nextBuildIndex++){
        if(arr[nextBuildIndex][index]==PREBUILD){
            count++;
            a[count] = nextBuildIndex;
        }
    }
    a[0] = count;

    return a;
}
int getMaxLevel(int *preBuildIndexList){
    int max = 0;
    for(int i=1; i<=preBuildIndexList[0]; i++){
        if(arr[0][preBuildIndexList[i]]>max)
            max = arr[0][preBuildIndexList[i]];
    }
    return max;
}
void updateBuildLevel(){
    for(int i=1; i<=N; i++){
        // level=1이면 큐에 넣기
        if(arr[0][i] == 1)
            q.push(i);
    }
    while(!q.empty()){
        int checkIndex = q.front();
        q.pop();

        int a[SIZE] = {0};
        int* nextBuildList = getNextBuildIndexList(a, checkIndex);

        for(int i=1; i<=nextBuildList[0]; i++){
            // 레벨이 정해졌다면 넘어감
            if(arr[0][nextBuildList[i]] != 0)
                continue;
            bool isLevelSetDone=true;
            int b[SIZE] = {0};
            int *preBuildList = getPreBuildIndexList(b, nextBuildList[i]);

            for(int j=1; j<=preBuildList[0];j++){
                if(arr[0][preBuildList[j]] == 0)
                    isLevelSetDone = false;
            }
            if(isLevelSetDone) {
                arr[0][nextBuildList[i]] = getMaxLevel(preBuildList) + 1;
                q.push(nextBuildList[i]);
            }
        }
    }
}
int* getTargetLevelIndexList(int a[], int level){
    int count=0;
    for(int i=1; i<=N; i++){
        if(arr[0][i] == level) {
            count++;
            a[count] = i;
        }
    }
    a[0] = count;

    return a;
}
int getTotalMaxLevel(){
    int max=0;
    for(int i=1; i<=N; i++){
        if(arr[0][i]>max)
            max = arr[0][i];
    }
    return max;
}
int getMaxBuildTimeOfPreBuild(int *preBuildList){
    int max = DP[preBuildList[1]];
    for(int i=2; i<=preBuildList[0]; i++){
        if(DP[preBuildList[i]] > max)
            max = DP[preBuildList[i]];
    }
    return max;
}
void calcMinBuildTime(){
    int maxLevel = getTotalMaxLevel();
    // level 1인 경우는 입력 받을때 넣어놨음
    for(int level=2; level<=maxLevel; level++){
        // 해당 레벨 인덱스 찾기
        int a[SIZE]={0};
        int* targetLevelIndexList = getTargetLevelIndexList(a, level);

        for(int i=1; i<=targetLevelIndexList[0]; i++){
            // 해당 레벨 인덱스의 사전에 지어져야하는 빌딩 중 이전 레벨에 해당하는 것 찾기
            int b[SIZE]={0};
            int* preBuildList = getPreBuildIndexList(b, targetLevelIndexList[i]);

            // 이전 레벨 해당 인덱스 중에서 가장 큰 값에 지금 인덱스 짓는 시간 더하기
            DP[targetLevelIndexList[i]] = getMaxBuildTimeOfPreBuild(preBuildList)+singleBuildTime[targetLevelIndexList[i]];
        }
    }
}
bool isError(){
    for(int i=1; i<=N; i++){
        if(DP[i] != 1)
            return false;
    }
    return true;
}
void printResult(){
    if(isError())
        return;
    for(int i=1; i<=N; i++){
        cout<<DP[i]<<endl;
    }
}
void getInput(){
    cin>>N;
    for(int i=1; i<=N; i++){
        cin>>singleBuildTime[i];
        int count=0;
        for(;;){
            int num;
            cin>>num;
            if(num==-1) break;
            count++;
            arr[i][num] = PREBUILD;
        }
        if(count==0) {
            arr[0][i] = 1;
            DP[i] = singleBuildTime[i];
        }
    }
}
int main(){

    getInput();
    updateBuildLevel();
    calcMinBuildTime();
    printResult();

    return 0;
}
