#include <iostream>
#include "CLStatus.h"
#include "CLLogger.h"

using namespace std;

CLStatus f()
{
	return CLStatus(-1, 4);
}

int main()
{
	CLStatus s = f();
	if(!s.IsSuccess())
	{
		// 静态的成员函数实现单例模式，获取一个CLLogger对象的指针
		CLLogger *pLogger = CLLogger::GetInstance();
		if(pLogger != 0)
			pLogger->WriteLog("this is an error", s.m_clErrorCode);
	}

	return 0;
}