#include <iostream>
using namespace std;

int cnt, tang;

template <typename T>
void bubble_sort(T *elems, int size);

template <typename T>
void show(T *elems, int size);
int main()
{
    int elems[] = {5, 1, 4, 2, 6, 7, 9, 5, 4, 3, 2, 5, 7, 15};
    int n = sizeof(elems) / sizeof(elems[0]);
    printf("Before sorting(n=%d): ", n);
    show(elems, n);
    bubble_sort(elems, n);
    cout << "After sorting: ";
    show(elems, n);
    return 0;
}

template <typename T>
void bubble_sort(T *elems, int size)
{
    int low = 0, high = size - 1;
    bool flag = true;
    while (low < high && flag == true)
    {
        flag = false;
        for (int i = low; i < high; i++)
        {
            if (elems[i] > elems[i + 1])
            {
                swap(elems[i], elems[i + 1]);
                printf("第%d次交换: ", ++cnt);
                show(elems, size);
                flag = true;
            }
        }
        printf("第%d趟结束,为从前向后遍历,high更新到%d\n", ++tang, --high);
        cnt = 0;
        for (int i = high; i > low; i--)
        {
            if (elems[i - 1] > elems[i])
            {
                swap(elems[i - 1], elems[i]);
                printf("第%d次交换: ", ++cnt);
                show(elems, size);
                flag = true;
            }
        }
        printf("第%d趟结束,为从后向前遍历,low更新到%d\n", ++tang, ++low);
        cnt = 0;
    }
}

template <typename T>
void show(T *elems, int size)
{
    for (int i = 0; i < size; i++)
        cout << elems[i] << " ";
    cout << endl;
}