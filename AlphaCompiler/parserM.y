%{

#include "P3M.h"

int yyerror (char* yaccProvidedMessage);
int yylex(void);

	extern char* yytext;
	extern FILE* yyin;
	extern FILE* yyout;

int pnum=0;
int namef=0;
int FlagScopeFormal=0;
char *IDV;
int flagMemberLvalue=0;
int lock1=0;
int lock2=0;
struct Stack *scopeoffsetstack; 
struct Stack *loopcounterstack; 
int funcounter=0;
int lockA=1;
int lock=1;
expr *ptrEx=NULL;
expr *ptrElist=NULL;
int flagElist;
expr *TableforlistHead[1000];
int elistptr=-1;
quad *ptrQ=NULL;
%}

%start program

%token IF_ST
%token ELSE_ST
%token FOR_ST
%token WHILE_ST
%token AND_ST
%token NOT_ST
%token OR_ST
%token LOCAL_ST
%token CONTINUE_ST
%token BREAK_ST
%token TRUE_ST
%token FALSE_ST
%token NIL_ST
%token FUNC_ST
%token RETURN_ST

%token PLUS_OP
%token MINUS_OP
%token EQUAL_OP
%token MULTI_OP
%token DIVISION_OP
%token PERCENT_OP
%token INCREMENT_OP
%token DICREMENT_OP

%token COMP_EQUAL_OP
%token COMP_NOT_EQUAL_OP
%token COMP_BIGGER_OP
%token COMP_LESS_OP
%token COMP_BIGGER_EQUAL_OP
%token COMP_LESS_EQUAL_OP






%token LEFT_CBRACKET
%token RIGHT_CBRACKET
%token LEFT_PARENTHESIS
%token RIGHT_PARENTHESIS
%token SEMICOLON
%token COMMA
%token COLON
%token DOUBLE_COLON
%token FULL_STOP
%token RANGE
%token LEFT_ARRAY
%token RIGHT_ARRAY

%token<strVal> ID
%token<doubleVal> NUMBER_REAL
%token<intVal> NUMBER_INT
%token<strVal> STRING

%token COMMENT
%token COMMENT1

%token SPACE

%token OTHER
%token OTHER2
%token OTHER3
%token OTHER4

%union{
int intVal;
double doubleVal;
char*  strVal;
struct  SymbolTableEntry *sym;
struct expr *expr;
unsigned un;
struct call *callx;
struct forpr *forpre;
struct stmt_t *stmt_t;
struct indext *indext;
}

%right EQUAL_OP
%left OR_ST  
%left AND_ST
%nonassoc COMP_EQUAL_OP COMP_NOT_EQUAL_OP
%nonassoc COMP_BIGGER_OP COMP_LESS_OP COMP_BIGGER_EQUAL_OP COMP_LESS_EQUAL_OP
%left  PLUS_OP MINUS_OP
%left  MULTI_OP DIVISION_OP PERCENT_OP
%right INCREMENT_OP DICREMENT_OP UMINUS NOT_ST
%left  FULL_STOP    RANGE
%left  LEFT_ARRAY  RIGHT_ARRAY
%left  LEFT_PARENTHESIS  RIGHT_PARENTHESIS

%type <expr> lvalue
%type <strVal> funcname
%type <sym> funcprefix
%type <sym> funcdef
%type <un> funcbody
%type <expr> member
%type <expr> primary
%type <expr> assignexpr
%type <expr> call
%type <expr> term
%type <expr> objectdef
%type <expr> const
%type <expr> tableitem
%type <expr> expr
%type <expr> elist
%type <callx> callsuffix
%type <callx> normcall
%type <callx> methodcall
%type <intVal> ifprefix
%type <intVal> elseprefix
%type <expr> ifstmt1
%type <expr> ifstmt2
%type <intVal> whilestart
%type <intVal> whilecond
%type <intVal> M
%type <intVal> N
%type <forpre> forprefix
%type <stmt_t> stmt
%type <stmt_t> loopstmt
%type <stmt_t> stmts
%type <stmt_t> block
%type <stmt_t>  returnstmt
%type <indext> indexedelems
%type <indext>  indexedelem
%type <indext>  indexed




%%

program: stmts stmt {
       
        printf("(%d)(program->stmts stmt)\n",++pnum);}
	    | {
        
        printf("(%d)(program->   )\n",++pnum);}
	    ;
	
stmts :stmts stmt{
          if($1==NULL&&$2!=NULL){
              $$=$2;
          }else if($1!=NULL&&$2!=NULL){
              $$=make_stmt( );
              $$->returnList= mergelist($1->returnList, $2->returnList);
              $$->breakList = mergelist($1->breakList, $2->breakList);
              $$->contList = mergelist($1->contList,$2->contList); 
          }else{

          }
          printf("(%d)(stmts->stmts stmt)\n",++pnum);}
       | {$$=NULL; printf("(%d)(stmts->    )\n",++pnum);}
       ;


