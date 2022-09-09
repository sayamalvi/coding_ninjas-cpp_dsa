    int n;
    cin >> n;
    int n1 = (n + 1) / 2, n2 = n / 2;
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2 + 1 - i; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = n2; i >= 1; i--)
    {
        for (int j = 1; j <= n2 - i + 1; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }