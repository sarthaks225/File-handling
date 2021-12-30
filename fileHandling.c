#include<stdio.h>
#include<string.h>
void addDetails()
{
char name[20],contact[30];
FILE *f;
int x;

printf("Enter name: ");
fgets(name,20,stdin); fflush(stdin);
name[strlen(name)-1]='\0';

printf("enter contact: ");
fgets(contact,30,stdin); fflush(stdin);
contact[strlen(contact)-1]='\0';

f=fopen("friends.ff","a");

fputs(name,f);
fputc('\n',f);
fputs(contact,f);
fputc('\n',f);

fclose(f);
printf("friend added\n");
}

void viewList()
{

FILE *g;
char name[20],contact[30];

g=fopen("friends.ff","r");

if(g==NULL)
{
printf("No friend added ....\n"); return;
}

while(1)
{
fgets(name,20,g);
if(feof(g)) break;
name[strlen(name)-1]='\0';
fgets(contact,30,g);
contact[strlen(contact)-1]='\0';
printf("Name :- %s  contact :- %s\n",name,contact);

}

fclose(g);
}


int main()
{
int ch;

while(1)
{
printf("1. Add Details\n");
printf("2. View list\n");
printf("3. exit\n");
printf("enter your choice: ");
scanf("%d",&ch); fflush(stdin);

if(ch==1)
{
addDetails();
}

if(ch==2)
{
viewList();
}

if(ch==3) break;

}

return 0;
}