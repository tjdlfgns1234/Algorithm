#include <stdio.h>
#include <string.h>


int main() {
    // 여기에 코드를 작성해주세요.

    char str[100];
    //scanf("%[^\n]", str);
    fgets(str, 100,stdin);

    for(int i=2;i<10;i++){
        printf("%c", str[i]); //얘 왜 %s로 하면 안되나요???
    }    
    return 0;
}