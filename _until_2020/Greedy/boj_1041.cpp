#include<iostream>
#include<algorithm>
#define MIN(A,B)(A<B? A:B)

using namespace std;

int main(){
    int arr[6];
    long long N, shape[3], result = 0;
    cin>>N;
    for(int i=0; i<6; i++)
        cin>>arr[i];
    if(N==1){
        sort(arr, arr+6);
        for(int i=0; i<5; i++) result += arr[i];
    }
    else {
        shape[0] = 4 * (N - 1) * (N - 2) + (N - 2) * (N - 2);
        shape[1] = 4 * (N - 1) + 4 * (N - 2);
        shape[2] = 4;

        arr[0] = MIN(arr[0], arr[5]);
        arr[1] = MIN(arr[1], arr[4]);
        arr[2] = MIN(arr[2], arr[3]);
        sort(arr, arr + 3);
        arr[3] = arr[0];
        arr[4] = arr[0] + arr[1];
        arr[5] = arr[0] + arr[1] + arr[2];

        for (int i = 0; i < 3; i++)
            result += shape[i] * arr[i + 3];
    }
    cout<<result<<endl;

    return 0;
}
