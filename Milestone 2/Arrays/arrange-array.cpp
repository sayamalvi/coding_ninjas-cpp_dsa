void arrange(int *arr, int n)
{
    // First Approach
    cin >> n;
    int st = 0, en = n - 1;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 != 0)
        {
            arr[st] = i;
            st++;
        }
        else
        {
            arr[en] = i;
            en--;
        }
    }

    //  Second approach

    // cin >> n;
    // int val = 1;
    // int first = (n - 1) / 2;
    // int second = first + 1;
    // for (int i = 0; i <= first; i++)
    // {
    //     arr[i] = val;
    //     val += 2;
    // }
    // if (n % 2 == 0)
    // {
    //     val = n;
    // }
    // else
    // {
    //     val = n - 1;
    // }
    // for (int j = second; j < n; j++)
    // {
    //     arr[j] = val;
    //     val -= 2;
    // }

    //  Third approach

    // cin >> n;
    // int val = 1, s=0, e=n-1,loop;
    // if(n%2==0){
    //   loop = n/2;
    // }
    // else{
    //     loop = (n/2)+1;
    // }
    // for(int i = 0;i<loop;i++){
    //     arr[s] = val;
    //     val++;
    //     if(s==e){
    //     break;
    //     }
    //     arr[e] = val;
    //     val++;
    //     s++;
    //     e--;
    // }
}

#include <iostream>
using namespace std;
int main()
{
}
