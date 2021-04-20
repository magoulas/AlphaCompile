#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assert.h"
#define  MAX_TABLE 10


unsigned programVaroffset=0;
unsigned functionLocaloffset=0;
unsigned formalArgoffset=0;
unsigned scopeSpaceCounter=1;

void resetformalArgoffset(){
	formalArgoffset=0;
}

void resetfunctionLocaloffset(){
	functionLocaloffset=0;
}


typedef enum{
  programvar=0,
  functionlocal,
  formalarg,
  function
}scopespace_t;

scopespace_t currscopespace(){
	if(scopeSpaceCounter==1)
	 return programvar;
	else if (scopeSpaceCounter%2==0)
	 return formalarg;
	 else
	 {
		 return functionlocal;
	 }
	 
}

unsigned currentscopeoffset(){
	switch( currscopespace()){
		case programvar:return programVaroffset;
		case functionlocal:return functionLocaloffset;
		case formalarg:return formalArgoffset;
		default:assert(0);
	}
}

unsigned incurrentscopeoffset(){
	switch( currscopespace()){
		case programvar:++programVaroffset; break;
		case functionlocal:++functionLocaloffset; break;
		case formalarg:++formalArgoffset; break;
		default:assert(0);
	}
}

void enterscopespace(){
	++scopeSpaceCounter;
}

void exitscopespace(){
	assert(scopeSpaceCounter>1);
	--scopeSpaceCounter;
}

typedef enum {
 GLOBAL=0, LOCAL, FORMAL,
 USERFUNC, LIBFUNC
}SymbolType;

const char* GetType(SymbolType type){
  switch(type)
  {
  	case GLOBAL: return "GLOBAL";
	case LOCAL: return "LOCAL";
	case FORMAL: return "FORMAL";
	case USERFUNC: return "USERFUNC";
	case LIBFUNC: return "LIBFUNC";
  }

}


const char* GetSpaceType(scopespace_t type){
  switch(type)
  {
  	case programvar: return "programvar";
	case functionlocal: return "functionlocal";
	case formalarg: return "formalarg";
	case function:return "function";
  }

}


const char* IsActive(int i){
	if(i==1) return "Active";
	else 	 return  "Inactive";
}

typedef struct SymbolTableEntry {
int isActive;
char *name;
int scope;
int line;
SymbolType type;
scopespace_t space;
int offset;
unsigned int iadress;
unsigned int totalLocals;
struct SymbolTableEntry *next;
struct SymbolTableEntry *nextScope;
struct SymbolTableEntry *args;
} SymbolTableEntry;

typedef struct Scope{
	int scope;
	SymbolTableEntry *symbol;
	struct Scope *next;
}Scope;

typedef struct ScopeBack{
		struct Scope *ptr;
}ScopeBack;

Scope *HeadScope=NULL;

SymbolTableEntry *Hash[MAX_TABLE]={NULL};
SymbolTableEntry *c={NULL};

Scope *HeadScope2=NULL;

SymbolTableEntry *Hash2[MAX_TABLE]={NULL};
SymbolTableEntry *c2={NULL};


void  MakeNewScope(int scope,SymbolTableEntry *symbol){
 		Scope* newnode=(Scope *)malloc(sizeof(Scope));
 		if(newnode==NULL) {
 		//	printf("error in making of new entry of scope list\n");
 			return;
		 }
		 
 		newnode->scope=scope;
		newnode->symbol=symbol;     //malloc for struct scope
		newnode->next=NULL;			//

		if(scope==0){
		    	HeadScope=newnode; //HeadScope is pointer in first element of scope list
		}else{
			 Scope *d;
			 Scope *dprev;
		    d=HeadScope;
			dprev=d;
		    while(d->next != NULL)
        		{
					   dprev=d;
					   d=d->next;
           			
        		}
        	if(d->scope<scope)	{
				d->next=newnode;
			}else{
				dprev->next=newnode;
				newnode->next=d;
			}
		}
		   
}


