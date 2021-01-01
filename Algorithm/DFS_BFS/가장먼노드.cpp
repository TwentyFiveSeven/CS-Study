#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
int edges[20001][20001];
int check[20001],N;

vector<int> list;
queue<pair<int,int>> Q;
void bfs(){
    while(!Q.empty()){
        int node = Q.front().first;
        int count = Q.front().second;
        Q.pop();
        list.push_back(count);
        for(int i=1; i<=N;i++){
            if(!check[i] && edges[node][i]){
                check[i] = 1;
                Q.push(make_pair(i,count+1));
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0,first, second;
    N = n;
    for(int i=0 ;i<edge.size();i++){
        first = edge[i][0];
        second = edge[i][1];
        edges[first][second] = 1;
        edges[second][first] = 1;
    }
    Q.push(make_pair(1,0));
    check[1] =1;
    bfs();
    int Max = list.back();
    for(int i=0;i<list.size();i++){
        if(list[i] == Max) answer++;
    }
    return answer;
}
