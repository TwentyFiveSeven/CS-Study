#include <iostream>
#define DIV 1000000007
using namespace std;

int arr[60000];

int solution(int n) {
    int answer = 0;
    arr[0]=1, arr[1] = 2;
    for(int i=2; i<n;i++){
        arr[i] = (arr[i-1] + arr[i-2])%DIV;
    }
    answer = arr[n-1];
    return answer;
}
