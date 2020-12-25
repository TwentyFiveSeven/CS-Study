#include <string>
#include <vector>

using namespace std;

vector<pair<int,int>> V;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    for(int i=0; i< priorities.size();i++){
        V.push_back(make_pair(priorities[i],i));
    }
    while(V.size()){
        int value = V.front().first;
        int idx = V.front().second;
        V.erase(V.begin());
        for(int i=0;i<V.size();i++){
            if(value < V[i].first){
                V.push_back(make_pair(value,idx));
                idx = -1;
                break;
            }
        }
        if(idx == -1) continue;
        answer++;
        if(idx == location)
            break;
    }
    return answer;
}
