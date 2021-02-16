#include<iostream>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selectionSort(int arr[], int n){
    for(int index=n-1; index>0; index--){
         int maxIndex = index;
         for(int i=0; i<index; i++){
             if(arr[i]>arr[maxIndex])
                 maxIndex = i;
         }
         swap(&arr[index], &arr[maxIndex]);
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

    selectionSort(arr, n);
    printArr(arr, n);

    return 0;
}
