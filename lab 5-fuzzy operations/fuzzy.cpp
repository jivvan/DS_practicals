#include <iostream>
#include <vector>
using namespace std;

class FuzzyElement
{
public:
    float domain;
    float membership;
};

void printUnion(vector<FuzzyElement> &fuzzySet1, vector<FuzzyElement> &fuzzySet2)
{
    vector<FuzzyElement> unionSet;
    cout << "The union of two sets is: \n";
    for (int i = 0; i < fuzzySet1.size(); i++)
    {
        for (int j = 0; j < fuzzySet2.size(); j++)
        {
            if (fuzzySet1[i].domain == fuzzySet2[j].domain)
            {
                if (fuzzySet1[i].membership > fuzzySet2[j].membership)
                {
                    unionSet.push_back(fuzzySet1[i]);
                }
                else
                {
                    unionSet.push_back(fuzzySet2[j]);
                }
            }
        }
    }
    for (int i = 0; i < unionSet.size(); i++)
    {
        cout << "domain: " << unionSet[i].domain << " membership: " << unionSet[i].membership << endl;
    }
}

void printIntersection(vector<FuzzyElement> &fuzzySet1, vector<FuzzyElement> &fuzzySet2)
{
    vector<FuzzyElement> intersectionSet;
    cout << "The union of two sets is: \n";
    for (int i = 0; i < fuzzySet1.size(); i++)
    {
        for (int j = 0; j < fuzzySet2.size(); j++)
        {
            if (fuzzySet1[i].domain == fuzzySet2[j].domain)
            {
                if (fuzzySet1[i].membership < fuzzySet2[j].membership)
                {
                    intersectionSet.push_back(fuzzySet1[i]);
                }
                else
                {
                    intersectionSet.push_back(fuzzySet2[j]);
                }
            }
        }
    }
    for (int i = 0; i < intersectionSet.size(); i++)
    {
        cout << "domain: " << intersectionSet[i].domain << " membership: " << intersectionSet[i].membership << endl;
    }
}

void fillValues(vector<FuzzyElement> &fuzzySet1, vector<FuzzyElement> &fuzzySet2)
{
    FuzzyElement temp;
    for (int i = 0; i < fuzzySet1.size(); i++)
    {
        bool notInB = true;
        for (int j = 0; j < fuzzySet2.size(); j++)
        {
            if (fuzzySet1[i].domain == fuzzySet2[j].domain)
            {
                notInB = false;
                break;
            }
        }
        if (notInB)
        {
            temp = fuzzySet1[i];
            temp.membership = 0;
            fuzzySet2.push_back(temp);
        }
    }
    for (int i = 0; i < fuzzySet2.size(); i++)
    {
        bool notInA = true;
        for (int j = 0; j < fuzzySet1.size(); j++)
        {
            if (fuzzySet1[j].domain == fuzzySet2[i].domain)
            {
                notInA = false;
                break;
            }
        }
        if (notInA)
        {
            temp = fuzzySet2[i];
            temp.membership = 0;
            fuzzySet1.push_back(temp);
        }
    }
}

int main()
{
    char ans;
    int aSize, bSize, opt;
    FuzzyElement el;
    vector<FuzzyElement> fuzzySet1, fuzzySet2;
    cout << "Enter size of fuzzy set A: ";
    cin >> aSize;
    for (int i = 0; i < aSize; i++)
    {
        cout << "Enter domain of element " << i + 1 << ": ";
        cin >> el.domain;
    retakeAInput:
        cout << "Enter member of element " << i + 1 << ": ";
        cin >> el.membership;
        if (el.membership > 1 || el.membership < 0)
            goto retakeAInput;
        fuzzySet1.push_back(el);
    }
    cout << "Enter size of fuzzy set B: ";
    cin >> bSize;
    for (int i = 0; i < bSize; i++)
    {
        cout << "Enter domain of element " << i + 1 << ": ";
        cin >> el.domain;
    retakeBInput:
        cout << "Enter member of element " << i + 1 << ": ";
        cin >> el.membership;
        if (el.membership > 1 || el.membership < 0)
            goto retakeBInput;
        fuzzySet2.push_back(el);
    }
    fillValues(fuzzySet1, fuzzySet2);
    do
    {
        cout << "Which operation would you like to perform?\n1.Union\n2.Intersection\n";
        cin >> opt;
        switch (opt)
        {
        case 1:
            printUnion(fuzzySet1, fuzzySet2);
            break;
        case 2:
            printIntersection(fuzzySet1, fuzzySet2);
            break;
        default:
            cout << "Enter valid option!";
            break;
        }
        cout << "Repeat again?(y/n)";
        cin >> ans;
    } while (tolower(ans) == 'y');
    return 0;
}