void PrintScopes(){

	Scope *ptr=HeadScope;
	SymbolTableEntry *ptr2;

	while(ptr!=NULL){
	    ptr2=ptr->symbol;
	    printf("-----------	Scope %d ----------\n",ptr->scope);
		while(ptr2!=NULL){
				if(ptr2->type==3){
						printf("\"%s\"	[%s] (line %d) (scope %d) (iadress %d) (totalLocals %d) (%s)",ptr2->name
				        ,GetType(ptr2->type),ptr2->line,ptr2->scope,ptr2->iadress,ptr2->totalLocals,IsActive(ptr2->isActive));
				}

				if(ptr2->type==4){
						printf("\"%s\"	[%s] (line %d) (scope %d)  (%s)",ptr2->name
				        ,GetType(ptr2->type),ptr2->line,ptr2->scope,IsActive(ptr2->isActive));
				}


				if(ptr2->type==0||ptr2->type==1||ptr2->type==2){
					    printf("\"%s\"	[%s] (line %d) (scope %d) (space %s) (offset %d) (%s)",ptr2->name
				        ,GetType(ptr2->type),ptr2->line,ptr2->scope,GetSpaceType(ptr2->space),ptr2->offset,IsActive(ptr2->isActive));
				}
				
				
				printf("\n");
			ptr2=ptr2->nextScope;   //traversal of scope list
		}
		ptr=ptr->next;
	}
	
}


void EnterScopeList(int scope,SymbolTableEntry *symbol){
	Scope *ptr=HeadScope;
	SymbolTableEntry *ptr2;  //ptr2 traversal of list of elements of scope
	SymbolTableEntry *prev;   //prev holds the trevious value of ptr2
	while(ptr!=NULL){
	    if(ptr->scope==scope) {
	    	ptr2=ptr->symbol;
			while(ptr2!=NULL){
			 prev=ptr2;
			 ptr2=ptr2->nextScope;   //end of list of scope,prev has the value of last struct
		    }
	    	break;
		}
		ptr=ptr->next;
	}
	
	if(prev!=NULL) prev->nextScope=symbol;  //link last element in tail
	else  // printf("prev is NULL\n");
	return;	
}


int  ScopeOfVariableExist(int scope){
			Scope *d;
			int flag=0;
			if(HeadScope==NULL){      //list of scopes does not exist//
		//		printf("HeadScope is NULL,list of scopes does not exist\n");
				return 0;
			}else{
				 d=HeadScope;
		    	 while(d!= NULL)
        		 {
        			if(d->scope==scope){
        				flag=1;   //scope we looking for exist!!
        				break;
					}
           			d=d->next;
        		 }
        		 
        		 if(flag==1){
        		     return 1; //scope struct exist
				 }else{
				 	return 0;  //scope struct does not exist
				 }   	    
			}	
}


int hash(const char * str) {
        int hash = 401;
        int c;
        while (*str != '\0') {
                hash = ((hash << 4) + (int)(*str)) % MAX_TABLE;
                str++;
        }
    //    printf("hasj numbe:r%d\n",hash % MAX_TABLE);
        return hash % MAX_TABLE;
}




SymbolTableEntry *insert( SymbolType  type,char *name,int scope,int line)
{
	
	  		SymbolTableEntry* newnode=(SymbolTableEntry *)malloc(sizeof(SymbolTableEntry));
	  		if(newnode==NULL){
	  	//		printf("error in making of new entry of hash\n");
				return;	
			}
			
            newnode->type=type;
	  		newnode->isActive=1;
	  		newnode->next=NULL;
	  		newnode->args=NULL;
	  		newnode->line=line;
	  		newnode->name=strdup(name);
	  		newnode->scope=scope;
	  		newnode->nextScope=NULL;
			if(type!=3&&type!=4){
				newnode->space=currscopespace();
				newnode->offset=currentscopeoffset();
				incurrentscopeoffset();
			}
			
			
	  
	        int i=hash(name);
	   		if(Hash[i] == NULL){		//if pointer in first element exist//
        		Hash[i] = newnode;
		
   	    	}else{
        		c=Hash[i];
        		while(c->next != NULL) //if pointer in first element of hash does not exist//
        		{
           			c=c->next;
        		}
        		c->next=newnode;		//chaining
    		}
    		
    		if(ScopeOfVariableExist(scope)==0){  //if returns 0,scope of variable does not exist//
    			MakeNewScope(scope,newnode);
			}else{
				EnterScopeList(scope,newnode);   //if returns 1,struct of scope exist
			}
    		
    		 return newnode;
}


