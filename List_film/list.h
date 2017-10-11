//创造接口文件
#ifndef
#define LIST_H_
#include <stdbool.h>//支持布尔类型

#define TSIZE
struct film{
  char title[TSIZE];
  int rating;

};//一般类型定义

typedef struct film Item;
typedef struct node {
  Item item;
  struct node *next;
}Node;

typedef Node *List;

void InitiallizeList(List *plist);

void ListIsEmpty(const List *plist);

bool ListIsFull(const List *plist);

unsigned int ListItemCount (const List *plist);

bool AddItem(Item item,List *plist);

void Traverse (const List *plist,void (*pfun)(Item item));

void EmptyTheList(List *plist);

#endif
