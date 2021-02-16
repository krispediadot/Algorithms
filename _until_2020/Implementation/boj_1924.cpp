#include <iostream>
#include <string>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	int x, y;
	int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	string days[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
	int days_gap=0, days_index;

	cin>>x>>y;
	// 1월 1일과 입력 달 이전 까지 날짜 구하기
	for(int i=0; i<x-1; i++) 
		days_gap += months[i];
	// 달 사이 날짜에 입력 날 추가하
	days_gap += y;
	// 1월 1일 시작이니 1 빼기
	days_gap -= 1;
	//1주일은 7일이니 7로 나눈 나머지 구하기
	days_index = days_gap%7;
	
	cout<<days[days_index]<<endl;

	return 0;
}

