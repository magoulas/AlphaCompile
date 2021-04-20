%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

int token=0;
int count = 0;

typedef struct node{
    int line;
    int token_counter;
    char* text;
    char* type;
    char* value; 


    struct node* next;
    struct node* prev;
}alpha_token_t;
/*
types :
IDENT 1  
INT 2
REAL 3
STRING 4
OPERATOR 5
KEYWORD 6
COMMENT 7
PUNCTUATION 8
*/

alpha_token_t *listHead=NULL;
alpha_token_t *listTail=NULL;

void insertNode (int line, char* value , char* text, int type){
	alpha_token_t *new_token = malloc(sizeof(alpha_token_t));
	new_token->line=line;
	new_token->token_counter=count;
	if(type==1){
		new_token->text=strdup(text);
		new_token->type=strdup("IDENT");
		new_token->value=strdup(text);

	}
	else if(type==2){
		new_token->text=strdup(text);
		new_token->type=strdup("INT");
		new_token->value = strdup(text);
	}
	else if(type==3){
		new_token->text=strdup(text);
		new_token->type=strdup("REAL");
		new_token->value = strdup(text);	
	}
	else if(type==4){
		new_token->text=strdup(text);
		new_token->type=strdup("STRING");
		new_token->value=strdup(value);	
	}
	else if(type==5){
		new_token->text=strdup(text);
		new_token->type=strdup("OPERATOR");
		new_token->value=strdup(value);
	}
	else if(type==6){
		new_token->text=strdup(text);
		new_token->type=strdup("KEYWORD");
		new_token->value=strdup(value);	
	}
	else if(type==7){
		new_token->text=strdup(text);
		new_token->type=strdup("COMMENT");
		new_token->value=strdup(value);
	}
	else if(type==8){
		new_token->text=strdup(text);
		new_token->type=strdup("PUNCTUATION");
		new_token->value=strdup(value);
	}

	if(listHead==NULL){
		listHead=new_token;
		listHead->next=new_token;
		listHead->prev=NULL;
		listTail=new_token;
		listTail->next=NULL;
		listTail->prev=new_token;
	}
	else{
		new_token->prev=listTail;
		new_token->next=NULL;
		listTail->next=new_token;
		listTail=new_token;
	}
}
void printList(){
	alpha_token_t* tmp = listHead;
	while(tmp!=NULL){
		printf("%d: #%d    %s    %s      %s\n",tmp->line,tmp->token_counter,tmp->text,tmp->type,tmp->value);
		tmp=tmp->next;
	}
}



%}

%option header-file="./scanner"
%option noyywrap
%option yylineno
%option case-insensitive 


IF_ST	"if"
ELSE_ST		"else"
FOR_ST "for"
WHILE_ST "while"
AND_ST "and"
NOT_ST "not"
OR_ST "or"
LOCAL_ST "local"
CONTINUE_ST "continue"
BREAK_ST "break"
TRUE_ST "true"
FALSE_ST "false"
NIL_ST "nil"
FUNC_ST "function"
RETURN_ST "return"

PLUS_OP "+"
MINUS_OP "-"
EQUAL_OP "="
MULTI_OP "*"
DIVISION_OP "/"
PERCENT_OP "%"
INCREMENT_OP "++"
DICREMENT_OP "--"

COMP_EQUAL_OP "=="
COMP_NOT_EQUAL_OP "!="
COMP_BIGGER_OP ">"
COMP_LESS_OP "<"
COMP_BIGGER_EQUAL_OP ">="
COMP_LESS_EQUAL_OP "<="

NUMBER_INT [0-9]+

NUMBER_REAL [0-9]+"."[0-9]+

STRING \"

LEFT_CBRACKET "{"
RIGHT_CBRACKET "}"
LEFT_PARENTHESIS "("
RIGHT_PARENTHESIS ")"
SEMICOLON ";"
COMMA ","
COLON ":"
DOUBLE_COLON "::"
FULL_STOP "."
RANGE ".."
LEFT_ARRAY "["
RIGHT_ARRAY "]"

ID [a-zA-Z][a-zA-Z0-9_]*

COMMENT  "//".*

COMMENT1 "/*"