stmt : expr SEMICOLON { 
        

            if(lock==0) Merikh_Assign($expr);
            lock=1;
            resettmp(); $stmt=NULL;  printf("(%d)(stmt->expr;)\n",++pnum);}
       |ifstmt1 { resettmp(); $stmt=NULL;    printf("(%d)(stmt->ifstmt1\n)",++pnum);}    
       |ifstmt2 { resettmp();  $stmt=NULL;   printf("(%d)(stmt->ifstmt2\n)",++pnum);}   
       |whilestmt { resettmp();  $stmt=NULL;  printf("(%d)(stmt->whilestmt\n,++pnum)");}
       |forstmt   { resettmp();  $stmt=NULL;  printf("(%d)(stmt->forstmt)\n",++pnum);}
       |returnstmt { resettmp();  $stmt=$returnstmt; printf("(%d)(stmt->returnstmt)\n",++pnum);}
      
       |BREAK_ST SEMICOLON {
          
          resettmp();

          if(loopcntr()>0){
             $stmt=make_stmt( );
             $stmt->breakList=newlist(nextquadlabel());
             emit(jump,NULL,NULL,NULL);
          }else{
             printf("\033[0;31m");
		       printf("Error(%d)	[Break not in loop] \n",yylineno); 
		       printf("\033[0m");
             $stmt=NULL;
          }
          
        //  printf("break:%d,%d",loopcntr(),yylineno);
          printf("(%d)(stmt->break;)\n",++pnum);}
       
       |CONTINUE_ST SEMICOLON {

          resettmp();

          if(loopcntr()>0){
             $stmt=make_stmt( );
             $stmt->contList=newlist(nextquadlabel());
             emit(jump,NULL,NULL,NULL);
          }else{
             printf("\033[0;31m");
		       printf("Error(%d)	[Continue not in loop] \n",yylineno); 
		       printf("\033[0m");
             $stmt=NULL;
          }
        
          //printf("continue:%d,%d",loopcntr(),yylineno);
          printf("(%d)(stmt->continue;)\n",++pnum);}
       |block {
          resettmp();
          $stmt=$block;
          printf("(%d)(stmt->block)\n",++pnum);}
       |funcdef { resettmp();   printf("(%d)(stmt->funcdef)\n",++pnum);  $stmt=NULL;}
       |SEMICOLON { resettmp(); printf("(%d)(stmt->;)\n",++pnum);  $stmt=NULL;}
       ;
