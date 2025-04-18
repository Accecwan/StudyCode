/*
    快速排序基于分治法的思想 -- 先找分界点，递归处理两个子区间 
    特点：不稳定，平均时间复杂度为O(nlogn)，最坏时间复杂度为O(n^2)，空间复杂度为O(logn)

    步骤：
    1. 选择一个分界点（pivot）， x = q[l + r >> 1]，即中间元素
    2. 调整区间，得到两个子区间，左边小于等于x，右边大于等于x。 
    --> int i = l - 1, j = r + 1; 
    --> 小于等于x的放左边，大于等于x的放右边
    --> while(i < j) {
        do i++; while(q[i] < x); // 找到大于等于x的元素，停止
        do j--; while(q[j] > x); // 找到小于等于x的元素
        if(i < j) swap(q[i], q[j]); // 交换这两个元素
    }
    3. 递归处理两个子区间，quick_sort(q, l, j); quick_sort(q, j + 1, r);
*/

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
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) scanf("%d", &q[i]);
    
    quick_sort(q, 0, n - 1);
    
    for(int i = 0; i < n; i++) printf("%d ", q[i]);
    
    return 0;
}