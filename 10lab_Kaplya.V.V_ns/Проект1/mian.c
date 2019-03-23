#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
#include "string.h"
#include "stdlib.h"
void bubble(void *base, size_t nelem, size_t width, int(*fcmp)(const int, const int, const void*, const size_t));
int Doublecmp(const int a, const int b, const double *base, const size_t width);
int Stringcmp(const int a, const int b, const char **base, const size_t width);
int sortD(char *filename);
int sortS(char *filename);
int main(int argvc,char* arg)
{
	char *argv[] = {"myprog", "strings.txt", "-s" };
	//char *argv[] = { "myprog", "numbers.txt", "-n" };

	argvc = 3;



	//////
	if (argvc == 3)
	{
		if (!strcmp(argv[2], "-n"))
		{
			if (sortD(argv[1]) == -1)
				printf("error");
		}
		else if(!strcmp(argv[2], "-s"))
		{
			if (sortS(argv[1]) == -1)
				printf("error");
		}
		else
		{
			printf("error");
		}
	}
	else
	{
		printf("error");
	}
	//////




	printf("\n");
	system("pause");
}

int sortD(char *filename)
{
	double *mass;



	int count = 10;

	FILE *readfile = fopen(filename, "r");
	if (readfile == NULL)return -1;

	mass = (double*)malloc(sizeof(double)*count);

	char buf[256];

	for (int i = 0; i < count; i++)
	{
		fgets(buf, 255, readfile);
		mass[i] = atof(buf);
	}





	for (int i = 0; i < count; i++)
		printf("%.1lf ",mass[i]);


	bubble(mass, count, sizeof(double), Doublecmp);


	printf("\n");
	for (int i = 0; i < count; i++)
		printf("%.1lf ", mass[i]);


	free(mass);
}
int sortS(char *filename)
{
	char **mass;



	int count = 5;
	int maxlinew = 7;

	FILE *readfile = fopen(filename, "r");
	if (readfile == NULL)return -1;

	mass = (double**)malloc(sizeof(char*)*count);

	char buf[256];
	 
	for (int i = 0; i < count; i++)
	{
		fgets(buf, 256, readfile);
		

		mass[i] = (char*)malloc(sizeof(char)*maxlinew+1);

		strcpy(mass[i], buf);

		mass[i][maxlinew] = '\0';
	}
	




	for (int i = 0; i < count; i++)
		printf("%s", mass[i]);


	bubble(mass, count, sizeof(char*), Stringcmp);


	printf("\n\n");
	for (int i = 0; i < count; i++)
		printf("%s", mass[i]);


	free(mass);
}

int Doublecmp(const int a, const int b, const double *base, const size_t width)
{
	return base[a] - base[b];
}
int Stringcmp(const int a, const int b, const char **base, const size_t width)
{
	return strcmp(base[a], base[b]);
}

void elemswap(const int a, const int b, void *base, const size_t width)
{
	void *tmp = malloc(width);
	if (tmp == NULL){printf("error"); return;}

	memmove(tmp, (char*)base + (a*width), width);
	memmove((char*)base + (a*width), (char*)base + (b*width), width);
	memmove((char*)base + (b*width),tmp, width);

	free(tmp);
}
void bubble(void *base, size_t nelem, size_t width, int(*fcmp)(const int, const int, const void*, const size_t))
{
	int i, sw;
	do
	{
		sw = 0;
		for (i = 0; i <= (int)nelem - 2; i++)
		{
			if (fcmp(i, i + 1, base, width) > 0)
			{
				elemswap(i, i + 1, base, width);
				sw = 1;
			}
		}
	} while (sw);
}