expr	:assignexpr 
       {
          $expr=$assignexpr;
          printf("(%d)(expr->assignexpr)\n",++pnum );}
	    |expr PLUS_OP expr {
            if($1!=NULL&&$3!=NULL){
                if(CheckTypeArithmExpr($1)==0&&CheckTypeArithmExpr($3)==0){
                    if(BothConstNum($1,$3)==1)  $$ = newexpr(constnum_e);
                    else                        $$ = newexpr(arithexpr_e);
                
                    if($$!=NULL){
                        $$=TmpRec($$,$1,$3);
                    } 
                    emit(add, $$, $1, $3);
                }else{
                        $$=NULL;
                        printf("expr+expr,[$1 or $3 is not arithmetic,or both]\n");
                }
            }else{
                 $$=NULL;
                 printf("expr+expr,[$1 or $3 is NULL,or both]\n");
            }
          printf("(%d)(expr->expr+expr)\n",++pnum );}
	    |expr MINUS_OP expr {
            if($1!=NULL&&$3!=NULL){
                if(CheckTypeArithmExpr($1)==0&&CheckTypeArithmExpr($3)==0){
                    if(BothConstNum($1,$3)==1)  $$ = newexpr(constnum_e);
                    else                        $$ = newexpr(arithexpr_e);
                
                    if($$!=NULL){
                        $$=TmpRec($$,$1,$3);
                    } 
                    emit(sub, $$, $1, $3);
                }else{
                        $$=NULL;
                        printf("expr-expr,[$1 or $3 is not arithmetic,or both]\n");
                }
            }else{
                 $$=NULL;
                 printf("expr-expr,[$1 or $3 is NULL,or both]\n");
            }
          printf("(%d)(expr->expr-expr)\n",++pnum);}
	    |expr MULTI_OP expr {
            if($1!=NULL&&$3!=NULL){
                if(CheckTypeArithmExpr($1)==0&&CheckTypeArithmExpr($3)==0){
                    if(BothConstNum($1,$3)==1)  $$ = newexpr(constnum_e);
                    else                        $$ = newexpr(arithexpr_e);
                
                    if($$!=NULL){
                        $$=TmpRec($$,$1,$3);
                    } 
                    emit(mult, $$, $1, $3);
                }else{
                        $$=NULL;
                        printf("expr * expr,[$1 or $3 is not arithmetic,or both]\n");
                }
            }else{
                 $$=NULL;
                 printf("expr*expr,[$1 or $3 is NULL,or both]\n");
            }
        
          printf("(%d)(expr->expr*expr)\n",++pnum);}
	    |expr DIVISION_OP expr {
              if($1!=NULL&&$3!=NULL){
                if(CheckTypeArithmExpr($1)==0&&CheckTypeArithmExpr($3)==0){
                    if(BothConstNum($1,$3)==1)  $$ = newexpr(constnum_e);
                    else                        $$ = newexpr(arithexpr_e);
                
                    if($$!=NULL){
                        $$=TmpRec($$,$1,$3);
                    } 
                    emit(divid, $$, $1, $3);
                }else{
                        $$=NULL;
                        printf("expr / expr,[$1 or $3 is not arithmetic,or both]\n");
                }
            }else{
                 $$=NULL;
                 printf("expr/expr,[$1 or $3 is NULL,or both]\n");
            }

          printf("(%d)expr->(expr/expr)\n",++pnum);}
	    |expr PERCENT_OP expr {
           if($1!=NULL&&$3!=NULL){
                if(CheckTypeArithmExpr($1)==0&&CheckTypeArithmExpr($3)==0){
                    if(BothConstNum($1,$3)==1)  $$ = newexpr(constnum_e);
                    else                        $$ = newexpr(arithexpr_e);
                
                    if($$!=NULL){
                        $$=TmpRec($$,$1,$3);
                    } 
                    emit(modul, $$, $1, $3);
                }else{
                        $$=NULL;
                        printf("expr % expr,[$1 or $3 is not arithmetic,or both]\n");
                }
            }else{
                 $$=NULL;
                 printf("expr % expr,[$1 or $3 is NULL,or both]\n");
            }
          printf("(%d)(expr->expr mod expr)\n",++pnum);}
	    |expr COMP_BIGGER_OP expr {
            if($1!=NULL&&$3!=NULL){
                lock=0;
                lockA=0;
               $$=newexpr(boolexpr_e);
               if($$!=NULL){
                   $$=TmpRec($$,$1,$3);
               }
               emit(if_greater,NULL,$1,$3);
               $$->trueList=currquad();
               emit(jump,NULL,NULL,NULL);
               $$->falseList=currquad();
               //Merikh_Assign($$);
            }else{
                 $$=NULL;
                 printf("NULL\n");
            }
          printf("(%d)(expr->expr>expr)\n",++pnum);}
	    |expr COMP_BIGGER_EQUAL_OP expr {
            if($1!=NULL&&$3!=NULL){
                lock=0;
                lockA=0;
               $$=newexpr(boolexpr_e);
               if($$!=NULL){
                  $$=TmpRec($$,$1,$3);
               }
               
               emit(if_greatereq,NULL,$1,$3);
               $$->trueList=currquad();
               emit(jump,NULL,NULL,NULL);
               $$->falseList=currquad();
             //  Merikh_Assign($$);

            }else{
                 $$=NULL;
                 printf("NULL\n");
            }
           
          printf("(%d)(expr->expr>=expr)\n",++pnum);}
	    |expr COMP_LESS_OP expr {
            if($1!=NULL&&$3!=NULL){
                lock=0;
                lockA=0;
               $$=newexpr(boolexpr_e);
               if($$!=NULL){
                   $$=TmpRec($$,$1,$3);
               }

               emit(if_less,NULL,$1,$3);
               $$->trueList=currquad();
               emit(jump,NULL,NULL,NULL);
               $$->falseList=currquad();
               //Merikh_Assign($$);
            }else{
                 $$=NULL;
                 printf("NULL\n");
            }
           
          printf("(%d)(expr->expr<expr)\n",++pnum);}
    	 |expr COMP_LESS_EQUAL_OP expr {
            if($1!=NULL&&$3!=NULL){
               lock=0;
               lockA=0;
               $$=newexpr(boolexpr_e);
               if($$!=NULL){
                   $$=TmpRec($$,$1,$3);
               }
               
               emit(if_lesseq,NULL,$1,$3);
               $$->trueList=currquad();
               emit(jump,NULL,NULL,NULL);
               $$->falseList=currquad();
              //Merikh_Assign($$);
            }else{
                 $$=NULL;
                 printf("NULL\n");
            }
           printf("(%d)(expr->expr<=expr)\n",++pnum);}
     	 |expr COMP_EQUAL_OP expr {
           if($1!=NULL&&$3!=NULL){
               lock=0;
               lockA=0;
               $$=newexpr(boolexpr_e);
               if($$!=NULL){
                   $$=TmpRec($$,$1,$3);
               }
              
              
               if($1->type==5 && $3->type!=5){
                   Merikh_Assign($1);
               }else if($3->type==5 && $1->type!=5){
                    Merikh_Assign($3);
               }else if($3->type==5 && $1->type==5){
                    Merikh_Assign($1);
                    Merikh_Assign($3);
               }else{

               } 

               emit(if_eq,NULL,$1,$3);
               $$->trueList=currquad();
               emit(jump,NULL,NULL,NULL);
               $$->falseList=currquad();
               

            }else{
                 $$=NULL;
                 printf("NULL\n");
            }
            printf("(%d)(expr->expr==expr)\n",++pnum);}
    	 |expr COMP_NOT_EQUAL_OP expr {
          if($1!=NULL&&$3!=NULL){
               lock=0;
               lockA=0;
               $$=newexpr(boolexpr_e);
               if($$!=NULL){
                   $$=TmpRec($$,$1,$3);
               }

               if($1->type==5 && $3->type!=5){
                   Merikh_Assign($1);
               }else if($3->type==5 && $1->type!=5){
                    Merikh_Assign($3);
               }else if($3->type==5 && $1->type==5){
                    Merikh_Assign($1);
                    Merikh_Assign($3);
               }else{

               } 

               emit(if_noteq,NULL,$1,$3);
               $$->trueList=currquad();
               emit(jump,NULL,NULL,NULL);
               $$->falseList=currquad();
              
            }else{
                 $$=NULL;
                 printf("NULL\n");
            }
         printf("(%d)(expr->expr!=expr)\n",++pnum);}
    	 |expr AND_ST M expr {
             lockA=0;
             lock=0;
            if($1!=NULL&&$4!=NULL){
               int flg2;
               int flg1;
               $$=newexpr(boolexpr_e);
               if($$!=NULL){
                   $$=TmpRec($$,$1,$4);
               }   
           
              if($1->type!=5){
                  emit(if_eq,$1,newexpr_bool(1),NULL);
                  $1->trueList=currquad();            
                  emit(jump,NULL,NULL,NULL);
                  patchlist($1->trueList,currquad()+1);
                  $1->falseList=currquad();               
                  flg1=1;
              }else{
                  flg1=0;
              }

              if($4->type!=5){
                  emit(if_eq,$4,newexpr_bool(1),NULL);
                  $4->trueList=currquad();
                  emit(jump,NULL,NULL,NULL);
                  $4->falseList=currquad();
                  flg2=1;
              }else{   
                  flg2=0;           
              }

              if(flg1==1&&flg2==1){
                    $$->trueList=$4->trueList;
              }else if(flg1==1&&flg2==0){
                    patchlist($4->trueList,currquad()-1);
                    $$->trueList=$1->trueList;
              }else if(flg1==0&&flg2==1){
                    patchlist($1->trueList,currquad()-1);
                    $$->trueList=$4->trueList;
              }else{
                   quads[$1->trueList].label=$1->trueList+2;
                   $$->trueList=$4->trueList;
              }
               
               

               $$->falseList=mergelist($1->falseList,$4->falseList);
            
            }else{
                 $$=NULL;
                 printf("expr->expr and expr,[$1 or $2 or both are NULL]\n");
            }
           printf("(%d)(expr->expr and expr)\n",++pnum);}
    	 |expr OR_ST  M expr {
            if($1!=NULL&&$4!=NULL){
               lockA=0;
               lock=0;
               int flg2;
               int flg1;
               $$=newexpr(boolexpr_e);
               if($$!=NULL){
                   $$=TmpRec($$,$1,$4);
               }   
           
              if($1->type!=5){
                  emit(if_eq,$1,newexpr_bool(1),NULL);
                  $1->trueList=currquad();            
                  emit(jump,NULL,NULL,NULL);
                  $1->falseList=currquad();
                  patchlist($1->falseList,currquad()+1);
                  flg1=1;
              }else{
                  flg1=0;
              }

              if($4->type!=5){
                  emit(if_eq,$4,newexpr_bool(1),NULL);
                  $4->trueList=currquad();
                  emit(jump,NULL,NULL,NULL);
                  $4->falseList=currquad();
                  flg2=1;
              }else{   
                  flg2=0;           
              }

              if(flg1==1&&flg2==1){
                    $$->falseList=$4->falseList;
              }else if(flg1==1&&flg2==0){
                    patchlist($4->falseList,currquad()-1);
                    $$->falseList=$1->falseList;
              }else if(flg1==0&&flg2==1){
                    patchlist($1->falseList,currquad()-1);
                    $$->falseList=$4->falseList;
              }else{
                  // quads[$1->falseList].label=$1->falseList+1;
                   int lbl=FindLabelLast ($1->falseList);
                   patchlist($1->falseList,lbl+1);
                   $$->falseList=$4->falseList;
              }
               
               

               $$->trueList=mergelist($1->trueList,$4->trueList);
            
             
            }else{
                 $$=NULL;
                 printf("NULL\n");
            }
           printf("(%d)(expr->expr or expr)\n",++pnum);}
	    |term {
            $expr=$term;
            printf("(%d)(expr->term)\n",++pnum);}
	    ;

