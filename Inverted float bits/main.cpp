/*
 * ��������� ���������� �������� ������� ����������, ������ 201(1)
 * ������ 1
 * ����� ����������: Visual Studio 2013
 */
#include <iostream>
using namespace std;

//�������� ���������� �������
int * toBits(unsigned int number);
unsigned int toInt(int* bits);
void invertBits(int* bits);
void printBits(int * bits);
bool qPressed();

//����� ����� � ���������
void main()
{
    setlocale(LC_ALL, "Russian");
    do
    {    
        //�����������, ���������� ���� float � unsigned int
        //���������� b �������� ������� �������� ��� ������������� ������ �� ���������� a � ���������� ����
        //��� ��������� �� ���������� b �������� �������� ���, ������� ����� ��������� ���� ���������� �
        union Number
        {
            float a;
            unsigned int b;
        };

        Number num;

        float number;
        cout << "������� ������������ �����: ";
        //�������� �������� ����� �� ����������
        cin >> number;

        //�������� ������� ������
        //����� ������ � ������������ ������� �����
        if (cin.fail())
        {
            cout << "\n������������ ������ �����. ���������� ��� ���.\n" << endl;
            //������� ����� �����
            cin.clear();
            cin.ignore(10000, '\n');
            //���������� ������������ ������� �� �������
            continue;
        }

        //���� ����� �����������, �� ������� ��� ��� �����������
        //��������, ����� ���� ������� ������ ������� ����� �������
        cout << "\n���������� �����: " << number << endl;

        //����������� ������ �����������
        num.a = number;

        //�������� ������ �����
        int * bits = toBits(num.b);
        //������� ��
        cout << "\n���� �����: " << endl;
        printBits(bits);

        //����������� ������� ������������ ������� �����
        invertBits(bits);
        //�������� ��
        cout << "\n��������������� ���� �����: " << endl;
        printBits(bits);

        //����������� ������ ����� � ����������� ����� � ����������� ���������� b � �����������
        num.b = toInt(bits);
        //�������� ���������� ����� a �� �����������
        cout << "\n���������� �����:" << endl;
        cout << num.a << endl;

        //����������� ������������, � ���, ����� ������� ������� ��� �����������\������
        cout << "\n��� ������ �� ��������� ������� q" << endl;
        cout << "��� ����, ����� ���������� ������, ������� ����� ������ ��� ������� ENTER" << endl;

        //������� �� ������ ��� ������
        delete[] bits;

        //������� ����� �����
        cin.clear();
        cin.ignore(10000, '\n');

        //���� ������������ ��� q, �� ������� �� ���������
        if (qPressed())
            break;

    } while (true); //��������� ����������
    //system("pause"); //�� ���������, ��� ��� ��� ������ �� ��������� ����� ������ ��������
}

//�������, �����������, ����� �� ������ q
bool qPressed()
{
    //�������� ������ � ����������
    char c = getchar();
    if (c == 'q')
        return true;
    else
        return false;
}

//�������, ��������������� ����������� ����� ����� � ������ �����. ���������� ��������� �� ������.
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

//������� ������������� ������ ����� � ����������� �����
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

//�������, ������������� ������� ������������ �����
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

//�������, ���������� ���� �� ������� �����
void printBits(int* bits)
{
    int length = 8 * sizeof(float);
    for (int i = 0; i < length; i++)
    {
        cout << bits[i];
        //����� ������ 8 ����� ������ ������ - ��� �������� ������
        if ((i + 1) % 8 == 0)
        {
            cout << " ";
        }
    }
    cout << endl;
}