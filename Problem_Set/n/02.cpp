// 02 restore

#include <iostream>
#include <vector>
using namespace std;

struct Time{
    int month;
    int day;
    int hour;
    int minute;
    int second;
    Time(int month, int day, int hour, int minute, int second)\
    :month(month), day(day), hour(hour), minute(minute), second(second){}
    void print() {
        cout<<month<<"/"<<day<<" "<<hour<<":"<<minute<<":"<<second<<" ";
    }
};
struct Customer{
    Time time;
    Time done;
    int need;
    int line;
    Customer(int month, int day, int hour, int minute, int second, int need)\
    :time(month, day, hour, minute, second), done(0,0,0,0,0), need(need), line(-1){}
    void print(){
        cout<<"[Customer] "<<endl;
        this->time.print();
        cout<<endl;
        this->done.print();
        cout<<endl;
    }
};
int days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
vector<vector<Customer>> kiosks;
int nKiosk, nCustomer;

Time timeAdd(Time t1, int plusminute){
    t1.minute += plusminute;
    if(t1.minute>60){
        t1.hour+=(t1.minute/60);
        t1.minute-=(t1.minute/60)*60;
        if(t1.hour>=24) {
            t1.day+=(t1.hour/24);
            t1.hour -= (t1.hour/24)*24;
            while (t1.day > days[t1.month]) {
                t1.day-=days[t1.month];
                t1.month++;
                if (t1.month > 12)
                    t1.month %= 12;
            }
        }
    }
    return t1;
}
bool compareMinTime(Time t1, Time t2){
    // t1<t2 이면 true, 아니면 false
    if(t1.month<t2.month) return true;
    else if(t1.month == t2.month){
        if(t1.day<t2.day) return true;
        else if(t1.day==t2.day){
            if(t1.hour<t2.hour) return true;
            else if(t1.hour==t2.hour) {
                if (t1.minute < t2.minute) return true;
                else if(t1.minute==t2.minute) {
                    if (t1.second <= t2.second) return true;
                    else return false;
                } else return false;
            } else return false;
        } else return false;
    } else return false;
}
Customer getCustomerInput(){
    string in; getline(cin,in);
    int month = stoi(in.substr(0,2));
    int day = stoi(in.substr(3,2));
    int hour = stoi(in.substr(6,2));
    int minute = stoi(in.substr(9,2));
    int second = stoi(in.substr(12,2));
    int need = stoi(in.substr(15,2));
    Customer newbie(month, day, hour, minute, second, need);
    newbie.done = timeAdd(newbie.time, newbie.need);
    return newbie;
}
void putInLine(Customer c){
    vector<int> ableLine;
    int targetLine = -1;
    // 0. 쉬고 있는 키오스크 확인
    for(int idx=0; idx<nKiosk; idx++){
        // 0-1. 키오스크 대기줄 마지막 고객의 시작시간+이용시간 < 새로운 고객이 들어온 시간이면 이용 가능
        if(kiosks[idx].size()==0 || compareMinTime(kiosks[idx].back().done, c.time))
            ableLine.push_back(idx);
    }
    // 1. (쉬고있는 키오스크가 있는 경우) 가장 오래 쉰 키오스크
    if(ableLine.size()>0){
        targetLine = ableLine[0];
        for(int idx=1; idx<ableLine.size(); idx++){
            if(kiosks[targetLine].size()==0) break;
            if(kiosks[ableLine[idx]].size()==0) {targetLine = ableLine[idx]; break;}
            if(kiosks[ableLine[idx]].size()>0 && compareMinTime(kiosks[ableLine[idx]].back().done, kiosks[targetLine].back().done))
                targetLine = ableLine[idx];
        }
    }
    // 2. (쉬고있는 키오스크가 없는 경우) 일찍 끝나는 키오스크
    else{
        targetLine = 0;
        for(int idx=1; idx<nKiosk; idx++){
            if(compareMinTime(kiosks[idx].back().done, kiosks[targetLine].back().done))
                targetLine = idx;
        }
    }
    c.line = targetLine;
    kiosks[targetLine].push_back(c);
}
void printLines(){
    for(int idx=0; idx<nKiosk; idx++){
        cout<<"====== "<<idx<<" Kiosk========"<<endl;
        for(int i=0; i<kiosks[idx].size(); i++){
            kiosks[idx][i].print();
        }
    }
}
void doWork(){
    // 1. 기본 정보 입력 받기
    cin>>nKiosk;
    for(int idx=0; idx<nKiosk; idx++) {
        vector<Customer> temp;
        kiosks.push_back(temp);
    }
    // 2. 고객 정보 입력 받기
    cin>>nCustomer; cin.ignore();
    for(int idx=0; idx<nCustomer; idx++) {
        Customer newbie = getCustomerInput();
        // 3. 규칙에 따라 고객 줄 세우기
        putInLine(newbie);
        //printLines();
    }
}
int getBestKiosk(){
    int max = kiosks[0].size();
    for(int idx=1; idx<nKiosk; idx++){
        if(kiosks[idx].size()>max)
            max = kiosks[idx].size();
    }
    return max;
}
int main(){
    doWork();
    printLines();
    cout<<getBestKiosk();

    return 0;
}

