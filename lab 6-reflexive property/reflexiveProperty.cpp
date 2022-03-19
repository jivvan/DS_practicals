#include <iostream>
#include <vector>
using namespace std;

bool checkReflexive(vector<vector<int>> matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        if (matrix[i][i] != 1)
        {
            return false;
        }
    }
    return true;
}

bool checkSymmetric(vector<vector<int>> matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            if (matrix[i][j] != matrix[j][i])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int size;
    cout << "Enter size of relation matrix" << endl;
    cin >> size;
    cout << "Enter elements of relation matrix rowwise: " << endl;
    vector<vector<int>> relMatrix;
    for (int i = 0; i < size; i++)
    {
        vector<int> matrixRow;
        for (int j = 0; j < size; j++)
        {
        retakeInput:
            int temp;
            cout << "Enter " << i << "*" << j << " element";
            cin >> temp;
            if (temp > 1 || temp < 0)
            {
                cout << "Value can be either 0 or 1";
                goto retakeInput;
            }
            matrixRow.push_back(temp);
        }
        relMatrix.push_back(matrixRow);
    }
    bool runAgain = true;
    int opt;
    char ans;
    while (runAgain)
    {
        cout << "What operation would you like to perform?\n1. Check Reflexive\n2. Check Symmetric\n";
        cin >> opt;
        switch (opt)
        {
        case 1:
            if (checkReflexive(relMatrix))
            {
                cout << "The relation is reflexive.\n";
            }
            else
            {
                cout << "The relation is not reflexive.\n";
            }
            break;
        case 2:
            if (checkSymmetric(relMatrix))
            {
                cout << "The relation is symmetric.\n";
            }
            else
            {
                cout << "The relation is not symmetric.\n";
            }
        default:
            break;
        }
        cout << "Would you like to try again? (y/n)";
        cin >> ans;
        if (tolower(ans) != 'y')
        {
            runAgain = false;
        }
    }
    return 0;
}