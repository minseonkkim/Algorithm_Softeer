#include<iostream>
#include<cmath>
using namespace std;

int n;

int main(int argc, char** argv)
{
    cin >> n;
    int p, c;
    int score = 0;
    for(int i = 0; i < n; i++){
        cin >> p >> c;
        if(abs(p - score) <= c) score++;
    }
    cout << score;
    return 0;
}
