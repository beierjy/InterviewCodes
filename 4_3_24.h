#include <stdlib.h>
#include <stdio.h>

bool VerifySequenceOfBST(int* sequence,int length){
	if(sequence == NULL || length <= 0)
		return false;
	int root = sequence[length - 1];
	int i = 0;
	while(i < length - 1){
		if(sequence[i]  > root)
			break;
		++i;
	}
	int j = i;
	while(j < length - 1){
		if(sequence[j] < root)
			return false;
		++j;
	}
	bool left = true;
	if(i > 0)
		left = VerifySequenceOfBST(sequence,i);
	bool right = true;
	if(length - 1 - i >0)
		right = VerifySequenceOfBST(sequence,length-1-i);
	return (right && left);
}
void Test()
{
	int a[7] = {5,7,6,9,11,10,8};
	int b = VerifySequenceOfBST(a,7);
	printf("%d",b);
}

