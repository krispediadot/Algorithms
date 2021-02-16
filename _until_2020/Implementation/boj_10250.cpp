#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        int H, W, N;
        cin >> H >> W >> N;

        N--;
        int Y = N % H + 1;
        int X = N / H + 1;
        cout << Y;
        if (1 <= X && X<= 9)
            cout << "0" << X << "\n";
        else
            cout << X << "\n";
    }
    return 0;
}
