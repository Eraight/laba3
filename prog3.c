#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

struct node
{
	char inf[256];  // полезная информация
	struct node* next; // ссылка на следующий элемент 
};
char find_el[256];
struct node* head = NULL, * last = NULL, * prelast = NULL, * f = NULL; // указатели на первый и последний элементы списка
int dlinna = 0;


struct node* get_struct(void) // функция создания элемента
{
	struct node* p = NULL;
	char s[256];

	if ((p = (struct node*)malloc(sizeof(struct node))) == NULL)  // выделяем память под новый элемент списка
	{
		printf("Ошибка при распределении памяти\n");
		exit(1);
	}

	printf("Введите название объекта: \n");   // вводим данные
	scanf("%s", s);
	if (*s == 0)
	{
		printf("Запись не была произведена\n");
		return NULL;
	}
	strcpy(p->inf, s);

	p->next = NULL;

	return p;		// возвращаем указатель на созданный элемент
}

/* Последовательное добавление в очередь элемента (в конец)*/
void spstore(void)
{
	struct node* p = NULL;
	p = get_struct();
	if (head == NULL && p != NULL)
	{
		head = p;
		prelast = p;
		last = p;
	}
	else if (head != NULL && p != NULL)
	{
		last->next = p;
		prelast = last;
		last = p;
		last->next = NULL;
	}
	dlinna++;
	return;
}


/* Просмотр содержимого очереди. */
void review(void)
{
	struct node* struc = head;
	if (head == NULL)
	{
		printf("Стек пуст\n");
	}
	while (struc)
	{
		printf("Имя - %s, \n", struc->inf);
		struc = struc->next;
	}
	return;
}

/* Поиск элемента по содержимому. */
struct node* find(char* name) // функция нахождения элемента
{
	struct node* struc = head;
	if (head == NULL)
	{
		printf("Стек пуст\n");
	}
	while (struc)
	{
		if (strcmp(name, struc->inf) == 0)
		{
			return struc;
		}
		struc = struc->next;
	}
	printf("Элемент не найден\n");
	return NULL;
}

/* Удаление элемента по содержимому. */
void del()
{
	if (head == NULL) // если голова списка равна NULL, то список пуст
	{
		printf("Стек пуст");
		_getch();
		return;
	}
	free(last);
	if (dlinna-- == 1) {
		head = NULL;
		last = NULL;
		prelast = NULL;
		return;
	}
	prelast->next = NULL;
	prelast = head;
	for (int i = 1; i < dlinna-1;i++) {
		prelast = prelast->next;
	};
	last = dlinna != 1 ? prelast->next : head;
}

int main() {
	setlocale(LC_ALL, "RU");

	while (1) {
		system("cls");
		printf("действия:\n\t1)добавить\n\t2)посмотреть\n\t3)удалить");
		switch (_getch()) {
		case '1':
			system("cls");
			spstore();
			system("cls");
			break;
		case '2':
			system("cls");
			review();
			printf("Нажать кнопку для продолжения");
			_getch();
			system("cls");
			break;
		case '3':
			system("cls");
			del();
			system("cls");
			break;
		}
	}


}