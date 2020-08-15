#include<iostream>
using namespace std;

void insertionSort(int arr[], int n){
    for(int i=1; i<n; i++){
        int target = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>target){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = target;
    }
}
void printArr(int *arr, int n){
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    int n=7;
    int arr[] = {4,2,5,7,6,1,3};
    printArr(arr, n);

    insertionSort(arr, n);
    printArr(arr, n);

    return 0;
}
