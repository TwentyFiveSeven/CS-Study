#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
vector<pair<int,int>> temp;

bool cmp(vector<int> a, vector<int> b){
    return a[0] > b[0];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0, time=0, average=0, n = jobs.size();
    sort(jobs.begin(),jobs.end(),cmp);

    while(!pq.empty() || !jobs.empty()){
        while((!jobs.empty()&&(jobs.back())[0] <= time) || pq.empty()){
            pq.push(make_pair((jobs.back())[1],(jobs.back())[0]));
            jobs.pop_back();
        }
        int start = pq.top().second;
        int workTime = pq.top().first;
        pq.pop();
        time = (start >= time ? start: time) + workTime;
        average += time - start;
    }
    answer = average/n;
    return answer;
}