SPACE  [\n\r \v\t]
OTHER	[!~?#$]
OTHER2	"&&"
OTHER3	"||"
OTHER4  .

%%
{IF_ST}		{++count;  insertNode(yylineno,"IF",yytext,6); 		return IF_ST;}
{ELSE_ST}	{++count;  insertNode(yylineno,"ELSE",yytext,6); 	return ELSE_ST;}
{FOR_ST}	{++count;  insertNode(yylineno,"FOR",yytext,6); 	return FOR_ST; }
{WHILE_ST}	{++count;  insertNode(yylineno,"WHILE",yytext,6); 	return WHILE_ST; }
{AND_ST}	{++count;  insertNode(yylineno,"AND",yytext,6); 	return AND_ST;}
{NOT_ST}	{++count;  insertNode(yylineno,"NOT",yytext,6); 	return NOT_ST;}
{OR_ST}		{++count;  insertNode(yylineno,"OR",yytext,6); 		return OR_ST;}
{LOCAL_ST}	{++count;  insertNode(yylineno,"LOCAL",yytext,6);	return LOCAL_ST;}
{CONTINUE_ST}	{++count;  insertNode(yylineno,"CONTINUE",yytext,6); 	return CONTINUE_ST;}
{BREAK_ST}	{++count;  insertNode(yylineno,"BREAK",yytext,6); 	return BREAK_ST;  }
{TRUE_ST}	{++count;  insertNode(yylineno,"TRUE",yytext,6); 	return TRUE_ST; }
{FALSE_ST}	{++count;  insertNode(yylineno,"FALSE",yytext,6); 	return FALSE_ST;}
{NIL_ST}	{++count;  insertNode(yylineno,"NIL",yytext,6); 	return NIL_ST;}
{FUNC_ST}	{++count;  insertNode(yylineno,"FUNCTION",yytext,6); return FUNC_ST; }
{RETURN_ST}	{++count;  insertNode(yylineno,"RETURN",yytext,6);  return RETURN_ST; }

{PLUS_OP}	{++count;  insertNode(yylineno,"PLUS",yytext,5); return PLUS_OP;}
{MINUS_OP}	{++count;  insertNode(yylineno,"MINUS",yytext,5); return MINUS_OP;}
{EQUAL_OP}	{++count;  insertNode(yylineno,"EQUAL",yytext,5); return EQUAL_OP;}
{MULTI_OP}	{++count;  insertNode(yylineno,"MULTIPLY",yytext,5); return MULTI_OP;}
{DIVISION_OP}	{++count;  insertNode(yylineno,"DIVISION",yytext,5); return DIVISION_OP;}
{PERCENT_OP}	{++count;  insertNode(yylineno,"PERCENT",yytext,5); return PERCENT_OP;}
{INCREMENT_OP}	{++count;  insertNode(yylineno,"INCREMENT",yytext,5); return INCREMENT_OP; }
{DICREMENT_OP}	{++count;  insertNode(yylineno,"DICREMENT",yytext,5); return DICREMENT_OP;}

{COMP_EQUAL_OP}	{++count;  insertNode(yylineno,"COMPARE EQUAL",yytext,5); return COMP_EQUAL_OP;}
{COMP_NOT_EQUAL_OP}	{++count;  insertNode(yylineno,"COMPARE NOT EQUAL",yytext,5); return COMP_NOT_EQUAL_OP;}
{COMP_BIGGER_OP}	{++count;  insertNode(yylineno,"COMPARE BIGGER",yytext,5); return COMP_BIGGER_OP; }
{COMP_LESS_OP}	{++count;  insertNode(yylineno,"COMPARE LESS",yytext,5); return COMP_LESS_OP; }
{COMP_BIGGER_EQUAL_OP}	{++count;  insertNode(yylineno,"COMPARE BIGGER EQUAL",yytext,5); return COMP_BIGGER_EQUAL_OP;  }
{COMP_LESS_EQUAL_OP}	{++count;  insertNode(yylineno,"COMPARE LESS EQUAL",yytext,5); return COMP_LESS_EQUAL_OP; }



{NUMBER_INT}     {++count;  yylval.intVal=atoi(yytext); insertNode(yylineno,NULL,yytext,2); return NUMBER_INT; }
{NUMBER_REAL}     {++count;  yylval.doubleVal=atof(yytext);	insertNode(yylineno,NULL,yytext,3); return NUMBER_REAL;}

{STRING}     {

		char *Stoken=(char*)malloc(sizeof(char));
		int c;
		int key=0;
		while((c=input())!=EOF )
		{
  			if(c=='"'){
				 Stoken=realloc(Stoken,(key+1) * (sizeof(char)));
				 Stoken[key++]='\0';		
				 break;
			}
			if(c=='\\') 
			{
			  c=input();
 				  if(c!=EOF){
					if	(c=='n'){
					  	Stoken=realloc(Stoken,(key+1) * (sizeof(char)));
						Stoken[key++]='\n';

					}else if (c=='t'){
						Stoken=realloc(Stoken,(key+1) * (sizeof(char)));
						Stoken[key++]='\t';

					}else if (c=='\\'){
						Stoken=realloc(Stoken,(key+1) * (sizeof(char)));
						Stoken[key++]='\\';

					}else if(c=='\"'){
						Stoken=realloc(Stoken,(key+1) * (sizeof(char)));
						Stoken[key++]='\"';

					}else{

						Stoken=realloc(Stoken,(key+1) * (sizeof(char)));
						Stoken[key++]='\\';
						Stoken=realloc(Stoken,(key+1) * (sizeof(char)));
						Stoken[key++]=c;

						printf("\033[0;31m");
						printf("Invalid escape character:%c\n",c);
						printf("\033[0m");
					}
				  }
			}else{
			Stoken=realloc(Stoken,(key+1) * (sizeof(char)));
			Stoken[key++]=c;
			}
			
		}

		if(c==EOF){
  			 printf("\033[0;31m");
		  	 printf("Unterminated string in line:%d\n",yylineno);
			 printf("\033[0m");
		}else{
			const char* a = "\"";
			char* final= malloc((sizeof(char)*strlen(a))+(sizeof(char)*strlen(Stoken))+(sizeof(char)*strlen(a)));
			strcat(final , a);
			strcat(final , Stoken);
			strcat(final , a);
			++count;
			insertNode(yylineno,Stoken,final,4);
			yylval.strVal=strdup(Stoken);
			return STRING;
			
		}
}


{LEFT_CBRACKET}	{++count;  insertNode(yylineno,"LEFT BRACKET",yytext,5); return LEFT_CBRACKET;  }
{RIGHT_CBRACKET}	{++count;  insertNode(yylineno,"RIGHT BRACKET",yytext,5); return  RIGHT_CBRACKET;}
{LEFT_PARENTHESIS}	{++count;  insertNode(yylineno,"LEFT PARENTHESIS",yytext,5); return LEFT_PARENTHESIS;  }
{RIGHT_PARENTHESIS}	{++count;  insertNode(yylineno,"RIGHT PARENTHESIS",yytext,5); return RIGHT_PARENTHESIS; }
{SEMICOLON}	{++count;  insertNode(yylineno,"SEMICOLON",yytext,5); return SEMICOLON; }
{COMMA}		{++count;  insertNode(yylineno,"COMMA",yytext,5); return COMMA; }
{COLON}		{++count;  insertNode(yylineno,"COLON",yytext,5); return  COLON; }
{DOUBLE_COLON}	{++count;  insertNode(yylineno,"DOUBLE_COLON",yytext,8); return DOUBLE_COLON; }
{FULL_STOP}		{++count;  insertNode(yylineno,"FULL_STOP",yytext,8); return  FULL_STOP; }
{RANGE}		{++count;  insertNode(yylineno,"RANGE",yytext,8); return RANGE; }
{LEFT_ARRAY}	{++count;  insertNode(yylineno,"LEFT_ARRAY",yytext,8); return LEFT_ARRAY;  }
{RIGHT_ARRAY}	{++count;  insertNode(yylineno,"RIGHT_ARRAY",yytext,8); return  RIGHT_ARRAY; }


{ID}		{++count; yylval.strVal=strdup(yytext);  insertNode(yylineno,NULL,yytext,1); return ID; }

{COMMENT} {++count;  insertNode(yylineno,"LINE COMMENT",yytext,7); }

{COMMENT1} {
       int firstline=yylineno;
       int lastline=1;
       int c;
       int left_counter=1;
       int right_counter=0;
       int balance=1;
       while((c=input())!=EOF)
       {
	        	if(balance==0)break;
 			if(c=='/'){
	 			if((c=input())=='*') left_counter++;
				else if(c=='/'){unput(c);}
				else{}
			}else  if(c=='*'){
				if((c=input())=='/') right_counter++;
				else if(c=='*'){unput(c);}
                                else{}

			}else{
			}
			balance=left_counter-right_counter;
			lastline=yylineno;
       }
	
	 if(c==EOF && balance != 0){
                         printf("\033[0;31m");
                         printf("Unterminated comment at line %d\n",firstline);
                         printf("\033[0m");
         }else{
			  		char buffer[258]; 
   					sprintf(buffer, "%d - %d", firstline, lastline); 
                    ++count; 
					insertNode(firstline,"BLOCK COMMENT",buffer,7);
        		 int j=1;
			 while(j<right_counter)
			 {
				++count; 
				insertNode(firstline,"NESTED COMMENT",buffer,7);
				 j++;
			 } 
	}
}

{SPACE}		{;}
{OTHER}		{printf("\033[0;31m");printf("Undifined Character '%s' in line: %d\n",yytext,yylineno);printf("\033[0m"); }
{OTHER2}	{printf("\033[0;31m");printf("Undifined Character '%s' in line: %d\n",yytext,yylineno);printf("\033[0m");}
{OTHER3}	{printf("\033[0;31m");printf("Undifined Character '%s' in line: %d\n",yytext,yylineno);printf("\033[0m"); }
{OTHER4}	{printf("\033[0;31m");printf("Undifined Character '%s' in line: %d\n",yytext,yylineno);printf("\033[0m"); }

%%

/*
int main(int argc,char** argv)
{
  if(argc>1){
   if(!(yyin=fopen(argv[1],"r"))){  //yyin dikths sto file p tha kanume scan//
      fprintf(stderr,"Cannot read file:%s\n",argv[1]);
      return 1;
   }
  }else{
    yyin=stdin;
  }

	printf("--------------------		Lexical Analysis		--------------------\n");
    yylex();
	printList();
    return 0;
}

*/
