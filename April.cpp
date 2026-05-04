#include <iostream>
#include <string>
#include <stdio.h>

/*
내일 생물시험이 있음. d일전에 시험이 있다는걸 암. 매일 공부해야했음
i번째 날에는 최소 min_i시간 이상, 최대max_i시간 이하로 공부
공부시간의 합 sum만 기억. 부모님의 조건을 만족하면서
d일간의 공부시간의 합이 sum이 맞도록 되는 시간표를 만드는게 가능한지??

입력
첫째줄에 정수d와 sum에 대해.
다음줄은 공부시간을 d개만큼 공백으로 출력
*/
void P4B()
{

    int numD = 0;
    int sumT = 0;
    std::cin >> numD >> sumT;

    int minT[numD], maxT[numD];

    int minSum = 0;
    int maxSum = 0;

    for (int i = 0; i < numD; i++)
    {
        std::cin >> minT[i];
        minSum += minT[i];

        std::cin >> maxT[i];
        maxSum += maxT[i];
    }
    // 최소 i시간만큼, 최대i시간만큼 공부해서 합친게 sum이 맞는지?
    // min max는 부모님의 요구사항, sum은 피터의 요구사항.
    if (minSum <= sumT && sumT <= maxSum)
    {
        std::cout << "YES" << "\n";
        // 반복돌면서
        for (int i = 0; i < numD; i++)
        {
            int add = std::min(maxT[i] - minT[i], sumT - minSum);
            minSum -= minT[i];
            int todayT = minT[i] + add;
            sumT -= todayT;
            std::cout << todayT << " ";
        }
    }
    else
    {
        std::cout << "NO";
    }
}

int main()
{
    P4B();
    return 0;
}