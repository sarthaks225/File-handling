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
for(x=0; name[x]; x++)
{
if(name[x]=='!')
{
printf("invalid name... it contains(!)\n");
return;
}
}

printf("enter contact: ");
fgets(contact,30,stdin); fflush(stdin);
contact[strlen(contact)-1]='\0';
for(x=0; contact[x]; x++)
{
if(contact[x]=='!')
{
printf("invalid contact... it contains(!)\n");
return;
}
}


f=fopen("friends.cont","a");

for(x=0; name[x]!='\0'; x++) fputc(name[x],f);
fputc('!',f);
for(x=0; contact[x]!='\0'; x++) fputc(contact[x],f);
fputc('!',f);
fclose(f);
printf("Friend added (%s)\n\n",name);

}

void viewList()
{
FILE *g;
char j,name[20],contact[30];
int x;

g=fopen("friends.cont","r");


if(g==NULL)
{
printf("No friend added ....\n"); return;
}

while(1)
{

j=fgetc(g);
if(feof(g)) break; 
name[0]=j;

x=0;

while(name[x]!='!')
{
x++;
name[x]=fgetc(g);
}

name[x]='\0';

x=0;
j=fgetc(g);
contact[0]=j;
while(contact[x]!='!')
{
x++;
contact[x]=fgetc(g);
}
contact[x]='\0';

printf("Name :- (%s)  Contact :- (%s)\n",name,contact);


}

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