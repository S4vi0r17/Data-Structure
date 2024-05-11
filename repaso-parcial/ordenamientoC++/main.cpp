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

int Partition(int arr[], int low, int high)
{
    int temp;

    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    temp = arr[high];
    arr[high] = arr[i + 1];
    arr[i + 1] = temp;

    return i + 1;
}

void QuickSort(int arr[], int low, int high)
{
    int pivot;
    if (low < high)
    {
        pivot = Partition(arr, low, high);

        QuickSort(arr, low, pivot - 1);
        QuickSort(arr, pivot + 1, high);
    }
}

int main(int argc, char const *argv[])
{
    int arreglo[5] = {5, 2, 1, 4, 3};
    QuickSort(arreglo, 0, 4);
    for (int i = 0; i < 5; i++)
    {
        cout << arreglo[i] << endl;
    }

    return 0;
}
