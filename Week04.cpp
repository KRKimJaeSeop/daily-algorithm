#include <iostream>
#include <string>
#include <stdio.h>

int input_n;
int input_l;
int input_r;

long long getLength(long long num){
    if(num <= 1) return 1;
    return 2 * getLength(num/2) + 1;
}

long long P768B_Recursion(long long num, long long l, long long r){
    if(l > r) return 0;
    if(num <= 1) return num;
    
    long long leftLen = getLength(num/2);
    long long mid = leftLen + 1;
    long long result = 0;
    
    // 왼쪽
    if(l <= leftLen){
        result += P768B_Recursion(num/2, l, std::min(r, leftLen));
    }
    
    // 가운데
    if(l <= mid && mid <= r){
        result += num % 2;
    }
    
    // 오른쪽
    if(r > mid){
        long long newL = std::max(l, mid+1) - mid;
        long long newR = r - mid;
        result += P768B_Recursion(num/2, newL, newR);
    }
    
    return result;
}

void P768B(){
    std::cin >> input_n >> input_l >> input_r;
    std::cout << P768B_Recursion(input_n, input_l, input_r);
}

int main(){
    P768B();
    return 0;
}