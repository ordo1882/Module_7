#include <iostream>
#include <string>
#include <exception>
#include "IntArray.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    try
    {
        // ����� ������� ������������� ������ � �����������, ������ ������� ������ ������ �� ������� ������������.
        int size;
        cout << "Enter the size of array:" << endl;
        cin >> size;

        //����� ��������� ���������� ������ �������.
        if (size > 100)
        {
            throw length_error("array is too big");
        }

        // ��������� ������������ ���� ���������� int. ����� �������� � �� ���� ������� �����, �� ����� ��� ��������� �������. 
        // ����� ���������� ���������� �� ������� ������ ��� �� �����, ��� � �������. ��-������ ����� �� ������ � ������� �����.
        if (cin.get() != (int)'\n')
        {
            throw bad_typeid();
        }

        // ��� ������� ������ ������������, � ��������� ����� ����������.
        int* arr = new int[size];
        cout << "Enter values:" << endl;
        int j;
        for (int i = 0; i < size; ++i)
        {
            cin >> j;

            if (cin.get() != (int)'\n')
            {
                throw bad_typeid();
            }

            arr[i] = j;
        }

        // ������� ������ ����������
        IntArray array(size);
        
        // ������ ��� ������ ������������ � ��������� � ��������� �������� ���������.
        array.enternumbers(size, arr);
        array.showArray();

        // ������� ����������� ������, ��� ��� �� ��� ������ �� �����.
        delete[] arr;

        while (true)
        {
            // ������������� ������������ ����� �������� � �����������. ����� ������ �������� � ������� ��������� ��������� ���������� ����� �������� ���������.
            // ��� ����������, � �������� ������������� �������� �� ��� �������� ��������.
            cout << "Choose an operation with your Array:" << endl
                << "Resize an array - 1" << endl
                << "Insert a new value before element - 2" << endl
                << "Remove element from the array - 3" << endl
                << "Insert new element at the beginning of array - 4" << endl
                << "Insert a new element at the end of array - 5" << endl
                << "To show the element by index - 6" << endl
                << "To find the element by value - 7" << endl
                << "To copy an array - 8" << endl
                << "To exit - 0" << endl;

            int choise;
            cin >> choise;
            cout << endl;

            switch (choise)
            {
            case 1:
                int newLenght;
                cout << "Enter a new length of array:" << endl;
                cin >> newLenght;
                cout << endl;

                array.resize(newLenght);
                array.showArray();
                break;

            case 2:
                int valBefore;
                int elemBefore;
                cout << "Enter the value: ";
                cin >> valBefore;
                cout << "Enter the index of element: ";
                cin >> elemBefore;
                cout << endl;

                array.insertBefore(valBefore, elemBefore);
                array.showArray();
                break;

            case 3:
                int elemRemove;
                cout << "Enter the index of element to remove: ";
                cin >> elemRemove;
                cout << endl;

                array.remove(elemRemove);
                array.showArray();
                break;

            case 4:
                int valBegin;
                cout << "Enter the value to put at the beginning of array: ";
                cin >> valBegin;
                cout << endl;

                array.insertAtBeginning(valBegin);
                array.showArray();
                break;

            case 5:
                int valEnd;
                cout << "Enter the value to put at the end of array: ";
                cin >> valEnd;
                cout << endl;

                array.insertAtEnd(valEnd);
                array.showArray();
                break;

            case 6:
                int index;
                cout << "Enter the index to show: ";
                cin >> index;
                cout << endl;

                array.showIndex(index);
                array.showArray();
                break;

            case 7:
                int value;
                cout << "Enter the value to find: ";
                cin >> value;
                cout << endl;

                array.findElement(value);
                array.showArray();
                break;

            case 8:
                {
                    IntArray b{ array };
                    b = array;
                    b = b;
                    array = array;
                }
                cout << endl;
                array.showArray();
                break;

            case 0:
                return false;
                break;

            default:
                break;
            }
        }
    }
    catch (const exception& exception)
    {
        cerr << "Error: " << exception.what() << '\n';
    }

    return 0;
}