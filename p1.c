p5b
// b) Check for un- terminated multi line comment statement in your C program


%{
#include<stdio.h>
int c=0,oc=0;
FILE *fp;
%}
%s COMMENT
%%
\n {c++;}
"/*" {BEGIN COMMENT;printf("\n comment begins in line no : %d\n",c);ECHO;oc=1;}
<COMMENT>"*/" {BEGIN 0;ECHO;oc=0;printf(": Comment ends in line no %d\n",c);}
<COMMENT>\n {c++;printf("\n");ECHO;}
<COMMENT>. {ECHO;}
. ;
%%
main()
{
yyin=fopen("source.txt","r");
yylex();
fclose(yyin);
if(oc==1)
{
 printf("\n comment is not closed till the end of file!");
}
}



source.txt

#include<stdio.h>
#include<conio.h>
#include<string.h>
/*dfddf*/
void main()
{
/*vbhfghfgh
dfhfgh
fghgfhfg
fghfh
*/
int a,b=78;
if((a<5&&j<9)
{
a=a+h;
g=6+7;
a=a+b;
printf("\n ");
}
/*
if(a<n)
{
h=j+k;
}
if(a<n))
{
g=h+k;
}
}
