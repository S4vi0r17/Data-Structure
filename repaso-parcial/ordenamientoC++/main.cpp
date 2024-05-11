#include <iostream>

using namespace std;

void InsertionSort(int arr[])
{
    int j, key;
    for (int i = 1; i < 5; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void SelectionSortMin(int arr[])
{
    int min, temp;
    for (int i = 0; i < 5 - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < 5; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

void SelectionSortMax(int arr[])
{
    int max, temp;
    for (int i = 0; i < 5 - 1; i++)
    {
        max = i;
        for (int j = i + 1; j < 5; j++)
        {
            if (arr[j] > arr[max])
            {
                max = j;
            }
        }
        temp = arr[max];
        arr[max] = arr[i];
        arr[i] = temp;
    }
}

void BubbleSort(int arr[])
{
    int temp;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5 - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int arreglo[5] = {5, 2, 1, 4, 3};
    BubbleSort(arreglo);
    for (int i = 0; i < 5; i++)
    {
        cout << arreglo[i] << endl;
    }

    return 0;
}
