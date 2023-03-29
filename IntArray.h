#pragma once
#include <exception>
#include <string>

using namespace std;

class IntArray
{
private:
    int m_length{};
    int* m_data{};

public:
    IntArray() = default;

    IntArray(int length) : m_length{ length }
    {
        m_data = new int[length] {};
    }

    IntArray(const IntArray& a)
    {
        reallocate(a.getLength());
        for (size_t i = 0; i < m_length; ++i)
        {
            m_data[i] = a.m_data[i];
            cout << a.m_data[i] << ' ';
        }
    }

    ~IntArray()
    {
        delete[] m_data;
    }

    void enternumbers(int length, int arr[])
    {
        for (size_t i = 0; i < length; ++i)
        {
            m_data[i] = arr[i];
        }
    }

    void showArray()
    {
        for (int i{ 0 }; i < m_length; ++i)
        {
            cout << m_data[i] << ' ';
        }
        cout << '\n' << '\n';
    }

    void erase()
    {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }

    int& operator[](int i)
    {
        if (i < 0 || i > m_length)
        {
            throw out_of_range("element is out of defined array range");
        }
        return m_data[i];
    }

    void reallocate(int newLength)
    {
        erase();
        if (newLength <= 0)
        {
            return;
        }
        m_data = new int[newLength];
        m_length = newLength;
    }

    void resize(int newLength)
    {
        if (newLength == m_length)
        {
            return;
        }

        int* data{ new int[newLength] };

        if (m_length > 0)
        {
            int elementsToCopy{ (newLength > m_length) ? m_length : newLength };

            for (size_t i = 0; i < elementsToCopy; ++i)
            {
                data[i] = m_data[i];
            }
        }

        delete[] m_data;

        m_data = data;
        m_length = newLength;
    }

    IntArray& operator=(const IntArray& a)
    {
        if (&a == this)
        {
            return *this;
        }

        reallocate(a.getLength());

        for (size_t i = 0; i < m_length; ++i)
        {
            m_data[i] = a.m_data[i];
        }

        return *this;
    }

    void insertBefore(int value, int index)
    {
        if (index < 0 || index > m_length)
        {
            throw out_of_range("index is out of the defined array range");
        }

        if (index != (int)'\n')
        {
            throw bad_typeid();
        }

        int* data{ new int[m_length + 1] };

        for (size_t before = 0; before < index; ++before)
        {
            data[before] = m_data[before];
        }

        data[index] = value;

        for (size_t after = index; after < m_length; ++after)
        {
            data[after + 1] = m_data[after];
        }

        delete[] m_data;
        m_data = data;
        ++m_length;
    }

    void remove(int index)
    {
        if (index < 0 || index > m_length)
        {
            throw out_of_range("index is not exists in the array range");
        }

        if (m_length == 1)
        {
            erase();
            return;
        }

        int* data{ new int[m_length - 1] };

        for (size_t before = 0; before < index; ++before)
        {
            data[before] = m_data[before];
        }

        for (size_t after = index + 1; after < m_length; ++after)
        {
            data[after - 1] = m_data[after];
        }

        delete[] m_data;
        m_data = data;
        --m_length;
    }

    void insertAtBeginning(int value) 
    {
        insertBefore(value, 0); 
    }

    void insertAtEnd(int value) 
    {
        insertBefore(value, m_length); 
    }

    void showIndex(int index)
    {
        if (index != (int)'\n')
        {
            throw bad_typeid();
        }

        int j;
        for (size_t i = 0; i <= index; ++i)
        {
            j = m_data[i];
        }
        cout << "Value under index " << index << " is " << j << endl << endl;
    }

    void findElement(int value)
    {
        if (value != (int)'\n')
        {
            throw bad_typeid();
        }

        for (size_t i = 0; i < m_length; ++i)
        {
            if (m_data[i] == value)
            {
                cout << "Index of the value " << value << " is " << i << endl;
                break;
            }
        }
    }

    int getLength() const 
    {
        return m_length; 
    }
};