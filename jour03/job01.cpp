#include <stdio.h>
#include <ctype.h>

int main(){
    char phrase [] = "vive la plateforme";
    for (int i = 0; phrase[i] != '\0'; i++){
        putchar(toupper(phrase[i]));
    }
    putchar('\n');
    return 0;
}