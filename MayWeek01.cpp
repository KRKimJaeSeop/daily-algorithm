#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <queue>

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
        if (members[i] >= members[k - 1] && members[i] > 0)
        {
            answer++;
        }
    }
    std::cout << answer;
}

/*
원형 도로에 시계방향으로 1번부터 n번까지 배치됨.
1번에서 시작해서 m개의 할일.i번째 할일은 반드시 i번째 집에서 완료.
집에서 집으로 이동할때에는 1시간이 걸린다.
*/
void P339B()
{
    int n = 0;
    int m = 0;

    int answer = 0;
    std::queue<int> q;
    std::cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int push = 0;
        std::cin >> push;

        // 작업을 추가한다.
        q.push(push);
    }

    int i = 1;
    // 작업이 남아있는동안 반복한다.
    while (!q.empty())
    {

        while (i == q.front())
        {
            q.pop();
        }

        if (q.empty())
            continue;

        // 한걸음 이동했음
        answer++;
        i++;
        if (i > n)
            i = 1;
    }
    std::cout << answer;
}

int main()
{
    //std::cout << "======MayWeek01======" << "\n";
    P339B();
    return 0;
}