#include "f.h"

// 被链接起来的两个cpp文件如果都导入了同一个头文件，且头文件中有变量定义，则会导致重复定义错误
// 解决方法：将变量定义放在一个cpp文件中，其他cpp文件通过extern声明该变量
// 见f.h和f.cpp
int main()
{
	f();

	return 0;
}
