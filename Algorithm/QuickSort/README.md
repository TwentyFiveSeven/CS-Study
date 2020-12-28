# QuickSort(퀵정렬) 정리
## QuickSort란?
- 퀵 정렬은 **불안정** 정렬에 속하고, 비교만으로 정렬을 수행할 수 있는 **비교 정렬**에 속한다.
- 분할 정복 알고리즘의 하나이고, 합병 정렬(Merge Sort)과 달리 비균등하게 리스트를 분할한다.

## 과정 (오름차순)
- 조건 i=0, 배열의크기=n
1. 리스트 안에서 한 요소를 선택한다.(pivot = 첫번째, 중간, 마지막, 랜덤 하게 선택가능하다.)
2. 피벗을 기준으로 정렬한다
  - 피벗보다 작은 원소는 왼쪽
  - 피벗보다 큰 원소는 오른쪽
3. 피벗을 제외한 왼쪽, 오른쪽 리스트를 다시 피벗을 잡아 정렬한다.
4. 더 이상 분할이 불가능할 때까지 반복한다.

## 코드 (C++)
```c
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
```

## 시간복잡도
### 최선의 경우
- 순환 호출의 깊이(logn) * 비교연산(n) = O(nlogn)

### 최악의 경우
- 순환 호출의 깊이(n) * 비교연산(n) = O(n^2)

### 평균의 경우
- O(nlogn)
- 퀵 정렬은 불필요한 데이터의 이동을 중리고, 먼거리의 데이터를 교환할 뿐만 아니라, 한번 결정된 피벗들이 추후 연산에서 제외되는 특성 때문에 ** 다른 정렬 알고리즘과 비교했을 때 가장 빠르다 **

## 장점
- 속도가 빠르다.
- 추가 메모리 공간을 필요로 하지 않는다.

## 단점
- 정렬된 리스트에 대해서는 분균형 분할에 의해 오히려 수행시간이 더 많이 걸린다.
