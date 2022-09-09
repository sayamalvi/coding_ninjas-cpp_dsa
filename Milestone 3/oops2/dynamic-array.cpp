#include <iostream>
using namespace std;
class DynamicArray
{
public:
    int *data;
    int nextIndex = 0, size;
    DynamicArray()
    {
        data = new int[5];
        size = 5;
    }
    DynamicArray(DynamicArray const &d)
    {
        this->data = new int[d.size];
        for (int i = 0; i < d.nextIndex; i++)
        {
            this->data[i] = d.data[i];
        }
        this->nextIndex = d.nextIndex;
        this->size = d.size;
    }
    void operator=(DynamicArray const &d)
    {
        this->data = new int[d.size];
        for (int i = 0; i < d.nextIndex; i++)
        {
            this->data[i] = d.data[i];
        }
        this->nextIndex = d.nextIndex;
        this->size = d.size;
    }
    void addElement(int element)
    {
        if (nextIndex == size)
        {
            int *newData = new int[2 * size];
            for (int i = 0; i < size; i++)
            {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            size *= 2;
            newData[nextIndex] = element;
            nextIndex++;
        }
        else
        {
            data[nextIndex] = element;
            nextIndex++;
        }
    }
    int getIndex(int i)
    {
        if (i < nextIndex)
        {
            return data[i];
        }
        else
        {
            return -1;
        }
    }
    void addAtParticularIndex(int i, int element)
    {
        if (i < nextIndex)
        {
            data[i] = element;
        }
        else if (i == nextIndex)
        {
            addElement(element);
        }
        else
            return;
    }
    void print() const
    {
        for (int i = 0; i < nextIndex; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    DynamicArray d1;
    d1.addElement(10);
    d1.addElement(20);
    d1.addElement(30);
    d1.addElement(40);
    d1.addElement(50);
    d1.addElement(60);
    d1.print();
    DynamicArray d2(d1);
    DynamicArray d3;
    d3 = d1;
    d1.addAtParticularIndex(0, 100);
    d1.print();
    d2.print();
    d3.print();
}