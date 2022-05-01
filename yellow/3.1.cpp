#include "3.1.h"

int Sum(int x, int y)
{
    return x + y;
}

string Reverse(string s)
{
    string answer;
    for (int i = (int)s.size() - 1; i >= 0; i--)
        answer += s[i];

    return answer;
}

// Функция быстрой сортировки
void quickSort(vector<int>& arr, int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];
 
    /* partition */
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };
 
    /* recursion */
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
    
}

void Sort(vector<int>& nums)
{
    quickSort(nums, 0, nums.size() - 1);
}