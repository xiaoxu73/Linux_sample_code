#include <iostream>
#include "CLThread.h"
#include "CLExecutiveFunctionProvider.h"
#include "CLMutex.h"

using namespace std;

struct SPara
{
    int Flag;
    CLMutex mutex;
};

class CLMyFunction : public CLExecutiveFunctionProvider
{
public:
    CLMyFunction()
    {
    }

    virtual ~CLMyFunction()
    {
    }

    virtual CLStatus RunExecutiveFunction(void *pContext)
    {
	SPara *p = (SPara*)pContext;

	p->mutex.Lock();

	p->Flag++;
	
	p->mutex.Unlock();

	return CLStatus(0, 0);
    }
};

/**
 * 主函数
 * 创建线程并执行自定义功能函数，通过共享参数结构体与子线程通信，
 * 在子线程运行期间主线程等待并最终同步访问共享数据。
 * @return 程序执行状态码，正常退出返回0
 */
int main()
{
    // 创建自定义功能提供者实例，用于在线程中执行特定功能
    CLExecutiveFunctionProvider *myfunction = new CLMyFunction();
    // 创建线程对象，将功能提供者与线程关联
    CLExecutive *pThread = new CLThread(myfunction);

    // 初始化线程间共享的参数结构体
    SPara *p = new SPara;
    p->Flag = 3;

    // 启动线程执行，传递共享参数
    pThread->Run((void *)p);

    // 锁定互斥量以安全访问共享数据
    p->mutex.Lock();

    // 修改共享数据并在控制台输出结果
    p->Flag++;
    cout << p->Flag << endl;

    // 解锁互斥量，允许其他线程访问共享数据
    p->mutex.Unlock();

    // 等待线程执行完成
    pThread->WaitForDeath();

    // 清理动态分配的内存资源
    delete p;

    delete pThread;
    delete myfunction;

    return 0;
}