//Алоритмы: Очередь и Стек
#include<iostream>
#include<string>
#include<conio.h>


struct node
{
	char inf[256];  // полезная информация
	struct node* next; // ссылка на следующий элемент 
	struct node* prev; // ссылка на предыдущий элемент 
};

struct node* head = NULL, * last = NULL, * f = NULL; // указатели на первый и последний элементы списка
int dlinna = 0;

struct node* get_struct(void)
{
	struct node* p = NULL;
	char s[256];

	if ((p = (node*)malloc(sizeof(struct node))) == NULL)  // выделяем память под новый элемент списка
	{
		printf("Ошибка при распределении памяти\n");
		exit(1);
	}

	printf("Введите название объекта: \n");   // вводим данные
	std::cin >> s;
	if (*s == 0)
	{
		printf("Запись не была произведена\n");
		return NULL;
	}
	strcpy_s(p->inf, s);

	p->next = NULL;
	p->prev = NULL;

	return p;		// возвращаем указатель на созданный элемент
}

void push(void)
{
	struct node* p = NULL;
	p = get_struct();
	if (head == NULL && p != NULL)	// если списка нет, то устанавливаем голову списка
	{
		head = p;
		last = p;
	}
	else if (head != NULL && p != NULL) // список уже есть, то вставляем в конец
	{
		last->next = p;
		p->prev = last;
		last = p;
	}
	return;
}

void pop_stack(void)
{
	struct node* sw = NULL;
	sw = last;
	last = last->prev;
	last->next = NULL;
	free(sw);
}

void pop_queue(void)
{
	struct node* sw = NULL;
	sw = head;
	head = head->next;
	head->prev = NULL;
	free(sw);
}

/* Просмотр содержимого списка. */
void review(void)
{
	struct node* struc = head;
	if (head == NULL)
	{
		printf("Список пуст\n");
	}
	while (struc)
	{
		printf("Имя - %s, \n", struc->inf);
		struc = struc->next;
	}
	printf("\n");
	_getch();
}

int Menu(void)
{
	int c = 0;

	system("cls");
	while ((c < '0' || c > '8') && c != 27)
	{
		printf("0.Выход\n"
			"1.Добавить\n"
			"2.Удалить из очереди\n"
			"3.Удалить из стека\n"
			"4.Вывести\n"
			">");
		c = _getch();
		printf("%c\n", c);
	}
	return c;
}

int main(void)
{
	setlocale(LC_ALL, "rus");

	int selection = 0;

	while ((selection = Menu()) != '0' && selection != 27)
		switch (selection)
		{
		case '1':
			push();
			break;
		case '2':
			pop_queue();
			break;
		case '3':
			pop_stack();
			break;
		case '4':
			review();
			break;
		}
}