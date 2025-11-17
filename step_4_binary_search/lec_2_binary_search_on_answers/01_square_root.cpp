#include <bits/stdc++.h>
using namespace std;

int fun(int n){
    int ans = 1;
    for (int i = 1; i < n; i++){
        if(i * i <= n){
            ans = i;
        } else {
            break;
        }
    }
    return ans;
}

int fun2(int n){
    int left = 1, right = n, ans = 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(mid * mid <= n){
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

int main(){
    int n = 37;
    cout << "Square root of " << n << " is: " << fun(n) << endl;
    cout << "Square root of " << n << " using binary search is: " << fun2(n) << endl;
    return 0;   
}