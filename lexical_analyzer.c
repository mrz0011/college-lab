#include <stdio.h>
#include <ctype.h>
#include <string.h>
int k_count=0,i_count=0;
void keyword(char str[10])
{
if (strcmp("include",str)==0||strcmp("printf",str)==0||strcmp("void",str)==0)
{
printf("\n%s is a keyword\n",str);
k_count++;
}
else
{
printf("\n%s is an identifier\n",str);
i_count++;
}
}
void main()
{
FILE *f1,*f2,*f3;
char c,str[10],str1[20];
int
str_count=0,num[100],lineno=0,tokenvalue=0,i=0,k=0,j=0,l=0,count=0,s_count=0;
printf("enter the c program:\n");
f1=fopen("input.txt","w");
while((c=getchar())!='$')
{
putc(c,f1);
}
fclose(f1);
f1=fopen("input.txt","r");
f2=fopen("identifier.txt","w");
f3=fopen("specialchar.txt","w");
while((c=getc(f1))!=EOF)
{
if(isdigit(c))
{
tokenvalue=c-'0';
c=getc(f1);
while(isdigit(c))
{
tokenvalue*=10+c-'0';
c=getc(f1);
}
num[i++]=tokenvalue;
ungetc(c,f1);
count=i;
}
else if(isalpha(c))
{
putc(c,f2);
c=getc(f1);
while(isdigit(c)||isalpha(c)||c=='_'||c=='$')
{
putc(c,f2);
c=getc(f1);
}
putc(' ',f2);
ungetc(c,f1);
}
else if(c==' '||c=='\t')
printf(" ");
else if (c=='\n')
lineno++;
else if (c=='\"')
{c=getc(f1);
while(c!='"')
{
str1[l++]=c;
c=getc(f1);
str_count++;
}
str1[l]='\0';}
else
putc(c,f3);
}
fclose(f2);
fclose(f3);
fclose(f1);
printf("\n The nos in the program are: ");
for(i=0;i<count;i++)
{
printf("%d\t",num[i]);
}
for(j=0;j<1;j++)
{
printf("\n");
f2=fopen("identifier.txt","r");
k=0;
printf("\nThe keyword & identifiers are: ");
while((c=getc(f2))!=EOF)
{
if(c!=' ')
str[k++]=c;
else
{
str[k]='\0';
keyword(str);
k=0;
}
}
fclose(f2);
f3=fopen("specialchar.txt","r");
printf("\nThe special characters are: ");
while((c=getc(f3))!=EOF)
{
printf("%c",c);
s_count++;
}
printf("\n");
fclose(f3);
printf("\n%s is a string literal\n",str1);
printf("\nTotal no of lines are: %d\n",lineno);
printf("\nCount of nos are: %d\n",count);
printf("\nTotal no of keywords are: %d\n",k_count);
printf("\nTotal no of identifiers are: %d\n",i_count);
printf("\nTotal no of special characters are: %d\n",s_count);
printf("\nTotal no of string characters are: %d\n",str_count);
}
}
