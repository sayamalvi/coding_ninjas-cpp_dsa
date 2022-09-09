#include <iostream>
using namespace std;

void printSubsetsOfArray(int input[], int inputSize, int output[], int outputSize)
{
    if (inputSize == 0)
    {
        for (int i = 0; i < outputSize; i++)
        {
            cout << output[i] << " ";
        }
        cout << endl;
        return;
    }

    printSubsetsOfArray(input + 1, inputSize - 1, output, outputSize);
    int *newOutput = new int[20];
    // int newOutput[20] = {};
    for (int i = 0; i < outputSize; i++)
    {
        newOutput[i] = output[i];
    }
    newOutput[outputSize] = input[0];
    printSubsetsOfArray(input + 1, inputSize - 1, newOutput, outputSize + 1);

    delete[] newOutput;
}

void printSubsetsOfArray(int input[], int size)
{
    int *output = new int[20];
    // int output[20] = {};
    printSubsetsOfArray(input, size, output, 0);

    delete[] output;
}

int main()
{
}