#include<iostream>
using namespace std;

void swap(int *a, int *b){
    int *temp = a;
    *a = *b;
    b = temp;
}
int partition(int *A, int p, int r){
    int pivot = A[r];
    int i = p-1;
    for(int j=p; j<r; j++){
        if(A[j]<pivot){
            i+=1;
            swap(A[i], A[j]);
        }
    }
    swap(A[i+1], A[r]);
    return i+1;
}
void quickSort(int *A, int p, int r){
    if(p<r){
        int q = partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}

int main(){
    int arr[9] = {4,2,3,6,7,1,8,9,5};

    quickSort(arr, 0, 8);

    for(int i=0; i<9; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
