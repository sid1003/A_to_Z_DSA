#include <bits/stdc++.h>
using namespace std;

double pow_expo(int x, int n){
    int m = n;
    double ans = 1;
    while(n > 0){
        if(n % 2 == 1){
            ans = ans * x;
            n--;
        }
        else {
            n = n / 2;
            x = x * x;
        }
    }
    if(m < 0){
        ans = (double)(1.0) / ans;
    }
    return ans;
}

int fun(int n, int m){
    for (int i = 1; i <= m; i++){
        long long ans = 1;
        for (int j = 1; j <= n; j++){
            ans = ans * i;
            if(ans > m){
                break;
            }
        }
        if (ans == m){
            return i;
        }
        if(ans > m){
            break;
        }
    }
    return -1;
}

int fun2(int n, int m){
    int left = 1, right = m;
    while(left <= right){
        int mid = left + (right - left) / 2;
        long long ans = 1;
        for (int i = 1; i <= n; i++){
            ans = ans * mid;
            if(ans > m){
                break;
            }
        }
        if(ans == m){
            return mid;
        }
        else if(ans > m){
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main(){
    int n = 3, m = 27;
    cout << n << "th root of " << m << " is: " << fun(n, m) << endl;
    cout << n << "th root of " << m << " using binary search is: " << fun2(n, m) << endl;
    return 0;   
}
