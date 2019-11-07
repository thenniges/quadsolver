#include <stdio.h>

//created as a point of discussion on how to potentially handle logging

int main(int argc, char*argv[]){
    char* arr[3];
    arr[0] = "pass";
    arr[1] = "fail";
    arr[2] = "pass";

    for(int i = 0 ; i < 3; i++){
        printf("%s\n", arr[i]);
    }



    return 1;
}