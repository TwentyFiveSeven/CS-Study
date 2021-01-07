#include <iostream>
#include <string>
#include <set>

using namespace std;

set<char> Set;

string parsing(string sentence);
string removeSymbol(string sentence, char c);
bool isLowerCase(char c);
int findLast(string s, char c);
int hasLowerCase(string s);
int isFirst(string s,int start);

string solution(string sentence) {
    string answer = "";
    answer = parsing(sentence);
    return answer;
}

int main(){
  string answer = solution("AxAxAxAoBoBoB");
  cout<< answer;
  return 0;
}

string parsing(string sentence){
  cout<<sentence<<'\n';
    int start = hasLowerCase(sentence);
    if(start == -1)
        return "sentence";

    int cut = start-1;
    int end = findLast(sentence, sentence[start])+1;
    if(end == -1) return "invalid";
    int firstFlag = isFirst(sentence, start);
    cout<<"firstflag: "<<firstFlag<<'\n';
    if(firstFlag == -1) return "invalid";
    if(!firstFlag) cut = start,end = end-1;

    string upper = sentence.substr(0, cut);
    if(upper != "") upper += ' ';
    string middle = removeSymbol(sentence.substr(cut, end-cut+1),sentence[start]);
    cout<<upper<<' '<<middle<<' '<<'\n';
    string last = parsing(sentence.substr(end+1));
    if(last != "") middle += ' ';
    if(last == "invalid") return "invalid";
    return upper + middle + last;
}

int isFirst(string s,int start){
    int count = 1, saveIdx= start;
    char c = s[start];
    for(int i=start+1; i<s.size();i++){
        if(s[i] == c){
            count++;
            if(count >2){
                if(i - saveIdx > 2)
                    return -1;
            }
            saveIdx = i;
        }
    }
    if(count == 2) return 0;
    if(start == 0) return -1;
    return 1;
}

int hasLowerCase(string s){
    for(int i=0; i<s.size();i++){
        if(isLowerCase(s[i]))
            return i;
    }
    return -1;
}

string removeSymbol(string sentence, char c){
    string ret = "";
    for(int i=0;i<sentence.size();i++){
        if(sentence[i] != c)
            ret += sentence[i];
    }
    return ret;
}

bool isLowerCase(char c){
    if(c >= 97 && c <= 122) return true;
    return false;
}

int findLast(string s, char c){
    if(Set.count(c)) return -1;
    Set.insert(c);
    for(int i=s.size(); i>=0;i--){
        if(s[i] == c)
            return i;
    }
    return -1;
}
