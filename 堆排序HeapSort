#include <stdio.h>
//堆调整
void HeapAdjust(int *nums,int s,int m)
{
	int k=nums[s];
	int j=0;
	for(j=2*s+1;j<=m;j=j*2+1)
	{
		if(j<m&&nums[j]<nums[j+1])++j;
		if(k>=nums[j])break;
		nums[s]=nums[j];s=j;
	}
	nums[s]=k;
}
//建初堆
void CreatHeap(int *nums,int numsSize)
{
	int n=numsSize;
	for(int i=(n-1)/2;i>=0;--i)
		HeapAdjust(nums,i,numsSize);
}
//堆排序
void HeapSort(int *nums,int numsSize)
{
	CreatHeap(nums,numsSize);
	int k;
	for(int i=numsSize-1;i>0;--i)
	{
		k=nums[0];
		nums[0]=nums[i];
		nums[i]=k;
		HeapAdjust(nums,0,i-1);
	}
}

int main(void)
{
	int nums[]={49,38,65,97,76,13,27,49};
	int numsSize=sizeof nums/sizeof(int);
	HeapSort(nums,numsSize);

	for(int i=0;i<numsSize;++i)
		printf("%3d",nums[i]);
	printf("\n");

	return 0;
}
