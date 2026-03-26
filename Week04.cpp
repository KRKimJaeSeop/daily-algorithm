
#include <iostream>
#include <string>
#include <stdio.h>


std::string output="";
int input_n;
int input_l;
int input_r;



void P768B_Recursion(long long num){
    //여기가 재귀의 마지막 줄
    if(num<=1){
        output+=std::to_string(num);
        return;
    }
    /*
        필요없는 부분이라면 버린다.
        이 다음줄이 재귀의 마지막 줄
    */
    if((num/2)<=1){
        
    }

    //나눠진 수로 각각 실행.
    P768B_Recursion(num/2);
    P768B_Recursion(num%2);
    P768B_Recursion(num/2);
}

void P768B(){
    std::cin>>input_n>>input_l>>input_r;
        
    P768B_Recursion(input_n);
    int score = 0;
    for (int i = input_l-1; i <= input_r-1; i++)
    {
        if(output[i]=='1'){
            score++;
        }
    }
    std::cout<<score;
}


int main(){
    P768B();
    return 0;
}


