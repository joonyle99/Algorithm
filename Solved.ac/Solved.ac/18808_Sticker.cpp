#include <bits/stdc++.h>
using namespace std;

int N, M, K;
vector<vector<int>> stickers[105];

int maxCount = -1000000000;

// vector<vector<int>> notebook를 90도 회전시키는 함수
vector<vector<int>> RotateSticker(int dir, vector<vector<int>> sticker) {     // dir: 0, 1, 2, 3 -> 4방향 회전
    if (dir == 0) return sticker;
    for (int i = 0; i < sticker.size(); i++) {
        for (int j = 0; j < sticker[i].size(); j++) {

        }
    }
    return sticker;
}

void Recursive(int curCount, vector<vector<int>> notebook) {
    if (curCount == K) {
        int count = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 4; j++) {
                if (notebook[i][j] == 1) {
                    count++;
                }
            }
        }
        maxCount = std::max(maxCount, count);
        return;
    }

    // notebook에 스티커를 붙힌다 (다양한 경우의 수 존재)
    for (int number = curCount; number < K; number++) {

        // 1번 스티커의 경우 노트북에 붙일 수 있는 경우의 수를 탐색한다
        // 왼쪽 상단을 최우선으로하고, 회전도 가능하다
        // 따라서 스티커를 이동시키고 회전시키는 기능을 구현해야 한다.

        // 회전 (0도, 90도, 180도, 270도 - 시계 방향)
        for (int rotatedNumber = 0; rotatedNumber < 4; rotatedNumber++) {
            auto sticker = stickers[curCount];
            vector<vector<int>> tempSticker = sticker;
            tempSticker = RotateSticker(rotatedNumber, tempSticker);
            // 이동 (위쪽이 우선, 왼쪽이 그 다음)
            for (int row = 0; row < N; row++) {                 // row = 0 : 위쪽 row = N : 아래쪽
                for (int col = 0; col < M; col++) {             // col = 0 : 왼쪽 col = M : 오른쪽
                    // 범위를 벗어나는 경우에 스킵
                    int stickerRowSize = sticker.size();
                    int stickerColSize = sticker[0].size();
                    if (row + stickerRowSize >= N || col + stickerColSize >= M) continue;
                    // 스티커를 노트북에 붙힘
                    vector<vector<int>> tempNotebook = notebook;
                    for (int r = 0; r < stickerRowSize; r++) {
                        for (int c = 0; c < stickerColSize; c++) {
                            tempNotebook[row + r][col + c] = sticker[r][c];
                        }
                    }
                    Recursive(curCount + 1, tempNotebook);
                }
            }
        }
    }
}

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : 스티커 붙이기

    cin >> N >> M >> K;
    for (int i = 0; i < K; i++) {
        int R, C; cin >> R >> C;
        stickers[i].resize(R);
        for (int row = 0; row < R; row++) {
            stickers[i][row].resize(C);
            for (int col = 0; col < C; col++) {
                cin >> stickers[i][row][col];
            }
        }
    }

    vector<vector<int>> notebook(N, vector<int>(M, 0));
    Recursive(0, notebook);

    cout << maxCount;

    return 0;
}
