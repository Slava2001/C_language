#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

enum Department
{
	DEPT_PROGRAMMERS,
	DEPT_MANAGEMENT,
	DEPT_SHIPPING
};
enum Transport
{
	TRANSP_TRAIN,
	TRANSP_AUTO,
	TRANSP_AERO,
	TRANSP_SHIP,
};
union Task
{
	struct Programmers
	{
		char Project[255];
		char CPU[127];
		int Memory;
	}Programmers;
	struct Management
	{
		char Project[255];
		char Customer[255];
		int ProgrammersNum;
	}Management;
	struct Shipping
	{
		char Address[255];
		char Customer[255];
		int Weight;
		enum Transport Transport;
	}Shipping;
};
typedef struct 
{
	char Name[255];
	char LastName[255];
	int Age;
	enum Department Department;
	union Task Task;
	struct node *next;
}Node;

Node *head_of_list = NULL;

Node* get(int index)
{
	Node* tmp;
	tmp = head_of_list;
	for (int i = 0; i < index &&tmp->next; i++)
	{
		tmp = tmp->next;	
	}
	return tmp;
}

void AddItem()
{





	Node *temp = (Node*)malloc(sizeof(Node));


	//////////////////////////////
	//ввод даных 

	printf("Введите Имя:\n");
	scanf("%s", &temp->Name);
	printf("Введите Фамилию:\n");
	scanf("%s", &temp->LastName);
	printf("Введите Возраст:\n");
	scanf("%d", &temp->Age);

	printf("Выберите отдел:\n1)Программисты\n2)Менеджмент\n3)Доставка\n");
	int t = 0;
	scanf("%d", &t);
	switch (t)
	{
	case 1:
		temp->Department = DEPT_PROGRAMMERS;

		printf("Введите проект:\n");
		scanf("%s", &temp->Task.Programmers.Project);
		printf("Введите CPU:\n");
		scanf("%s", &temp->Task.Programmers.CPU);
		printf("Введите размер памяти:\n");
		scanf("%d", &temp->Task.Programmers.Memory);

	
		break;
	case 2:
		temp->Department = DEPT_MANAGEMENT;

		printf("Введите проект:\n");
		scanf("%s", &temp->Task.Management.Project);
		printf("Введите заказчика:\n");
		scanf("%s", &temp->Task.Management.Customer);
		printf("Введите кол-во програмистов:\n");
		scanf("%d", &temp->Task.Management.ProgrammersNum);

		break;
	case 3:
		temp->Department = DEPT_SHIPPING;

		printf("Введите адрес:\n");
		scanf("%s", &temp->Task.Shipping.Address);
		printf("Введите заказчика:\n");
		scanf("%s", &temp->Task.Shipping.Customer);
		printf("Введите вес:\n");
		scanf("%d", &temp->Task.Shipping.Weight);

		printf("Выберите транспорт:\n1)Поезд\n2)Машина\n3)Самолет\n4)Корабль\n");
		t = 0;
		scanf("%d", &t);
		temp->Task.Shipping.Transport = (enum Transport)(t - 1);

		break;
	default:
		printf("ERROR!!!");
		system("pause");
		free(temp);
		return;
	}


	
	/////////////////////////////////
	unsigned int n = 0;
	fflush(stdin);
	printf("Введите номер записи после которой добавить новую:");
	scanf("%u", &n);


	if (!n||!head_of_list)
	{
		temp->next = head_of_list;
		head_of_list = temp;

	}
	else
	{
		Node *tmphead = get(n-2);

		temp->next = tmphead->next;
		tmphead->next = temp;
	}	
}

void delete() 
{
	system("cls");
	Node *temp=NULL;

	 int n = 0;
	fflush(stdin);
	//printf("Enter deliting number:");
	printf("Введите номер удаляемой записи:");
	scanf("%d", &n);
	if (n < 0)return;
	if (!head_of_list)return;

	if (n==1)
	{
		temp = head_of_list;
		head_of_list = temp->next;
	}
	else if (n > 1)
	{
		Node *temp2 = get(n - 2);
		if (temp2->next)
		{
			temp = temp2->next;
			temp2->next = temp->next;
		}
	}
	free(temp);
	//printf("ydalenie prohlo yspehno!!");
	printf("Запись удалена");
}