term:  LEFT_PARENTHESIS expr RIGHT_PARENTHESIS{
        $term=$2;
        printf("(%d)( term->(expr) )\n",++pnum);}
      
       | MINUS_OP expr %prec UMINUS  {
         if($2!=NULL && CheckTypeArithmExpr($2)==0){
              $term = newexpr(arithexpr_e);
              $term->sym =  istempexpr($expr) ? $expr->sym : newtmp();
              emit(uminus, $term,$2, NULL);
         }else{
              $term=NULL;
               printf("term-> -expr,[$2 is not arithmetic,or is  NULL]\n");
         }
          
          printf("(%d)(term-> -expr UMINUS)\n",++pnum);}
       | NOT_ST expr	{
           if($expr!=NULL){
                lockA=0;
                lock=0;
                $$=newexpr(boolexpr_e);
                if($$!=NULL){
                           if(istempexpr($expr)){
                                $$->sym=$expr->sym;
                           }else{
                                $$->sym=newtmp();
                           }
               }   

              
               int var1,var2;
               if($expr->type!=5)
               {
                     emit(if_eq,NULL,$expr,newexpr_bool(1));
                     $expr->trueList=currquad();
                     emit(jump,NULL,NULL,NULL);
                     $expr->falseList=currquad();
                     var1=$expr->falseList;
                     var2=$expr->trueList; 
                     $$->trueList=var1;
                     $$->falseList=var2; 
                    
                     // printf("AAAAAXXXX:T%d,F:%d", $$->trueList, $$->falseList);
               }else{
                     var1=$expr->falseList;
                     var2=$expr->trueList; 
                     $$->trueList=var1;
                     $$->falseList=var2; 
               }
                     
                  
           }else{
               printf("term->!expr,[$expr is NULL]\n");
           }
           printf("(%d)(term->!expr)\n",++pnum);}
    
       | INCREMENT_OP lvalue  { 
         if(IsFunction(scope,$lvalue->sym->name,yylineno)==1){
          printf("\033[0;31m");
			 printf("Error(%d)	[Variable] (function name with  operator) \"++%s\"\n",yylineno,$2); 
			 printf("\033[0m");
          $term=NULL;
         }else{
             if(CheckTypeArithmExpr($lvalue)==0&&$lvalue!=NULL){
                
                 if((strcmp("tableitem_e",GetTypeExpr($lvalue->type))==0)){
                         $term = emit_iftableitem($lvalue);
                         emit(add,$term,$term, newexpr_num_int(1));
                         emit(tablesetelem,$lvalue,$lvalue->index,$term);
                 }else{
                         emit(add,$lvalue,$lvalue,newexpr_num_int(1));
                         $term=newexpr(arithexpr_e);
                         $term->sym = newtmp();
                         emit(assign, $term,$lvalue,NULL);
                 }
              }else{
                 $term=NULL;
                 printf("term-> ++lvalue,[$2 is not arithmetic or is NULL]\n");
              }

         }
      
         printf("(%d)(term-> ++lvalue)\n",++pnum);}
   
       | lvalue INCREMENT_OP  {
         if(IsFunction(scope,$lvalue->sym->name,yylineno)==1){
          printf("\033[0;31m");
			 printf("Error(%d)	[Variable] (function name with operator) \"%s++\"\n",yylineno,$1); 
			 printf("\033[0m");
          $term=NULL;
         }else{
                 if(CheckTypeArithmExpr($lvalue)==0&&$lvalue!=NULL){
                 $term=newexpr(var_e);
                 $term->sym=newtmp();

                 if((strcmp("tableitem_e",GetTypeExpr($lvalue->type))==0)){
                        expr* val = emit_iftableitem($lvalue);
                        emit(assign, $term,val, NULL);
                        emit(add,val,val,newexpr_num_int(1));
                        emit(tablesetelem,$lvalue, $lvalue->index,val);
                 }else{
                         emit(assign,$term,$lvalue,NULL);
                         emit(add,$lvalue,$lvalue,newexpr_num_int(1));
                 }
                

              }else{
                 $term=NULL;
                 printf("term-> lvalue++,[$1  is NULL,or not arithmetic]\n");
              }
         }


 
         printf("(%d)(term-> lvalue++)\n",++pnum);}
   
      | DICREMENT_OP lvalue  {
        if(IsFunction(scope,$lvalue->sym->name,yylineno)==1){
          printf("\033[0;31m");
			 printf("Error(%d)	[Variable] (function name with operator) \"--%s\"\n",yylineno,$2); 
			 printf("\033[0m");
          $term=NULL;
        }else{
               if(CheckTypeArithmExpr($lvalue)==0&&$lvalue!=NULL){
                
                 if((strcmp("tableitem_e",GetTypeExpr($lvalue->type))==0)){
                         $term = emit_iftableitem($lvalue);
                         emit(sub,$term,$term, newexpr_num_int(1));
                         emit(tablesetelem,$lvalue,$lvalue->index,$term);
                 }else{
                         emit(sub,$lvalue,$lvalue,newexpr_num_int(1));
                         $term=newexpr(arithexpr_e);
                         $term->sym = newtmp();
                         emit(assign, $term,$lvalue,NULL);
                 }
              }else{
                 $term=NULL;
                 printf("term-> --lvalue,[$2 is not arithmetic or is NULL]\n");
              }
         }
        printf("(%d)(term-> --lvalue)\n",++pnum);}
    
      | lvalue DICREMENT_OP {
       if(IsFunction(scope,$lvalue->sym->name,yylineno)==1){
          printf("\033[0;31m");
			 printf("Error(%d)	[Variable] (function name with operator) \"%s--\"\n",yylineno,$1); 
			 printf("\033[0m");
          $term=NULL;
       }else{
            if(CheckTypeArithmExpr($lvalue)==0&&$lvalue!=NULL){
                 $term=newexpr(var_e);
                 $term->sym=newtmp();

                 if((strcmp("tableitem_e",GetTypeExpr($lvalue->type))==0)){
                        expr* val = emit_iftableitem($lvalue);
                        emit(assign, $term,val, NULL);
                        emit(sub,val,val,newexpr_num_int(1));
                        emit(tablesetelem,$lvalue, $lvalue->index,val);
                 }else{
                         emit(assign,$term,$lvalue,NULL);
                         emit(sub,$lvalue,$lvalue,newexpr_num_int(1));
                 }
                

            }else{
                 $term=NULL;
                 printf("term-> lvalue--,[$1  is NULL,or not arithmetic]\n");
                 printf("error\n");
            }
         }
         printf("(%d)(term-> lvalue--)\n",++pnum);}

      | primary  {
        $term=$primary;
        printf("(%d)(term->primary)\n",++pnum);}
      ;

