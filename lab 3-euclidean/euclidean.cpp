#include <iostream>
using namespace std;

class Euclidean
{
protected:
    int a, b, temp;

public:
    void takeInput()
    {
        cout << "Enter A and B: ";
        cin >> a >> b;
        cout << "Assuming A = " << a << " and b = " << b << endl;
    }
    int calculate()
    {
        if (b == 0)
            return a;
        else
        {
            temp = b;
            b = a % b;
            a = temp;
            return calculate();
        }
    }
};

class ExtendedEuclidean : public Euclidean
{
public:
    int s1 = 1, s2 = 0, s, t1 = 0, t2 = 1, t, q; // q is quotient, s and t are from sa+tb=gcd(a,b)
    int calculate()
    {
        if (b == 0)
        {
            return a;
        }
        else
        {
            q = a / b;
            s = s1 - q * s2;
            t = t1 - q * t2;
            s1 = s2;
            s2 = s;
            t1 = t2;
            t2 = t;
            temp = b;
            b = a % b;
            a = temp;
            return calculate();
        }
    }
};

int main()
{
    char ans;
    int opType, gcd;
    do
    {
        Euclidean e;
        ExtendedEuclidean ee;
        cout << "What type of operation would you like to perform?" << endl;
        cout << "1. Euclidean\n2. Extended Euclidean\n";
        cin >> opType;
        switch (opType)
        {
        case 1:
            e.takeInput();
            gcd = e.calculate();
            cout << "The gcd is " << gcd << endl;
            break;
        case 2:
            ee.takeInput();
            gcd = ee.calculate();
            cout << "GCD is: " << gcd << endl
                 << "s is: " << ee.s1 << ", t is: " << ee.t1 << endl; // the values of s1 and t1 at last is value of s and t
            break;
        default:
            cout << "Enter valid option\n";
            break;
        }
        cout << "Repeat again? (y/n)\n";
        cin >> ans;
    } while (tolower(ans) == 'y');
    return 0;
}