#include <deque>
#include <iostream>

using namespace std;

struct info {
    int power;//내구도
    bool is_on;// 로봇 존재 여부
};

// 벨트를 한 칸 회전
void rotateBelt(deque<info> &belt, int n) {
    belt.push_front(belt.back());//뒤에 있던 것을 앞으로 이동
    belt.pop_back();
    belt[n - 1].is_on = false; // 로봇이 내리는 위치,1번부터 구현하므로 n-1
}

// 로봇을 움직일 수 있으면 한 칸 이동
void moveRobot(deque<info> &belt, int n) {
    for (int i = n - 2; i >= 0; i--) {//n-1번칸은 내리는 위치므로 n-2부터 0번까지
        if (!belt[i].is_on) {//로봇이 없으면 pass
            continue;
        }

        if (!belt[i + 1].is_on && (belt[i + 1].power >= 1)) {
            // 다음 칸에 로봇이 없으면서 다음 칸에 내구도가 남아있을 때
            belt[i].is_on = false;
            belt[i + 1].is_on = true;
            belt[i + 1].power--;//도착했으므로 내구도가 줄어듦
        }

        belt[n - 1].is_on = false; // 로봇이 내리는 위치
    }
}

// 올리는 칸에 로봇을 올릴 수 있으면 올림
void putRobot(deque<info> &belt) {
    if (!belt[0].is_on && belt[0].power >= 1) {
        // 올리는 칸에 로봇이 존재하지 않고, 내구도가 남아있으면
        belt[0].is_on = true;
        belt[0].power--;//내구도가 줄어듦
    }
}

// 벨트의 내구도 체크
bool checkFinish(deque<info> &belt, int n, int k) {
    int count = 0;

    for (int i = 0; i < 2 * n; i++) {
        if (belt[i].power == 0) {
            count++;//모든 칸을 순회하면서 count
        }
    }

    return count >= k;
}

int solution(deque<info> &belt, int n, int k) {
    int step = 1;//1번째부터 count
    while (true) {
        // 1. 회전
        rotateBelt(belt, n);
        // 2. 이동
        moveRobot(belt, n);
        // 3. 로봇 올리기
        putRobot(belt);

        // 4. 내구도 체크하기
        if (checkFinish(belt, n, k)) {
            return step;//중단됐을 때 step
        }
        step++;
    }
}
int main() {

    // 입력
    int n, k;
    cin >> n >> k;
    deque<info> belt(2 * n); //벨트의 내구도, 로봇 존재 여부 저장,2*n개의 칸으로 초기화
    for (int i = 0; i < 2 * n; i++) {
        cin >> belt[i].power;//내구도의 초기값
        belt[i].is_on = false;//초기엔 로봇이 없음
    }

    // 연산
    int answer = solution(belt, n, k);

    // 출력
    cout << answer;
}