#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
int k;
int min(int i, int j, vector<int> P, vector< vector<int> > A)
{
    if (i == j)
    {
        k = i;
        return P[i];
    }
    vector<int> m(j - i + 1);
    int t, s = 0;
    for (t = i; t <= j; t++)
    {
        m[s] = A[i][t - 1] + A[t + 1][j];
        s++;
    }
    int min = m[0];
    k = 0;
    for (t = 1; t < j - i + 1; t++)
    {
        if (min > m[t])
        {
            min = m[t];
            k = t;
        }
    }
    for (t = i; t <= j; t++)
    {
        min = min + P[t];
    }
    k = k + i;
    return min;
}
void optsearchtree(int n, vector<int> P, vector< vector<int> >& A, vector< vector<int> >& R)
{
    int i, j, digonal;
    for (i = 1; i <= n; i++)
    {
        A[i][i - 1] = 0;
        A[i][i] = P[i];
        R[i][i - 1] = 0;
        R[i][i] = i;
    }

    for (digonal = 0; digonal <= n - 1; digonal++)
    {
        for (i = 1; i <= n - digonal; i++)
        {
            j = i + digonal;
            A[i][j] = min(i, j, P, A);
            R[i][j] = k;
        }
    }
}
void print_preorder(int i, int j, vector< vector<int> > R)
{
    if (i > j)
        return;
    if (i == j)
    {
        cout << i << " ";
        return;
    }
    int par = R[i][j];
    cout << par << " ";

    print_preorder(i, par - 1, R);
    print_preorder(par + 1, j, R);

}
int main()
{
   
    int num_of_data;
    ifstream file;
    file.open("input.txt");

    file >> num_of_data;
    while(num_of_data--)
    {
        int number_of_key;
        file >> number_of_key;
        int n = number_of_key;
        vector< vector<int> > A(n + 2, vector<int>(n + 2, 0));vector< vector<int> > R(n + 2, vector<int>(n + 2, 0));
        vector<int> P(n + 1);
        int frequency;
        for (int i = 1; i <= n; i++)
        {
            file >> frequency;
            P[i] = frequency;
        }
        optsearchtree(n, P, A, R);
        print_preorder(1, n, R);
        cout << "\n";
    }
    file.close();
    return 0;
}