assignexpr:lvalue EQUAL_OP expr{
  
    //newtmp();
    if($lvalue!=NULL){
      if($lvalue->sym->name!=NULL){
      
      if(IsFunction(scope,$lvalue->sym->name,yylineno)==1&&lock1!=1&&lock2!=1) {
          printf("\033[0;31m");
			    printf("Error(%d)	[Variable] (Assignation to function:%s)\n",yylineno,$1); 
			    printf("\033[0m");  
      }

      if(IsFunctionLocal(scope,$lvalue->sym->name,yylineno)==1&&lock1==1&&lock2!=1){
          printf("\033[0;31m");
			    printf("Error(%d)	[Variable] (Assignation(local) to function:%s)\n",yylineno,$1); 
			    printf("\033[0m"); 
      }

      if(IsFunctionLocal(0,$lvalue->sym->name,yylineno)==1&&lock2==1&&lock1!=1){
          printf("\033[0;31m");
			    printf("Error(%d)	[Variable] (Assignation(local) to function:%s)\n",yylineno,$1); 
			    printf("\033[0m"); 
      }

     }
  
      if($expr!=NULL){
            if($3->trueList!=0&&$3->falseList!=0&&lockA==0){
                Merikh_Assign($3);
                lock=1;
            }

            lockA=0;

            if($lvalue->type==1){
             
                emit(tablesetelem,$lvalue,$lvalue->index,$expr);

                 $assignexpr = emit_iftableitem ($lvalue); 
                 if($assignexpr!=NULL){
                     $assignexpr->type = assignexpr_e;
                 }else{
                     printf("[$assignexpr is NULL]\n");
                     $assignexpr=NULL;
                 }
            }else{
              
                emit(assign,$lvalue,$expr,(expr*)0);
                $assignexpr=newexpr(assignexpr_e);
                if($assignexpr!=NULL){
                    $assignexpr->sym=newtmp();
                    emit(assign, $assignexpr,$lvalue,(expr*)0);
                }else{
                    printf("[$assignexpr is NULL]\n");
                    $assignexpr=NULL;
                }
            }
      }else{
              $assignexpr=NULL;
              printf("assignexpr:lvalue EQUAL_OP expr,[$expr is NULL]\n");
      }

    }else{
              $assignexpr=NULL;
              printf("assignexpr:lvalue EQUAL_OP expr,[$lvalue is NULL]\n");
    }
   
  
            lock1=0;
            lock2=0;
            printf("(%d)(assignexpr->lvalue=expr)\n",++pnum);}
    
	;

primary: lvalue {
         $primary = emit_iftableitem($lvalue);
         printf("(%d)(primary->lvalue)\n",++pnum);}
		| call  {
         $primary=$call;
         printf("(%d)(primary->call)\n",++pnum);}
		| objectdef {
         $primary=$objectdef;
         printf("(%d)(primary->objectdef)\n",++pnum);}
		| LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS {
         $primary = newexpr(programfunc_e);
         $primary->sym = $funcdef;
         printf("(%d)(primary->(funcdef) )\n",++pnum);}
		| const	{
         $primary=$const;
         printf("(%d)(primary->const)\n",++pnum);}
		;

lvalue:	ID {SymbolTableEntry *sym=LookUpVariable(scope,$1,yylineno);
        
         if(sym!=NULL){
            $lvalue=lvalue_expr(sym);
         }else{
            $lvalue=NULL;
            printf("LookUpVariable returns NULL\n");
         }
          printf("(%d)(lvalue->ID:%s)\n",++pnum,$1);  
         
      }
		| LOCAL_ST ID {SymbolTableEntry *sym=LookUpLocal($2,scope,yylineno);
        if(sym!=NULL){
           $lvalue=lvalue_expr(sym);
        }else{
           $lvalue=NULL;
           printf("LookUpLocal returns NULL\n");
        }
       
        lock1=1;
		  printf("(%d)(lvalue->local ID)\n",++pnum);}
		| DOUBLE_COLON ID {SymbolTableEntry *sym=LookUpGlobal($2,yylineno);
        if(sym!=NULL){
           $lvalue=lvalue_expr(sym);
        }else{
           $lvalue=NULL;
           printf("LookUpGlobal returns NULL\n");
        }

        lock2=1;
        printf("(%d)(lvalue->:: ID)\n",++pnum);}
		| member{
        printf("(%d)(lvalue->member)\n",++pnum);}
		;


