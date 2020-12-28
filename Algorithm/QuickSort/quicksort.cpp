#include <iostream>

using namespace std;
void quickSort(int arr[], int left, int right);
int partition(int arr[], int left, int right);
void swap(int arr[], int left, int right);

int main(){
  int arr[8] = {80, 70, 60, 50, 40, 30, 20, 10};
  quickSort(arr, 0, 8-1);

  for(int i=0; i<8 ;i++){
    cout<<arr[i]<<' ';
  }
  cout<<'\n';
  return 0;
}

void quickSort(int arr[], int left, int right){
  if(left < right){
    int pivot = partition(arr, left, right);
    quickSort(arr, left, pivot-1);
    quickSort(arr, pivot+1, right);
  }
}

int partition(int arr[], int left, int right){
  int mid = (left+right)/2;
  swap(arr, left, mid);

  int pivot = arr[left];
  int ll = left, rl = right;
  while(ll < rl){
    while(pivot < arr[rl]){
      rl--;
    }
    while(ll < rl && pivot >= arr[ll]){
      ll++;
    }
    swap(arr, ll, rl);
  }
  arr[left] = arr[ll];
  arr[ll] = pivot;
  return ll;
}

void swap(int arr[], int left, int right){
  int temp = arr[left];
  arr[left] = arr[right];
  arr[right] = temp;
}
