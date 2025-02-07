#include<iostream>
#include<cstring>
using namespace std;

int n, m;
int map[100][100];
int cnt[100][100];
bool visited[100][100];
bool exist;
int answer;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

bool checkExist(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j]) return true;
        }
    }
    return false;
}

void dfs(int x, int y){
    visited[x][y] = true;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) continue;

        if(map[nx][ny]) cnt[nx][ny]++;
        else dfs(nx, ny);
    }
}

int main(int argc, char** argv)
{
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
            if(map[i][j]) exist = true;
        }
    }
    while(exist){
        answer++;
        
        dfs(0, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(cnt[i][j] >= 2) map[i][j] = 0;
            }
        }

        memset(visited, false, sizeof(visited));
        memset(cnt, 0, sizeof(cnt));
        exist = checkExist();
    }
    cout << answer;
    return 0;
}
