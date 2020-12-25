#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = skill_trees.size(),depth;
    for(int i=0; i<skill_trees.size();i++){
        depth = -1;
        for(int j=0; j<skill.size();j++){
            int newDepth = skill_trees[i].find(skill[j]);
            if(newDepth == -1){
                depth = -1;
                continue;
            }
            if((j != 0 && depth == -1) || newDepth < depth){
                answer--;
                break;
            }
            depth = newDepth;
        }
    }
    return answer;
}