void display()
{
    int i;
    for(i=0;i<MAX_TABLE;i++)
          {
       //    printf("\nentries at index %d\n",i);
               if(Hash[i] == NULL)
               {
         //      printf("No Hash Entry");
               }
               else
               {
                              for(c=Hash[i];c!=NULL;c=c->next)
                              {
                              	printf("[name:%s,scope:%d,line:%d]",c->name,c->scope,c->line);
							  }
                              
               }
          }
         printf("\n");
}

void InitHash(){

insert(4,"print",0,0);
    insert(4,"input",0,0);
    insert(4,"objectmemberkeys",0,0);
    insert(4,"objecttotalmembers",0,0);
    insert(4,"objectcopy",0,0);
    insert(4,"totalarguments",0,0);
    insert(4,"argument",0,0);
    insert(4,"typeof",0,0);
    insert(4,"strtonum",0,0);
    insert(4,"sqrt",0,0);
    insert(4,"cos",0,0);
    insert(4,"sin",0,0);
 return;

}

SymbolTableEntry *LookUpLocal(char *name,int scope,int line){
	int i=hash(name);
	if(Hash[i]==NULL){
		printf("Insertion(%d)	[Local:%s]\n",line,name);
		if(scope==0) {
			return insert(0,name,scope,line);
		}
		else {
			return insert(1,name,scope,line);
		}		 
	}else{

        if(scope!=0){
			c=Hash[i];
			while(c!=NULL){
				if((strcmp(name,c->name)==0)&&(c->type==4)){
					printf("\033[0;31m");
					printf("Error(%d)	[Local] (Shadowing Function:%s)\n",line,name); 
					printf("\033[0m");
					return NULL;
				}
				c=c->next;
			}
	   }
		c=Hash[i];
		while(c!=NULL){
			if((strcmp(name,c->name)==0)&&(c->scope==scope)&&(c->isActive==1)) break;
			c=c->next;		
	    }
	    
	    if(c==NULL){
	    	printf("Insertion(%d)	[Local:%s]\n",line,name);
		    if(scope==0){
				return insert(0,name,scope,line);
			} 
		    else{
				return insert(1,name,scope,line);
			}		 
		}else{
			printf("\033[0;32m");
			printf("Reference(%d)	[Local]     \"%s\"	(%d)\n",line,name,c->line);
			printf("\033[0m");
			return c;
		}
	}
	
		
}

void Hide(int scope)
{

  Scope *ptr=HeadScope;
  SymbolTableEntry* ptr2=NULL;
  
  if((HeadScope!=NULL)&&(scope!=0)){
	while((ptr!=NULL))
	{
		if(ptr->scope==scope){
 		  break;
		}
		ptr=ptr->next;
 	}

    if(ptr!=NULL)
    {
		ptr2=ptr->symbol;
		while(ptr2!=NULL){
		  ptr2->isActive=0;
		  ptr2=ptr2->nextScope;
		}
    }else{
    //	printf("Error:cant find scope list for hiding\n");
	}
    
 }else{
  //	printf("Error:cant use hide for scope zero\n");
 }

 return ;
}

