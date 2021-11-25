#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct N{
	char* str;
	struct N *next;
	struct N *prev;
	}nodo_t;
typedef nodo_t* pnodo;

char* dup_string(char str[]){
 char *pt;
 int i;
 pt = (char*)malloc( sizeof(char) * (strlen(str) + 1) );
 for(i=0; i<strlen(str); i++)
        { *(pt + i) = str[i];
        }
 *(pt + strlen(str)) = '\0';
 return pt;
 }


int main(){
 char temp[100];
 int len;
 pnodo head, holder;
 head = NULL;
 holder = NULL;
 pnodo cur, prev;

 scanf("%[^\n]", temp);
 len = strlen(temp);
 while( strcmp(temp, "stop") != 0)
	{ holder = malloc( (sizeof(char) * (len+1) ) + sizeof(pnodo) + sizeof(pnodo) );
	  if(holder)
		{
		  holder->str = dup_string( temp );
		  holder->next = head;
		  holder->prev = NULL;
		  head = holder;
		  head->prev = head;
		  free(holder);
		  scanf("%s", temp);
 		  len = strlen(temp);
		}
	  else
		{printf("Errore allocazione memoria");
		}
	}

 cur = head;
 while(cur->next != NULL)
	{cur = cur->next;
	}

 while(cur->prev != head)
	{printf("%s", cur->str);
	 free(cur->next);
	 cur = cur->prev;
	}

 free(head);

 return 0;
 }
