#include <iostream>
#include <unistd.h>
#include "CLThread.h"

using namespace std;

// 基于模板类实现线程和线程函数
class CLMyThread : public CLThread<CLMyThread>
{
public:
    CLStatus RunThreadFunction()
    {
	long i = (long)m_pContext;
	cout << i << endl;
	return CLStatus(0, 0);
    }
};

int main()
{
    CLMyThread thread;

    thread.Run((void *)3);
    thread.WaitForDeath();

    return 0;
}