char start[] = { 218,196,196,196,	194,	196,196,196,196,196,196,196,196,196,196,	194,	196,196,196,196,196,196,196,196,196,196,	194,	196,196,196,196,196,196,196,196,196,196,	194,	196,196,196,196,196,196,196,196,196,196,	194,194,	196,196,196,196,196,196,196,196,196,196,	194,	196,196,196,196,196,196,196,196,196,196,	194,	196,196,196,196,196,196,196,196,196,196,	194,	196,196,196,196,196,196,196,196,196,196,	191,0 };
char mid[] = { 195,	196,196,196,	197,	196,196,196,196,196,196,196,196,196,196,	197,	196,196,196,196,196,196,196,196,196,196,	197,	196,196,196,196,196,196,196,196,196,196,	197,	196,196,196,196,196,196,196,196,196,196,	197,197,	196,196,196,196,196,196,196,196,196,196,	197,	196,196,196,196,196,196,196,196,196,196,	197,	196,196,196,196,196,196,196,196,196,196,	197,	196,196,196,196,196,196,196,196,196,196,	180,0 };
char end[] = { 192,	196,196,196,	193,	196,196,196,196,196,196,196,196,196,196,	193,	196,196,196,196,196,196,196,196,196,196,	193,	196,196,196,196,196,196,196,196,196,196,	193,	196,196,196,196,196,196,196,196,196,196,	193,193,	196,196,196,196,196,196,196,196,196,196,	193,	196,196,196,196,196,196,196,196,196,196,	193,	196,196,196,196,196,196,196,196,196,196,	193,	196,196,196,196,196,196,196,196,196,196,	217,0 };


