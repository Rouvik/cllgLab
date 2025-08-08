#include <stdio.h>

typedef struct Person {
	int id;
	int salary;
	char name[32];
	char address[64];
} Person_t;

void input(Person_t *p)
{
	printf("Enter id: ");
	scanf("%d", &p->id);

	printf("Enter salary: ");
	scanf("%d", &p->salary);

	while(getchar() != '\n');	// flush stdin till \n

	printf("Enter name: ");
	fgets(p->name, 32, stdin);

	while(getchar() != '\n');	// flush stdin till \n

	printf("Enter address: ");
	fgets(p->address, 64, stdin);
}

void print(Person_t *p)
{
	printf("Name: %s\nId: %d\nSalary: %d\nAddress: %s\n", p->name, p->id, p->salary, p->address);
}

int main()
{
	Person_t person;
	input(&person);
		
	person.salary += 1000;	// got a Rs 1000 bonus

	print(&person);
	return 0;
}
