queue队列
```c++
#include <queue>
```
FIFO

这也是一个受限容器(容器适配器), 其操作受到被封装容器的限制(默认封装的是deque), 例如
```c++
queue<int, vector<int>> q;
q.push(1);
q.front();  //编译报错
```
因为vector没有 `vector.pop_front()` , 只有 `pop_back()`;


入队  push()
出队 front() pop()
查看是否为空 empty()