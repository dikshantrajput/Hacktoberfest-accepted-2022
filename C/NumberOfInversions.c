#include <stdio.h>

int a[11], b[11];
int n=10; 

int merge(int low, int mid, int high)
{
    int cnt =0; 
    int l = low;
    int i= low;
    int r = mid+1;
    
    while(l<=mid && r<=high)
    {
        if(a[l]<=a[r])
            b[i++] = a[l++];
        else 
        {
            b[i++] = a[r++];
            cnt += (mid-i);
        }
    }
    
    while(l<=mid) b[i++]=a[l++];
    
    while(r<=high) b[i++]=a[r++];
    
    for(int j=low; j<=high; j++)
    {
        a[j] = b[j];
    }
    
    return cnt;
}

int inv(int low, int high)
{
    int mid, inv_cnt=0;
    if(low<high)
    {
        mid = (low+high)/2;
        inv_cnt += inv(low, mid);
        inv_cnt += inv(mid+1, high);
        inv_cnt += merge(low, mid, high);
    }
    return inv_cnt;
}

int main()
{
    printf("Enter the elements of array: ");
    for(int i=0; i<10; i++)
        scanf("%d", &a[i]);
    int cnt = inv(0, 9);
    printf("%d", cnt);
    return 0;
}
