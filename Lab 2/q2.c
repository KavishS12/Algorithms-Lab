#include<stdio.h>

int isPrime(int n){
	if(n<=1)return 0;
	for(int i=2;i*i<=n;i++){
		if(n%i==0)return 0;
	}
	return 1;
}

int main()
{
	int num1,num2,t;
	int opcount = 0;
	printf("Enter the two numbers:");
	scanf("%d%d",&num1,&num2);

	if(num1<num2){
		int temp = num1;
		num1 = num2;
		num2 = temp;
	}
	int i = 2;
	int gcd = 1;
	while(num2 != 1 && num2>=i){
		opcount++;
		if(isPrime(i)==1){
			opcount++;
			if(num1%i==0 && num2%i==0){
				gcd *= i;
				num1 /= i;
				num2 /= i;
			}
			else i++;
		}
		else i++;
	}

    printf("GCD of the two numbers is : %d\n",gcd);
    printf("Opcount = %d\n",opcount);
    return 0;
}

