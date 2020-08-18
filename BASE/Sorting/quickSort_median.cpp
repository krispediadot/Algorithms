#include<iostream>
using namespace std;

void swap(int *a, int *b){
    int *temp = a;
    *a = *b;
    b = temp;
}
int getMedianValueIndex(int *A, int begin, int middle, int end){
   if((A[middle]<=A[begin]&&A[begin]<=A[end])||(A[end]<=A[begin]&&A[begin]<=A[middle]))
       return begin;
    if((A[begin]<=A[middle]&&A[middle]<=A[end])||(A[end]<=A[middle]&&A[middle]<=A[begin]))
        return middle;
    if((A[begin]<=A[end]&&A[end]<=A[middle])||(A[middle]<=A[end]&&A[end]<=A[begin]))
        return end;
}
int partition(int *A, int p, int r){
    int pivotIndex = getMedianValueIndex(A, p, int((p+r)/2), r);
    swap(A[pivotIndex], A[r]);

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
