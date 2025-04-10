/*
st[N] 表示栈
top 表示栈顶指针,初始top=-1,表示没有元素
插入元素 st[++tt] = x
弹出 top--
判空 top == 0
*/

#include <iostream>

using namespace std;

const int N = 100010;
int st[N], top = -1;

int main(){
    int n;
    cin >> n;
    
    while(n--){
        string s;
        cin >> s;
        
        if(s == "push"){
            int x;
            cin >> x;
            st[++top] = x; // 栈顶所在索引往后移动一格，然后放入x
        }
        
        if(s == "pop"){
            top--; // 往前移动一格
        }
        
        if(s == "empty"){ // 大于等于0栈非空，小于0栈空
            if(top == -1) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        
        if(s == "query"){
            cout << st[top] << endl;
        }
    }
    
    return 0;
}