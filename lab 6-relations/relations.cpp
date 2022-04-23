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

bool checkTransitive(vector<vector<int>> matrix)
{
    bool isTransitive = true;
    for (int i = 0; i < matrix.size(); i++)
    {
        vector<int> currRow;
        vector<int> currCol;
        for (int j = 0; j < matrix.size(); j++)
        {
            if (matrix[i][j] == 1)
                currRow.push_back(j);
            if (matrix[j][i] == 1)
                currCol.push_back(j);
        }
        for (int c = 0; c < currCol.size(); c++)
        {
            for (int r = 0; r < currRow.size(); r++)
            {
                if (matrix[currCol[c]][currRow[r]] == 0)
                {
                    isTransitive = false;
                    break;
                }
            }
            if (!isTransitive)
                break;
        }
        if (!isTransitive)
            break;
    }
    return isTransitive;
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
        cout << "What operation would you like to perform?\n1. Check Reflexive\n2. Check Symmetric\n3. Check Transitive\n";
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
            break;
        case 3:
            if (checkTransitive(relMatrix))
            {
                cout << "The relation is transitive.\n";
            }
            else
            {
                cout << "The relation is not reflexive.\n";
            }
            break;
        case 4:
            if (checkTransitive(relMatrix) && checkReflexive(relMatrix) && checkSymmetric(relMatrix))
            {
                cout << "The relation is equivalent.\n";
            }
            else
            {
                cout << "The relation is not equivalent.\n";
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