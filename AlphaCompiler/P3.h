#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "Table.h"

#define INITIAL_CAPACITY 2

int tmpcounter=0;
int scope=0;
extern int yylineno;
int flagstart=1;
int loopcounter=0;
typedef enum{
  assign=0,add,sub,
  mult,divid,modul,
  uminus,and,or,
  not,if_eq,if_noteq,
  if_lesseq,if_greatereq,if_less,
  if_greater,call,param,
  ret,getretval,funcstart,
  funcend,tablecreate,
  tablegetelem,tablesetelem,jump,
  start
}iopcode;

typedef enum{
  var_e=0,
  tableitem_e,
  programfunc_e,
  libraryfunc_e,
  arithexpr_e,
  boolexpr_e,
  assignexpr_e,
  newtable_e,
  constnum_e,
  constbool_e,
  conststring_e,
  nil_e

}expr_t;

const char* GetTypeOp(iopcode op){
  switch(op)
  {
  case assign: return "assign";
	case add: return "add";
	case sub: return "sub";
	case mult: return "mul";
	case divid: return "div";
  case modul: return "mod";
  case uminus: return "uminus";
  case and: return "and";
  case or: return "or";
  case not: return "not";
  case if_eq: return "if_eq";
  case if_noteq: return "if_noteq";
  case if_lesseq: return "if_lesseq";
  case if_greatereq: return "if_greatereq";
  case if_less: return "if_less";
  case if_greater: return "if_greater";
  case call: return "call";
  case param: return "param";
  case ret: return "return";
  case getretval: return "getretval";
  case funcstart: return "funcstart";
  case funcend: return "funcend";
  case tablecreate: return "tablecreate";
  case tablegetelem: return "tablegetelem";
  case tablesetelem: return "tablesetelem";
  case jump:return "jump";
  }
}


int CheckLabelOp(iopcode op){
        if(strcmp(GetTypeOp(op),"if_eq")==0||strcmp(GetTypeOp(op),"if_noteq")==0||strcmp(GetTypeOp(op),"if_greater")==0||
        strcmp(GetTypeOp(op),"if_less")==0||strcmp(GetTypeOp(op),"if_greatereq")==0||strcmp(GetTypeOp(op),"if_lesseq")==0||
        strcmp(GetTypeOp(op),"jump")==0){
                return 1;
        }else{
                 return 0;
        }
}

const char* GetTypeExpr(expr_t expr){
  switch(expr)
  {
    case var_e: return "var_e";
    case tableitem_e: return "tableitem_e";
    case programfunc_e: return "programfunc_e";
    case libraryfunc_e: return "libraryfunc_e";
    case arithexpr_e: return "arithexpr_e";
    case boolexpr_e: return "boolexpr_e";
    case assignexpr_e: return "assignexpr_e";
    case newtable_e: return "newtable_e";
    case constnum_e: return "constnum_e";
    case constbool_e: return "constbool_e";
    case conststring_e: return "conststring_e";
    case nil_e: return "nil_e";
  }
}



typedef struct expr{
    expr_t  type;
    SymbolTableEntry*   sym;
    struct expr* index;
    double doubleConst;
    int   intConst;
    char* strConst;
    unsigned char boolConst;
    struct expr* next;
    int truelist;
    int falselist;
    int quadF;
}expr;

typedef struct quad{
  iopcode op;
  expr* result;
  expr* arg1;
  expr* arg2;
  int label;
  unsigned line;

}quad;

typedef struct call {
expr* elist;
unsigned char method;
char* name;
}callx;

typedef struct forpr {
int test;
int enter;
}forpre;

typedef struct stmt_t {
int breakList, contList,returnList;
}stmt_t;

typedef struct indext {
   expr *index;
   expr *value;
   struct indext *next;
}indext;


quad* quads=(quad*)0;
unsigned total=0;
unsigned int currQuad=0;


#define EXPAND_SIZE 2
#define CURR_SIZE (total*sizeof(quad))
#define NEW_SIZE (EXPAND_SIZE*sizeof(quad)+CURR_SIZE)



void expand(){
  assert(total==currQuad);
  quad* p=(quad*)malloc(NEW_SIZE);
  if(quads){
    memcpy(p,quads,CURR_SIZE);
    free(quads);
  }
  quads=p;
  total +=EXPAND_SIZE;
}

