#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, k;
vector<int> rail;
int answer = 987654321;

int main(int argc, char** argv)
{
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        int w;
        cin >> w;
        rail.push_back(w);
    }
    sort(rail.begin(), rail.end());

    do{
        int cnt = 0, sum = 0, tmp = 0, idx = 0;
        while(cnt < k){
            tmp = 0;

            while(tmp + rail[idx] <= m){
                tmp += rail[idx];
                sum += rail[idx];
                idx = (idx + 1) % n;
            }
            cnt++;
        }
        answer = min(sum, answer);
    } while(next_permutation(rail.begin(), rail.end()));

    cout << answer;
    return 0;
}
