#include<iostream>
#define MIN(X,Y)(((X)<(Y))?(X):(Y))
using namespace std;

int main(){
    int T;
    cin>>T;

    for(int t=1; t<=T; t++){
        int N, M, K;
        cin>>N>>M>>K;

        int maxN = N/2;
        int maxM = M;

        int maxTeam = MIN(maxN, maxM);

        int left = (N-(maxTeam*2))+(M-(maxTeam));
        while((N-(maxTeam*2))+(M-(maxTeam)) < K){
            maxTeam--;
        }
        cout<<"#"<<t<<" "<<maxTeam<<endl;
    }

    return 0;
}
