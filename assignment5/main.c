#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node
{
  char *key;
  struct Node *left;
  struct Node *right;
} Node;

void InsertNode(Node **, const char *);
void DeleteNode(Node **, const char *);
void ShowNode(Node *);

void ShowNode(Node *temp)
{
  if (temp == NULL)
  {
    puts("No value entered!");
    return;
  }
}

void InsertNode(Node **root, const char *data)
{
  Node *newnode = (Node *)malloc(sizeof(Node));
  Node *temp = *root;
}

int main(int argc, char const *argv[])
{
  char mode;
  char input_string[10];
  char *string;
  while (true)
  {
    scanf("%c %s", &mode, input_string);
    string = (char *)malloc(sizeof(input_string) + 1);
    strcpy_s(string, 10, input_string);
    if (mode == 'Q')
    {
      break;
    }
    else if (mode == 'I')
    {
      /* code */
    }
    else if (mode == 'S')
    {
      /* code */
    }
    else if (mode == 'D')
    {
      /* code */
    }
  }

  return 0;
}
