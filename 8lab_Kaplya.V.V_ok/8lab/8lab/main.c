#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


unsigned char input;


void print_bit();
unsigned char get_bit(unsigned char n);
unsigned char get_part(unsigned char n, unsigned char k);
void print_info(unsigned char layer,unsigned char type,unsigned char bitinf1,unsigned char bitinf2,unsigned char cs);
unsigned char contrl_summ();

int main() 
{
	while (1) 
	{
		unsigned char layer,type,bitinf1,bitinf2,cs;


		printf("Enter: ");
		scanf("%u",&input);
		print_bit();


		

		layer = get_part(7, 6);
		type = get_part(5, 5);

		if (type == 0) 
		{
			bitinf1 = get_part(4, 4);
			bitinf2 = get_part(3, 1);
		}
		else 
		{
			bitinf1 = get_part(4, 3);
			bitinf2 = get_part(2, 1);
		}
		
		cs= get_part(0, 0);

		print_info(layer, type, bitinf1, bitinf2, cs);




		
	}
}

void print_bit() 
{
	for (char i = 7; i >= 0; i--)
	{
		printf("%u", get_bit(i));
	}
	printf("\n");
}

unsigned char get_bit(unsigned char n)
{
	unsigned char a;
	a = input & (1 << n);
	return a >> n;
}

unsigned char get_part(unsigned char n, unsigned char k)
{
	unsigned char a=0;
	for (char i = n; i >= k; i--)
	{
		a=a << 1;
		a = a | get_bit(i);
	}
	return a;
}

void print_info
(
	unsigned char layer,
	unsigned char type,
	unsigned char bitinf1,
	unsigned char bitinf2,
	unsigned char cs
) 
{
	printf("Layer:\t\t");
	switch (layer)
	{
	case 0:
		printf("Layer I\n");
		break;
	case 1:
		printf("Layer II\n");
		break;
	case 2:
		printf("Layer III\n");
		break;
	case 3:
		printf("Reserved\n");
		break;
	}


	printf("Type:\t\t");
	switch (type)
	{
	case 0:
		printf("Constant Bitrate(CBR)\n");
		break;
	case 1:
		printf("Variabel Bitrate(VBR)\n");
		break;
	}


	if (type == 0)
	{
		printf("Mode:\t\t");
		switch (bitinf1)
		{
		case 0:
			printf("Mono\n");
			break;
		case 1:
			printf("Stereo\n");
			break;
		}

		printf("Bitrate:\t");
		switch (bitinf2)
		{
		case 0:
			printf("32 kbps\n");
			break;
		case 1:
			printf("48 kbps\n");
			break;
		case 2:
			printf("64 kbps\n");
			break;
		case 3:
			printf("96 kbps\n");
			break;
		case 4:
			printf("128 kbps\n");
			break;
		case 5:
			printf("192 kbps\n");
			break;
		case 6:
			printf("256 kbps\n");
			break;
		case 7:
			printf("320 kbps\n");
			break;
		}

	}
	else
	{
		printf("Range:\t\t");
		switch (bitinf1)
		{
		case 0:
			printf("32-48 kbps\n");
			break;
		case 1:
			printf("64-96 kbps\n");
			break;
		case 2:
			printf("128-192 kbps\n");
			break;
		case 3:
			printf("256-320 kbps\n");
			break;
		}
		printf("Mode:\t\t");
		switch (bitinf2)
		{
		case 0:
			printf("Stereo\n");
			break;
		case 1:
			printf("joint stereo\n");
			break;
		case 2:
			printf("dual channel\n");
			break;
		case 3:
			printf("single channel\n");
			break;
		}
	}

	printf("CS:\t\t%u",cs);

	if (cs == contrl_summ()) 
	{
		printf(" = %u\n", contrl_summ());
		printf("the checksums are the same\n");
	}
	else 
	{
		printf(" != %u\n", contrl_summ());
		printf("ERROR: checksums do not match\n");
	}


	}
	
char contrl_summ() 
{
	char cs = 0;
	for (int i = 7; i >= 1; i--) 
	{
		cs = cs ^ get_bit(i);
	}
	return cs;
}