void emit(iopcode op,expr* result,expr* arg1,expr* arg2)
{
  if(flagstart==1){
      if(currQuad==total) expand();
      quad *p=quads+currQuad++;
      p->arg1=NULL;
      p->arg2=NULL;
      p->result=NULL;
      p->line=currline();
      p->label=0;
      p->op=op;
      flagstart=0;
  }else{
         if(currQuad==total) expand();
        quad *p=quads+currQuad++;
        p->arg1=arg1;
        p->arg2=arg2;
        p->result=result;
        p->line=currline();
        p->label=0;
        p->op=op;

  }

 
}

quad *ReturnQuad(int index){
  quad *p=quads+index;
  if(p!=NULL) return p;
  else return NULL;
}
int isInteger(double val)
{
    int truncated = (int)val;
    if (val == truncated) return 1;
    else return 0;
}

void PrintByExprType(expr* expr,int i){

  if(strcmp("tableitem_e",GetTypeExpr(expr->type))==0||strcmp("var_e",GetTypeExpr(expr->type))==0||strcmp("programfunc_e",GetTypeExpr(expr->type))==0
    ||strcmp("assignexpr_e",GetTypeExpr(expr->type))==0||strcmp("boolexpr_e",GetTypeExpr(expr->type))==0||
    strcmp("libraryfunc_e",GetTypeExpr(expr->type))==0||strcmp("arithexpr_e",GetTypeExpr(expr->type))==0||
      strcmp("newtable_e",GetTypeExpr(expr->type))==0){
    if(expr->sym!=NULL){
          printf("arg%d:\"%s\"   ",i,expr->sym->name);
          return;
    }else{
          printf("expr->sym is NULL\n");
          return;
    }
 }else if(strcmp("conststring_e",GetTypeExpr(expr->type))==0){
    if(expr->strConst!=NULL){
          printf("arg%d:\"%s\"   ",i,expr->strConst);
          return;
    }else{
          printf("expr->strConst is NULL\n");
          return;
    }
 }else  if(strcmp("constbool_e",GetTypeExpr(expr->type))==0){
    if(expr->boolConst==1){
          printf("arg%d:\"true\"    ",i);
          return;
    }else if (expr->boolConst==0){
          printf("arg%d:\"false\"    ",i);
          return;
    }else{
          printf("expr->boolConst is NULL\n");
          return;
    }
 }else  if(strcmp("constnum_e",GetTypeExpr(expr->type))==0){
     if(strcmp(expr->strConst,"int")==0){
         printf("arg%d:\"%d\"   ",i,expr->intConst);
     }else if(strcmp(expr->strConst,"double")==0){
         printf("arg%d:\"%f\"   ",i,expr->doubleConst);
     }else{
         printf("expr->strConst is NULL\n");
     }
          
          return;
 }else if(strcmp("nil_e",GetTypeExpr(expr->type))==0){
     printf("arg%d:\"null\"",i);
     return;
 
 }else{
  // printf("no print type !\n");
   return;
 }

 return ;
}

void PrintResult(expr* expr){

  if(strcmp("tableitem_e",GetTypeExpr(expr->type))==0||strcmp("var_e",GetTypeExpr(expr->type))==0||strcmp("programfunc_e",GetTypeExpr(expr->type))==0
    ||strcmp("assignexpr_e",GetTypeExpr(expr->type))==0||strcmp("boolexpr_e",GetTypeExpr(expr->type))==0||
    strcmp("libraryfunc_e",GetTypeExpr(expr->type))==0||strcmp("arithexpr_e",GetTypeExpr(expr->type))==0||
     strcmp("newtable_e",GetTypeExpr(expr->type))==0){
    if(expr->sym!=NULL){
          printf("result:\"%s\"   ",expr->sym->name);
          return;
    }else{
          printf("expr->sym is NULL\n");
          return;
    }
 }else if(strcmp("conststring_e",GetTypeExpr(expr->type))==0){
    if(expr->strConst!=NULL){
          printf("result:\"%s\"   ",expr->strConst);
          return;
    }else{
          printf("expr->strConst is NULL\n");
          return;
    }
 }else  if(strcmp("constbool_e",GetTypeExpr(expr->type))==0){
    if(expr->boolConst==1){
          printf("result:\"true\"    ");
          return;
    }else if (expr->boolConst==0){
          printf("result:\"false\"    ");
          return;
    }else{
          printf("expr->boolConst is NULL\n");
          return;
    }
 }else  if(strcmp("constnum_e",GetTypeExpr(expr->type))==0){
     
     if(strcmp(expr->strConst,"int")==0){
         printf("result:\"%d\"   ",expr->intConst);
     }else if(strcmp(expr->strConst,"double")==0){
         printf("result:\"%f\"   ",expr->doubleConst);
     }else{
         printf("expr->strConst is NULL\n");
     }
          
          return;
 }else if(strcmp("nil_e",GetTypeExpr(expr->type))==0){
     printf("result:\"null\"   ");
     return;
 
 }else{
  // printf("no print type !\n");
   return;
 }

 return ;
}



