#include<iostream>
#include<string>

using namespace std;

int maxPalindrome(string sub, int max){
    if(sub.length()<max)
        return max;
    int count=0;
    bool palindrome = true;
    if(sub.length()%2==1) count++;
    for(int i=0; i<sub.length()/2; i++){
        if(sub[i]!=sub[sub.length()-1-i]) {
            palindrome = false;
            break;
        }
        count += 2;
    }
    if(palindrome)
        return max>count?max:count;
    return max;
}

int main(){
    string s;cin>>s;
    int max = 0;
    if(s.length()==1) max = 1;
    for(int i=0; i<s.length()-1; i++){
        int len = s.length()-i;
        for(int l=0; l<=len; l++)
            max = maxPalindrome(s.substr(i,l), max);
    }
    cout<<max;
}