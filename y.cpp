#include <iostream>
#include <time.h>
using namespace std;

void BubbleSort(int* a, int n)  // пузырек
{
    int i, j, x;
    for (i = 1; i < n; i++)
        for (j = n - 1; j >= i; j--)
            if (a[j - 1] > a[j])
            {
                x = a[j - 1];
                a[j - 1] = a[j];
                a[j] = x;
            }
}




void QuickSort(int* a, int n) // быстрая
{
    int x, w, i, j;
    x = a[n / 2];
    i = 0; j = n - 1;
    do
    {
        while (a[i] < x) i++;
        while (x < a[j]) j--;
        if (i <= j)
        {
            w = a[i]; a[i] = a[j]; a[j] = w;
            i++; j--;
        }
    } while (i < j);
    if (j > 0)
        QuickSort(a, j + 1);
    if (i < n - 1)
        QuickSort(a + i, n - i);
}

void selectionSort(int data[], int lenD)  // выбором
{
    int j = 0;
    int tmp = 0;
    for (int i = 0; i < lenD; i++) {
        j = i;
        for (int k = i; k < lenD; k++) {
            if (data[j] > data[k]) {
                j = k;
            }
        }
        tmp = data[i];
        data[i] = data[j];
        data[j] = tmp;
    }
}



void shellSort(int list[], int listLength)  // шелла
{
    for (int step = listLength / 2; step > 0; step /= 2)
    {
        for (int i = step; i < listLength; i += 1)
        {
            int j = i;
            while (j >= step && list[j - step] > list[i])
            {
                swap(list[j], list[j - step]);
                j -= step;
                cout << "\ndid";
            }
        }
    }
}

    
void merge(int* a, int n) {
    int step = 1;  // шаг разбиения последовательности
    int* temp = (int*)malloc(n * sizeof(int)); // дополнительный массив
    while (step < n)  // пока шаг меньше длины массива
    {
        int index = 0;    // индекс результирующего массива
        int l = 0;      // левая граница участка
        int m = l + step;  // середина участка
        int r = l + step * 2;  // правая граница участка
        do
        {
            m = m < n ? m : n;  // сортируемый участок не выходит за границы последовательности
            r = r < n ? r : n;
            int i1 = l, i2 = m; // индексы сравниваемых элементов
            for (; i1 < m && i2 < r; ) // пока i1 не дошёл до середины и i2 не дошёл до конца
            {
                if (a[i1] < a[i2]) { temp[index++] = a[i1++]; } // заполняем участок результирующей последовательности
                else { temp[index++] = a[i2++]; }
            }
            // Или i1 < m или i2 < r - только один из операторов while может выполниться
            while (i1 < m) temp[index++] = a[i1++]; // заносим оставшиеся элементы сортируемых участков
            while (i2 < r) temp[index++] = a[i2++]; // в результирующий массив
            l += step * 2; // перемещаемся на следующий сортируемый участок
            m += step * 2;
            r += step * 2;
        } while (l < n); // пока левая граница сортируемого участка - в пределах последоватльности
        for (int i = 0; i < n; i++) // переносим сформированный массив обратно в a
            a[i] = temp[i];
        step *= 2; // увеличиваем в 2 раза шаг разбиения
    }
}

void InsertionSort(int* array, int size) {
    for (int k = 1; k < size; k++)
    {
        int temp = array[k];
        int j = k - 1;
        while (j >= 0 && temp <= array[j])
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
}

void ShakerSort(int* a, int n) // шейкерная
{
    int j, k = n - 1, left = 1, right = n - 1, x;
    do
    {
        for (j = right; j >= left; j--)
            if (a[j - 1] > a[j])
            {
                x = a[j - 1];
                a[j - 1] = a[j];
                a[j] = x;
                k = j;
            }
        left = k + 1;
        for (j = left; j <= right; j++)
            if (a[j - 1] > a[j])
            {
                x = a[j - 1];
                a[j - 1] = a[j];
                a[j] = x;
                k = j;
            }
        right = k - 1;
    } while (left < right);
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int N[1] = { 50000 };
    double time;
    void (*f[7])(int*, int) = { BubbleSort,ShakerSort,QuickSort,merge,selectionSort,shellSort,InsertionSort };
    for (int i = 0; i < 7; i++)
    {
        int* mas1 = new int[N[i]];
        int* mas2 = new int[N[i]];
        for (int j = 0; j < N[i]; j++)
            mas2[j] = mas1[j] = rand() % 149999 - 750000;
        cout << "Кол-во символов: " << N[i] << endl;
        for (int j = 0; j < 7; j++)
        {
            switch (j)
            {
            case 0: cout << "Пузырек:\n "; break;
            case 1: cout << "Быстрая:\n "; break;
            case 2: cout << "Выбором: \n"; break;
            case 3: cout << "Шелла: \n"; break;
            case 4: cout << "Слияний: \n"; break;
            case 5: cout << "Вставками: \n"; break;
            case 6: cout << "Шейкер: \n"; break;
            }
            cout << "Время: ";

            time = clock();
            f[j](mas2, N[i]);
            cout << (clock() - time) / CLOCKS_PER_SEC << " сек" << endl;
            

        }
        cout << "========================================================================" << endl;
        delete[] mas2;

    }
    system("pause");
}