void PrintQuads(){
  quad *p=NULL;
  int i=1;
  printf("----------------------------------------Quads-----------------------------------------------\n");
  for(i;i<currQuad;i++){
    
      p=quads+i;
      printf("quad:%d    ",i);
      printf("opcode:%s    ",GetTypeOp(p->op));
      if(p->result!=NULL){
        PrintResult(p->result);
 //            printf("result:\"%s\"   ",p->result->sym->name);
      }
      
      if(p->arg1!=NULL){
         PrintByExprType(p->arg1,1);
      }

       if(p->arg2!=NULL){
          PrintByExprType(p->arg2,2);
      }
     if(i>0){
          if(CheckLabelOp(p->op)==1) printf("[%d]   ",p->label);
          printf("[line %d]",p->line);
           printf("\n");
     }
      
  }
}
 

char *newtmpname(){
 
     char strnum[20];
     char name[]="^";

     sprintf(strnum,"%d",tmpcounter);
  
     char* str1=(char *)malloc(sizeof(strnum)+sizeof(name)+1); 
    if (str1!= NULL) {
         strcpy(str1, name);
         strcat(str1, strnum);

    } else{
        printf ( "malloc() failed in newtmpname!\n");
    } 
  
    printf("%s\n",str1);
    tmpcounter++;
    return str1;
}

void resettmp(){
  tmpcounter=0;
}

int currscope()
{
  return scope;
}

int currline(){
  return yylineno;
}

SymbolTableEntry *newtmp(){
  char *name;
  SymbolTableEntry *sym;
  name=strdup(newtmpname());
  sym=LookUpScope(name,currscope());
  if(sym==NULL){
    return insert( 1,name,currscope(),0);
  }else{
    return sym;
  }

}

unsigned nextquadlabel(){
 return currQuad;
}

expr *function_def(SymbolTableEntry *sym){
   assert(sym);
   if(sym==NULL) {
     printf("sym in function_def is NULL\n ");
     return NULL;
   }
   expr* e=(expr*)malloc(sizeof(expr));
   memset(e,0,sizeof(expr));
   e->next=(expr*)0;
   e->sym=sym;
   e->type=programfunc_e;

   return e;
}

struct Stack { 
    int top; 
    unsigned capacity; 
    int* array; 
}; 
  
// function to create a stack of given capacity. It initializes size of 
// stack as 0 


struct Stack* createStack(unsigned capacity) 
{ 
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack)); 
    stack->capacity = capacity; 
    stack->top = -1; 
    stack->array = (int*)malloc(stack->capacity * sizeof(int)); 
    return stack; 
} 
  

// Stack is full when top is equal to the last index 
int isFull(struct Stack* stack) 
{ 
    return stack->top == stack->capacity - 1; 
} 
  
// Stack is empty when top is equal to -1 
int isEmpty(struct Stack* stack) 
{ 
    return stack->top == -1; 
} 
  
// Function to add an item to stack.  It increases top by 1 
void push(struct Stack* stack,unsigned item) 
{ 
    if (isFull(stack)) 
        return; 
    stack->array[++stack->top] = item; 
 //   printf("%d pushed to stack\n", item); 
} 
  
// Function to remove an item from stack.  It decreases top by 1 
int pop(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top--]; 
} 
  
// Function to return the top from stack without removing it 
int peek(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top]; 
} 



void restorecurrscopeoffset(unsigned n){
  switch (currscopespace())
  {
  case programvar:programVaroffset=n; break;
  case functionlocal:functionLocaloffset=n; break;
  case formalarg :formalArgoffset=n; break;
  
  default:assert(0);
  }
}


