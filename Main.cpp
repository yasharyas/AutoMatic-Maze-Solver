#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int n, m, sx, sy, ex, ey;
vector<vector<int>> a;
vector<vector<int>> vis;
vector<vector<pair<int, int>>> parent;
int step = 0;

int fx[5] = {0, 1, 0, -1, 0};
int fy[5] = {0, 0, 1, 0, -1};

void printMaze() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == sx && j == sy)
                cout << "\033[32mS\033[0m";  // Start position
            else if (i == ex && j == ey)
                cout << "\033[32mE\033[0m";  // End position
            else if (a[i][j] == 2)
                cout << "\033[31m2\033[0m";  // Path
            else if (a[i][j] == 3)
                cout << "0";  // Visited
            else
                cout << a[i][j];  // Walls or unvisited
        }
        cout << endl;
    }
}

void printPath(int x, int y) {
    if (x == sx && y == sy) return;
    int px = parent[x][y].first;
    int py = parent[x][y].second;
    printPath(px, py);
    a[x][y] = 2;
    step++;
}

void bfs() {
    queue<tuple<int, int>> q;
    q.push(make_tuple(sx, sy));

    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        for (int i = 1; i <= 4; i++) {
            int tx = x + fx[i];
            int ty = y + fy[i];

            if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && a[tx][ty] == 0) {
                a[tx][ty] = 3;  // Mark as visited
                q.push(make_tuple(tx, ty));
                parent[tx][ty] = make_pair(x, y);

                if (tx == ex && ty == ey) {
                    printPath(ex, ey);
                    return;
                }
            }
        }
    }
}

void welcome() {
    cout << "Welcome to YSC-Maze! An automatic maze solve program." << endl;
    cout << "Developed by YURLAK, 2023." << endl;
}

int main() {
    welcome();

    cout << "\033[32m[INPUT x AND y]\033[0m";
    cin >> n >> m;

    a.resize(n + 1, vector<int>(m + 1, 0));
    vis.resize(n + 1, vector<int>(m + 1, 0));
    parent.resize(n + 1, vector<pair<int, int>>(m + 1, {-1, -1}));

    cout << "\033[32m[INPUT YOUR MAZE BELOW]\033[0m" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    cout << "\033[32m[INPUT START]\033[0m";
    cin >> sx >> sy;
    cout << "\033[32m[INPUT END]\033[0m";
    cin >> ex >> ey;

    if (a[sx][sy] == 1 || a[ex][ey] == 1) {
        cout << "Invalid start or end position on a wall." << endl;
        return 0;
    }

    bfs();

    cout << "\033[32m[RESULT OUTPUT]\033[0m" << endl;
    printPath(ex, ey);
    cout << endl;

    cout << "\033[32m[MAZE]\033[0m" << endl;
    printMaze();

    cout << "\033[32mSteps: " << step << "\033[0m" << endl;
}
