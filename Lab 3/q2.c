#include<stdio.h>
#include<string.h>

int stringMatching(char t[100],char p[30],int *opc)
{
	int m = strlen(t);
	int n = strlen(p);

	for(int i=0;i<=m-n;i++){
		for(int j=0;j<n;j++){
			(*opc)++;
			if(t[i+j] != p[j])
				break;
			if(j == n-1)
				return i;
		}
	}
	return -1;
}

int main()
{
	char text[100],pattern[30];
	printf("Enter text : ");
	scanf("%s",text); 
	printf("Enter pattern : ");
	scanf("%s",pattern);

	int opcount = 0;
	int res = stringMatching(text,pattern,&opcount);

	if(res != -1)
		printf("Pattern found at index %d",res);
	else
		printf("Pattern not found");

	printf("\nOpcount = %d",opcount);

	return 0;
}