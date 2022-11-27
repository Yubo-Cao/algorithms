#include <iostream>

using namespace std;

const int N = 1510;
int h, w, d;

char base[N][N];
char canvas[N][N];

void empty(int x, int y, int w, int h) {
    for (int i = x; i < x + w; i++)
        for (int j = y; j < y + h; j++)
            canvas[i][j] = ' ';
}

void print_area(int x, int y, int w, int h) {
    for (int i = x; i < x + w; i++) {
        for (int j = y; j < y + h; j++) cout << canvas[i][j];
        cout << endl;
    }
}

void print() {
    print_area(0, 0, h + d + 1, w + d + 1);
}

void draw_base(int x, int y) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (base[i][j] == ' ') continue;
            if (!base[i][j]) continue;
            canvas[x + i][y + j] = base[i][j];
        }
    }
}

void draw_dig(int x, int y) {
    for (int i = 1; i <= d; i++)
        canvas[x + i][y + i] = '\\';
}

void extrude() {
    // empty
    empty(0, 0, w + d + 1, h + d + 1);
    // draw base
    draw_base(0, 0);
    // for each corner, from bottom left to upper right, draw diagonal. corner are represented by +
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (canvas[i][j] == '+') draw_dig(i, j);
    draw_base(d + 1, d + 1);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        cin >> h >> w >> d;
        cin.get();
        for (int i = 0; i < h; i++) {
            cin.getline(canvas[i], w + 1);
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++)
                base[i][j] = canvas[i][j];
        }
        extrude();
        print_area(0, 0, h + d + 1, w + d + 1);
    }
    return 0;
}