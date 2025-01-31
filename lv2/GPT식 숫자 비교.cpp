#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main(int argc, char** argv)
{
    cin >> n;
    string str;
    for(int i = 0; i < n; i++){
        cin >> str;
        if(str.find(".") == string::npos){
            v.push_back({stoi(str), -1});
        } else{
            int idx = str.find(".");
            v.push_back({stoi(str.substr(0, idx)), stoi(str.substr(idx + 1))});
        }
    }
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < n; i++){
        cout << v[i].first;
        if(v[i].second != -1) cout << "." << v[i].second;
        cout << '\n';
    }
    return 0;
}
