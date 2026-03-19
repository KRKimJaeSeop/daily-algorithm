#include <iostream>
#include <stdio.h>
using namespace std;



void P734B(){
    /*
        2,3,5,6을 입력받는다. 그것들로 숫자를 만들고, 
        256을 만들면 256점을 얻는다.
        32를 만들면 32점을 얻는다.

        vector 랑 list 랑 비슷하다.

    */
    int k2,k3,k5,k6;
    cin>>k2>>k3>>k5>>k6;
    
    int score = 0;
    while(k2>0&&
            k5>0&&
            k6>0){
        k2--;
        k5--;
        k6--;
        score+=256;
    }
    while(k3>0
            &&k2>0){
        k3--;
        k2--;
        score+=32;
    }
    
    cout<<score;
}

void P158B(){
    /*
    택시 한대에는 최대 4명이 탈 수 있다.
    모든 그룹원은 흩어질수없다. 꼭 같은 그룹끼리 타야한다.
    각각의 그룹에는 1명부터 4명까지 멤버가 있다.
    한 택시에는 여러 그룹이 탈 수 있다.
    몇 대의 택시가 필요할까?
    */
   int group_n = 0;
   cin >> group_n;
   
   vector<int> group;
   int taxi_n=0;

   for (int i = 0; i < group_n; i++)
   {
        int member_n = 0;
        cin>> member_n;
        group.push_back(member_n);
   }

   

}


int main(){
   // P734B();
    P158B();
    return 0;
    
}