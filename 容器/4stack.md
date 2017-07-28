# stack容器
```c++
#include <stack>
template<
    class T,
    class Container = std::deque<T>
> class stack;
```
(FILO)
这类受限容器, 又称为容器适配器, 因为可以用来适配其他容器(默认是简单封装了deque), 实际上而言可以用其他的容器,  比如:
```c++
stack<int, vecotr<int>> s;
s.push(1); //实际上调用的是vector.push_back(1);
```
这个时候, 受限容器的操作受限于被封装的容器. 
(否则可能出现编译错误)


压栈出栈操作
```c++
push();//入栈
if(!stack.empty()){
     stack.top(); //获取栈顶元素
	 stack.pop(); //出栈
}
```

stack.size(); //栈的大小


