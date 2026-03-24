
#include <iostream>
#include <string>
#include <stdio.h>

/*
수가 들어온다.
수가 1보다 크다면, 그 수를 2로 나눈다.
홀수라면 가운데 1이 남고, 짝수라면 가운에 0이다.
*/

int P768B_Recursion(int devidedNum){
    std::cout<<"devidedNum is"<<devidedNum<<"\n";
    
    return 0;
}

void P768B(){
    int inputNum;
    std::cin>>inputNum;

    if(inputNum<=1){
        std::cout<<"lower than 2\n";
        return;
    }

    P768B_Recursion(inputNum/2);
    P768B_Recursion(inputNum%2);
    P768B_Recursion(inputNum/2);
}



int main(){
    P768B();
    return 0;
}


