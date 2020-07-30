#include <iostream>
#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    string input;
    int count=0;

    getline(cin,input);

    //cout<<input<<'\n';

    for(int i=0; i<input.length(); i++){
        if(input.at(i) == ' ')
            count++;
    }
    if(input.at(0) == ' ')
        count--;
    if(input.at(input.length()-1) == ' ')
        count--;

    cout<<count+1<<'\n';

    return 0;
}
