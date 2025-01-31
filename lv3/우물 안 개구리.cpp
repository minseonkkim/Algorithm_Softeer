#include<iostream>
using namespace std;

int n, m;
int weight[100001];
bool best[100001];

int main(int argc, char** argv)
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> weight[i];
        best[i] = true;
    }

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        if(weight[a] > weight[b]) best[b] = false;
        else if(weight[b] > weight[a]) best[a] = false;
        else{
            best[a] = false;
            best[b] = false;
        }
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(best[i]) cnt++;
    }
    cout << cnt;
    return 0;
}