lvalue: tableitem {
        
          $lvalue= $tableitem;
         
          printf("(%d)(lvalue->tableitem)\n",++pnum);
          }
          ;
tableitem :lvalue FULL_STOP ID{
         
           $tableitem = member_item($lvalue, $ID);         

           printf("(%d)(tableitem->lvalue.ID)\n",++pnum);
         }
         ;

tableitem:lvalue LEFT_ARRAY expr RIGHT_ARRAY{
            if($lvalue!=NULL){
                $lvalue = emit_iftableitem($lvalue);
                $tableitem = newexpr(tableitem_e); 
                if( $tableitem!=NULL && $expr!=NULL){
                 $tableitem->sym = $lvalue->sym;
                 $tableitem->index = $expr;
                }else{
                  printf("$tableitem is NULL \n");
                }
                
            }else{
              printf("member->lvalue[expr],[$lvalue is NULL]\n");
            }

            printf("(%d)(member->lvalue[expr])\n",++pnum);
          }
          ;



member://lvalue FULL_STOP ID {
       // flagMemberLvalue=1;
      //  printf("(%d)(member->lvalue.ID)\n",++pnum);}
	  //lvalue LEFT_ARRAY expr RIGHT_ARRAY {printf("(%d)(member->lvalue[expr])\n",++pnum);}
     call FULL_STOP ID	{printf("(%d)(member->call.ID)\n",++pnum);}
      	  | call LEFT_ARRAY expr RIGHT_ARRAY 	{printf("(%d)(member->call[expr])\n",++pnum);}
          ;

call : call LEFT_PARENTHESIS elist RIGHT_PARENTHESIS {
       $$=make_call($1,ReverseElist($elist));
       printf("(%d)(call->call(elist) )\n",++pnum);}
	 | lvalue callsuffix	{

       $lvalue = emit_iftableitem($lvalue);
       if($callsuffix!=NULL){
            if ($callsuffix->method ){
               expr* t = $lvalue;
               $lvalue = emit_iftableitem(member_item(t, $callsuffix->name));
               if($callsuffix->elist!=NULL)  t->next=$callsuffix->elist;
               $callsuffix->elist= t; 
            }
               $$ = make_call($lvalue,ReverseElist($callsuffix->elist));
       }else{
               printf("Error.callsuffix is NULL in call:call(elist)\n");
               $$=NULL;
       }
       printf("(%d)(call->lvalue callsuffix)\n",++pnum);}

	 | LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS LEFT_PARENTHESIS elist RIGHT_PARENTHESIS {
       expr* func = newexpr(programfunc_e);
       if($funcdef!=NULL)   func->sym = $funcdef;
       $call = make_call(func,ReverseElist($elist));
       printf("(%d)(call->(funcdef)(elist) )\n",++pnum);}
	 ;

callsuffix: normcall {$callsuffix=$normcall; printf("(%d)(callsuffix->normcall)\n",++pnum);}
	 | methodcall    {$callsuffix=$methodcall; printf("(%d)(callsuffix->methodcall)\n",++pnum);}
	 ;

normcall:LEFT_PARENTHESIS elist RIGHT_PARENTHESIS {
         callx *ptrX=(callx*)malloc(sizeof(callx));
         if(ptrX!=NULL){
            ptrX->elist = $elist;
            ptrX->method = 0;
            ptrX->name = NULL;
            $normcall=ptrX;
         }else{
            printf("ptrX is NULL in normcall:(elist)\n");
            $normcall=NULL;
         }
         printf("(%d)(normcall->(elist) )\n",++pnum);}
         ;

methodcall: RANGE ID LEFT_PARENTHESIS elist RIGHT_PARENTHESIS {
            callx *ptrX=(callx*)malloc(sizeof(callx));
            if(ptrX!=NULL){
                  ptrX->elist = $elist;
                  ptrX->method = 1;
                  ptrX->name = strdup($ID);
                  $methodcall=ptrX;
            }else{
                  printf("ptrX is NULL in normcall:(elist)\n");
                  $methodcall=NULL;
            }
            printf("(%d)(methodcall->..id(elist) )\n",++pnum);}
            ;
elist:expr{

                if($1->trueList!=0&&$1->falseList!=0){
                 Merikh_Assign($1);
                 lockA=1;
                 lock=1;
               }

               flagElist=0;
               elistptr++;
               if($expr!=NULL){                 
                  TableforlistHead[elistptr]=$expr;
                  $expr->next=NULL;
               }else{
                  printf("$expr is NULL in elist:expr \n");
                  flagElist=1;
               } 
      }exprs{
               if(flagElist==0){ $elist=TableforlistHead[elistptr];
               }else { $elist=NULL;}
            
                   elistptr--;

               printf("(%d)(elist->expr exprs)\n",++pnum);}
	   |{       $elist=NULL;  printf("(%d)(elist->  )\n",++pnum);}
	   ;
	 
exprs:COMMA expr {
       if(flagElist==0)
       {       
               if($2->trueList!=0&&$2->falseList!=0){
                 Merikh_Assign($2);
                 lockA=1;
                 lock=1;
               }
               ptrElist=TableforlistHead[elistptr];
               while(ptrElist->next!=NULL){
                   ptrElist=ptrElist->next;
               }
         
               if($expr!=NULL){
                   ptrElist->next=$expr;
                   $expr->next=NULL;
               }else{
                   flagElist=1;
               }
       }
         
      } exprs {printf("(%d)(exprs->COMMA expr epxrs) \n",++pnum); }
	   |  {printf("(%d)(exprs->   )\n",++pnum);}
	   ;

