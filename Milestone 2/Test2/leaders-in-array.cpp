#include <iostream>
using namespace std;
#include<climits>


void Leaders(int *arr, int len)
{
    int j = 0;
    int *temp = new int[len];
    int largest = INT_MIN;
    for (int i = len - 1; i >= 0; i--)
    {
        if (arr[i] >= largest)
        {
            temp[j] = arr[i];
            j++;
            largest = arr[i];
        }
    }
    for (int i = j - 1; i >= 0; i--)
    {
        cout << temp[i] << " ";
    }
}

int main()
{
    int len;
    cin>>len;
	int *arr = new int[len + 1];
	
	for(int i=0;i<len;i++)
	{
		cin>>arr[i];
	}
	Leaders(arr,len);
}