#include<pthread.h>
#include<iostream>
#include<unistd.h>

using namespace std;

void *thread(void *arg)
{
    sleep(5);
    long i = (long)arg;
    cout << "in thread, tid = " << pthread_self() << endl;
    cout << "arg is " << i << endl;

    return (void *)0;
}

// 程序执行没有任何输出，因为主线程创建子线程后立刻退出，导致进程终止，子线程还没来得及执行就被强制终止了
int main()
{
    pthread_t tid;
    if(pthread_create(&tid, NULL, thread, (void *)2) != 0)
    {
	cout << "pthread_create error" << endl;
	return 0;
    }

    return 0;
}