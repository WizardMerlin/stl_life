deque双端数组
和vector一样采用顺序存储, 但是可以在双端进行增删操作.

如下
```c++
deque<T> deqT

push_back()
push_front()
pop_back()
pop_front()
```

也就是说, 适用于收尾插入和删除.


根据迭代器, 求数组下标:
deque<T>::iterator it = find(d1.begin(), d1.end(), value);
if(it!=d1.end()){
    cout << distance(d1.begin(), it);// 下标
}



其他补充:
* deque不存在capacity, reserve方法(但是有resize方法)
