#include<iostream>
#include<algorithm>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    int len = 0;
    int house_cost[1000][3];
    int result[1000][3];
 
    cin>>len;
    for (int idx = 0; idx < len; idx++) {
        int r, g, b;
        cin>>r>>g>>b;
        house_cost[idx][0] = r;
        house_cost[idx][1] = g;
        house_cost[idx][2] = b;
    }
 
    result[0][0] = house_cost[0][0];
    result[0][1] = house_cost[0][1];
    result[0][2] = house_cost[0][2];
 
    for (int idx = 1; idx < len; idx++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (col == 0) {  
                result[idx][col] = house_cost[idx][col] + min(result[idx - 1][1], result[idx - 1][2]);
            }
            else if (col == 1) { 
                result[idx][col] = house_cost[idx][col] + min(result[idx - 1][0], result[idx - 1][2]);
            }
            else if (col == 2) { 
                result[idx][col] = house_cost[idx][col] + min(result[idx - 1][0], result[idx - 1][1]);
            }
        }
    }
 
    int answer = result[len - 1][0] < result[len - 1][1] ? min(result[len - 1][0], result[len - 1][2]) : min(result[len - 1][1], result[len - 1][2]);
    cout<<answer;
 
    return 0;
}