SymbolTableEntry *LookUpGlobal(char *name,int line)
{
  Scope *ptr=HeadScope;
  SymbolTableEntry  *ptr2;
  if(ptr!=NULL){
     	ptr2=ptr->symbol;
        while(ptr2!=NULL){
            if(strcmp(ptr2->name,name)==0) break;
                  ptr2=ptr2->nextScope;
        }
  }else{
    printf("Error(%d).HeadScope is NULL(LookUpGlobal).\n",line);
    return NULL;
  } 

  if(ptr2!=NULL) {
    printf("\033[0;32m");
    printf("Reference(%d)	[Global::]     \"%s\"	(%d)\n",line,name,ptr2->line);
    printf("\033[0m");
	return ptr2;
  }else{
    printf("\033[0;31m");
    printf("Error(%d)	[Global::] (No existing reference to symbol:%s)\n",line,name); 
    printf("\033[0m");
	return NULL;

  }
  
 
}






void PrintScopes2(){

	Scope *ptr=HeadScope2;
	SymbolTableEntry *ptr2;

	while(ptr!=NULL){
	    ptr2=ptr->symbol;
	    printf("-----------	Scope %d ----------\n",ptr->scope);
		while(ptr2!=NULL){
				
				printf("\"%s\"	[%s] (line %d) (scope %d) (%s)",ptr2->name,GetType(ptr2->type),ptr2->line,ptr2->scope,IsActive(ptr2->isActive));
				printf("\n");
			ptr2=ptr2->nextScope;   //traversal of scope list
		}
		ptr=ptr->next;
	}
	
	printf("\n\n");
}







SymbolTableEntry *LookUpFunction(int scope,char *name,int line)
{
 
	int i=hash(name);
	if(Hash[i]==NULL){
		printf("Insertion(%d)	[Function:%s]\n",line,name);
		return insert(3,name,scope,line);
	
	}else{

      
		c=Hash[i];
		while(c!=NULL){
			if((strcmp(name,c->name)==0)&&(c->scope==scope)&&(c->isActive==1)) break;
			c=c->next;		
	    }
	    
	    if(c==NULL){
	    	c=Hash[i];
			while(c!=NULL){
				if((strcmp(name,c->name)==0)&&(c->type==4)){
					printf("\033[0;31m");
					printf("Error(%d)	[Function] (Shadowing Function:%s)\n",line,name); 
					printf("\033[0m");
					return NULL;
				}
				c=c->next;
			}
			
			if(c==NULL) {
				return 	insert(3,name,scope,line);
			}	
			
		}else{
			printf("\033[0;31m");
			if(c->type==0||c->type==1||c->type==2) 	printf("Error(%d)	[Function] (Redeclaration Var:%s)		(%d)\n",line,name,c->line);
			if(c->type==3)	printf("Error(%d)	[Function] (Redeclaration Function:%s)		(%d)\n",line,name,c->line); 
			if(c->type==4)  	printf("Error(%d)	[Function] (Shadowing Function:%s)		(%d)\n",line,name,c->line); 
			printf("\033[0m");
			return NULL;
		}
	}
	
		
}




void LookUpFormal(char *name,int line,int scope)
{
 
	int i=hash(name);
	if(Hash[i]==NULL){
		printf("Insertion(%d)	[Formal:%s]\n",line,name);
		insert(2,name,scope,line);
	
	}else{

      
		c=Hash[i];
		while(c!=NULL){
			if((strcmp(name,c->name)==0)&&(c->scope==scope)&&(c->isActive==1)) break;
			c=c->next;		
	    }
	    
	    if(c==NULL){
	    	c=Hash[i];
			while(c!=NULL){
				if((strcmp(name,c->name)==0)&&(c->type==4)){
					printf("\033[0;31m");
					printf("Error(%d)	[Formal] (Shadowing Function:%s)\n",line,name); 
					printf("\033[0m");
					return;
				}
				c=c->next;
			}
			
			if(c==NULL) 	insert(2,name,scope,line);
			return;
		}else{
			printf("\033[0;31m");
			if(c->type==0||c->type==1||c->type==2) 	printf("Error(%d)	[Formal] (Redeclaration Var:%s)\n		(%d)\n",line,name,c->line);
			if(c->type==3)	printf("Error(%d)	[Formal] (Redeclaration Function:%s)		(%d)\n",line,name,c->line);
			if(c->type==4)  	printf("Error(%d)	[Formal] (Shadowing Function:%s)		(%d)\n",line,name,c->line); 
			printf("\033[0m");
		}
	}
	
		return;
}







