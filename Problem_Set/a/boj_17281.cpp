#include<iostream>
#include<vector>
#define MAX 50
#define OUT 0
using namespace std;

int info[MAX][10];
int n, ans=0;

void getInput(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int idx=1; idx<=9; idx++){
            cin>>info[i][idx];
        }
    }
}
int simulation(vector<int> lineup){
    int score=0;
    int playCount=0;
    int turnIdx=0;// turn 0~8
    // n번의 게임 진행
    while(playCount<n){
        vector<int> baseRunner; // 이닝 시작 시 주자 없음
        int outCount=0;         // 이닝 시작 시 아웃 없음
        // 3번 아웃 되기 전까지 경기 진행
        while(outCount<3){
            int playerIdx = lineup[turnIdx];
            if(info[playCount][playerIdx]==OUT){ // 현재 주자 아웃이면
                outCount++;
                turnIdx++;
                turnIdx%=9;
                continue;
            }
            // 안타이면 이동
            int moveTerm = info[playCount][playerIdx];
            // 주자가 있는 경우
            if(baseRunner.size()>0) {
                // 홈도착 점수 세기
                while(baseRunner.size()>0 && baseRunner.front()+moveTerm>=4){
                    score++;
                    baseRunner.erase(baseRunner.begin());
                }
                // 남아있는 주자 위치 정비
                for (int idx = 0; idx <baseRunner.size(); idx++) {
                    baseRunner[idx] += moveTerm;
                }
            }
            if(moveTerm == 4) score++;
            else baseRunner.push_back(moveTerm);
            turnIdx++;
            turnIdx%=9;
        }
        playCount++;
    }
    return score;
}
void setLineup(vector<int> lineup, bool done[10]){
    if(lineup.size()==9){
        int res = simulation(lineup);
        ans = res>ans?res:ans;
        return;
    }
    if(lineup.size()==3){
        lineup.push_back(1);
        setLineup(lineup, done);
        lineup.pop_back();
    }
    else {
        for (int idx = 2; idx < 10; idx++) {
            if (!done[idx]) {
                lineup.push_back(idx);
                done[idx] = true;
                setLineup(lineup, done);
                done[idx] = false;
                lineup.pop_back();
            }
        }
    }
}
int main(){
    // 입력
    getInput();
    vector<int> lineup;
    bool done[10]={false,};
    done[1] = true;
    // 완전탐색
    setLineup(lineup, done);
    // 점수 출력
    cout<<ans;
    return 0;
}