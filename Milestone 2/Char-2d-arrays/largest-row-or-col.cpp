#include <iostream>
using namespace std;
// void findLargest(int **input, int nRows, int mCols)
// {
//     int cmax = -2147483648, rmax = -2147483648;
//     int csum = 0, cind = 0;
//     int rsum = 0, rind = 0;
//     for (int j = 0; j < nRows; j++)
//     {
//         int csum = 0;
//         for (int i = 0; i < mCols; i++)
//         {
//             csum = csum + input[i][j];
//         }
//         if (csum > cmax)
//         {
//             cmax = csum;
//             csum = 0;
//             cind = j;
//         }
//     }
//     for (int i = 0; i < mCols; i++)
//     {
//         int rsum = 0;
//         for (int j = 0; j < nRows; j++)
//         {
//             rsum = rsum + input[i][j];
//         }
//         if (rsum > rmax)
//         {
//             rmax = rsum;
//             rsum = 0;
//             rind = i;
//         }
//     }
//     if (cmax > rmax)
//         cout << "column"
//              << " " << cind << " " << cmax;
//     else
//         cout << "row"
//              << " " << rind << " " << rmax;
// }

#include <climits>
void findLargest(int **input, int nRows, int mCols)
{
    int cmax = -2147483648, rmax = -2147483648;
    int cind = 0;
    int rind = 0;
    for (int i = 0; i < nRows; i++)
    {
        int rsum = 0;
        for (int j = 0; j < mCols; j++)
        {
            rsum = rsum + input[i][j];
        }
        if (rsum > rmax)
        {
            rmax = rsum;

            rind = i;
        }
    }

    for (int i = 0; i < mCols; i++)
    {
        int csum = 0;
        for (int j = 0; j < nRows; j++)
        {
            csum = csum + input[j][i];
        }
        if (csum > cmax)
        {
            cmax = csum;

            cind = i;
        }
    }

    if (cmax > rmax)
        cout << "column"
             << " " << cind << " " << cmax << endl;
    else
        cout << "row"
             << " " << rind << " " << rmax << endl;
}

int main()
{
}
