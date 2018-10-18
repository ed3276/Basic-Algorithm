#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//next_permutation函数
bool next_permutation(int *nums,int numsSize)
{
	if(nums==NULL||numsSize<=1)return false;
	int m=numsSize-1,s=m-1,k=numsSize-1;
	int i=0;
	for(i=numsSize-1;i>0;i--)
	{
		if(nums[i-1]<nums[i])
		{m=i;s=i-1;break;}
	}
	if(i==0)
	{return false;}
	else
	{
		for(int i=numsSize-1;i>=m;i--)
		{
			if(nums[s]<nums[i])
			{
				k=i;break;
			}
		}
		int temp=nums[s];
		nums[s]=nums[k];
		nums[k]=temp;
	}
	//对k--end进行逆序
	int mid=(numsSize-1+m)/2-m;
	for(int i=0;i<=mid;++i)
	{
		int temp=nums[m+i];
		nums[m+i]=nums[numsSize-1-i];
		nums[numsSize-1-i]=temp;
	}
	return true;
}
//打印数组
void display(int *nums,int numsSize)
{
	if(nums==NULL||numsSize<=0)
		return;
	for(int i=0;i<numsSize;++i)
		printf("%3d",nums[i]);
	printf("\n");
}
//测试主函数
int main(void)
{
	int nums[]={1,2,3};
	int numsSize=sizeof nums/sizeof(int);
	do
	{
		display(nums,numsSize);
	}while(next_permutation(nums,numsSize));

	return 0;
}
