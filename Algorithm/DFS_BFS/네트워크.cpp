#include <string>
#include <vector>

using namespace std;
int check[200];
vector<vector<int>> computer;

void dfs(int start, int n){
    check[start] = 1;
    for(int i=0; i<n;i++){
        if(check[i] != 1 && computer[start][i])
            dfs(i, n);
    }
}

int solution(int n, vector<vector<int>> computers) {
    computer = computers;
    int answer = 0;
    for(int i=0;i<n;i++){
        computers[i][i] = 0;
    }

    for(int i=0; i<n;i++){
        if(check[i] != 1){
            dfs(i,n);
            answer++;
        }
    }

    return answer;
}
