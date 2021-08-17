p5a
// Write a Lex program to accept a C program and do the following error detection &
correction.
 a) Check for the valid if statement in the input C program. Report the errors to users.


%{
#include<stdio.h>
int c=0,bc=0,fc=0;
FILE *fp;
%}
%s IF OPENP CLOSEP OPENF
%%
\n { c++; }
"if" {BEGIN IF;ECHO;bc=0;}
<IF>\n {c++;ECHO;printf("\n");}
<IF>"(" {BEGIN OPENP;ECHO;bc++;}
<IF>")" {BEGIN CLOSEP;ECHO;bc--;}
<OPENP>")" {ECHO;bc--;BEGIN CLOSEP;}
<OPENP>"(" {ECHO;bc++;}
<OPENP>. {ECHO;}
<CLOSEP>"{" {if(bc==0) {printf("condn is valid in line no %d\n",c+1);}
 else printf("condn invalid in line no %d;Paranthesis mismatch in
condn\n",c+1);
 BEGIN OPENF;ECHO;printf("\n");fc++;}
<CLOSEP>"(" {BEGIN OPENP;bc++;ECHO;}
<CLOSEP>")" {ECHO;bc--;}
<CLOSEP>. {ECHO;}
<CLOSEP>\n {ECHO;printf("\n");c++;}
<OPENF>"}" {fc--;if(fc==0) BEGIN 0;;ECHO;printf("\n");}
<OPENF>. {ECHO;}
<OPENF>\n {ECHO;c++;}
.|\n ;
%%

main()
{
yyin=fopen("source.txt","r");
yylex();
fclose(yyin);
}



source.txt

#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
int a,b=78;
if((a<5&&j<9)
{
a=a+h;
g=6+7;
a=a+b;
printf("\n ");
}
if(a<n)
{
h=j+k;
}
if(a<n))
{
g=h+k;
}
}
