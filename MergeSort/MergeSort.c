void merge(int *nums, int *arr, int start, int end)
{
	int mid = (start + end) / 2;
	int i = start, j = mid + 1, k = start;
	while (i <= mid&&j <= end)
	{
		if (nums[i] <= nums[j])
		{
			arr[k] = nums[i];
			++i; ++k;
		}
		else
		{
			arr[k] = nums[j];
			++j; ++k;
		}
	}
	while (i <= mid)
	{
		arr[k] = nums[i];
		++i; ++k;
	}
	while (j <= end)
	{
		arr[k] = nums[j];
		++j; ++k;
	}
	for (int t = start; t <= end; ++t)
		nums[t] = arr[t];
}
//二分归并排序
void mergeSort(int *nums, int *arr, int start, int end)
{
	if (start >= end)return;
	int mid = (start + end) / 2;
	mergeSort(nums, arr, start, mid);
	mergeSort(nums, arr, mid + 1, end);
	merge(nums, arr, start, end);
}
void msort(int* nums, int numsSize)
{
	int *arr = (int*)malloc(numsSize * sizeof(int));
	mergeSort(nums, arr, 0, numsSize - 1);
	free(arr);
}
int main(void) {
	int nums[] = { 2,5,1,9,8,5,7 };
	int length = sizeof nums / sizeof(int);
	for (int i = 0; i<length; ++i)printf("%3d", nums[i]); putchar('\n');
	msort(nums, length);
	for (int i = 0; i<length; ++i)printf("%3d", nums[i]); putchar('\n');
	return 0;
}
