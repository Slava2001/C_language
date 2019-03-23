#define _CRT_SECURE_NO_WARNINGS 1 
#include "stdio.h"
#include "string.h"


int main()
{

	char ToUpperSdvig = 'A' - 'a';
	printf("%d\n", ToUpperSdvig);


	FILE *readfile = fopen("input.txt", "r");
	FILE *outfile = fopen("out.txt", "w");

	if (readfile == NULL || outfile == NULL)
		return -1;//не удалось открыть файл


	char buffer[256];

	char NowInKovichki = 0;

	char lastletter='a';
	char lastlastletter='a';


	while (fgets(buffer, 256, readfile)!=NULL)
	{
	
		

		
		for (int i = 0; i < strlen(buffer); i++)
		{
			if (buffer[i] == '\"' || buffer[i] == '\'')
				NowInKovichki = NowInKovichki==0?1:0;


			if (NowInKovichki==0)
				if (lastletter == ' ' && buffer[i] == ' ')
					continue;//пропустить символ



			if ((lastletter == '.'&&buffer[i] != ' '&&buffer[i] != '\n') ^ (lastlastletter == '.' && lastletter == ' '))
					buffer[i] =buffer[i]>('a'-1)?buffer[i] + ToUpperSdvig:buffer[i];
			
			

			if (buffer[i] != '\n')
			{
				lastlastletter = lastletter;
				lastletter = buffer[i];
			}

			putc(buffer[i], outfile);
			printf("%c", buffer[i]);
		}
	
	}
	printf("\n");
	system("pause");


}