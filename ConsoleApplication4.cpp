#include <iostream>
#include <fstream>
using namespace std;

void quicksort(float* A, int left, int right)
{
    if (left == right)
        return;
    float elem;
    int beg = left;
    int endin = right;
    elem = A[left];
    while (left < right)
    {
        while ((A[left] > elem) && (left < right))
        {
            left++;
        }
        while ((A[right] < elem) && (right > left))
        {
            right--;
        }
        if (left != right)
        {
            float cont = A[right];
            A[right] = A[left];
            A[left] = cont;
        }
    }
    float cont = elem;
    elem = A[right];
    A[right] = cont;
    if (beg < left)
    {
        quicksort(A, beg, left-1);
    }
    if (endin > right)
        quicksort(A, right+1, endin);
}

int main()
{
    int N, min = 0;
    float elem;
    fstream f;
    f.open("massiv.txt");
    f >> N;
    float* A = new float[N];
    for (int i = 0; i < N; i++)
        f >> A[i];
    quicksort(A, 0, N - 1);
    for (int i = 0; i < N; i++)
        cout << " " << A[i];
    f.close();
}