#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++) cin >> a[i];

    int up = 0;            // 로봇 올리는 위치
    int down = n - 1;      // 로봇 내리는 위치
    int step = 0;          // 단계 수

    while (true) {
        step++;

        // ① 회전
        up = (up - 1 + 2 * n) % (2 * n);
        down = (down - 1 + 2 * n) % (2 * n);

        // 회전 후 내리는 위치에 로봇이 있으면 내림
        if (a[down] >= 1000) a[down] -= 1000;

        // ② 로봇 이동 (뒤에서 앞으로)
        for (int i = 1; i <= n; i++) {
            int cur = (down - i + 2 * n) % (2 * n);
            int next = (cur + 1) % (2 * n);

            // 로봇이 현재 칸에 있고, 다음 칸에 로봇이 없으며, 내구도가 남아있을 때 이동
            if (a[cur] >= 1000 && a[next] < 1000 && a[next] % 1000 > 0) {
                a[cur] -= 1000;   // 현재 칸 로봇 제거
                a[next] += 1000;  // 다음 칸에 로봇 추가
                a[next]--;        // 내구도 감소
            }
        }

        // 이동 후 내리는 위치에 로봇이 있으면 반드시 내림 (💡 핵심 수정 ①)
        if (a[down] >= 1000) a[down] -= 1000;

        // ③ 올리는 위치에 로봇 올리기
        if (a[up] < 1000 && a[up] % 1000 > 0) {
            a[up] += 1000; // 로봇 올리기
            a[up]--;       // 내구도 감소
        }

        // ④ 내구도 0인 칸 개수 세기 (💡 핵심 수정 ②)
        int zeroCnt = 0;
        for (int x : a) {
            if (x % 1000 == 0) zeroCnt++;
        }

        if (zeroCnt >= k) break;
    }

    cout << step;
    return 0;
}