expr *lvalue_expr(SymbolTableEntry *sym){
  
   assert(sym);
  
   if(sym==NULL) {
     printf("sym in lvalue_expr is NULL\n ");
     return NULL;
   }

   expr* e=(expr*)malloc(sizeof(expr));
   memset(e,0,sizeof(expr));
   e->next=(expr*)0;
   e->sym=sym;
   
   switch(sym->type){
     case 0:e->type=var_e; break;
     case 1:e->type=var_e; break;
     case 2:e->type=var_e; break;
     case 3:e->type=programfunc_e; break;
     case 4:e->type=libraryfunc_e; break;
   }
   
   return e;
}

expr *newexpr(expr_t t){
   
   expr *e=(expr*)malloc(sizeof(expr));
   if(e==NULL){
     printf("new_expr makes NULL pinter\n");
     return NULL;
   }
   memset(e,0,sizeof(expr));
   e->type=t;
   return e;
}

 expr *newexpr_constring(char* s){
   if(s==NULL){
     printf("newexpr_constring makes NULL pointer\n");
     return NULL;
   }

   expr *e=newexpr(conststring_e);
   if(e!=NULL){
     e->strConst=strdup(s);
     return e;
   }else{
     printf("newexpr_constring makes NULL pointer\n");
     return NULL;
   }

 }

 expr *emit_iftableitem(expr *e){
  if(e==NULL){
    printf("(1)NULL in emit_iftableelem\n");
    return NULL;
  }

  if(e->type!=1){
      printf("SLOGAN MPAMPAS\n");
      return  e;
  }else{
      expr *result=newexpr(var_e);
      if(result==NULL){
          printf("(2)NULL in emit_iftableelem\n");
          return NULL;
      }

      result->sym=newtmp();
      if(result->sym==NULL){
          printf("(3)NULL in emit_iftableelem\n");
          return NULL;
      }

      emit(tablegetelem,result,e,e->index);
      return result;
  }


 }

 expr* member_item (expr* lv, char* name) { 

   if(lv!=NULL && name!=NULL){
    
     lv=emit_iftableitem(lv); 
 
     expr* ti = newexpr(1); // Make a new expression 
     if(ti==NULL){
       printf("(1)NULL,member_item\n");
       return NULL;
     }
     
     ti->sym = lv->sym;
     ti->index = newexpr_constring(name);// Const string index return ti; 
    
     if(newexpr_constring(name)==NULL){
       printf("(2)NULL,member_item\n");
       return NULL;
     }
      return ti;
   }else{
     printf("(3)NULL,member_item\n");
     return NULL;
   }   
}

/*
  arithexpr_e,
  boolexpr_e,
  newtable_e,
  constnum_e,
  constbool_e,
  mil_e
*/


expr *newexpr_num_int(int val){
      expr *e=newexpr(constnum_e);
      if(e!=NULL){
        e->intConst=val;
        e->strConst=strdup("int");
         return e;
      }else{
        printf("newexpr_num_int makes NULL pointer\n");
        return NULL;
     }
 }

 expr *newexpr_num_double(double val){
      expr *e=newexpr(constnum_e);
      if(e!=NULL){
        e->doubleConst=val;
        e->strConst=strdup("double");
         return e;
      }else{
        printf("newexpr_num_double makes NULL pointer\n");
        return NULL;
     }
 }

 expr *newexpr_string(char *val){
      expr *e=newexpr(conststring_e);
      if(e!=NULL){
      
        e->strConst=strdup(val);
         return e;
      }else{
        printf("newexpr_string makes NULL pointer\n");
        return NULL;
     }
 }

int CheckTypeArithmExpr(expr *expr){
  if(strcmp(GetTypeExpr(expr->type),"programfunc_e")==0){
    printf("\033[0;31m");
		printf("Error(%d) [Illegal expr]\n",currline());
    printf("\033[0m");
    return 1;
  }else if(strcmp(GetTypeExpr(expr->type),"libraryfunc_e")==0){
    printf("\033[0;31m");
		printf("Error(%d) [Illegal expr]\n",currline());
    printf("\033[0m");
    return 1;
  }else if(strcmp(GetTypeExpr(expr->type),"boolexpr_e")==0){
    printf("\033[0;31m");
		printf("Error(%d) [Illegal expr]\n",currline());
    printf("\033[0m");
    return 1;
  }else if(strcmp(GetTypeExpr(expr->type),"newtable_e")==0){
    printf("\033[0;31m");
	  printf("Error(%d) [Illegal expr]\n",currline());
    printf("\033[0m");
    return 1;
  }else if(strcmp(GetTypeExpr(expr->type),"constbool_e")==0){
    printf("\033[0;31m");
		printf("Error(%d) [Illegal expr]\n",currline());
    printf("\033[0m");
    return 1;
  }else if(strcmp(GetTypeExpr(expr->type),"conststring_e")==0){
    printf("\033[0;31m");
		printf("Error(%d) [Illegal expr]\n",currline());
    printf("\033[0m");
    return 1;
  }else if(strcmp(GetTypeExpr(expr->type),"nil_e")==0){
    printf("\033[0;31m");
    printf("Error(%d) [Illegal expr]\n",currline());
    printf("\033[0m");
    return 1;
  }else{
    return 0;
  }
}