void EnterScopeList2(int scope,SymbolTableEntry *symbol){
	Scope *ptr=HeadScope2;
	while(ptr!=NULL){
	    if(ptr->scope==scope) {
	         symbol->nextScope=ptr->symbol;
		     ptr->symbol=symbol;
	    	break;
		}
		ptr=ptr->next;
	}
	return;
}
	

void  MakeNewScope2(int scope,SymbolTableEntry *symbol){
 		Scope* newnode=(Scope *)malloc(sizeof(Scope));
 		if(newnode==NULL) {
 		//	printf("error in making of new entry of scope list\n");
 			return;
		 }
		 
 		newnode->scope=scope;
		newnode->symbol=symbol;     //malloc for struct scope
		newnode->next=NULL;			//

		if(scope==0){
		    	HeadScope2=newnode; //HeadScope is pointer in first element of scope list
		}else{
			 Scope *d;
			 Scope *dprev;
		     d=HeadScope2;
			 dprev=d;
		    while(d->next != NULL)
        		{
           			
					   d=d->next;
           			
        		}
        	d->next=newnode;	
			if(d->scope<scope)	{
				d->next=newnode;
			}else{
				dprev->next=newnode;
				newnode->next=d;
			}
		}
		   
}

int  ScopeOfVariableExist2(int scope){
			Scope *d;
			int flag=0;
			if(HeadScope2==NULL){      //list of scopes does not exist//
			//	printf("HeadScope2 is NULL,list of scopes does not exist\n");
				return 0;
			}else{
				 d=HeadScope2;
		    	 while(d!= NULL)
        		 {
        			if(d->scope==scope){
        				flag=1;   //scope we looking for exist!!
        				break;
					}
           			d=d->next;
        		 }
        		 
        		 if(flag==1){
        		     return 1; //scope struct exist
				 }else{
				 	return 0;  //scope struct does not exist
				 }   	    
			}	
}

void MakeTableWithElementsReverse(){
	
	
	Scope *ptr=HeadScope;
	SymbolTableEntry *ptr2;

	while(ptr!=NULL){
	    ptr2=ptr->symbol;
	 //   printf("-----------	Scope %d ----------\n",ptr->scope);
		while(ptr2!=NULL){
			
			
			
	  		SymbolTableEntry* newnode=(SymbolTableEntry *)malloc(sizeof(SymbolTableEntry));
	  		if(newnode==NULL){
	  			printf("error in making of new entry of hash\n");
				return;	
			}
			
            newnode->type=ptr2->type;
	  		newnode->isActive=ptr2->isActive;
	  		newnode->next=NULL;
	  		newnode->args=NULL;
	  		newnode->line=ptr2->line;
	  		newnode->name=strdup(ptr2->name);
	  		newnode->scope=ptr2->scope;
	  		newnode->nextScope=NULL;
	  
	        int i=hash(ptr2->name);
	   		if(Hash2[i] == NULL){		//if pointer in first element exist//
        		Hash2[i] = newnode;
		
   	    	}else{
        		c=Hash2[i];
        		while(c->next != NULL) //if pointer in first element of hash does not exist//
        		{
           			c=c->next;
        		}
        		c->next=newnode;		//chaining
    		}
    		
    		if(ScopeOfVariableExist2(ptr2->scope)==0){  //if returns 0,scope of variable does not exist//
    			MakeNewScope2(ptr2->scope,newnode);
			}else{
				EnterScopeList2(ptr2->scope,newnode);   //if returns 1,struct of scope exist
			}
			
	
			
			ptr2=ptr2->nextScope;   //traversal of scope list
		}
		ptr=ptr->next;
	}
	
  //  printf("--------BLUEFACE BABY-------\n");
//	PrintScopes2();

	return;
	
}


