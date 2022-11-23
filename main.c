#include <stdio.h>
#include <string.h>
#include <sys/random.h>

int min(int a, int b){
    return a < b ? a : b;
}

int getRandomNumber(void){
    int rnd = 'A';
    getrandom(&rnd, 1, GRND_RANDOM);
    return (rnd);
}

int randomStringGenerator(char * res, int s){
    const char charset[] = "0123456789abcdefghijklmnopqrstuvxywzABCDEFGHIJKLMNOPQRSTUVXYWZ/-+*()<>[]{}\\!@#$%&*_-=";

    const int passwdSize = 12;
    int i = 0;
    while(i < min(passwdSize, s)){
        int a = getRandomNumber();
        if((a != '\0') && (NULL != strchr(charset, a))){
            strncat(res, (char*)&a, 1);
            i++;
        }
    }
    return (0);
}

int main(){
    for(int i = 0; i < 100; i++){
        char value[100] = "";
        randomStringGenerator(value, sizeof(value));
        printf("%s\n", value);
    }
    return 0;
}
