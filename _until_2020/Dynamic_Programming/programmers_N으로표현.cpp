#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

#define MAX_V 8

int solution(int N, int number) {
    int answer = EOF;
    int base = 0;

    unordered_set<int> numbers[MAX_V];

    for(int i=0; i<MAX_V; i++){
        base = base*10 + 1;
        numbers[i].insert(base*N);
    }

    for(int i=1; i<MAX_V; i++){
        for(int j=0; j<i; j++){
            for(auto op1: numbers[j]){
                for(auto op2: numbers[i-j-1]){
                    numbers[i].insert(op1+op2);
                    numbers[i].insert(op1-op2);
                    numbers[i].insert(op1*op2);
                    if(op2!=0) numbers[i].insert(op1/op2);
                }
            }
        }
        if(numbers[i].count(number)>0) {answer = i+1; break;}
    }
    return answer;
}
int main(){
    int n = 5, number = 12;
    cout<<solution(n, number);
}