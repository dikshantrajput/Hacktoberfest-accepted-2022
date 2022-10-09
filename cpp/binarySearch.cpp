int bSearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int m = left + (right - left) / 2;
 
        if (arr[m] == target)
            return m;
 
        if (arr[m] < target)
            left = m + 1;
 
        else
            right = m - 1;
    }

    return -1;
}
