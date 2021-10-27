
// 2208 KB,	0ms

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int PATTERN = 666;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;

    int seriesNumber = 0;
    
    int front = 0;
    int frontNoSixEnd = front;
    int back = 0;

    bool isBackTurn = false;
    int cntFrontSix = 0;
    int bacKLimit = 1;
    

    for (int i = 0; i < n; i++) {
        
        if ((front - 6) % 10 == 0 || isBackTurn == true) {

            if (isBackTurn == false) {
                isBackTurn = true;

                frontNoSixEnd = front;

                while ((frontNoSixEnd - 6) % 10 == 0) {
                    cntFrontSix++;
                    bacKLimit *= 10;
                    frontNoSixEnd /= 10;
                }                
            }

            seriesNumber = (frontNoSixEnd * 1000 + PATTERN) * pow(10, cntFrontSix) + back;
            back++;

            if (back == bacKLimit) {
                front++;
                back = 0;

                isBackTurn = false;
                cntFrontSix = 0;
                bacKLimit = 1;
            }
        }
        else {
            seriesNumber = front * 1000 + PATTERN;
            front++;
        }
    }

    cout << seriesNumber << '\n';

    return 0;
}
