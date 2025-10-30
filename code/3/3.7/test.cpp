#include <iostream>
#include <unistd.h>
#include "CLThread.h"

using namespace std;

// 面向对象的方式创建线程
class CLMyThread : public CLThread
{
public:
    virtual CLStatus RunThreadFunction()
    {
	    long i = (long)m_pContext;
	    cout << i << endl;
	    return CLStatus(0, 0);
    }
};

int main()
{
    CLThread *pThread = new CLMyThread;

    // Run中子进程和主进程（继续执行waitfordeath）并发执行
    pThread->Run((void *)2);
    pThread->WaitForDeath();

    delete pThread;

    return 0;
}
