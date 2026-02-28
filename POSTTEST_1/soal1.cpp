#include <iostream>
using namespace std;

int findmin(int *arr, int n)
{
    int min = arr[0];
    int indexmin = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            indexmin = i;
        }
    }
    return min;
}

int main()
{
    int arr[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    findmin(arr, 8);
    int indexmin;
    int terkecil = findmin(arr, 8, indexmin);

    cout << "Nilai Minimum: " << terkecil << endl;
    cout << "Index Minimum: " << indexmin << endl;
    return 0;
}