#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

string setForm(string message){
    // 2_4_5_ --> 2,4 and 5:
    // 1. 숫자 사이 쉼표 또는 and 추가
    // 2. 마지막 글자 : 추가

    // blank 위치 1,3,5 등 홀수임
    int nBlank = message.length()/2;
    int p=1;
    for(int i=1; i<=nBlank; i++){
        if(i==nBlank)
            message.insert(p,1,':');
        else if(i==nBlank-1) {
            // and 추가
            message.insert(p,1,'d');
            message.insert(p,1,'n');
            message.insert(p, 1, 'a');
            message.insert(p, 1, ' ');

            p +=6;
        }
        else {
            message.insert(p, 1, ',');
            p += 3;
        }
    }
    return message;
}
void solution(string s) {
    bool rule[6] = {false,};
    stringstream ss(s);
    string tmp;
    vector<string> split;
    while (getline(ss, tmp, ' ')) {
        split.push_back(tmp);
    }

    rule[1] = true;
    if (split[split.size() - 1].compare("clap") == 0 && split[split.size() - 2].compare("stomp") == 0 &&
        split[split.size() - 3].compare("clap") == 0)
        rule[2] = true;
    if (find(split.begin(), split.end(), "twirl") != split.end()) {
        if (find(split.begin(), split.end(), "hop") != split.end())
            rule[3] = true;
    } else {
        rule[3] = true;
    }
    if (split[0].compare("jiggle") != 0)
        rule[4] = true;

    for (int i = 0; i < split.size(); i++) {
        if (split[i].compare("dip") == 0) {
            rule[5] = true;
            bool rule1 = false;
            if ((i - 1 >= 0 && split[i - 1].compare("jiggle") == 0) ||
                (i - 2 >= 0 && split[i - 2].compare("jiggle") == 0) ||
                (i + 1 < split.size() && split[i + 1].compare("twirl") == 0)) {
                rule1 = true;
            }
            if(rule1==false) {
                rule[1] = false;
                split[i] = "DIP";
            }
        }
    }
    string errorMessage = "";
    for (int i = 1; i <= 5; i++) {
        if (rule[i] == false) {
            errorMessage += to_string(i) + ' ';
        }
    }

    cout<<"form ";
    if (errorMessage.length() > 0) {
        if(errorMessage.length()>2)
            cout<<"errors ";
        else
            cout<<"error ";
        errorMessage = setForm(errorMessage);
        cout << errorMessage;
    } else {
        cout <<"ok: ";
    }
    for(int i=0; i<split.size(); i++){
        cout<<split[i];
        if(i!=split.size()-1)
            cout<<" ";
    }
    cout<<endl;
}

int main(){
    string s;
    while(getline(cin, s))
        solution(s);
    return 0;
}