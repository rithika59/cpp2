/* Assignment 3 ---  Accept N word from user(allocate all space dynamically and properly free it at end) and sort them using qsort() */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int cmp_str(const void* a,const void* b)
{
	return strcmp(*(const char**)a,*(const char**)b);
}

void print_arr(char** arr,size_t len)
{
	size_t i;
	for( i=0 ; i<len; i++)
	{
		printf("%s  ",arr[i]);
	}
	printf("\n");
	
}


int main()
{
	int i,j,M=0,N=0;
	char **q = NULL;
	char word[1024];
	int len_word;
	printf("enter number of strings\n");
	scanf("%d",&N);


	q = (char **)malloc(N*sizeof(char *));

	for(i=0;i<N;i++)
	{
		printf("enter %d  string\n",i+1 );
		scanf("%s",word);
		M = strlen(word);
	//	printf("length of the string is %d \n",M);
		*(q+i)=(char *)malloc((M+1)*sizeof(char));
		for(j=0;j<(M+1);j++)
		{
			*(*(q+i)+j) = word[j];
			}
		}

		printf("before sorting\n");
		
		print_arr(q,N);

		qsort(q,N,sizeof(char*),cmp_str);

		printf("after sorting\n");

		print_arr(q,N);




















/*	for( i =0; i < N; i++)
	{
		printf("%d string entered is : %s \t",i+1,*(q+i));
	//	*midword = (q+i);
		len_word = strlen(*(q+i));
		printf("length of string : %d \t",len_word);

		if((len_word%2)== 0)
			printf("middle character of string is : %c \n",*(*(q+i)+(len_word/2)-1));
		else
			printf("middle character of string is : %c \n",*(*(q+i)+((len_word-1)/2)));
	}*/

	free(*q);

		return 0;
}

























