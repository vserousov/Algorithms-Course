/*
 * Программу разработал Сероусов Виталий Эдуардович, группа 201(1)
 * Проект 1
 * Среда разработки: Visual Studio 2013
 */
#include <iostream>
using namespace std;

//Описание прототипов функций
int * toBits(unsigned int number);
unsigned int toInt(int* bits);
void invertBits(int* bits);
void printBits(int * bits);
bool qPressed();

//Точка входа в программу
void main()
{
    setlocale(LC_ALL, "Russian");
    do
    {    
        //Объединение, содержащее типы float и unsigned int
        //Переменная b является удобным способом для представления данных из переменной a в десятичном виде
        //Это позволяет из переменной b получить двоичный код, который равен двоичному коду переменной а
        union Number
        {
            float a;
            unsigned int b;
        };

        Number num;

        float number;
        cout << "Введите вещественное число: ";
        //Пытаемся прочесть число из клавиатуры
        cin >> number;

        //Проверка входных данных
        //Вывод ошибки о неправильном формате числа
        if (cin.fail())
        {
            cout << "\nНеправильный формат числа. Попробуйте еще раз.\n" << endl;
            //Очищаем поток ввода
            cin.clear();
            cin.ignore(10000, '\n');
            //Заставляем пользователя вводить всё сначала
            continue;
        }

        //Если число прочиталось, то образом как оно прочиталось
        //Например, могут быть удалены лишние символы после пробела
        cout << "\nПрочтенное число: " << number << endl;

        //Присваиваем нашему объединению
        num.a = number;

        //Получаем массив битов
        int * bits = toBits(num.b);
        //Выводим их
        cout << "\nБиты числа: " << endl;
        printBits(bits);

        //Инвертируем порядок расположения массива битов
        invertBits(bits);
        //Печатаем их
        cout << "\nИнвертированные биты числа: " << endl;
        printBits(bits);

        //Преобразуем массив битов в беззнаковое целое и присваиваем переменной b в объединении
        num.b = toInt(bits);
        //Печатаем полученное число a из объединения
        cout << "\nПолученное число:" << endl;
        cout << num.a << endl;

        //Информируем пользователя, о том, какие клавиши набрать для продолжения\выхода
        cout << "\nДля выхода из программы введите q" << endl;
        cout << "Для того, чтобы продолжить работу, введите любой символ или нажмите ENTER" << endl;

        //Удаляем из памяти наш массив
        delete[] bits;

        //Очищаем поток ввода
        cin.clear();
        cin.ignore(10000, '\n');

        //Если пользователь ввёл q, то выходим из программы
        if (qPressed())
            break;

    } while (true); //повторяем бесконечно
    //system("pause"); //не требуется, так как при выходе из программы будет лишняя задержка
}

//Функция, проверяющая, ввели ли символ q
bool qPressed()
{
    //получаем символ с клавиатуры
    char c = getchar();
    if (c == 'q')
        return true;
    else
        return false;
}

//Функция, преобразовующая беззнаковое целое число в массив битов. Возвращает указатель на массив.
int* toBits(unsigned int number)
{
    int length = 8 * sizeof(float);
    int* result = new int[length];
    for (int i = length - 1; i >= 0; i--)
    {
        result[i] = number % 2;
        number /= 2;
    }
    return result;
}

//Функция преобразующая массив битов в беззнаковое целое
unsigned int toInt(int * bits)
{
    int length = 8 * sizeof(float);
    unsigned int result = 0;
    for (int i = 0; i < length; i++)
    {
        result += bits[i] * pow(2, length - i - 1);
    }
    return result;
}

//Функция, инвертирующая порядок расположения битов
void invertBits(int* bits)
{
    int length = 8 * sizeof(float);
    for (int i = 0; i < length / 2; i++)
    {
        int temp = bits[length - i - 1];
        bits[length - i - 1] = bits[i];
        bits[i] = temp;
    }
}

//Функция, печатающая биты из массива битов
void printBits(int* bits)
{
    int length = 8 * sizeof(float);
    for (int i = 0; i < length; i++)
    {
        cout << bits[i];
        //Через каждые 8 битов ставим пробел - для удобного чтения
        if ((i + 1) % 8 == 0)
        {
            cout << " ";
        }
    }
    cout << endl;
}