#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int R, C;
int sticker[15][15];
int origin[15][15];
int notebook[50][50];
int maxCount = 0;

bool CheckAttach(int mr, int mc)
{
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            // 스티커를 붙일 수 있는지 확인한다
            if (notebook[mr + i][mc + j] == 1 && sticker[i][j] == 1)
                return false;
        }
    }

    return true;
}

void DoAttach(int mr, int mc)
{
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            // 스티커인 부분만 붙인다
            if (sticker[i][j] == 1) {
                notebook[mr + i][mc + j] = 1;
            }
        }
    }
}

void Rotate(int rotatedCount)
{
    if (rotatedCount == 0) return;

    int temp[15][15];

    // copy
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            temp[i][j] = sticker[i][j];
        }
    }

    // rotate
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            sticker[j][R - 1 - i] = temp[i][j];
        }
    }

    // swap row and col
    std::swap(R, C);
}

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : 스티커 붙이기

    cin >> N >> M >> K;
    while (K--) {
        // 스티커를 순서대로 붙인다
        cin >> R >> C;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> sticker[i][j];
                origin[i][j] = sticker[i][j];
            }
        }

        // TODO: 최선을 찾는 문제가 아니다
        // 그냥 상황이 되면 붙이는 그리디 알고리즘 같은 것이다
        
        // 회전
        for (int rotatedCount = 0; rotatedCount < 4; rotatedCount++) {
            Rotate(rotatedCount);
            if (R > N || C > M) continue;
            // 이동
            for (int moveRow = 0; moveRow < N; moveRow++) {
                for (int moveCol = 0; moveCol < M; moveCol++) {
                    if (moveRow + R > N || moveCol + C > M) continue;
                    // 스티커 붙일 수 있는 지 체크
                    if (CheckAttach(moveRow, moveCol)) {
                        DoAttach(moveRow, moveCol);
                        goto end;
                    }
                }
            }
        }

        end:

        int count = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                count += notebook[i][j];
            }
        }
        maxCount = std::max(maxCount, count);
    }

    cout << maxCount;

    return 0;
}
