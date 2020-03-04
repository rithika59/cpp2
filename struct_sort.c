/*Assignment 4 ----- Sort array of structure based on " int id " and "char name[100]" using qsort()*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*Defining structure */
struct student
{
	int id;
	char name[100];
	};

/*Comparison functions for id and name sort*/
int id_cmp(const void* a, const void* b)
{
	return (((struct student*)a)->id -((struct student*)b)->id);
}

int name_cmp(const void* a, const void* b)
{
	return strcmp(((struct student*)a)->name,((struct student*)b)->name);
}

/*Function to print*/
void print_str(struct student* data_1, int len_1)
{
	size_t i;
	printf("\n");
	for(i=0;i<len_1;i++)
	{
		printf("Name: %s \t Id: %d \n",data_1[i].name,data_1[i].id);
	}

	printf("\n");

}
int main()
{
	struct student data[] = {{1,"Namish"},{2,"Danish"},{3,"Geetha"},{12,"Pari"},{8,"robert"},{4,"kris"},{9,"heli"},{11,"mohi"},{15,"deep"}};

	size_t len = sizeof(data)/sizeof(data[0]);

	printf("Before sort: \n");

	print_str(data,len);

	qsort(data,len,sizeof(struct student),id_cmp);

	printf("After id sort: \n");

	print_str(data,len);

	qsort(data,len,sizeof(struct student),name_cmp);

	printf("After name sort: \n");

	print_str(data,len);

}
