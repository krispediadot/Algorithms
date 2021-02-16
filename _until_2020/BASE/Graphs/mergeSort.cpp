#include<iostream>
using namespace std;

void merge(int arr[], int begin, int q, int end){
    int a[end];
    int i=begin, j=q+1, k=begin;

    while(i<=q && j<=end){
        if(arr[i]<=arr[j])
            a[k++] = arr[i++];
        else
            a[k++] = arr[j++];
    }
    int tmp = i>q? j:i;
    while(k<=end)
        a[k++] = arr[tmp++];
    for(int i=begin; i<=end; i++)
        arr[i] = a[i];
}
void mergeSort(int arr[], int begin, int end){
    if(begin < end){
        int q = (begin+end)/2;
        mergeSort(arr, begin, q);
        mergeSort(arr, q+1, end);
        merge(arr, begin, q, end);
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

    mergeSort(arr, 0, n-1);
    printArr(arr, n);

    return 0;
}
