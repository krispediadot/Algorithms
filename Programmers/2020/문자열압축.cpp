#include <string>
#include <vector>
#include <iostream>
#define MIN(X,Y)((X)<(Y)?(X):(Y))

using namespace std;

int solution(string s) {
    int answer = s.length();

    if(s.length()==1)
        return 1;

    for(int term = 1; term<=int(s.length()/2); term++){
        string res = "";
        int div = (s.length()/term);
        int index = 0;
        while(index<div){
            string base = s.substr(index*term, term);
            string other = s.substr((index+1)*term, term);
            int count = 1;

            if(index==div-1){
                res += base;
                break;
            }

            while(s.substr(index*term, term).compare(s.substr((index+1)*term, term))==0){
                count++;
                index++;
                if(index+1 == div)
                    break;
            }

            if(count==1){
                res += base;
            }
            else{
                res += (to_string(count) + base);
            }
            index++;
        }
        res += s.substr(term*div);

        answer = MIN(answer, res.length());
    }

    return answer;
}
int main(){
    string s; cin>>s;
    cout<<solution(s);

}
