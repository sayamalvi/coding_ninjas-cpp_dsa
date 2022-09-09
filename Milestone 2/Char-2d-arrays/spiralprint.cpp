#include <iostream>
using namespace std;
void spiralPrint(int **input, int nRows, int nCols)
{
    if ((nRows == 0) || (nCols == 0))
    {
        return;
    }

    int i, currRow = 0, currCol = 0;
    while (currRow < nRows && currCol < nCols)
    {
        for (i = currCol; i < nCols; i++)
        {
            // print the first row normally
            cout << input[currRow][i] << " ";
        }
        currRow++; // point to next row
        for (i = currRow; i < nRows; ++i)
        {
            // Print the last column
            cout << input[i][nCols - 1] << " ";
        }
        nCols--; // set the n-1th column is current last column
        if (currRow < nRows)
        {
            // when currRow is in the range, print the last row
            for (i = nCols - 1; i >= currCol; --i)
            {
                cout << input[nRows - 1][i] << " ";
            }
            nRows--; // decrease the row range
        }
        if (currCol < nCols)
        {
            // when currCol is in the range, print the fist column
            for (i = nRows - 1; i >= currRow; --i)
            {
                cout << input[i][currCol] << " ";
            }
            currCol++;
        }
    }

    // second approach

    // int count = 0;
    // int cs=0,rs=0,ce=nCols-1,re=nRows-1;
    // while(count<nRows*nCols){
    //     for(int i = cs;i<=ce;i++){
    //         cout << input[rs][i] << " ";
    //         count++;
    //     }
    //      rs++;
    //     for(int i = rs;i<=re;i++){
    //         cout << input[i][ce] << " ";
    //         count++;
    //     }
    //     ce--;
    //     if(count<nRows*nCols){
    //     for(int i = ce;i>=cs;i--){
    //         cout << input[re][i] << " ";
    //         count++;
    //     }
    //     re--;
    //     for(int i = re;i>=rs;i--){
    //         cout << input[i][cs] << " ";
    //         count++;
    //     }
    //     cs++;
    //     }
    // }
}
int main()
{
}