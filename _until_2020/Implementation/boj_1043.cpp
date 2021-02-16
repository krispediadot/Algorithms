// https://www.acmicpc.net/problem/1043
#include <iostream>
#define SIZE 51
#define KNOWS 1
#define PARTYPEOPLE 2

using namespace std;

int PARTY[SIZE] = {0,};
int PT[SIZE][SIZE] = {0,};
int N, M;

void printPersonStatus(){
    for(int i=1; i<=N; i++)
        cout<<PT[0][i]<<" ";
    cout<<endl;
}

void printPT(){
    for(int r=0; r<=M; r++){
        for(int c=0; c<=N; c++){
            cout<<PT[r][c]<<" ";
        }
        cout<<endl;
    }
}

void printArr(int arr[], int n){
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void spreadTruth(int party_index){

    // 해당 파티에 참석한 사람이 누구인지 확인
    int num=0;
    int party_people[PT[party_index][0]];
    for(int person_index=1; person_index<=N; person_index++){
        if(PT[party_index][person_index] == PARTYPEOPLE) {
            party_people[num] = person_index;
            num++;
        }
    }

    //printArr(party_people, num);
    //printPersonStatus();

    // 해당 파티에 참석한 모든 사람 party_people[i]
    for(int i=0; i<num; i++){
        // 진실을 모르는 사람이 진실의 파티에 참석하면 진실을 알게되고 진실이 퍼짐.
        if(PT[0][party_people[i]] != KNOWS){
            PT[0][party_people[i]] = KNOWS;

            // 이 사람이 참석하는 파티가 어디인지 살펴봄
            int num_party = 0;
            int p_party[M];
            for(int p=1; p<=M; p++){
                if(PT[p][party_people[i]] == PARTYPEOPLE){
                    // 지금 보는 파티 제외하
                    if(p==party_index) continue;
                    p_party[num_party] = p;
                    num_party++;
                }
            }

            //printArr(p_party, num_party);

            // 진실을 모르는 파티에 참석하면 진실이 퍼짐.
            for(int p_index=0; p_index<num_party; p_index++) {
                if(PARTY[p_party[p_index]] != KNOWS) {
                    PARTY[p_party[p_index]] = KNOWS;
                    spreadTruth(p_party[p_index]);
                }
            }
        }
    }
    return;
}

int main(void){
    cin>>N>>M;

    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int index;
        cin>>index;
        PT[0][index] = KNOWS;
    }

    for(int party_index=1; party_index<=M; party_index++){
        int num;
        cin>>num;
        PT[party_index][0] = num;
        for(int i=0; i<num; i++){
            int person_index;
            cin>>person_index;
            PT[party_index][person_index] = PARTYPEOPLE;
            if(PT[0][person_index] == KNOWS) PARTY[party_index] = KNOWS;
        }
    }

    //printPT();
    //printArr(PARTY, M+1);


    for(int party_index=1; party_index<=M; party_index++){
        // 진실의 파티이면 모두 사실을 아는지 확인
        if(PARTY[party_index] == KNOWS){
            spreadTruth(party_index);
        }
    }

    int count = 0;
    for(int party_index=1; party_index<=M; party_index++){
        if(PARTY[party_index] != KNOWS)
            count++;
    }

    //printArr(PARTY, M+1);
    cout<<count<<endl;

    return 0;
}
