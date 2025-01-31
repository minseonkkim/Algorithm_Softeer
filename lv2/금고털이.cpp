#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int w, n;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second > b.second;
}

int main(int argc, char** argv)
{
    cin >> w >> n;
    int m, p;
    for(int i = 0; i < n; i++){
        cin >> m >> p;
        v.push_back({m, p});
    }
    sort(v.begin(), v.end(), cmp);
    int answer = 0;
    for(int i = 0; i < v.size(); i++){
        int putweight = (w < v[i].first) ? w : v[i].first;
        answer += putweight * v[i].second;
        w -= putweight;
        if(w <= 0) break;
    }
    cout << answer;
    return 0;
}
