#include<iostream>
#include<string>

using namespace std;

char seq[]={'A','C','G','T'};

int main(){
    int n;cin>>n;
    for(int t=0; t<n; t++){
        string s; cin>>s;

        // 작은 값 찾기
        int seqIndex = -1;
        for(int i=0; i<4; i++){
            if(s.find(seq[i])!=string::npos) {
                seqIndex = i;
                break;
            }
        }
        int loc = s.find(seq[seqIndex]);
        string res = s.substr(loc) + s.substr(0,loc);
        string ans = res;
        while(true){
            loc = res.substr(1).find(seq[seqIndex]);
            if(loc==string::npos)
                break;
            string newRes = res.substr(loc+1) + res.substr(0,loc+1);
            if(newRes.compare(ans)==0)
                break;
            if(newRes<ans)
                ans = newRes;
            res = newRes;
        }
        cout<<ans<<endl;
    }

    return 0;
}