objectdef:LEFT_ARRAY elist RIGHT_ARRAY {
           
            printElist($elist);
            expr *t=newexpr(newtable_e);
            t->sym=newtmp();
            emit(tablecreate,t,NULL,NULL);
            int i=0;
            expr *curr=$elist;
            while(curr!=NULL){
               emit(tablesetelem,t,newexpr_num_int(i),curr);
               i++;
               curr=curr->next;
            }
            $objectdef=t;
            printf("(%d)(objectdef->[elist])\n",++pnum);}
         |LEFT_ARRAY indexed RIGHT_ARRAY {
            expr *t=newexpr(newtable_e);
            t->sym=newtmp();
            emit(tablecreate,t,NULL,NULL);
            indext *curr=$indexed;
            while(curr!=NULL){
               emit(tablesetelem,t,curr->index,curr->value);
               curr=curr->next;
            }
            $objectdef=t;
            printf("(%d)(objectdef->[indexed])\n",++pnum);}
	       ;
indexed:indexedelem indexedelems {
             printf("OZUNA\n");
            $1->next=$2;
             printf("FARR\n");
            $$=$1;
             printf("J BALVIN\n");
           
            printTableindex($$);
            printf("(%d)(indexed->indexedelem indexedelems)\n",++pnum);}
         ;  
         
 	   
		
indexedelems	: COMMA indexedelem indexedelems	{
               $2->next=$3;
               $$=$2;
               
               printf("(%d)(indexedelems-> ,indexedelem indexedelems)\n",++pnum);}
				|	{ $$=NULL; printf("(%d)(indexedelems->  )\n",++pnum);}
				;	

indexedelem :LEFT_CBRACKET expr COLON expr RIGHT_CBRACKET {
               indext *ptr=(indext *)malloc(sizeof(indext));
               ptr->index=$2;
               ptr->value=$4;
               $$=ptr;
               printf("(%d)(indexedelem ->{ expr : expr })\n",++pnum);}
             ;
block:LEFT_CBRACKET { ++scope;}  stmts RIGHT_CBRACKET {Hide(scope--); $block=$stmts; printf("(%d)(block->{stmts})\n",++pnum);}
     ;

funcblockstart: { push(loopcounterstack, loopcounter); loopcounter=0; }

funcblockend:{ loopcounter = pop(loopcounterstack); }

funcbody: funcblockstart block funcblockend{
   $funcbody=currentscopeoffset();
   exitscopespace();
   if($block!=NULL){
       patchlist($block->returnList, nextquadlabel());
   }
   printf("(%d)(funcbody->block )\n",++pnum);
}
;

funcargs:LEFT_PARENTHESIS{++scope; } 
  idlist RIGHT_PARENTHESIS{
  scope--;
  enterscopespace();
  resetfunctionLocaloffset();
  printf("(%d)(funcargs->LEFT_PARENTHESIS idlist RIGHT_PARENTHESIS)\n",++pnum);
}
;

funcname:ID{
   $funcname=$1;
  
   printf("(%d)(funcname->ID )\n",++pnum);
}
;

funcname:  {
   $funcname=MakeFunctionName(namef++);
   printf("(%d)(funcname-> )\n",++pnum);
}
;

funcprefix:FUNC_ST funcname{
    $funcprefix=LookUpFunction(scope,$funcname,yylineno);
    
    if( $funcprefix!=NULL){
        $funcprefix->iadress = nextquadlabel();
        emit(funcstart,function_def($funcprefix), NULL, NULL); 
    }else{
      printf("LookUpFunction returns NULL\n");
    }
    push(scopeoffsetstack,currentscopeoffset());
    enterscopespace();
    resetformalArgoffset();
    funcounter++;
    printf("(%d)(funcprefix->FUNC_ST funcname )\n",++pnum);
}
;


funcdef:N funcprefix funcargs funcbody{
     
     exitscopespace();
   
     SymbolTableEntry *ptr=(SymbolTableEntry*)malloc(sizeof(SymbolTableEntry));
     $funcdef=ptr;
     

     int offset = pop(scopeoffsetstack);
     restorecurrscopeoffset(offset); 
     if($funcprefix!=NULL){
          $funcdef=$funcprefix;
          $funcdef->totalLocals=$funcbody;
   
     }else{
          $funcdef=NULL;
       printf("$funcprefix is NULL in :funcdef:funcprefix funcargs funcbody\n");
     }
    
     
     emit(funcend,function_def($funcprefix), NULL, NULL);
     patchlabel($N,nextquadlabel());
     funcounter--;
     printf("(%d)(funcdef->funcprefix funcargs funcbody )\n",++pnum);
}
;


const:NUMBER_INT{
      $const=newexpr_num_int($NUMBER_INT);
      printf("(%d)(const->NUMBER_INT)\n",++pnum);}
     |NUMBER_REAL{
      $const=newexpr_num_double($NUMBER_REAL);
      printf("(%d)(const->NUMBER_REAL)\n",++pnum);} 
     |STRING {
       $const=newexpr_string($STRING);
       printf("(%d)(const->STRING)\n",++pnum);}
     |TRUE_ST {
        $const=newexpr_bool(1);
        printf("(%d)(const->TRUE)\n",++pnum);}
     |FALSE_ST  {
        $const=newexpr_bool(0);
        printf("(%d)(const->FALSE)\n",++pnum);}
     |NIL_ST     {
        $const=newexpr(nil_e);
        printf("(%d)(const->NIL)\n",++pnum);}
     ;
idlist:ID {LookUpFormal($1 ,yylineno,scope);} IDS {printf("(%d)(idlist->ID IDS)\n",++pnum);}
	 | {printf("(%d)(idlist-> )\n",++pnum);}
	 ;
	 
IDS:COMMA ID {LookUpFormal($2 ,yylineno,scope);} IDS {printf("(%d)(IDS->COMMA ID IDS)\n",++pnum);}
	 | {printf("(%d)(IDS-> )\n",++pnum);}
	 ;

elseprefix:ELSE_ST
{
       
        emit(jump, NULL, NULL, NULL);
        $elseprefix = currquad();
}

ifprefix:IF_ST LEFT_PARENTHESIS expr RIGHT_PARENTHESIS{

            if($3->trueList!=0&&$3->falseList!=0){
                 Merikh_Assign($expr);
                 lockA=1;
                 lock=1;
             }
            emit(if_eq,NULL,$expr,newexpr_bool(1));
            
            quads[currquad()].label=currquad()+2;
            emit(jump, NULL, NULL, NULL);
            $ifprefix = currquad();
            printf("(%d)(ifprefix->if(expr)\n",++pnum);
        }
        ; 
