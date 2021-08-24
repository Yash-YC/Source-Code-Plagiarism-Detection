#include <cstdio>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <string>

struct node
{
	char ch;
	node* next;
};

void Print(node ** first)
{
	if (*first == NULL)
	{
		return;
	}
	node * temp = *first;
	while (temp->next != NULL)
	{
		printf("%c", temp->ch);
		temp = temp->next;
	}
	printf("%c", temp->ch);
}

void PrintStr(node ** first, char * str)
{
	if (*first == NULL || str == NULL)
	{
		return;
	}
	node * temp = *first;
	int count = 0;
	while (temp->next != NULL)
	{
		str[count] = (temp->ch);
		temp = temp->next;
		count++;
	}
	str[count] = (temp->ch);
	str[count + 1] = '\0';
}

void Insert(char a, node ** first)
{
	node* ins = new node();
	ins->ch = a;
	ins->next = NULL;

	if (*first == NULL)
	{
		*first = ins;
		return;
	}
	node * head = *first;
	// if new char < first char insert new char at last
	if (a < head->ch)
	{
		node * temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = ins;
	}
	else 		// new char >= first char insert new char at first
	{
		node* temp = *first;
		*first = ins;
		(*first)->next = temp;
	}
}

int main()
{
	int Ntest;
	scanf("%d", &Ntest);
	getchar();
	std::vector<std::string> output;
	for (int test = 0; test<Ntest; ++test)
	{
		node * head = NULL;
		int count = 0;
		char buf = getchar();
		count++;
		while (buf != '\n')
		{
			Insert(buf, &head);
			count++;
			buf = getchar();
		}
		char * out = new char[count];
		PrintStr(&head, out);
		output.push_back(std::string(out));
		delete[] out;
	}

	for (int test = 0; test<Ntest; ++test)
	{
		printf("Case #%d: %s\n", test+1, output[test].c_str());
	}
	return 0;
}