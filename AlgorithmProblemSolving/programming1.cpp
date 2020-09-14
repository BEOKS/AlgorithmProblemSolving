#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    int size = new_id.size();
    //1
    for (int i = 0; i < size; i++) {
        new_id[i] = tolower(new_id[0]);
    }
    //2
    for (int i = 0; i < size; i++) {
        if(new_id[i]!='.'&&
            new_id[i] != '-'&&
            new_id[i] != '_'&&
            !isalpha(new_id[i])&&
            !isdigit(new_id[i])) {
            new_id.erase(i);
        }
    }
    //3
    return new_id;
}