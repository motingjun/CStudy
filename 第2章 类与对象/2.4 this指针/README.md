在`2.3 封装`中，程序创建了两个对象`stu`和`stu1`，通过对象`stu`调用`getName()`函数获取的姓名是“张三”，
通过对象`stu1`调用`getName()`函数获取的姓名是“李四”。
在调用过程中，`getName()`函数可以区分到底是对象stu还是对象stu1调用，是通过`this指针`实现的。

`this指针`是C++实现封装的一种机制，它将对象和对象调用的非静态成员函数联系在一起，从外部看来，
每个对象都拥有自己的成员函数。当创建一个对象时，编译器会初始化一个this指针，指向创建的对象，
this指针并不存储在对象内部，而是作为所有非静态成员函数的参数。

```c++
void Student::setName(Student* this,string name)  
{ 
    this->_name = name; 
} 
string Student::getName(Student* this) 
{ 
    return this->_name; 
}
```
上述代码演示的过程是隐含的，由编译器完成。当对象stu调用成员函数时，指向对象stu的this指针作为成员函数的第一个参数，
在成员函数内部使用对象属性时，编译器会通过this指针访问对象属性。

* 如果类的成员函数返回值为一个对象，则可以使用return*this返回对象本身。