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

    long long answer = 0;
    std::queue<int> q;
    std::cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int push = 0;
        std::cin >> push;

        // 작업을 추가한다.
        q.push(push);
    }

    int i = q.front();
    answer = i - 1;
    // 작업이 남아있는동안 반복한다.
    while (!q.empty())
    {

        while (i == q.front())
        {
            q.pop();
        }

        if (q.empty())
            continue;

        // 이제 한걸음씩 가는게 아닌, 다음꺼까지 남은걸 계산해서 한번에 넘기기.
        // 이번업무과 다음업무 사이의 dStep임.
        long long dStep = q.front() - i;
        if (dStep < 0)
            dStep = n + dStep;

        // 한걸음 이동했음
        answer += dStep;
        i += dStep;
        if (i > n)
        {
            i -= n;
        }
    }
    std::cout << answer;
}

// 정중앙으로 이동하기위한 최소 이동 횟수
void P263A()
{

    // 25번 입력받고,
    int row_i = -1;
    int col_i = -1;

    int step = 0;

    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col < 5; col++)
        {
            int input = 0;
            std::cin >> input;
            if (input == 1)
            {
                row_i = row;
                col_i = col;
            }
        }
    }

    step = abs(row_i - 2);
    step += abs(col_i - 2);

    std::cout << step;
}

/*
5              ← 더미 개수 n
2 7 3 4 9      ← 각 더미의 벌레 수 n개
3              ← 쿼리 개수 m
1 15 19        ← 질문할 벌레 번호 m개
*/
void P474B()
{
    // 더미개수
    int dummy_n = 0;
    // 더미별 벌레 수 입력받기
    std::cin >> dummy_n;

    int dummies[dummy_n];

    int sum[dummy_n];
    for (int i = 0; i < dummy_n; i++)
    {
        sum[i] = 0;
        // 더미 입력받기
        std::cin >> dummies[i];

        // 누적 합 계산
        if (i == 0)
            sum[i] = dummies[i];
        else
            sum[i] = sum[i - 1] + dummies[i];
    }

    // 쿼리 개수
    int query_n = 0;
    std::cin >> query_n;

    // 질문할 벌레 번호 입력받기
    int queries[query_n];

    for (int i = 0; i < query_n; i++)
    {
        std::cin >> queries[i];
    }

    // 질문할 벌레 번호 에 대해서, 해당 벌레가 몇번째 더미에 있는지 계산하기.
    for (int i = 0; i < query_n; i++)
    {

        // for (int j = 0; j < dummy_n; j++)
        // {
        //     if (sum[j] >= queries[i])
        //     {
        //         std::cout << j + 1<<"\n";
        //         break;
        //     }
        // }
        auto it = std::lower_bound(sum, sum + dummy_n, queries[i]);
        int idx = it - sum;
        std::cout << idx + 1 << "\n";
    }
}

// 길이가 l , 가로등 수가 n.
// 가로등의 위치가 정해져 있을 때, 전체를 밝히려면 갖춰야하는 최소 밝기
void P492B()
{
    // n,l입력 받기
    long long n = 0;
    long long l = 0;
    std::cin >> n >> l;

    long long lamps[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> lamps[i];
    }
    std::sort(lamps, lamps + n);

    double diff = 0;
    for (int i = 0; i < n; i++)
    {
        double currentDiff = 0;
        if (i == 0)
            currentDiff = lamps[0];
        else
            currentDiff = (lamps[i] - lamps[i - 1]) / 2.0;

        if (i == n - 1)
            diff = std::max(diff, (double)(l - lamps[n - 1]));

        if (currentDiff > diff)
            diff = currentDiff;
    }

    printf("%.10f\n", diff);
}

// n개의 팀 참가
// 색의 종류가 홈 x_i , 어웨이 y_i
// void P432B()
// {
//     int n = 0;
//     std::cin >> n;

//     // n번째 팀의 홈킷 색깔
//     int home[n];
//     // n번째 팀의 어웨이킷 색깔
//     int away[n];

//     // n팀의 홈입은 횟수, 어웨이 입은 횟수
//     int ansewr_home[n];
//     int answer_away[n];

//     std::string answer = "";

//     for (int i = 0; i < n; i++)
//     {
//         std::cin >> home[i] >> away[i];
//         ansewr_home[i] = 0;
//         answer_away[i] = 0;
//     }
//     // 입력 끝. 모든팀이 서로 경기를 치른다. 이중포문?
//     // 만약 홈과 어웨이의 색이 같다면 어웨이도 홈을 입는다.
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             // std::cout << i << "팀과" << j << "팀의 경기" << "\n";

//             ansewr_home[i]++;
//             ansewr_home[j]++;

//             if (away[i] == home[j])
//             {
//                 ansewr_home[i]++;
//             }
//             else
//             {
//                 answer_away[i]++;
//             }

//             if (away[j] == home[i])
//             {
//                 ansewr_home[j]++;
//             }
//             else
//             {
//                 answer_away[j]++;
//             }
//         }
//         answer += std::to_string(ansewr_home[i]);
//         answer += ' ';
//         answer += (std::to_string(answer_away[i]) + "\n");
//     }

//        std::cout << answer;
// }
void P432B()
{
    int n = 0;
    std::cin >> n;

    int home[n];
    int away[n];
    int ansewr_home[n];
    int answer_away[n];
    int homeCount[100001] = {0};

    for (int i = 0; i < n; i++)
    {
        std::cin >> home[i] >> away[i];
        ansewr_home[i] = 0;
        answer_away[i] = 0;
        homeCount[home[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        // 홈 경기: n-1번 (나머지 모든 팀과)
        ansewr_home[i] += (n - 1);

        // 어웨이 경기: 상대 홈색이 내 어웨이색과 같으면 홈킷, 아니면 어웨이킷
        int conflict = homeCount[away[i]];
        // 단, 내 홈색과 내 어웨이색이 같은 경우는 없으므로 자기 자신은 제외 불필요
        ansewr_home[i] += conflict;
        answer_away[i] += (n - 1 - conflict);
    }

    for (int i = 0; i < n; i++)
        std::cout << ansewr_home[i] << " " << answer_away[i] << "\n";
}

int main()
{
    P432B();
    return 0;
}