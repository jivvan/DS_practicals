#include <iostream>
#include <set>
using namespace std;

void printCartesian(set<int> &A, set<int> &B)
{
    cout << "The cartesian product is: {";
    for (auto i = A.begin(); i != A.end(); i++)
    {
        for (auto j = B.begin(); j != B.end(); j++)
        {
            cout << "(" << *i << "," << *j << ")";
            if (*A.rbegin() != *i || *B.rbegin() != *j)
                cout << ",";
        }
    }
    cout << "}\n";
}

void printDifference(set<int> &A, set<int> &B)
{
    set<int> differenceSet;
    cout << "The difference is:  A-B={";
    for (auto i = A.begin(); i != A.end(); i++)
    {
        bool isDifferent = true;
        for (auto j = B.begin(); j != B.end(); j++)
        {
            if (*i == *j)
            {
                isDifferent = false;
            }
        }
        if (isDifferent)
        {
            cout << *i << ",";
        }
    }
    cout << "}\n";
}

void printUnion(set<int> &A, set<int> &B)
{
    set<int> unionSet;
    for (auto i = A.begin(); i != A.end(); i++)
    {
        unionSet.insert(*i);
    }
    for (auto i = B.begin(); i != B.end(); i++)
    {
        unionSet.insert(*i);
    }
    cout << "The union is: {";
    for (auto i = unionSet.begin(); i != unionSet.end(); i++)
    {
        cout << *i;
        if (*unionSet.rbegin() != *i)
            cout << ",";
    }
    cout << "}\n";
}
void printIntersection(set<int> &A, set<int> &B)
{
    set<int> intersectionSet;
    for (auto i = A.begin(); i != A.end(); i++)
    {
        if (B.count(*i) != 0)
            intersectionSet.insert(*B.find(*i));
    }
    cout << "The intersection is: {";
    for (auto i = intersectionSet.begin(); i != intersectionSet.end(); i++)
    {
        cout << *i;
        if (*intersectionSet.rbegin() != *i)
            cout << ",";
    }
    cout << "}\n";
}

int main()
{
    char ans;
    int lenA, lenB, el, opt;
    set<int> A, B;
    cout << "Enter number of elements in set A: \n";
    cin >> lenA;
    for (int i = 0; i < lenA; i++)
    {
        cout << "Enter element " << i + 1 << ":";
        cin >> el;
        A.insert(el);
    }
    cout << "Enter number of elements in set B: \n";
    cin >> lenB;
    for (int i = 0; i < lenB; i++)
    {
        cout << "Enter element " << i + 1 << ":";
        cin >> el;
        B.insert(el);
    }
    do
    {
        cout << "Which set operation would you like to perform?\n1.Cartesian Product\n2.Difference\n3.Union\n4.Intersection\n";
        cin >> opt;
        switch (opt)
        {
        case 1:
            printCartesian(A, B);
            break;
        case 2:
            printDifference(A, B);
            break;
        case 3:
            printUnion(A, B);
            break;
        case 4:
            printIntersection(A, B);
            break;
        default:
            break;
        }
        cout
            << "Would you like to perform another operation? ";
        cin >> ans;
    } while (tolower(ans) == 'y');
}