int BothConstNum(expr *expr1,expr *expr2){
  if(strcmp(GetTypeExpr(expr1->type),"costnum_e")==0&&strcmp(GetTypeExpr(expr2->type),"costnum_e")==0){
    //printf("AHORA MUCHACHOS\n");
    return 1;
  }else{
    return 0;
  }

}

expr *newexpr_bool(unsigned char val){
      expr *e=newexpr(constbool_e);
      if(e!=NULL){
         e->boolConst=val;
         return e;
      }else{
        printf("newexpr_bool makes NULL pointer\n");
        return NULL;
     }
 }

unsigned int istempname (char* s) {
 // printf("DIAMONDS\n");
return *s == '^';
}
unsigned int istempexpr (expr* e) {
return e->sym && istempname(e->sym->name);
}

expr* make_call (expr* lv, expr* reversed_elist) {
  
         expr* func = emit_iftableitem(lv);
         while (reversed_elist) {
            emit(param, NULL,reversed_elist, NULL);
            reversed_elist = reversed_elist->next;
         }
        if(func!=NULL) emit(call,NULL,func,NULL);
        expr* result = newexpr(var_e);
        result->sym = newtmp();
        emit(getretval, result, NULL, NULL);
        return result;
}

expr *ReverseElist(expr *elist){
    if(elist==NULL) return NULL;
    //nitialize three pointers prev as NULL, curr as head and next as NULL.
    expr *next=NULL;
    expr *curr=NULL;
    expr *prev=NULL;
    curr=elist;

    while(curr!=NULL){
      next=curr->next;
      curr->next=prev;
      prev=curr;
      curr=next;
    }

     return prev;
}

void printElist(expr *elist){
     expr  *curr=elist;

    while(curr!=NULL){
     PrintResult(curr);
     curr=curr->next;
    }
}

void printTableindex(indext *elist){
     indext  *curr=elist;
    printf("BAD BUNNY\n");
    while(curr!=NULL){
     PrintResult(curr->index);
     PrintResult(curr->value);
     printf("\n");
     curr=curr->next;
    }
}


int makelist(int i){
  quad *p=quads+i;
  p->label=0;
  return i;
}

int currquad(){
   return currQuad-1;
}

void patchlist (int list, int label) {
    while (list) {
      int next = quads[list].label;
      quads[list].label = label;
      list = next;
    }
}

void patchlabel(int quadNo,int label){
  assert(quadNo<currQuad &&!quads[quadNo].label);
  quads[quadNo].label=label;
}


int mergelist (int l1, int l2) {
  if (!l1)
    return l2;
  else
  if (!l2)
    return l1;
  else {
    int i = l1;
  while (quads[i].label)
    i = quads[i].label;
    quads[i].label = l2;
    return l1;
  }
}

expr  *TmpRec(expr *$$,expr *$1,expr *$3){
      if(istempexpr($1)){
                           $$->sym=$1->sym;
      }else if(istempexpr($3)){
                           $$->sym=$3->sym;
      }else{
                           $$->sym=newtmp();
      }

      return $$;
}


int loopcntr(){
  return loopcounter;
}


stmt_t *make_stmt ( )
{ 
  stmt_t *ptr=(stmt_t*)malloc(sizeof(stmt_t));
  ptr->breakList=ptr->returnList=ptr->contList=0;
  return ptr;
}

int newlist (int i)
{ quads[i].label = 0; return i; }

void Printpatchlist (int list) {
    while (list) {
      printf("MAGIC:%d",list);
      int next = quads[list].label;
      list = next;
    }
}