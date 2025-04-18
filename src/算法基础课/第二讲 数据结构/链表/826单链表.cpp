/*
head 表示链表的当前的头节点，head=-1 表示链表为空
e[N] 存储节点的 value
ne[N] 存储节点的 next
idx 表示当前可以分配的位置，从 0 开始

- k从1开始，而idx从0开始，因此涉及到k时，如remove(k-1)和add(k-1,x), 应该传入k-1
*/

#include <iostream>

using namespace std;

const int N = 1000010;

int head, e[N], ne[N], idx; 
// head表示头结点，head=-1为空
// e[N]存储节点value，ne[N]存储节点next，idx表示当前可以分配的位置，从0开始

void init(){ // 初始化链表
    head = -1, idx = 0;
}

void add_to_head(int x){ // 向链表头插入一个数
    e[idx] = x; 
    ne[idx] = head; 
    head = idx; // 让head指向idx
    idx++; // 指针后移，以便下一次插入元素
}

// 在第k个插入的数后插入一个数
// 注意：k从1开始，而idx从0开始，因此应该传入k-1
void add(int k, int x){
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx; // 让原来元素的指针指向自己
    idx++; //指针后移
}

void remove(int k){
    ne[k] = ne[ne[k]];
}

int main(){
    int m;
    cin >> m;
    
    init(); // 初始化链表
    
    while(m-- ){
        int k, x;
        char op;
        
        cin >> op;
        
        if(op == 'H'){
            cin >> x;
            add_to_head(x);
        }
        if(op == 'D'){
            cin >> k;
            if(k == 0) head = ne[head]; // 删除头结点
            else remove(k - 1);
        }
        if(op == 'I'){
            cin >> k >> x;
            add(k - 1, x);
        }
    }
    
        // 遍历输出链表
        for(int i = head; i != -1; i = ne[i]) cout << e[i] << ' '; 
        cout << endl;
    
    return 0;
}