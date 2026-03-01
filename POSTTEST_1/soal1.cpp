#include <iostream>
using namespace std;

int findmin(int *arr, int n, int &indexmin)
{
    int min = arr[0];
    indexmin = 0;
    int n = 8;

    for (int i = 0; i < n; i++)
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
    int indexmin;

    int terkecil = findmin(arr, 8, indexmin);

    cout << "Nilai Minimum : " << terkecil << endl;
    cout << "Index Minimum : " << indexmin << endl;

    return 0;
}

/*
Analisis Kompleksitas Waktu

----------------------------------------------------
Pseudocode              Cost      Tmin         Tmax
----------------------------------------------------
procedure FindMin        C1        1            1
min ← A[0]               C2        1            1
for i ← 1 to n-1         C3        n            n
if A[i] < min            C4        n-1          n-1
min ← A[i]               C5        0            n-1
end if                   C6        n-1          n-1
end for                  C7        n            n
return min               C8        1            1
end procedure            C9        1            1
----------------------------------------------------

Mencari Tmin (Best Case):

Tmin​(n)=C1(1)+C2(1)+C3(n)+C4(n−1)+C5(0)+C6(n−1)+C7(n)+C8(1)+C9(1)
Tmin​(n)=C1+C2+nC3+(n−1)C4+(n−1)C6+nC7+C8+C9        ----> C5 hilang
Tmin​(n)=C1+C2+nC3+(nC4−C4)+(nC6−C6)+nC7+C8+C9
Tmin​(n)=n(C3+C4+C6+C7)+(C1+C2−C4−C6+C8+C9)
Tmin​(n)=n(1+1+1+1)+(1+1−1−1+1+1)
Tmin​(n)=4n+2         -----> jawabannya
Big-O   ======> O(n)

Mencari Tmax (Worst Case):

Tmax​(n)=C1+C2+C3(n)+C4(n−1)+C5(n−1)+C6(n−1)+C7(n)+C8+C9
Tmax​(n)=C1+C2+nC3+(nC4−C4)+(nC5−C5)+(nC6−C6)+nC7+C8+C9
Tmax(n)=n(C3+C4+C5+C6+C7)+(C1+C2-C4-C5-C6+C8+C9)
Tmax​(n)=n(1+1+1+1+1)+(1+1−1−1-1+1+1)
Tmax​(n)=5n+1       -------> jawabannya
Big-O   ======> O(n)
------------------------------------------------------------------------

Tmin(n)  = 4n + 2
Tmax(n)  = 5n + 1

Best Case  : O(n)
Worst Case : O(n)

Kedua fungsi sama-sama membentuk fungsi linier, di mana pangkat tertinggi dari n adalah 1.
*/