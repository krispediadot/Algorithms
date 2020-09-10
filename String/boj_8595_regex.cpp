#include<iostream>
#include<string>
#include<regex>

using namespace std;

int main(){
    int n; cin>>n;
    string s; cin>>s;
    regex re("[0-9]+");
    smatch match;

    auto start = sregex_iterator(s.begin(), s.end(), re);
    auto end = sregex_iterator();

    long long sum=0;
    while(start != end){
        //cout<<start->str()<<endl;
        sum += stoi(start->str());
        ++start;
    }
    cout<<sum<<endl;
}