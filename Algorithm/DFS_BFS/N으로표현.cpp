#include <iostream>

using namespace std;
int Min = 9;
int _number, unit;
void dfs(int depth, int value){
    if(depth > 8) return;
    if(value == _number){
        Min = depth < Min ? depth : Min;
    }
    int temp = 0;
    for(int i=1;i<=8-depth;i++){
        temp = temp*10 + unit;
        dfs(depth+i, value/temp);
        dfs(depth+i, value*temp);
        dfs(depth+i, value+temp);
        dfs(depth+i, value-temp);
    }
}

int solution(int N, int number) {
    int answer = 0;
    unit = N, _number = number;
    int depth=1,value=0;
    dfs(0,0);
    answer = Min > 8 ? -1 : Min;
    return answer;
}