void print()
{
	system("cls");

																																																			
	Node *tmp = head_of_list;																																																
	int i = 1;		
	setlocale(LC_ALL, "C");
  printf("%s\n", start);	
  setlocale(LC_ALL, "");
 // printf("+---+----------+----------+----------+----------++----------+----------+----------+----------+\n");
  printf("| № | Имя      | Фамилия  | Возраст  | Отдел  П || Проект   | CPU      | Memory   |          |\n");	
  printf("|   |          |          |          |        М || Проект   | Заказчик | Прогр-сты|          |\n");
  printf("|   |          |          |          |        Д || Адрес    | Заказчик | Вес      | Транспорт|\n");
  setlocale(LC_ALL, "C");
	
	//char head_start[] = { 179,32 ,252,32 ,179,32 ,136,172,239,32 ,32 ,32 ,32 ,32 ,32 ,179,32 ,148,160,172,168,171,168,239,32 ,32 ,179,32 ,130,174,167,224,160,225,226,32 ,32 ,179,32 ,142,226,164,165,171,32 ,32 ,143,32 ,179,179,32 ,143,224,174,165,170,226,32 ,32 ,32 ,179,32 ,67 ,80 ,85 ,32 ,32 ,32 ,32 ,32 ,32 ,179,32 ,77 ,101,109,111,114,121,32 ,32 ,32 ,179,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,179,10 };
	//for (int i = 0; head_start[i] != 10; i++)
	//	printf("%c", head_start[i]);
	//printf("\n");
	//char head_mid[] = { 179,32 ,32 ,32 ,179,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,179,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,179,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,179,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,140,32 ,179,179,32 ,143,224,174,165,170,226,32 ,32 ,32 ,179,32 ,135,160,170,160,167,231,168,170,32 ,179,32 ,143,224,174,163,224,45 ,225,226,235,179,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,179,10 };
	//for (int i = 0; head_mid[i] != 10; i++)
	//	printf("%c", head_mid[i]);
	//printf("\n");
	//char head_end[] = { 179,32 ,32 ,32 ,179,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,179,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,179,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,179,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,132,32 ,179,179,32 ,128,164,224,165,225,32 ,32 ,32 ,32 ,179,32 ,135,160,170,160,167,231,168,170,32 ,179,32 ,130,165,225,32 ,32 ,32 ,32 ,32 ,32 ,179,32 ,146,224,160,173,225,175,174,224,226,179,10 };
	//for (int i = 0; head_end[i] != 10; i++)
	//	printf("%c", head_end[i]);
	//printf("\n");



	printf("%s\n", mid);																																																	
	//printf("+---+----------+----------+----------+----------++----------+----------+----------+----------+\n");
	if (tmp) {																																																				
		printf("|%2d |%-10.10s|%-10.10s|%-10d|", i, tmp->Name, tmp->LastName,tmp->Age);			
		
		switch (tmp->Department)																																															
		{		
		case DEPT_PROGRAMMERS:	
			setlocale(LC_ALL, "");
			printf("Программис");
			setlocale(LC_ALL, "C");
			printf("||%-10.10s|%-10.10s|%-10d|          |\n",tmp->Task.Programmers.Project,tmp->Task.Programmers.CPU,tmp->Task.Programmers.Memory);																
			break;																																																			
		case DEPT_MANAGEMENT:					
			setlocale(LC_ALL, "");
			printf("Менеджмент");
			setlocale(LC_ALL, "C");
			printf("||%-10.10s|%-10.10s|%-10d|          |\n", tmp->Task.Management.Project, tmp->Task.Management.Customer, tmp->Task.Management.ProgrammersNum);
			break;																																																												
		case DEPT_SHIPPING:
			setlocale(LC_ALL, "");
			printf("Доставка  ");
			setlocale(LC_ALL, "C");
			printf("||%-10.10s|%-10.10s|%-10d|", tmp->Task.Shipping.Address, tmp->Task.Shipping.Customer, tmp->Task.Shipping.Weight);
			setlocale(LC_ALL, "");
			switch (tmp->Task.Shipping.Transport)
			{
			case TRANSP_TRAIN:
				printf("Поезд     |\n");
				break;
			case TRANSP_AUTO:
				printf("Машина    |\n");
				break;
			case TRANSP_SHIP:
				printf("Корабль   |\n");
				break;
			case TRANSP_AERO:
				printf("Самолет   |\n");
				break;
			}
			setlocale(LC_ALL, "C");
			break;
		}
		

		tmp = tmp->next;
	}
	while (tmp)
	{
		i++;
		//вывод данных


		printf("%s\n", mid);
		//printf("+---+----------+----------+----------+----------++----------+----------+----------+----------+\n");
		printf("|%2d |%-10.10s|%-10.10s|%-10d|", i, tmp->Name, tmp->LastName, tmp->Age);
		setlocale(LC_ALL, "");
		switch (tmp->Department)
		{
		case DEPT_PROGRAMMERS:
			setlocale(LC_ALL, "");
			printf("Программис");
			setlocale(LC_ALL, "C");
			printf("||%-10.10s|%-10.10s|%-10d|          |\n", tmp->Task.Programmers.Project, tmp->Task.Programmers.CPU, tmp->Task.Programmers.Memory);
			break;
		case DEPT_MANAGEMENT:
			setlocale(LC_ALL, "");
			printf("Менеджмент");
			setlocale(LC_ALL, "C");
			printf("||%-10.10s|%-10.10s|%-10d|          |\n", tmp->Task.Management.Project, tmp->Task.Management.Customer, tmp->Task.Management.ProgrammersNum);
			break;
		case DEPT_SHIPPING:
			setlocale(LC_ALL, "");
			printf("Доставка  ");
			setlocale(LC_ALL, "C");
			printf("||%-10.10s|%-10.10s|%-10d|", tmp->Task.Shipping.Address, tmp->Task.Shipping.Customer, tmp->Task.Shipping.Weight);
			setlocale(LC_ALL, "");
			switch (tmp->Task.Shipping.Transport)
			{
			case TRANSP_TRAIN:
				printf("Поезд     |\n");
				break;
			case TRANSP_AUTO:
				printf("Машина    |\n");
				break;
			case TRANSP_SHIP:
				printf("Корабль   |\n");
				break;
			case TRANSP_AERO:
				printf("Самолет   |\n");
				break;
			}
			setlocale(LC_ALL, "C");
			break;
		}

		tmp = tmp->next;
	}
	printf("%s\n", end);
	//printf("+---+----------+----------+----------+----------++----------+----------+----------+----------+\n");
	setlocale(LC_ALL, "");
}

