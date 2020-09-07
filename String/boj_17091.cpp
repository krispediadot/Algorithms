#include<iostream>
#include<string>

using namespace std;

string H[] = {"one",
              "two",
              "three",
              "four",
              "five",
              "six",
              "seven",
              "eight",
              "nine",
              "ten",
              "eleven",
              "twelve"
};
string M[] = {"one",
              "two",
              "three",
              "four",
              "five",
              "six",
              "seven",
              "eight",
              "nine",
              "ten",
              "eleven",
              "twelve",
              "thirteen",
              "fourteen",
              "quarter",
              "sixteen",
              "seventeen",
              "eighteen",
              "nineteen",
              "twenty",
              "twenty one",
              "twenty two",
              "twenty three",
              "twenty four",
              "twenty five",
              "twenty six",
              "twenty seven",
              "twenty eight",
              "twenty nine",
              "half"
};
int h,m;

void getInput(){
    cin>>h>>m;
}
void solution(){
    bool over30 = m>30?true:false;
    string op = m>30?"to":"past";
    if(over30) h +=1;
    if(h>12) h %= 12;
    if(over30) m = 60-m;

    if(m==0)
        cout<<H[h-1]<<" o' clock";
    else{
        if(m==1)
            cout<<M[m-1]<<" minute "<<op<<" "<<H[h-1];
        else if(m==15)
            cout<<M[m-1]<<" "<<op<<" "<<H[h-1];
        else if(m==30)
            cout<<M[m-1]<<" "<<op<<" "<<H[h-1];
        else
            cout<<M[m-1]<<" minutes "<<op<<" "<<H[h-1];
    }
    cout<<endl;
}

void test(){
    for(h=1; h<=12; h++){
        for(m=0; m<=60; m++){
            cout<<"["<<h<<":"<<m<<"] ";
            solution();
        }
    }
}

int main(){
    getInput();
    solution();

    //test();

    return 0;
}