ifstmt1:ifprefix stmt {patchlabel($ifprefix,nextquadlabel()); printf("(%d)(ifstmt->ifprefix stmt )\n",++pnum);}
        ;
ifstmt2:ifprefix stmt  elseprefix stmt {
         patchlabel($ifprefix, $elseprefix + 1);
         patchlabel($elseprefix, nextquadlabel());
         printf("(%d)(ifstmt2->if ifprefix stmt elseprefix stmt ) \n",++pnum);}
       ;

loopstart: { ++loopcounter; }
         ;

loopend: { --loopcounter; }
         ;

loopstmt: loopstart stmt loopend { $loopstmt = $stmt;
             printf("(%d)(loopstmt->loopstart stmt loopend )\n",++pnum);
          }
         ;

whilestart:WHILE_ST
          {
            $whilestart = nextquadlabel();
            printf("(%d)(whilestart->WHILE_ST)\n",++pnum);
          }
          ;

whilecond: LEFT_PARENTHESIS expr RIGHT_PARENTHESIS
         {
             if($2->trueList!=0&&$2->falseList!=0){
                 Merikh_Assign($2);
                 lockA=1;
                 lock=1;
             }
             emit(if_eq,NULL,$expr,newexpr_bool(1));
             quads[currquad()].label=currquad()+2;
             emit(jump, NULL, NULL,NULL);
             $whilecond = currquad();
             printf("(%d)(whilecond->(expr) stmt)\n",++pnum);
         }
         ;

whilestmt :whilestart whilecond loopstmt
        {
             emit(jump, NULL, NULL, NULL);
             quads[currquad()].label=$whilestart;
             patchlabel($whilecond, nextquadlabel());
             if($loopstmt!=NULL){
                Printpatchlist ($loopstmt->breakList);
                Printpatchlist ($loopstmt->contList);
                patchlist($loopstmt->breakList, nextquadlabel());
                patchlist($loopstmt->contList, $whilestart);
             }
             printf("(%d)(whilestart->whilecond whilecond loopstmt)\n",++pnum);
        }
        ;



//whilestmt : WHILE_ST LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt  {printf("(%d)(whilestmt->while ( expr ) stmt ) \n",++pnum);}

N :{ $N = nextquadlabel(); emit(jump,NULL,NULL,NULL); }
  ;

M :{ $M = nextquadlabel(); }
  ;

forprefix : FOR_ST LEFT_PARENTHESIS elist SEMICOLON M expr SEMICOLON
          {
             if($expr->trueList!=0&&$expr->falseList!=0){
                 Merikh_Assign($expr);
                 lockA=1;
                 lock=1;
             }
            forpre *ptr=(forpre*)malloc(sizeof(forpre));
            ptr->test = $M;
            ptr->enter = nextquadlabel();
            $forprefix=ptr;
            emit(if_eq,NULL,$expr,newexpr_bool(1));
          }
          ;

forstmt: forprefix N elist RIGHT_PARENTHESIS N loopstmt N
          {
            patchlabel($forprefix->enter,$5+1); 
            patchlabel($2, nextquadlabel()); 
            patchlabel($5, $forprefix->test);
            patchlabel($7, $2+1);
             if($loopstmt!=NULL){
                Printpatchlist ($loopstmt->breakList);
                Printpatchlist ($loopstmt->contList);
                patchlist($loopstmt->breakList, nextquadlabel());
                patchlist($loopstmt->contList, $2+1);
             }
          }
          ;


//forstmt:     	FOR_ST LEFT_PARENTHESIS elist SEMICOLON expr SEMICOLON elist RIGHT_PARENTHESIS stmt {printf("(%d)(forstmt->for (elist;expr;elist) stmt )\n",++pnum);}
  //           	; 

returnstmt:RETURN_ST SEMICOLON {
            printf("FUNCCOUNTER:%d\n",funcounter);
            if(funcounter>0){
                emit(ret,NULL,NULL,NULL);
                $returnstmt=make_stmt( );
                $returnstmt->returnList=newlist(nextquadlabel());
                emit(jump,NULL,NULL,NULL);
            }else{
                printf("\033[0;31m");
		      	 printf("Error(%d)	[Return not in function] \n",yylineno); 
		          printf("\033[0m");
                $returnstmt=NULL;
            }
            
            printf("(%d)(returnstmt->return ;)\n",++pnum);}
          |RETURN_ST expr SEMICOLON {
            printf("FUNCCOUNTER:%d\n",funcounter);
            if(funcounter>0){
                emit(ret,$expr,NULL,NULL);
                $returnstmt=make_stmt( );
                $returnstmt->returnList=newlist(nextquadlabel());
                emit(jump,NULL,NULL,NULL);
            }else{
                printf("\033[0;31m");
		      	 printf("Error(%d)	[Return not in function] \n",yylineno); 
		          printf("\033[0m");
                $returnstmt=NULL;
            }          
            printf("(%d)(returnstmt->return expr;)\n",++pnum);}
          ;



%%

int yyerror (char* yaccProvidedMessage)
{
        fprintf(stderr, "%s: at line %d, before token: '%s'\n", yaccProvidedMessage, yylineno, yytext);
}



int main(int argc,char** argv)
{
  if(argc>1){
   if(!(yyin=fopen(argv[1],"r"))){  
      fprintf(stderr,"Cannot read file:%s\n",argv[1]);
      return 1;
   }
  }else{
    yyin=stdin;
  }

    printf("--------------------            Syntax Analysis         --------------------\n");
    InitHash();
    scopeoffsetstack=createStack(1000);
    loopcounterstack=createStack(1000);
    emit(start,NULL,NULL,NULL);
    yyparse();
   // display();
  //  MakeQuadTable();
   // SymbolTableEntry *a=newtmp();
   // SymbolTableEntry *a2=newtmp();
    PrintScopes();
     PrintQuads();
    return 0;
}





