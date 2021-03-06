// StructListen.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.

#include "stdafx.h"
#include "address.h"


int main()
{
	char input[15] = "";
	address *pIter = NULL;

	const int wait_time = 1000;

	while (true)
	{
		system("cls");

		if (pIter != NULL)
		{
			print_entry(pIter);
			printf("[Next]	  :	 show next entry.\n");
			printf("[Prev]	  :	 show previous entry.\n");
			printf("[New]	  :	 create new entry.\n");
			printf("[Del]	  :	 delete current entry.\n");
			printf("[Edit]	  :	 edit current entry.\n");
			printf("[Exit]	  :	 exit application.\n");
			print_spacer();
			printf("\n");
		}
		else
		{
			print_spacer();
			printf("No entries. Create one, please.\n");
			print_spacer();
			printf("\n\n");
			print_spacer();
			printf("[New]	  :	 create new entry.\n");
			printf("[Exit]	  :	 exit application.\n");
			print_spacer();
			printf("\n");
		}

		printf(" > ");
		gets_s(input, 15);
		printf("\n");

		if(strcmp(input, "Next") == 0)
		{
			if (pIter != NULL && pIter->next != NULL)
			{
				pIter = switch_address(pIter, true);
				continue;
			}

			print_spacer();
			printf("No further entries.\n");
			print_spacer();

			Sleep(wait_time);
		}
		else if(strcmp(input, "Prev") == 0)
		{
			if (pIter != NULL && pIter->prev != NULL)
			{
				pIter = switch_address(pIter, false);
				continue;
			}

			print_spacer();
			printf("No previous entries.\n");
			print_spacer();
			Sleep(wait_time);
		}
		else if (strcmp(input, "New") == 0)
		{
			while (pIter != NULL && pIter->next != NULL)
			{
				pIter = pIter->next;
			}

			pIter = input_new_entry(pIter);
			Sleep(wait_time);
		}
		else if (strcmp(input, "Del") == 0 || strcmp(input, "Delete") == 0)
		{
			address *temp_entry = NULL;
			if (pIter != NULL && pIter->next != NULL)
			{
				temp_entry = pIter->next;

				print_spacer();
				printf("Showing the next entry.\n");
				print_spacer();
			}
			if (pIter != NULL && pIter->prev != NULL)
			{
				temp_entry = pIter->prev;

				print_spacer();
				printf("Showing the previous entry.\n");
				print_spacer();
			}
			if (pIter == NULL)
			{

				print_spacer();
				printf("No entries.\n");
				print_spacer();
			}

			free_entry(pIter);
			pIter = temp_entry;
			Sleep(wait_time);
		}
		else if (strcmp(input, "Edit") == 0)
		{
			if (pIter == NULL)
				continue;

			pIter = edit_current_entry(pIter);
		}
		else if (strcmp(input, "Exit") == 0)
		{
			break;
		}
		else
		{
			print_unknown_command(input, wait_time);
		}
	}

	return 0;
}