void read() 
{
	system("cls");
	char a[128];
	//printf("Enter the path to the file: ");
	printf("Введите путь к файлу: ");
	scanf("%s", a);

	FILE *readfile = fopen(a, "r");
	if (!readfile) 
	{
		printf("Unable to open file %s\n",a);
		system("pause");
		return;
	}

	while (!feof(readfile))
	{


		Node *temp = (Node*)malloc(sizeof(Node));
		
		int a = 0;
		fscanf(readfile, "{%s ;%s ;%d;%d;", temp->Name, temp->LastName, &temp->Age, &a);
		temp->Department = (enum Department)a;
		if (feof(readfile))break;


		switch (temp->Department)
		{
		case DEPT_PROGRAMMERS:
			fscanf(readfile, "%s ;%s ;%d}\n", temp->Task.Programmers.Project, temp->Task.Programmers.CPU, &temp->Task.Programmers.Memory);
			break;
		case DEPT_MANAGEMENT:
			fscanf(readfile, "%s ;%s ;%d}\n", temp->Task.Management.Project, temp->Task.Management.Customer, &temp->Task.Management.ProgrammersNum);
			break;
		case DEPT_SHIPPING:
			a = 0;
			fscanf(readfile, "%s ;%s ;%d;%d}\n", temp->Task.Shipping.Address, temp->Task.Shipping.Customer, &temp->Task.Shipping.Weight, &a);
			temp->Task.Shipping.Transport = (enum Transport)a;
			break;
		}


		if (!head_of_list)
		{
			temp->next = head_of_list;
			head_of_list = temp;

		}
		else
		{
			Node *newhead = head_of_list;
			for (int i = 1;newhead->next; i++)
				newhead = newhead->next;

			temp->next = newhead->next;
			newhead->next = temp;
		}
	
	}
	fclose(readfile);	
	//printf("The reading is successful\n");
	printf("Чтение прошло успешно\n");
}

void write()
{
	system("cls");
	char a[128];
	//printf("Enter the path to the file: ");
	printf("Введите путь к файлу: ");
	scanf("%s", a);
	FILE *writefile = fopen(a, "w");
	if (!writefile)
	{
		//printf("Unable to open file %s\n", a);
		printf("Не удалось открыть файл %s\n", a);
		system("pause");
		return;
	}

	Node *node = head_of_list;
	
	
	while (node)
	{


		fprintf(writefile,"{%s ;%s ;%d;%d;", node->Name, node->LastName, node->Age,(int)node->Department);

		switch (node->Department)
		{
		case DEPT_PROGRAMMERS:
			fprintf(writefile,"%s ;%s ;%d}\n", node->Task.Programmers.Project, node->Task.Programmers.CPU, node->Task.Programmers.Memory);
			break;
		case DEPT_MANAGEMENT:
			fprintf(writefile,"%s ;%s ;%d}\n", node->Task.Management.Project, node->Task.Management.Customer, node->Task.Management.ProgrammersNum);
			break;
		case DEPT_SHIPPING:
			fprintf(writefile,"%s ;%s ;%d;%d}\n", node->Task.Shipping.Address, node->Task.Shipping.Customer, node->Task.Shipping.Weight, (int)node->Task.Shipping.Transport);
			break;
		}

		node = node->next;
	}
	
	fclose(writefile);
	//printf("The entry was successful\n");
	printf("Запись прошла успешно\n");
}

int main()
{

	
	setlocale(LC_ALL, "");
	
	while (1)
	{


		system("cls");
		
		printf("1)Создать новую запись\n");
		printf("2)Удалить запись\n");
		printf("3)Загрузить\n");
		printf("4)Сохранить\n");
		printf("5)Вывести таблицу\n");

	

		unsigned int n = 0;
		fflush(stdin);
		scanf("%u", &n);

		switch (n)
		{
		case 1:
			AddItem();
			break;
		case 2:
			delete();
			break;
		case 3:
			read();
			break;
		case 4:
			write();
			break;
		case 5:
			print();
			break;

		default:
			break;
		}
		system("pause");
	}

	
	return 0;
}


