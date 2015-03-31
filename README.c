//Special-five-digit-number-detection-algorithm -- Finds special five-digit numbers under specified conditon

/*
Find the number of five-digit numbers with the following
properties: there are two pairs of digits such that digits from each pair are
equal and are next to each other, digits from different pairs are different,
and the remaining digit (which does not belong to any of the pairs) is
different from the other digits.
*/

/*
My algorithm finds total number of all those special numbers satisfying given condition.
*/

#include <stdio.h>

int main(void){
	
	int i, j;
	int digits[5];
	int num;
	int temp;
	int count = 0;
	for(i = 10000; i <= 99999; i++){
		num = i;
		for(j = 0; j < 5; j++){
			digits[j] = num%10;
			num = num / 10;
		}
		
		for(j = 0; j < 5/2; j++){
			temp = digits[j];
			digits[j] = digits[5-j-1];
			digits[5-j-1] = temp;
		}
		
		if(digits[0] == digits[1] && digits[2] == digits[3] && digits[1] != digits[2] && digits[4] != digits[1] && 	           digits[4] != digits[2]){
			count++;
		}
		else if(digits[0] == digits[1] && digits[3] == digits[4] && digits[1] != digits[4]
		        && digits[2] != digits[1] && digits[2] != digits[4]){
		        	count++;
		        }
		else if(digits[1] == digits[2] && digits[3] ==digits[4] && digits[2] != digits[3]
		          && digits[0] != digits[1] && digits[0] != digits[3]){
		          	count++;
		          }
		
	}
	
	printf("Total: %d\n", count);
	
	return 0;
}
