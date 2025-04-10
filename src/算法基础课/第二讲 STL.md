# C++ STL常用

转载自：
[callmewenhao/AcWing](https://github.com/callmewenhao/AcWing/tree/main)
[acwing常用代码模板2-数据结构](https://www.acwing.com/blog/content/404/)

> 没记住就上网查c++ STL用法。

`vector`, 变长数组，倍增的思想

```C++
vector<int> a(10, 3); // 10个3

size()  返回元素个数
empty()  返回是否为空
clear()  清空
front()/back() 返回第一/最后一个数
push_back()/pop_back() 向最后插入一个数/把最后一个数删掉
begin() --> 相当于a[0] /end() --> 相当于a[a.size()]
[]
支持比较运算，按字典序

三种遍历方式
for(int i = 0; i < a.size(); i++) cout << a[i] << ' ';

for(auto i = a.begin(); i != a.end(); i++) cout << *i << ' ';

for(auto x : a) cout << x << ' ';
```

`pair<int, int>`，存储一个二元组

```C++
pair<int, string>p;
p = make_pair(10, "yxc");
p = {20, "abc"};

first, 第一个元素
second, 第二个元素
支持比较运算，以first为第一关键字，以second为第二关键字（字典序）
```

`string`，字符串

```C++
string a = "yxc";
a += "acwing";

size()/length()  返回字符串长度
empty()
clear()
substr(起始下标，(子串长度))  返回子串
c_str()  返回字符串所在字符数组的起始地址
```

`queue`, 队列

```C++
#include <queue>
queue<int> q;

size()
empty()
push()  向队尾插入一个元素
front()  返回队头元素
back()  返回队尾元素
pop()  弹出队头元素
```

`priority_queue`, 优先队列，其实就是堆，默认是大根堆(即堆顶元素是最大的)

```C++
size()
empty()
push()  插入一个元素
top()  返回堆顶元素
pop()  弹出堆顶元素
定义成小根堆的方式：(或者存-x)
priority_queue<int, vector<int>, greater<int>> q;
```

`stack`, 栈

```C++
size()
empty()
push()  向栈顶插入一个元素
top()  返回栈顶元素
pop()  弹出栈顶元素
```

`deque`, 双端队列，加强版vector

```C++
size()
empty()
clear()
front()/back()
push_back()/pop_back()
push_front()/pop_front()
begin()/end()
[]
```

`set, map, multiset, multimap`, 基于平衡二叉树（红黑树），动态维护有序序列

```C++
size()
empty()
clear()
begin()/end()
++, -- 返回前驱和后继，时间复杂度 O(logn)

set/multiset
    insert()  插入一个数
    find()  查找一个数
    count()  返回某一个数的个数
    erase()
        (1) 输入是一个数x，删除所有x   O(k + logn)
        (2) 输入一个迭代器，删除这个迭代器
    lower_bound()/upper_bound()
        lower_bound(x)  返回大于等于x的最小的数的迭代器
        upper_bound(x)  返回大于x的最小的数的迭代器

map/multimap
    insert()  插入的数是一个pair
    erase()  输入的参数是pair或者迭代器
    find()
    []  注意multimap不支持此操作。 时间复杂度是 O(logn)
    lower_bound()/upper_bound()

unordered_set, unordered_map, unordered_multiset, unordered_multimap, 哈希表
    和上面类似，增删改查的时间复杂度是 O(1)
    不支持 lower_bound()/upper_bound()，迭代器的++，--
```

`bitset`, 压位

```C++
bitset<10000> s;  // 10000 是位的个数

支持一下位操作
~, &, |, ^
>>, <<
==, !=
[]

count()  返回有多少个1

any()  判断是否至少有一个1
none()  判断是否全为0

set()  把所有位置成1
set(k, v)  将第k位变成v
reset()  把所有位变成0
flip()  等价于~
flip(k) 把第k位取反
```