#include <stdio.h>
#include <stdlib.h>

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

  return 0;
}
