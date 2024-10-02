#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Point {
    int x, y;
    int distance;

    Point(int _x, int _y, int _dis) 
        { this->x = _x, this->y = _y; this->distance = _dis; }
    Point() { this->x = 0; this->y = 0; this->distance = 0; }
};

char inputMap[1100][1100];
char lastStep[1100][1100];
int n, m;
Point start, dst;

bool isValid(int x, int y) {
    return x < m && x >= 0 && y >= 0 && y < n;
}

// d, y, x
int steps[4][2] = {
    -1,  0, // UP
     1,  0, // DOWN
     0, -1, // LEFT
     0,  1  // RIGHT
};

char labels[4] = { 'U', 'D', 'L', 'R' };

// trace backwards to the start, then print in the right order
void printPath(int x, int y) {
    stack<char> path;
    while (!(start.x == x && start.y == y)) {
        //cout << "Going backward, lastStep: " << lastStep[y][x] << ", x = " << x << ", y = " << y << endl;
        path.push(lastStep[y][x]);
        switch (lastStep[y][x]) {
            case 'L': x++; break;
            case 'R': x--; break;
            case 'D': y--; break;
            case 'U': y++; break;
            default: return;
        }
    }

    while (!path.empty()) {
        cout << path.top();
        path.pop();
    }

    /*
    while (!(dst.x == x && dst.y == y)) {
        cout << lastStep[y][x];
        switch (lastStep[y][x]) {
            case 'L': x--; break;
            case 'R': x++; break;
            case 'D': y++; break;
            case 'U': y--; break;
            default: return;
        }
    }
    */
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        cin >> inputMap[i];
    }

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (inputMap[y][x] == 'A') {
                start = Point(x, y, 0);
            } else if (inputMap[y][x] == 'B') {
                dst = Point(x, y, 0);
            }
        }
    }

    queue<Point> workQueue;
    workQueue.push(start);

    // bfs start
    while (!workQueue.empty()) {
        Point head = workQueue.front();

        if (head.x == dst.x && head.y == dst.y) {
            cout << "YES\n" << head.distance << endl;
            printPath(head.x, head.y);
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int yNext = head.y + steps[i][0];
            int xNext = head.x + steps[i][1];

            if (isValid(xNext, yNext) && lastStep[yNext][xNext] == 0 && inputMap[yNext][xNext] != '#') {
                Point nextPoint = Point(xNext, yNext, head.distance + 1);
                lastStep[yNext][xNext] = labels[i];
                workQueue.push(nextPoint);
            }
        }
        workQueue.pop();
    }

    cout << "NO" << endl;


    return 0;
}
