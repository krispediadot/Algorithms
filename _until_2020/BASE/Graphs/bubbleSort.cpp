#include<iostream>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleSort(int arr[], int n){
    for(int i=n-1; i>0; i--){
        for(int j=0; j<n-1; j++){
            if(arr[j]>arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
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

    bubbleSort(arr, n);
    printArr(arr, n);

    return 0;
}
