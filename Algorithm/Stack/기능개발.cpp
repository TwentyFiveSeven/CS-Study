#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer, restWork;
    for(int i=0; i<progresses.size();i++){
        int restDay = 100 - progresses[i];
        restDay = restDay/speeds[i] + (restDay%speeds[i] != 0 ? 1: 0);
        restWork.push_back(restDay);
    }
    int Max = -1,count=0;
    for(int i=0; i<restWork.size();i++){
        if(restWork[i] > Max){
            answer.push_back(count);
            Max = restWork[i];
            count=0;
        }
        count++;
    }
    answer.push_back(count);
    answer.erase(answer.begin());
    return answer;
}