SymbolTableEntry *LookUpVariable(int scope,char *name,int line)
{
	MakeTableWithElementsReverse();   //make Global list reverse
	
	int scopeoffunction;
    int scopeT=scope;
	Scope *ptr=HeadScope2;
	int functionFlag=0;
	SymbolTableEntry* ptr2=NULL;
	int flag=0;
	while(scopeT>=0){
		ptr=HeadScope2;				//head of the global table with reverse elements
		while(ptr!=NULL){
			if(ptr->scope==scopeT) break;
			ptr=ptr->next;
		}
		
		if(ptr!=NULL){
			ptr2=ptr->symbol;
			while(ptr2!=NULL){
				if(strcmp(ptr2->name,name)==0&&(ptr2->isActive==1))
				{
					 flag=1;
					 break;	
				}
			
				if(ptr2->type==3&&(ptr2->isActive==1)) {functionFlag=1;
				  scopeoffunction=ptr2->scope;
				}
				ptr2=ptr2->nextScope;
			}
		}else{
			printf("line(%d):LookUpVariable  [ptr==NULL]\n",line);
		}
		
		if(	flag==1) {
		//	printf("ENA DIO\n");
			break;
		}
		else {
			
		}
		--scopeT;
	}
	
		HeadScope2=NULL;
	
	if(flag==1 && ptr2!=NULL) {
		if(ptr2->scope==0){
			printf("\033[0;32m");
			printf("Reference(%d)	[Variable] (Refernce to Global:%s)		(%d)\n",line,name,ptr2->line);
    		printf("\033[0m");	
    		return ptr2;
		}

        if(ptr2->type==3) {
			printf("\033[0;32m");
			printf("Reference(%d)	[Variable] (Refernce to Function:%s)		(%d)\n",line,name,ptr2->line);
			printf("\033[0m");	
			return ptr2;
		}



		if(functionFlag==1&&ptr2->type!=3&&scopeoffunction<scope) {
			printf("\033[0;31m");
			printf("Error(%d)	[Variable] (Function Between:%s)		(%d)\n",line,name,ptr2->line); 
			printf("\033[0m");	
			return NULL;
		}else{
			printf("\033[0;32m");
			printf("Reference(%d)	[Variable] (Refernce to Variable:%s)			(%d)\n",line,name,ptr2->line);
    		printf("\033[0m");	
    		return ptr2;
		}
		
	
	}else{
		
		printf("Insertion(%d)	[Variable:%s]\n",line,name);
		if(scope==0){
			return 	 insert(0,name,scope,line);
		}
		else {
			return	  insert(1,name,scope,line);
	    }
	}		
	 
	 return;
}


char *MakeFunctionName(int i){
 
     char strnum[20];
     char name[]="$f";

     sprintf(strnum,"%d",i);
  
     char* str1=(char *)malloc(sizeof(strnum)+sizeof(name)+1); 
    if (str1!= NULL) {
         strcpy(str1, name);
         strcat(str1, strnum);

    } else{
        printf ( "malloc() failed in MakeFunctionName!\n");
    } 
  
   // printf("%s\n",str1);
    return str1;
}



