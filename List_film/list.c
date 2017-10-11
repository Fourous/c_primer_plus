#include <stdio.h>
#include <stdlib.h>
#include "list.h"
static void CopyToNode(Item item,Node *pnode);

void InitiallizeList(List *plist){
  *plist=NULL;
}

bool ListIsEmpty(const List *plist){
  if(*plist==NULL) return true;
  else return false;
}

bool ListIsFull(LIst *plist){
  Node *pt;
  bool full;
  pt=(Node *)malloc(sizeof(Node));
  if(pt==NULL)
  full=true;
  else
  full=false;
  free (pt);
  return full;
}

unsigned int ListItemCount(const List *plist){
  unsigned int count=0;
  Node *pnode=*plist;
  while (pnode!=NULL) {
    ++count;
    pnode=pnode->next;
  }
  return count;
}


bool AddItem(Item item,List *plist){
  Node *pnew;
  Node *scan=*plist;
  pnew = (Node *)malloc(sizeof(Node));
  if(pnew==NULL)
  return false;
  CopyToNode(item,pnew);
  pnew->next=NULL;
  if(scan==NULL)
    *plist=pnew;
    else{
      while (scan->next!=NULL) {
        scan=scan->next;
        scan->next=pnew;
      }
    }
    return true;
}

void Traverse(const List *plist),void(*pfun)(Item item) {
    Node *pnode=*plist;
    while (pnode!=NULL){
      (*pfun)(pnode->item);
      pnode=pnode->next;
    }
}

void EmptyTheList(List *plist){
  Node *psava;
  while (*plist!=NULL) {
    psava=(*plist)->next;
    free(*plist);
    *plist=psave;
  }
}

static void CopyToNode(Item item,Node *pnode) {
  pnode->next=item;
}
