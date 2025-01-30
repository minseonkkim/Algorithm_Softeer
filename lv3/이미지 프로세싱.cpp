#include<iostream>
using namespace std;

int h, w, q;
int map[129][129];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void dfs(int x, int y, int orig, int c){
    map[x][y] = c;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx <= 0 || nx > h || ny <= 0 || ny > w) continue;
        if(map[nx][ny] == orig){
            dfs(nx, ny, orig, c);
        }
    }
}

int main(int argc, char** argv)
{
    cin >> h >> w;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            cin >> map[i][j];
        }
    }
    cin >> q;
    for(int i = 0; i < q; i++){
        int x, y, c;
        cin >> x >> y >> c;
        if(map[x][y] == c) continue;
        dfs(x, y, map[x][y], c);
    }
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            cout << map[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}
