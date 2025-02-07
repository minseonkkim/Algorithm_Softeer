#include<iostream>
#include<cmath>
using namespace std;

int n;
int map[4][4];
bool visited[4][4];
int tmp_cnt;
int answer;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void dfs(int cnt, int tmp){
    if(cnt == tmp_cnt){
        answer = max(answer, tmp);
        return;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j]){
                visited[i][j] = true;
                for(int k = 0; k < 4; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

                    if(!visited[nx][ny]){
                        visited[nx][ny] = true;
                        dfs(cnt + 1, tmp + map[i][j] + map[nx][ny]);
                        visited[nx][ny] = false;
                    }
                }
                visited[i][j] = false;
            }
        }
    }
}

int main(int argc, char** argv)
{
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }
    if(n == 2) tmp_cnt = 2;
    else tmp_cnt = 4;
    dfs(0, 0);
    cout << answer;
    return 0;
}
