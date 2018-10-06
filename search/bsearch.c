#include "stdio.h"
#include "stdlib.h"

//若查找成功返回下标，若查找失败返回0
int b_search(int *a, int k, int n)
{
    int low = 0, high = n - 1, mid;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(a[mid] == k)
            return mid;
        else if(a[mid] > k)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return 0；
}

int main()
{
    int arr[] = {1,4,6,9,10,17,30}, k, n = 7;
    scanf("%d", &k);
    while(k)
    {
        printf("%d\n", b_search(arr, k, n));
        scanf("%d", &k);
    }

    return 0;
}
