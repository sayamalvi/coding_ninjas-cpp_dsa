#include <iostream>
using namespace std;
void wavePrint(int **input, int nRows, int mCols)
{
    for (int j = 0; j < mCols; j++)
    {
        if (j == 0 || j % 2 == 0)
        {
            for (int i = 0; i < nRows; i++)
            {
                cout << input[i][j] << " ";
            }
        }
        else
        {
            for (int i = nRows - 1; i >= 0; i--)
            {
                cout << input[i][j] << " ";
            }
        }
    }
}
int main()
{
}