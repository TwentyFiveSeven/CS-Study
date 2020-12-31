#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<string> globalWords;
int check[50], Min = 100, N=0;

int isPossible(string a, string b){
    int count = 0;
    for(int i=0;i<a.size();i++){
        if(a[i] != b[i]) count++;
    }
    if(count == 1) return true;
    return false;
}

void dfs(string begin,string target,int idx,int depth){
    if(begin == target){
        if(depth < Min) Min = depth;
        return;
    }
    check[idx] = 1;
    for(int i=0;i<globalWords.size();i++)
        if(!check[i])
            if(isPossible(begin,globalWords[i]))
                dfs(globalWords[i],target,i,depth+1);

}

int solution(string begin, string target, vector<string> words) {
    int answer = 0, size = words.size();
    globalWords = words;
    for(int i=0;i<size;i++){
        if(isPossible(begin,words[i])){
            dfs(words[i],target, i, 1);
        }
        memset(check, 0, sizeof(check));
    }
    if(Min == 100) return 0;
    answer = Min;
    return answer;
}