int IsFunction(int scope,char *name,int line)
{
	MakeTableWithElementsReverse();   //make Global list reverse
	
    int scopeT=scope;
	Scope *ptr=HeadScope2;
	int functionFlag=0;
	SymbolTableEntry* ptr2=NULL;
	int flag=0;
	while(scopeT>=0){
		ptr=HeadScope2;				//head of the global table with reverse elements
		while(ptr!=NULL){
			if(ptr->scope==scopeT) break;
			ptr=ptr->next;
		}
		
		if(ptr!=NULL){
			ptr2=ptr->symbol;
			while(ptr2!=NULL){
				if(strcmp(ptr2->name,name)==0&&(ptr2->isActive==1))
				{
					 flag=1;
					 break;	
				}
			
			
				ptr2=ptr2->nextScope;
			}
		}else{
		//	printf("line(%d):LookUpVariable  [ptr==NULL]\n",line);
		}
		
		if(	flag==1) {
			//printf("ENA DIO\n");
			break;
		}
		else {
			
		}
		--scopeT;
	}
	
		HeadScope2=NULL;
	
	if(flag==1 && ptr2!=NULL&&(ptr2->type==3||ptr2->type==4)) {

			return	1;
		
	}else{
		
		    return	0;
	}
    return;
}

int IsFunctionLocal(int scope,char *name,int line)
{
	MakeTableWithElementsReverse();   //make Global list reverse
	
    int scopeT=scope;
	Scope *ptr=HeadScope2;
	int functionFlag=0;
	SymbolTableEntry* ptr2=NULL;
	int flag=0;
	while(scopeT>=0){
		ptr=HeadScope2;				//head of the global table with reverse elements
		while(ptr!=NULL){
			if(ptr->scope==scopeT) break;
			ptr=ptr->next;
		}
		
		if(ptr!=NULL){
			ptr2=ptr->symbol;
			while(ptr2!=NULL){
				if(strcmp(ptr2->name,name)==0&&(ptr2->isActive==1)&&(ptr2->scope==scope))
				{
					 flag=1;
					 break;	
				}
			
			
				ptr2=ptr2->nextScope;
			}
		}else{
		//	printf("line(%d):LookUpVariable  [ptr==NULL]\n",line);
		}
		
		if(	flag==1) {
			//printf("ENA DIO\n");
			break;
		}
		else {
			
		}
		--scopeT;
	}
	
		HeadScope2=NULL;
	
	if(flag==1 && ptr2!=NULL&&(ptr2->type==3||ptr2->type==4)) {

			return	1;
		
	}else{
		
		    return	0;
	}
    return;
}

SymbolTableEntry *LookUpScope(char *name,int scope){

	Scope *ptr=HeadScope;
	SymbolTableEntry *ptr2;

	while(ptr!=NULL){
		if(ptr->scope==scope){
			ptr2=ptr->symbol;
			while(ptr2!=NULL){
					if(strcmp(ptr2->name,name)==0&&(ptr2->isActive==1)) return ptr2;
					ptr2=ptr2->nextScope;   //traversal of scope list
			}
		}
		ptr=ptr->next;
	}
	
	return NULL;
}

SymbolTableEntry *newsymbol( SymbolType  type,char *name,int scope,int line)
{
	
	  		SymbolTableEntry* newnode=(SymbolTableEntry *)malloc(sizeof(SymbolTableEntry));
	  		if(newnode==NULL){
	  	//		printf("error in making of new entry of hash\n");
				return;	
			}
			
            newnode->type=type;
	  		newnode->isActive=1;
	  		newnode->next=NULL;
	  		newnode->args=NULL;
	  		newnode->line=line;
	  		newnode->name=strdup(name);
	  		newnode->scope=scope;
	  		newnode->nextScope=NULL;
	  
	        int i=hash(name);
	   		if(Hash[i] == NULL){		//if pointer in first element exist//
        		Hash[i] = newnode;
		
   	    	}else{
        		c=Hash[i];
        		while(c->next != NULL) //if pointer in first element of hash does not exist//
        		{
           			c=c->next;
        		}
        		c->next=newnode;		//chaining
    		}
    		
    		if(ScopeOfVariableExist(scope)==0){  //if returns 0,scope of variable does not exist//
    			MakeNewScope(scope,newnode);
			}else{
				EnterScopeList(scope,newnode);   //if returns 1,struct of scope exist
			}
    		
    		return newnode;
}