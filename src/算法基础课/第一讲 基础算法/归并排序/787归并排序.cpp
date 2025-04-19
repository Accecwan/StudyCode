/*
    归并排序 -- 基于分治思想，先把两个子区间排好序，再合并成一个有序区间
    时间复杂度：O(nlogn)  空间复杂度：O(n)  稳定性：稳定

    步骤： --> 需要开辟一个tmp数组，大小为n
    1. 将区间划分成两个子区间，一般从中间分割
        --> int mid = l + r >> 1;
    2. 递归处理两个子区间
        --> merge_sort(q, l, mid); merge_sort(q, mid + 1, r);
    3. 合并两个有序的子区间，合并时需要一个辅助数组，存储合并后的结果
        --> int k = 0, i = l, j = mid + 1; // k表示辅助数组的下标，i和j分别表示两个子区间的下标
        --> while(i <= mid && j <= r) { // 两个子区间没有超过范围，即还未遍历完
            if(q[i] <= q[j]) tmp[k++] = q[i++]; // 将小的元素放入辅助数组
            else tmp[k++] = q[j++];
        }
        --> 如果其中一个子区间已经遍历完，则将另一个子区间的剩余元素放入辅助数组tmp
    4. 将辅助数组的结果复制回原数组 --> 将tmp数组复制回q数组
        --> for(i = l, j = 0; i <= r; i++, j++) q[i] = tmp[j]; 
        // 注意：i对应q[]数组，因此从最左侧开始，j对应tmp数组，从0开始
*/

#include <iostream>

using namespace std;

const int N = 100010;
int q[N], tmp[N];

void merge_sort(int q[], int l, int r){
    if(l >= r) return;
    
    int mid = l + r >> 1;
    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);
    
    int k = 0, i = l, j = mid + 1;
    while(i <= mid && j <= r){
        if(q[i] <= q[j]) tmp[k++] = q[i++];
        else tmp[k++] = q[j++];
    }
    while(i <= mid) tmp[k++] = q[i++];
    while(j <= r) tmp[k++] = q[j++];
    
    for(i = l, j = 0; i <= r; i++, j++) q[i] = tmp[j];
}

int main(){
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) scanf("%d", &q[i]);
    
    merge_sort(q, 0, n - 1);
    
    for(int i = 0; i < n; i++) cout << q[i] << " ";
    
    return 0;
}