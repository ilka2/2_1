#include <iostream>
#include <windows.h>

using namespace std;


class smart_array
{
public: 
    int len;
    int nowLen;
    int* arr;

    smart_array(int len)
    {
        this->len = len;
        nowLen = 0;
        arr = new int[len]();
    }

    /*void expansione_array(int* arr)
    {
        len *= 2;

        int* array = new int[len]();

        for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
        {
            array[i] = arr[i];
        }

        delete[] arr;
        arr = new int[len]();

        for (int i = 0; i < len; i++)
        {
            arr[i] = array[i];
        }

        delete[] array;
    }*/

    int* expansione_array(static int* arr)
    {
        len *= 2;

        int* array = new int[len]();

        for (int i = 0; i < (len / 2); i++)
        {
            array[i] = arr[i];
        }

        delete[] arr;

        return array;
    }

    void add_element(int number)
    {
        if (len == nowLen)
        {
            arr = expansione_array(arr);
        }

        arr[nowLen] = number;
        nowLen += 1;
    }


    int get_element(int number)
    {
        if (nowLen > number)
        {
            return arr[number];
        }
        throw runtime_error("Такого элемента массива еще не существует!");

        return 0;
    }

    void now_length()
    {
        cout << nowLen;
    }

    void length()
    {
        cout << len;
    }

    ~smart_array()
    {
        delete[] arr;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try {
        smart_array arr(3);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
        arr.add_element(999);
        std::cout << arr.get_element(5) << std::endl;
    }
    catch (const exception& ex) {
        cout << ex.what() << endl;
    }

    return 0;
}