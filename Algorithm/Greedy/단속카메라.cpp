#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(vector<int> a, vector<int> b){
    return a[0] < b[0];
}

bool isContain(int start, int end, int value){
    if(value >= start && value <= end) return true;
    return false;
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end(), cmp);
    while(!routes.empty()){
        int start = routes.back()[0];
        int end = routes.back()[1];
        routes.pop_back();
        while(!routes.empty() && isContain(routes.back()[0],routes.back()[1],start)){
            routes.pop_back();
        }
        answer++;
    }
    return answer;
}
