#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>

/*
n명의 참가자 중,
k등의 점수보다 크고, 양수인 참가자가 다음라운드 진출.
다음라운드 진출하는 참가자의 수은?


*/
void P158A()
{
    int n = 0;
    int k = 0;
    std::cin >> n >> k;
    int answer = 0;
    int members[n];

    for (int i = 0; i < n; i++)
    {
        std::cin >> members[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (members[i] >= members[k-1] && members[i] > 0)
        {
            answer++;
        }

    }
    std::cout << answer;
}

int main()
{
    // std::cout << "======MayWeek01======" << "\n";
    P158A();
    return 0;
}