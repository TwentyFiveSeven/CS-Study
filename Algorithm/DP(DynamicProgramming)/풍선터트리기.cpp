#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> a) {
    int size = a.size();
    int answer = 2, l = 0, r = size-1;
    for(int i=1;i<size-1;i++){
        if(a[i] < a[l]){
            answer++;
            l = i;
        }

        if(a[size-1-i] < a[r]){
            answer++;
            r = size-1-i;
        }
    }
    if(l == r) answer--;
    return answer;
}
