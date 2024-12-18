#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;
int A[1000];

int main(){
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        A[a]++;
    }
    int ans = 0;
    for (int i = 1; i < 1000; i++)
        ans = max(ans, A[i - 1] + A[i]);
    cout << ans << endl;
    return 0;
}
