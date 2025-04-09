/*
    每一个节点有两个指针，一个指向前面元素，另一个指向后面元素
    0 表示左端点 1 表示右端点
    l[N] 存储左侧节点
    r[N] 存储右侧节点
    idx 表示当前可以分配的位置
*/
#include <iostream>

using namespace std;

const int N = 1000010;

int m, e[N], l[N], r[N], idx;

void init(){ // 初始化链表
    // 0表示左端点，1表示右端点
    r[0] = 1, l[0] = 0;
    idx = 2；
}

void add_right(int k, int x){ // 在第k个插入的数右边插入一个数
    e[idx] = x;
    r[idx] = r[k]; // 新插入点的右边 = k的右边
    l[idx] = k;    // 新插入点的左边 = k
    // 修改之前的边
    l[r[k]] = idx; // 原来位于k右边的点，现在他的左边是idx
    r[k] = idx;    // 现在k的右边是idx
    idx++;
}

void remove(int k){
    r[l[k] = r[k];  // 左边的右边 = 我的右边
    l[r[k]] = l[k]; // 右边的左边 = 我的左边
}

int main(){
    
    return 0;
}