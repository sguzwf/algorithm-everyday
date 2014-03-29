#include <iostream>
#include <string>
#include <cstring>
#include <cassert>
#include <cstdio>
using namespace std;

//����ģʽ
//C++
class Singleton
{
private:
    static Singleton *instance;
    Singleton(){}
public:
    static Singleton* getInstance()
    {
        if (instance == NULL)
        {
            //Lock();
            if (instance == NULL)
            {
                instance = new Singleton();
            }
            //Unlock();
        }
        return instance;
    }
    void display()
    {
        cout << "welcome" << endl;
    }
};
Singleton *Singleton::instance = NULL;//���������ľ�̬�����������ⶨ��

int main()
{
    Singleton::getInstance()->display();
    return 0;
}

//JAVA
public class Singleton
{
    private volatile static Singleton instance;
    private Singleton(){}
    public static Singleton getInstance()
    {
        if (instance == null)
        {
            SYNCHRONIZE(Singleton.class)
            {
                if (instance == null) instance = new Singleton();
            }
        }
    }
}
