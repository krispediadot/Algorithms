#include<iostream>
#include<string>

using namespace std;

void solve(string in1, string in2){
    int sH,sM,sS, eH,eM,eS;
    sH = stoi(in1.substr(0,2));
    sM = stoi(in1.substr(3,2));
    sS = stoi(in1.substr(6,2));
    eH = stoi(in2.substr(0,2));
    eM = stoi(in2.substr(3,2));
    eS = stoi(in2.substr(6,2));

    if(sH==eH && sM==eM && sS==eS) {
        cout << "24:00:00" << endl;
        return;
    }

    int subH,subM,subS;
    if(eS<sS){
        subS = 60-sS+eS;
        sM++;
    }
    else{
        subS = eS-sS;
    }

    if(eM<sM){
        subM = 60-sM+eM;
        sH++;
    }
    else{
        subM = eM-sM;
    }

    if(eH<sH){
        subH = 24-sH+eH;
    }
    else{
        subH = eH-sH;
    }

    cout.width(2);
    cout.fill('0');
    cout<<subH<<":";
    cout.width(2);
    cout.fill('0');
    cout<<subM<<":";
    cout.width(2);
    cout.fill('0');
    cout<<subS<<endl;
}
int main(){
    string in1, in2;
    cin>>in1>>in2;

    solve(in1, in2);

    return 0;
}
