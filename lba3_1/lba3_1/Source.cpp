//��������: ������� � ����
#include<iostream>
#include<string>
#include<conio.h>


struct node
{
	char inf[256];  // �������� ����������
	struct node* next; // ������ �� ��������� ������� 
	struct node* prev; // ������ �� ���������� ������� 
};

struct node* head = NULL, * last = NULL, * f = NULL; // ��������� �� ������ � ��������� �������� ������
int dlinna = 0;

struct node* get_struct(void)
{
	struct node* p = NULL;
	char s[256];

	if ((p = (node*)malloc(sizeof(struct node))) == NULL)  // �������� ������ ��� ����� ������� ������
	{
		printf("������ ��� ������������� ������\n");
		exit(1);
	}

	printf("������� �������� �������: \n");   // ������ ������
	std::cin >> s;
	if (*s == 0)
	{
		printf("������ �� ���� �����������\n");
		return NULL;
	}
	strcpy_s(p->inf, s);

	p->next = NULL;
	p->prev = NULL;

	return p;		// ���������� ��������� �� ��������� �������
}

void push(void)
{
	struct node* p = NULL;
	p = get_struct();
	if (head == NULL && p != NULL)	// ���� ������ ���, �� ������������� ������ ������
	{
		head = p;
		last = p;
	}
	else if (head != NULL && p != NULL) // ������ ��� ����, �� ��������� � �����
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

/* �������� ����������� ������. */
void review(void)
{
	struct node* struc = head;
	if (head == NULL)
	{
		printf("������ ����\n");
	}
	while (struc)
	{
		printf("��� - %s, \n", struc->inf);
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
		printf("0.�����\n"
			"1.��������\n"
			"2.������� �� �������\n"
			"3.������� �� �����\n"
			"4.�������\n"
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