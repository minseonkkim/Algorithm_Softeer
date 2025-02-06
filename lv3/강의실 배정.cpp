#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<pair<int, int>> lecture;

int main(int argc, char** argv)
{
    cin >> n;
    int s, f;
    for(int i = 0; i < n; i++){
        cin >> s >> f;
        lecture.push_back({f, s});
    }
    sort(lecture.begin(), lecture.end());
    
    int end = lecture[0].first;
    int cnt = 1;
    for(int i = 1; i < n; i++){
        if(lecture[i].second >= end){
            cnt++;
            end = lecture[i].first;
        }
    }
    cout << cnt;
    return 0;
}
