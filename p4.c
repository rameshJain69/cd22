p4a
// Write a Lex program to accept a C program and do the following error detection &
correction.
a) Check for the valid usages of numerical constants in the input C program. Intimate the
invalid usages to user.


%{
#include<stdio.h>
int c=0;
%}
number [0-9]+(".")?[0-9]*
invalid [0-9]+(".")[0-9]*((".")[0-9]*)+
%%
\n {c++;}
{number} {printf("\nValid number in line number %d : ",c+1);ECHO;printf("\n");}
{number}[a-zA-Z0-9_]+ {printf("\nInvalid number in line number %d: Number
followed with alphabets is invalid",c+1);ECHO;printf("\n");}
{invalid} {printf("\nInvalid number in line number %d: Number with more than one
decimal point sis invalid",c+1);ECHO;printf("\n");}
. ;
%%
void main()
{
yyin = fopen("source.txt","r");
yylex();
fclose(yyin);
}



source.txt

#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
int a=56;
a=1b;
a=a+5h;
a=a+4.5+5.6.6;
}



