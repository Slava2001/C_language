

#include <stdio.h>
#include <locale.h>//рус.яз.


int Status = 1;


int zachelka()
{
	static int i = 2;
	i--;
	if (i < 0)
	{
		i = 0;
	}
	return(i);
	
}
double f(int x, int y)
{
	double res=1;

	if (x > y)
	{
		int vrm = x;
		x = y;
		y = vrm;
	}

		

	for (float a = x; a < (y+1); a++)
	{
		if (a==0)
		{
			Status = 0;
			res = 0;
			break;
		}
		else
		{
			res *= (1 / a);
			Status = 1;
		}
	}


	return(res);
}

int main()
{
	setlocale(LC_ALL, "Rus");

	while (1)
	{
	system("cls");
    printf("1.Функция-счетчик\n");
	printf("2.Вычисление суммы 1/z\n");
	printf("3.Выход\n");
	printf("Введите номер (1-3)\n");

	int n=0;
	scanf_s("%d", &n);

	switch (n)
	{
	case 1:
		system("cls");
		printf("%d\n",zachelka());		
		system("pause");

		break;
	case 2:
		system("cls");
		int x = 0;
		int y = 0;
		scanf_s("%d", &x);
		scanf_s("%d", &y);

		printf("%lf\n", f(x,y));
		printf("Status = %i\n", Status);
		system("pause");
		break;
	case 3:
		return(0);
		break;
	
		
	default:
		printf("Не корректный ввод!!!\n");
		system("pause");
		break;
	}
}
	return(0);
}