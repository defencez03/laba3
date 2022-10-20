// ��������� �������� ������ 21��3: ������� �.�. � ����� �.�.
// ������������ �������
#include<iostream>


struct node
{
	int pri;
	char inf[256];  // �������� ����������
	struct node* next = NULL; // ������ �� ��������� ������� 
};

struct node* head = NULL, * last = NULL, * f = NULL; // ��������� �� ������ � ��������� �������� ������
int dlinna = 0;
char find_el[256];
int prioritet = 0;
struct node* priority(node* el);

struct node* get_struct(void)
{
	struct node* p = NULL;
	char s[256];

	if ((p = (node*)malloc(sizeof(struct node))) == NULL)  // �������� ������ ��� ����� ������� ������
	{
		printf("������ ��� ������������� ������\n");
		exit(1);
	}

	puts("������� �������� �������: ");   // ������ ������
	std::cin >> s;
	puts("������� ���������: ");   
	std::cin >> p->pri;
	if (*s == 0)
	{
		printf("������ �� ���� �����������\n");
		return NULL;
	}
	strcpy_s(p->inf, s);

	p->next = NULL;

	return p;		// ���������� ��������� �� ��������� �������
}

/* ���������������� ���������� � ������ �������� (� �����)*/
void push(void)
{
	struct node* p = NULL;
	p = get_struct();
	priority(p);
}

void pop(void)
{
	struct node* sw = NULL;
	sw = head;
	head = head->next;
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
}

struct node* priority(node* el)
{
	struct node* sw = NULL;
	if (head == NULL)
	{
		head = el;
		last = el;
		return NULL;
	}
	if (head->pri > el->pri)
	{
		el->next = head;
		head = el;
		return NULL;
	}
	struct node* struc = head;
	while (struc)
	{
		if (el->pri < struc->pri)
		{
			el->next = struc;
			sw->next = el;
			return NULL;
		}
		sw = struc;
		struc = struc->next;
	}
	if (head != NULL && el != NULL)
	{
		last->next = el;
		last = el;
	}
	return NULL;
}

int main() 
{
	setlocale(LC_ALL, "RUS");

	int var = 0;

	printf("���-�� ������: ");
	std::cin >> var;
	for (int i = 0; i < var; i++) {
		push();
	}
	review();
	pop();
	review();
	return 0;
}
