#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>



int ReadFile(char line[2]);
int CoutInstr(char* line, char* subline);
void Counter();


int main()
{
	setlocale(LC_ALL, "");

	system("cls");											
	printf("***************************************\n");			
	printf("*                                     *\n");			
	printf("* Working with files and string data. *\n");			
	printf("*                                     *\n");			
	printf("***************************************\n");			

	printf("Количество символов в текстовом режиме : %d\n", ReadFile("rt"));//"r"
	printf("Количество символов в бинарном режиме  : %d\n\n", ReadFile("rb"));



	Counter();


	getchar();


}
int ReadFile(char line[2])
{
	int count = 0;
	FILE *input = fopen("input.txt", line);
	char buffer;

	if (input == NULL) return -1;

	while (!feof(input))
	{
		buffer = fgetc(input);
		count++;
	}

	fclose(input);
	return count;
}
void Counter()
{
	/////////////////////////////
	char **lib;
	int *CountWordInLine;
	int CountWordInLib = 0;



	///////////////////////////////////////////////
	FILE *words = fopen("words.txt", "r");

	lib = (char**)malloc(sizeof(char*));
	lib[0] = (char*)malloc(sizeof(char));


	char buff;
	int k = 0;

	while ((buff = fgetc(words)) != EOF)
	{

		if (buff != '\n'&& buff != '\0')
		{
			lib[CountWordInLib] = (char*)realloc(lib[CountWordInLib], sizeof(char)*(k + 1));
			lib[CountWordInLib][k] = buff;
			k++;
		}
		else
		{
		
			lib[CountWordInLib] = (char*)realloc(lib[CountWordInLib], sizeof(char)*(k + 1));
			lib[CountWordInLib][k] = '\0';
			k = 0;
			CountWordInLib++;
			lib = (char**)realloc(lib, sizeof(char*)*(CountWordInLib + 1));
			lib[CountWordInLib] = (char*)malloc(sizeof(char));


		}
	}


	fclose(words);
	
	///////////////////////////////////////////////


	CountWordInLine = (int*)malloc(sizeof(int)*CountWordInLib);
	for (int i = 0; i < CountWordInLib; i++)
		CountWordInLine[i] = 0;
	/////////////////////////////////////////////////

	FILE *input = fopen("input.txt", "r");
	char buffer[256];

	if (input == NULL) return;

	while (fgets(buffer, 256, input) != NULL)
		for (int i = 0; i < CountWordInLib; i++)
			CountWordInLine[i] += CoutInstr(&buffer, lib[i]);


	fclose(input);



	//////////
	FILE *out = fopen("out.txt", "w");
	for (int i = 0; i < CountWordInLib; i++)
	{
		printf("%s %d\n", lib[i], CountWordInLine[i]);
		fprintf(out, "%s %d\n", lib[i], CountWordInLine[i]);
	}
	fclose(out);
	/////////

	free(CountWordInLine);
	for (int i = 0; i <= CountWordInLib;i++)
		free(lib[i]);
	free(lib);
}
int CoutInstr(char* line, char* subline)
{

	int n = 0;
	int i = 0;
	int count = 0;
	while (line[n] != '\0')
	{

		if (line[n] == subline[i])
		{
			i++;
			if (subline[i] == '\0')
			{
				count++;
				i = 0;
			}
		}
		else
			i = 0;

		n++;
	}
	return count;
}
