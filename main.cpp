#include <iostream>
#include <string.h>
#define MAXSIZE 255

using namespace std;

void delete_middle_element(char *s, int length, int k) {

    for(int i = 0; i <= length; ++i) {
        if (i >= k) s[i] = s[i + 1];
    }
    s[length + 1] = 0;
}
int check_(char s){
    char symbol[4] = {'.', ',', '!', '?'};
    for(int i = 0; i < 4; ++i){
        if(symbol[i] == s) return 1;
    }
    return 0;
}


void problem1(){
    char* str = (char *) malloc(sizeof(char) * MAXSIZE);
    printf("Введите строку:\n");
    fgets(str, MAXSIZE, stdin);

    int size = strlen(str) - 2;
    int i = 0;
    while(i <= size){
        if(i == 0 && str[i] == ' ') {
            memmove(str, str+1, size);
            str[size] = 0;     //Удаление пробелов в начале
            size--;
        }
        else if( i != 0 && check_(str[i + 1]) && str[i] == ' '){
            delete_middle_element(str, size, i);
            size--;
        }
        else if(i != 0 && str[i] == ' ' && str[i + 1] == ' '){
            delete_middle_element(str, size, i);
            size--;

        }
        else i++;
    }
    fputs(str, stdout);
}






int main() {
    printf("TASK10.1\n");
    problem1();
    return 0;
}
