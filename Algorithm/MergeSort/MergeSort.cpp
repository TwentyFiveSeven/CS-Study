#include<iostream>
#include<string.h>
using namespace std;

void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

int main(){
  int arr[8] = { 123, 1, 441, 221, 6 ,-3, 16, 110 };
  mergeSort(arr, 0, 7);
  for(int i=0;i<8;i++){
    cout<<arr[i]<<' ';
  }
  return 0;
}

void mergeSort(int arr[], int left, int right) {
  if(left<right){
    int mid = (left + right) /2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
  }
}

void merge(int arr[], int left, int mid, int right){
  int leftArr[8] = {0}, rightArr[8]= {0};
  memcpy(leftArr, arr+left, sizeof(int)*(mid-left+1));
  memcpy(rightArr, arr+mid+1, sizeof(int)*(right-(mid+1)+1));

  int i=0, j=0, k=left;
  int ll=mid-left+1, rl=right-mid;

  while(i < ll && j < rl) {
    if(leftArr[i] <=rightArr[j])
      arr[k] = leftArr[i++];
    else
      arr[k] = rightArr[j++];
    k++;
  }
  while(i < ll)
    arr[k++] = leftArr[i++];
  while(j < rl)
    arr[k++] = rightArr[j++];
}
