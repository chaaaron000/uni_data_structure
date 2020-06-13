// https://robodream.tistory.com/192
// https://www.randygaul.net/2015/06/15/printing-pretty-ascii-trees/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node
{
  char *key;
  struct Node *left;
  struct Node *right;
} * P_Node;

typedef struct Tree
{
  P_Node root;
} * P_Tree;

P_Tree Root = NULL;
char decorating[2056];
int depth;

P_Node GenerateNode();
void Initialize();
void Insert(const char *);
bool SearchData(const char *);
void Delete(const char *);
void Push(char);
void Pop();
void ShowNode();

P_Node GenerateNode()
{
  P_Node newNode;
  newNode = (P_Node)malloc(sizeof(struct Node));
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

void Push(char c)
{
  decorating[depth++] = ' ';
  decorating[depth++] = c;
  decorating[depth++] = ' ';
  decorating[depth++] = ' ';
  decorating[depth] = 0;
}

void Pop()
{
  decorating[depth -= 4] = 0;
}

void ShowNode(P_Node show)
{
  if (show)
  {
    printf(" %s\n", show->key);
    printf("%s +--", decorating);
    Push('|');
    if (show->left)
    {
      ShowNode(show->left);
    }
    else
    {
      printf("(NULL)\n");
    }
    Pop();

    printf("%s +--", decorating);
    Push(' ');
    if (show->right)
    {
      ShowNode(show->right);
    }
    else
    {
      printf("(NULL)\n");
    }
    Pop();
  }
}

void Initialize()
{
  Root = (P_Tree)malloc(sizeof(struct Tree));
  Root->root = NULL;
}

bool SearchData(const char *data)
{
  P_Node temp;
  temp = Root->root;
  while (1)
  {
    if (strcmp(temp->key, data) == 0)
    {
      return true;
    }
    if (strcmp(temp->key, data) > 0)
    {
      if (temp->left == NULL)
      {
        return false;
      }
      temp = temp->left;
    }
    else
    {
      if (temp->right == NULL)
      {
        return false;
      }
      temp = temp->right;
    }
  }
}

void Insert(const char *data)
{
  P_Node newNode;
  newNode = GenerateNode();
  newNode->key = malloc(sizeof(char) * strlen(data) + 1);
  strcpy(newNode->key, data);
  if (!Root->root)
  {
    Root->root = newNode;
    return;
  }
  if (SearchData(data))
  {
    puts("Already in there");
    return;
  }
  P_Node temp = Root->root;
  while (1)
  {
    if (strcmp(temp->key, data) > 0)
    {
      if (!temp->left)
      {
        temp->left = newNode;
        return;
      }
      temp = temp->left;
    }
    else
    {
      if (!temp->right)
      {
        temp->right = newNode;
        return;
      }
      temp = temp->right;
    }
  }
}

void Delete(const char *data)
{
  P_Node temp;
  P_Node parent, child;
  P_Node temp2, temp2_parent;
  temp = Root->root;
  parent = NULL;

  // 데이터가 이진 탐색 트리에 있는지 확인
  if (!SearchData(data))
  {
    puts("Value not found in binary serch tree");
    return;
  }

  // 삭제하고 싶은 데이터까지 temp를 이동
  while ((temp != NULL) && (strcmp(temp->key, data)))
  {
    // puts("while start");
    parent = temp;
    if (strcmp(temp->key, data) > 0)
    {
      temp = temp->left;
    }
    else
    {
      temp = temp->right;
    }
    // puts("while end");
  }

  // puts("Between");

  // 자식 노드가 없을 때
  if (temp->left == NULL && temp->right == NULL)
  {
    // puts("No child");
    // 부모 노드가 있다면
    if (parent)
    {
      // puts("parent");
      if (parent->left == temp)
      {
        parent->left = NULL;
      }
      else
      {
        parent->right = NULL;
      }
    }

    // 부모 노드가 없으면
    else
    {
      Root->root = NULL;
    }
  }

  // 자식 노드가 하나만 있을 때
  else if ((temp->left == NULL) || (temp->right == NULL))
  {
    // puts("1 child");
    // child 할당
    if (temp->left)
    {
      child = temp->left;
    }
    else
    {
      child = temp->right;
    }

    // 부모 노드가 있을 때
    if (parent)
    {
      if (parent->left == temp)
      {
        parent->left = child;
      }
      else
      {
        parent->right = child;
      }
    }

    // 부모 노드가 없을 때
    else
    {
      Root->root = child;
    }
  }

  // 자식 노드가 2개 있을 때
  else
  {
    // puts("2 child");
    temp2 = temp->left;
    temp2_parent = temp;

    // 후계자 노드까지 이동
    while (temp2->right != NULL)
    {
      // puts("while start");
      temp2_parent = temp2;
      temp2 = temp2->right;
      // puts("while end");
    }

    // puts("Between");

    if (temp2_parent->left == temp2)
    {
      temp2_parent->left = temp2->left;
    }
    else
    {
      temp2_parent->right = temp2->left;
    }
    temp->key = temp2->key;
    temp = temp2;
  }
  free(temp);
}

int main(int argc, char const *argv[])
{
  char mode;
  char *data;
  P_Node show;
  data = malloc(sizeof(char) * 128);
  Initialize();
  while (1)
  {
    mode = getchar();
    if (mode == 'Q')
    {
      break;
    }
    else if (mode == 'I' || mode == 'S' || mode == 'D')
    {
      scanf("%s", data);
      getchar();
      if (mode == 'I')
      {
        Insert(data);
      }
      else if (mode == 'S')
      {
        printf(SearchData(data) ? "is In Tree\n" : "Isn't in Tree\n");
      }
      else if (mode == 'D')
      {
        Delete(data);
      }
    }
    else
    {
      while (getchar() != '\n')
      {
      }
      puts("Wonrg input");
      continue;
    }
    show = Root->root;
    printf("----------[ Show Tree ]----------\n");
    ShowNode(show);
    printf("---------------------------------\n");
  }

  return 0;
}
