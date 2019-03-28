#include "stdio.h"
#include "stdlib.h"
#include "string.h"
char **data;

void Save(char* newData);
void Print(int j);
void PrintAll();
void Delete(int j);

int main()
{
	data = (char**)malloc(sizeof(char*));

	char line[] = "\1qwerty";
	char line2[] = "\2my str";
	char line3[] = "\3test line";
	char line4[] = "\4keyboard";
	char line5[] = "\5dhtnd";

	Save(&line);
	Save(&line2);
	Save(&line3);
	Save(&line4);
	Save(&line5);

	PrintAll();
	Delete(2);
	printf("\n");
	PrintAll();
	Delete(2);
	printf("\n");
	PrintAll();
	Delete(2);
	printf("\n");
	PrintAll();
	printf("\n");


	Save(&line);
	Save(&line2);
	Save(&line3);
	Save(&line4);
	Save(&line5);

	PrintAll();
	printf("\n");
	Delete(5);
	PrintAll();
	printf("\n");
	system("pause");
	return 0;
}

char line_count = 0;
void Save(char* newData)
{

	data = (char**)realloc(data, sizeof(char*)*(line_count + 1));
	data[line_count] = (char*)malloc(sizeof(char)*(strlen(newData)+1));

	if (data == NULL) { printf("ERROR!Out of Memory\n"); return; }
	if (data[line_count] == NULL) { printf("ERROR!Out of Memory\n"); return; }

	memcpy(data[line_count],newData,strlen(newData)+1);


	line_count++;
}
void Print(int j)
{
	for (int i=0;data[j][i] != 0;i++)
		printf("%2X ", (unsigned char)data[j][i]);
	printf("\n");

}
void PrintAll()
{
	for (int i = 0; i < line_count; i++)
		Print(i);
}

void Delete(int j)
{
	free(data[j]);


	memmove(data+j, data+j + 1, sizeof(char*)*(line_count - (j+1)));


	line_count--;
	data = (char**)realloc(data, sizeof(char*)*(line_count));

	if (data == NULL) { printf("ERROR!Out of Memory\n"); return; }
	
}


/////////////////////////////////////////////////////////////////////
/*#include "stdio.h"
#include "stdlib.h"

char **data;

void Save(char* newData);
void Print(int j);
void PrintAll();
void Delete(int j);

int main() 
{
	data = (char**)malloc(sizeof(char*));


	char line[] = "\1qwerty\0";
	char line2[] = "\2my str\0";
	char line3[] = "\3test line\0";
	char line4[] = "\4keyboard\0";
	char line5[] = "\5dhtnd\0";

	Save(&line);
	Save(&line2);
	Save(&line3);
	Save(&line4);
	Save(&line5);

	PrintAll();
	Delete(2);
	printf("\n");
	PrintAll();
	Delete(2);
	printf("\n");
	PrintAll();
	Delete(2);
	printf("\n");
	PrintAll();
	printf("\n");
	Save(&line);
	Save(&line2);
	Save(&line3);
	Save(&line4);
	Save(&line5);
	PrintAll();
	printf("\n");
	Delete(5);
	PrintAll();
	printf("\n");
	system("pause");
	return 0;
}

char line_count = 0;
void Save(char* newData)
{

	data = (char**)realloc(data,sizeof(char*)*(line_count + 1));
	data[line_count] = (char*)malloc(sizeof(char));

	if (data == NULL) { printf("ERROR!Out of Memory\n"); return; }

	int n = 0;
	
	while (newData[n] != 0)
	{
		data[line_count] = (char*)realloc(data[line_count], sizeof(char)*(n + 1));
		if (data[line_count] == NULL) { printf("ERROR!Out of Memory\n"); return; }

		data[line_count][n] = newData[n];
		n++;
		
	}

	data[line_count] = (char*)realloc(data[line_count], sizeof(char)*(n + 1));
	if (data[line_count] == NULL) { printf("ERROR!Out of Memory\n"); return; }
	data[line_count][n] = '\0';

	line_count++;
}
void Print(int j) 
{

	int i = 0;
	while (data[j][i]!=0)
	{
		printf("%2X ", (unsigned char)data[j][i]);
		i++;
	}
	printf("\n");

}
void PrintAll()
{
	for (int i = 0; i < line_count; i++)
		Print(i);
}

void Delete(int j)
{
	free(data[j]);


	for (int i = j; i < line_count; i++)
	data[i] = data[i+1];
	


	line_count--;
	data = (char**)realloc(data, sizeof(char*)*(line_count));

}*/
/////////////////////////////////////////////////////////////////////
/*
void Delete(int j) 
{
	data[j][0] = 0;

	int vrm = line_count-1;
	line_count = j;

	for (int i = j; i < vrm; i++)
		Save(data[i + 1]);

	data = (char**)realloc(data, sizeof(char*)*line_count);

	if (data == NULL) { printf("ERROR!Out of Memory\n"); return; }
}
*/

/*
#include "stdio.h"
#include "stdlib.h"

char data[20][100];

void Save(char* newData);
void Print(int j);
void PrintAll();
void Delete(int j);

int main()
{
	char line[] = "linetest\0";
	char line2[] = "sdfsdfsdfsdsdf\0";

	Save(&line);
	Save(&line);
	Save(&line2);
	Save(&line);
	Save(&line);

	PrintAll();
	Delete(3);
	printf("\n");
	PrintAll();

	system("pause");
	return 0;
}


char line_count = 0;
void Save(char* newData)
{

	int n = 0;
	if (line_count > 19)
	{
		printf("ERROR!OUT OF MEMMORY\n");
		return;
	}
	while (newData[n] != 0)
	{
		data[line_count][n] = newData[n];
		n++;
		if (n > 99)
		{
			printf("ERROR!Line So long\n");
			return;
		}
	}
	data[line_count][n] = '\0';

	line_count++;
}
void Print(int j)
{

	int i = 0;
	while (data[j][i]!=0)
	{
		printf("%X ", (unsigned char)data[j][i]);
		i++;
	}
	printf("\n");

}
void PrintAll()
{
	for (int i = 0; i < line_count; i++)
		Print(i);
}
void Delete(int j)
{
	data[j][0] = 0;

	int vrm = line_count-1;
	line_count = j;

	for (int i = j; i < vrm; i++)
		Save(data[i + 1]);

}
*/