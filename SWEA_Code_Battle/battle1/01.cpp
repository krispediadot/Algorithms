#include<iostream>
#include<vector>

using namespace std;

int main(){
    int T;
    cin>>T;
    for(int t=1; t<=T; t++){
        int N, M;
        vector<int> time;
        cin>>N>>M;

        int max = 0;
        for(int n=0; n<N; n++){
            int in;
            cin>>in;
            time.push_back(in);
            if(time[n]>max)
                max = time[n];
        }
        int check = 0;
        while(1){
            check++;
            int count=0;
            for(int i=0; i<N; i++){
                count+=(check/time[i]);
            }

            if(count>M-1)
                break;
        }

        cout<<"#"<<t<<" "<<check<<endl;

    }

    return 0;
}
