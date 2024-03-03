#include<stdio.h>

int main()
{
	int num1,num2,t;
	int opcount = 0;
	printf("Enter the two numbers:");
	scanf("%d%d",&num1,&num2);

	if(num1<num2)t = num1;
	else t = num2;

	while(t != 1){
		opcount++;
		if(num1 % t == 0){
			if(num2 % t == 0){
				break;	
			}
		}
		t--;
	}
	printf("GCD of the two numbers is : %d\n",t);
	printf("Opcount = %d\n",opcount);

	return 0;
}