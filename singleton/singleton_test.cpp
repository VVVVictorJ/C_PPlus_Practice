#include <iostream>
#include <mutex>
#include <pthread.h>
#include <unistd.h>

#pragma region 命名空间调用
using std::cout;
using std::endl;
#pragma endregion

class SingletonInstance
{
private:
    SingletonInstance() { cout << "构造函数" << endl; };
    ~SingletonInstance()
    {
        cout << "析构函数" << endl;
    };
    SingletonInstance(const SingletonInstance &signal);
    const SingletonInstance &operator=(const SingletonInstance &signal);

private:
    static SingletonInstance *m_SingletonInstance;
    class Release_singleton
    {
    public:
        ~Release_singleton()
        {

            if (nullptr != SingletonInstance::m_SingletonInstance)
            {
                delete SingletonInstance::m_SingletonInstance;
                cout << "fuck" << endl;
            }
        }
    };
    /* 
    程序结束时，系统自动析构所有的全局变量，所以定义一个静态成员，系统结束时自动调用其析构函数。
    利用其析构函数，删除单例对象实例。
    一般命名为Gabor(garbage labor 垃圾回收工人)
    */
    static Release_singleton m_release;

public:
    static SingletonInstance *
    GetInstance();
    static void DeleteInstance();
    void print();
};

/* SingletonInstance 实例初始化 */
SingletonInstance *SingletonInstance::m_SingletonInstance = NULL;
/* ReleaseSingletonInstance 实例初始化 */
SingletonInstance::Release_singleton SingletonInstance::m_release;

#pragma region SingletonInstace 函数实现
SingletonInstance *SingletonInstance::GetInstance()
{
    if (m_SingletonInstance == NULL)
    {
        //std::nothrow 分配内存失败的时候返回一个空指针
        //没加锁多线程不安全，线程并发时会创建多个实例
        m_SingletonInstance = new (std::nothrow) SingletonInstance;
    }
    return m_SingletonInstance;
}

void SingletonInstance::DeleteInstance()
{
    if (m_SingletonInstance)
    {
        delete m_SingletonInstance;
        m_SingletonInstance = NULL;
    }
}

void SingletonInstance::print()
{
    cout << "单例实际地址为" << this << endl;
}

#pragma endregion

void *PrintHello(void *threadid)
{
    pthread_detach(pthread_self());
    int tid = *((int *)threadid); //*为解引用符
    cout << "此线程id为：" << tid << endl;
    SingletonInstance::GetInstance()->print();
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[2] = {0};
    int indexes[2] = {0};

    int ret = 0;
    int i = 0;

    cout << "----------main-----------" << endl;
    for (size_t i = 0; i < 2; i++)
    {
        cout << "创建线程[" << i << "]" << endl;
        indexes[i] = i;
        ret = pthread_create(&threads[i], NULL, PrintHello, (void *)&(indexes[i]));
        if (ret)
        {
            cout << "Error! 创建线程[" << i << "] 失败。" << endl;
            exit(-1);
        }
        sleep(1);
    }

    //SingletonInstance::DeleteInstance();
    //sleep(1);
    cout << "----------main结束-----------" << endl;
    return 0;
}