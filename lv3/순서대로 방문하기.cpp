#include<iostream>
using namespace std;

int n, m;
int map[5][5];
bool visited[5][5];
int point[17][2];
int cnt = 0;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void dfs(int x, int y, int passed){
    if(passed == m){
        cnt++;
        return;
    }
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
        
        if(!visited[nx][ny] && map[nx][ny] == 0){
            visited[nx][ny] = true;
            if(point[passed + 1][0] == nx && point[passed + 1][1] == ny){
                dfs(nx, ny, passed + 1);
            } else{
                dfs(nx, ny, passed);
            }
            visited[nx][ny] = false;
        }
    }
    return;
}

int main(int argc, char** argv)
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> map[i][j];
        }
    }
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        point[i][0] = x;
        point[i][1] = y;
    }
    visited[point[1][0]][point[1][1]] = true;
    dfs(point[1][0], point[1][1], 1);
    cout << cnt;
    return 0;
}
