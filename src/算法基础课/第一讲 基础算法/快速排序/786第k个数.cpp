/*
    快速选择算法 -- 注意与快排的区别
*/

// y总解法 -- 快速选择算法，与快排不同点在于，每次只需要递归处理一边，时间复杂度O(n)
// 如果左边的元素个数(左端点为l,右端点为j，个数为j-l+1)大于k，则在左边递归，否则在右边递归
// --> if(j - l + 1 >= k) return quick_sort(q, l, j, k);
// --> else return quick_sort(q, j + 1, r, k - (j - l + 1)); 右边递归时，k要减去左边的个数，即k - (j - l + 1)
#include <iostream>
using namespace std;

const int N = 100010;
int q[N];

int quick_sort(int q[], int l, int r, int k){
    if(l >= r) return q[l]; // 注意点1：l=r时，返回q[l]，即返回当前的数
    
    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while(i < j){
        do i++; while(q[i] < x);
        do j--; while(q[j] > x);
        if(i < j) swap(q[i], q[j]);
    }
    
    if(j - l + 1 >= k) return quick_sort(q, l, j, k); // 如果左边的元素个数(左端点为l,右端点为j，个数为j-l+1)大于k，则在左边递归
    else return quick_sort(q, j + 1, r, k - (j - l + 1)); // 在右边递归，此时k的位置应该 k减去左边的个数
}

int main(){
    int n, k;
    cin >> n >> k;
    
    for(int i = 0; i < n; i++) scanf("%d", &q[i]);
    
    cout << quick_sort(q, 0, n-1, k) << endl;
    
    return 0;
}

// 我写的，直接硬套快排模版，取出排序后数组的第k-1个数
#include <iostream>

using namespace std;

const int N = 100010;
int q[N];

void quick_sort(int q[], int l, int r){
    if(l >= r) return;
    
    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while(i < j){
        do i++; while(q[i] < x);
        do j--; while(q[j] > x);
        if(i < j) swap(q[i], q[j]);
    }
    
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

int main(){
    int n, k;
    cin >> n >> k;
    
    for(int i = 0; i < n; i++) scanf("%d", &q[i]);
    
    quick_sort(q, 0, n-1);
    
    cout << q[k-1];
    
    return 0;
}