/*
 The following program implements listed programs that
 use recursion.
 1. a^n
 2. b^n mod m
 3. linear search
 */

#include <iostream>
using namespace std;

double recursivePower(double, double);
int recursiveMod(int, int);
int recursiveSearch(int[], int, int);

void powerOperation()
{
    double a, exponent;
    cout << "Enter a:";
    cin >> a;
    cout << "Enter exponent:";
    cin >> exponent;
    double powA = recursivePower(a, exponent);
    cout << a << " to the exponent " << exponent << " is " << powA << endl;
}

void modOperation()
{
    int b, exponent, m;
    cout << "Enter b:";
    cin >> b;
    cout << "Enter exponent:";
    cin >> exponent;
    cout << "Enter m:";
    cin >> m;
    int power = recursivePower(b, exponent);
    int ans = recursiveMod(power, m);
    if (ans == -1)
    {
        cout << "cannot divide by 0" << endl;
        return;
    }
    cout << b << "^" << exponent << " mod " << m << " = " << ans << endl;
}

void linearSearch()
{
    int n, search;
    cout << "Enter an size of array:"
         << endl;
    cin >> n;
    int a[n];
    cout << "Enter elements of array:";
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> a[i];
    }
    cout << "Enter the number to find index of:";
    cin >> search;
    int index = recursiveSearch(a, search, n);
    cout << "The index of " << search << " is " << index << endl;
}

int main()
{
    bool goon = true;
    while (goon)
    {
        int ans;
        cout << "What recursive operation would you like to perform?\n";
        cout << "1. a^n\n2. b^n mod m\n3. linear search\n";
        cin >> ans;
        switch (ans)
        {
        case 1:
            powerOperation();
            break;
        case 2:
            modOperation();
            break;
        case 3:
            linearSearch();
            break;
        default:
            break;
        }
        cout << "Would you like to perform another operation?(y/n)"
             << endl;
        char res;
        cin >> res;
        if (tolower(res) != 'y')
            goon = false;
    }
    return 0;
}

double recursivePower(double a, double exponent)
{

    if (exponent == 1)
        return a;
    else if (exponent < 0)
        return recursivePower(1 / a, -exponent);
    else
    {
        return a * recursivePower(a, exponent - 1);
    }
}

int recursiveMod(int dividend, int divisor)
{
    if (divisor == 0)
        return -1;
    if (dividend < 0)
    {
        return recursiveMod((-1 * dividend) + divisor, divisor);
    }
    else if (dividend < divisor)
        return dividend;
    else
        return recursiveMod(dividend - divisor, divisor);
}

int recursiveSearch(int arr[], int searchItem, int size)
{
    if (size < 0)
        return -1;
    if (arr[size] == searchItem)
    {
        return size;
    }
    return recursiveSearch(arr, searchItem, size - 1);
}