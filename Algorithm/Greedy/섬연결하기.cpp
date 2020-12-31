#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int linkTable[100];

bool cmp(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

int Find(int num){
    if(linkTable[num] == num)
        return num;
    return linkTable[num] = Find(linkTable[num]);
}

void unionIsland(int a, int b){
    int pa = Find(a);
    int pb = Find(b);
    if(pa < pb)
        linkTable[pb] = pa;
    else
        linkTable[pa] = pb;
}

bool isLinked(int n){
    for(int i=0;i<n;i++)
        if(linkTable[i] != 0)
            return false;
    return true;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0,size = costs.size(),first,second,cost;
    sort(costs.begin(), costs.end(), cmp);
    for(int i=0;i<n;i++)
        linkTable[i] =i;
    for(int i=0;i<size;i++){
        first = costs[i][0];
        second = costs[i][1];
        cost = costs[i][2];
        if(Find(first) == Find(second)) continue;
        unionIsland(first, second);
        answer += cost;
        if(isLinked(n)) break;

    }
    return answer;
}
