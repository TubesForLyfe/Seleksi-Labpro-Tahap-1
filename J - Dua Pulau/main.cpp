#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int x, y, dist;
    
    Node(int x, int y, int dist) {
        this->x = x;
        this->y = y;
        this->dist = dist;
    }
}; 

int around_x[4] = { 0, 1, 0, -1 };
int around_y[4] = { 1, 0, -1, 0 };

bool isValidIdx(int x, int y, int N) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}
 
bool isBorder(int i, int j, int** pulau, int N) {
    for (int idx = 0; idx < 4; idx++) {
        int x = i + around_x[idx];
        int y = j + around_y[idx];
        if (isValidIdx(x, y, N) && pulau[x][y] == 0) {
            return true;
        }
    }
    return false;
}
 
void SearchByDFS(int i, int j, bool** visited, queue<Node>& q, int** pulau, int N) {
    visited[i][j] = true;
    if (isBorder(i, j, pulau, N)) {
        q.push(Node(i, j, 0));
    }
    for (int idx = 0; idx < 4; idx++) {
        int x = i + around_x[idx];
        int y = j + around_y[idx];
        if (isValidIdx(x, y, N) && pulau[x][y] == 1 && !visited[x][y]) {
            SearchByDFS(x, y, visited, q, pulau, N);
        }
    }
}
 
int SearchByBFS(queue<Node>& q, bool** visited, int** pulau, int N) {
    while (q.size() > 0) {
        Node p = q.front();
        q.pop();
        for (int idx = 0; idx < 4; idx++) {
            int x = p.x + around_x[idx];
            int y = p.y + around_y[idx];
            if (isValidIdx(x, y, N) && pulau[x][y] == 1 && !visited[x][y]) {
                return p.dist;
            }
            if (isValidIdx(x, y, N) && pulau[x][y] == 0 && !visited[x][y]) {
                q.push(Node(x, y, p.dist + 1));
                visited[x][y] = true;
            }
        }
    }
    return -1;
}
 
int minimumDIstance(int** pulau, int N) {
    queue<Node> q;
    bool** visited = new bool*[N];
    for (int i = 0; i < N; i++) {
        visited[i] = new bool[N];
    }
    bool flag = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (pulau[i][j] == 1) {
                SearchByDFS(i, j, visited, q, pulau, N);
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }
    return SearchByBFS(q, visited, pulau, N);
}

int main() {
    // INPUT
    int N;
    cin >> N;
    int** pulau = new int*[N];
    for (int i = 0; i < N; i++) {
        pulau[i] = new int[N];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> pulau[i][j];
        }
    }
    
    // OUTPUT
    cout << minimumDIstance(pulau, N) << endl;
}