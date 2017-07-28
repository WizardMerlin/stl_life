# priority_queue

 优先级队列
(按照值的特性, 决定入队的顺序)

```c++
#include<queue>
```

初始化
```c++
priority_queue<T> p1; //默认是最大值优先队列(最大值放在队首)
```
相当于:
```c++
priority_queue<T, vector<T>, less<T>> p1;
```
如果你需要最小值优先队列, 可以这样写:
```c++
priority_queue<T, vector<T>, greater<T>> p2;
```

其他操作

push(); //插入元素
pop();  //删除元素

top(); //获取头部元素
size();  //获取容器的大小



取得元素:
list.front(); //返回第一个元素
list.back(); //返回最后一个元素