//使用类型
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void showmovies (Item item);
char *s_gets(char *st,int n);
int main(void){
  List movies;
  Item temp;
  InitiallizeList(&movies);
  if(ListIsFull(&movies)){
    fprintf(stderr, "No memory available!\n", );
    exit(1);
  }

  puts("Enter first movie title");
  while (s_gets(temp.title,TSIZE)!=NULL&&temp.title[0]!='\0') {
    puts("Enter your rating <0-10>: ");
    scanf("%d\n",&temp.rating );
    while (getchar()!='\0') {
      continue;
      if (AddItem(Item,&movies)==false) {
        fprintf(stderr, "Problem allicating memory\n");
        break;
      }
      if (ListIsFull(&movies)) {
        puts("the List is full.");
        break;
      }
      puts("enter next movie tile (empty lint to stop:)");
    }

    if (ListIsEmpty(&movies))
      printf("No data entered\n");
      else {
        printf("here is the movie list:  \n" );
        Traverse(&movies,showmovies);
      }
      printf("you entered %d movies.\n",ListItemCount(&movies) );
      //清理
      EmptyTheList(&movies);
      printf("Bye!\n" );
      return 0;
  }

  void showmovies(Item item){
    printf("Movies : %s  Rating : %d\n",item.title,item.rating );
  }
  char *s_gets(char *st,int n){
    char *ret_val;
    char *find;
    ret_val=fgets(st,n,stdin);
    if (ret_val) {
      find=strchr(st,'\n');
      if(find) *find='\0';
      else
      while (getchar()!='\n') {
        continue;
      }
    }
  }
  return ret_val;
}
