#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
//создадим простой класс
class ClassData
{
public:
//внутренние поля 
//поленимся и не будем заботиться о стилистическом оформлении класса
   int a;
   int b;


//конструктор
   ClassData()

   {
       a = 5;
       b = 10;
   }


//метод, чтобы получить а
   int getA()const
   {
       return a;
   }


//метод чтобы получить b
   int getB()const
   {
       return b;
   }
};

int main(int argc, char *argv[])
{
//выделим память на стеке для 10-ти объектов
   unsigned char buff[sizeof(ClassData)*10];
//обнулим память для чистоты эксперимента
   memset(buff,0,sizeof(ClassData)*10);
//для того чтобы объекты создались в сырой памяти (смотрите выше, мы выделяли именно нужное количество байт, а не объекты ClassData),
//нам нужно вызвать new с размещением, который и вызовет конструкторы
   ClassData* cursor = new(buff) ClassData[10];
   ClassData* classData2 = cursor+5;
//теперь при выводе значения A мы увидим 5-ку (а не 0)
//как и должно быть, поскольку в конструкторе по умолчанию мы 
//задаем значение а равное 5
   std::cout<<classData2->getA()<<std::endl;
   return 0;
}