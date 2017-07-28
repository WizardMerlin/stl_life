# 容器string.
 
string就是一个char*的容器, 不用考虑内存释放和越界问题.
 
主要考虑使用的是:
find, copy, erase, replace, insert

 
* 初始化
 ```c++
#include<string>
using std:string;

string s1 = "aaa";
string s2("aaa");
string s3(3, 'a');
string s4 = s3;
 ```
* 遍历
 ```c++
string s1 = "aaa";

//以数组的方式(因为[]运算符重载了)
s1[i];  //i<s1.length();

s1.at(i);// 越界会抛出异常, 但是[]不会抛异常, 而是运行报错.

//迭代器的方式
for(string::iterator it = s1.begin(); it != s1.end(); it++){
    cout << *it << endl;
}
 ```
* 和C_string的转换
 ```c++
string s1 = "aaa"; 
s1.c_str(); //const char *
 ```
 * s1的内容拷贝到buf所指向的空间里
 ```c++
int copy(char* s, int n, int pos=0) const;

char buf[128]={0};
int count =127;
pos =0;  
s1.copy(buf, count, pos); //拷贝的时候, 不会加上\0的.
 ```
* 两个字符串连接
operator+()或者append().

例子:
 ```c++
string s1 = "aaa";
string s2 = "bbb";
s1 = s1 + s2;
//s1.append(s2);
 ```
* 两个字符串比较
 ```c++
int compare(const string&s) const;
int compare(const char*s) const;
 ```
* 子串
 ```c++
string substr(int pos=0, int n=string::npos) const; //返回从pos开始的n个字符的string
 ```
* 查找(重点) 
 注意头文件algorithm: find(), rfind();
 例如:
```c++
string s1 = "bmw_good";
//从0位置开始查找bmw第一次出现的index, 找不到返回-1
int index = s1.find("bmw", 0);  
 ```
 注意 `string::npos` 其实就是 -1 .
* 替换(重点)
 ```c++
//注意替换的字符串的长度为n
//先删除从pos开始的n个字符, 然后在pos处插入char*s
string &replace(int pos, int n, const char*s); 
string &replace(int pos, int n, const string& s); 

void swap(string &s2);// 交换当前字符串和s2的内容
 ```
 * 区间删除
  ```c++
string& erase(int pos=0, int n =string::npos);// 删除pos开始的n个字符, 返回修改后的string对象
 ```
 例如:
 ```c++
string s1 = "aabaa";
string s2 = s1.erase(2,1);
 ```
 erase()函数也可以删除迭代器所指的位置:
 `s1.erase(s1.begin());`
 或者删除整个字符串
 `s1.erase(s1.begin(), s1.end());//返回空string, 长度为0`
 * 插入
 ```c++
string& insert(int pos, const char*s);
string& insert(int pos, const string &s);
string& insert(int pos, int n, char c); //从pos开始插入n个字符c
 ```
 (当然也可以在s.length(),即尾部进行插入, 而不必担心越界,内存等问题)
* 其他算法
 string的成员函数, 或者stl全局函数(友元函数), 例如大小写转换:
 ```c++
string s = "aaBB";
//toupper/tolower其实是函数对象
transform(s.begin(), s.end(),s.begin(), toupper/tolower); //第三个参数表示转换后的位置
 ```