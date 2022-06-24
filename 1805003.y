

%{
#include<bits/stdc++.h>
#include <fstream>
using namespace std;


#include "1805003_SymbolHelper.h"
#include "1805003_SymbolTable.h"







ofstream logoutput;
ofstream erroroutput;


extern int line_no;
int error_count = 0;


int yyparse(void);
int yylex(void);

extern FILE *yyin;

void yyerror(string s){
	logoutput<<"Error at line "<<line_no<<": "<<s<<"\n"<<endl;
	erroroutput<<"Error at line "<<line_no<<": "<<s<<"\n"<<endl;
    error_count++;
}


int bucket_size = 31;
SymbolTable *table = new SymbolTable(bucket_size);
bool is_function_now = false;
vector<SymbolInfo>function_params;




void free_memory_s(SymbolInfo* s) // erase memory of SymbolInfo pointer
{
    if(s!=NULL) delete (s);
}

void free_memory_h(SymbolHelper* h) // erase memory of Helper pointer
{
    if(h!=NULL) delete (h);
}


%}


%token IF NEWLINE ELSE STRING LOWER_THAN_ELSE FOR WHILE DO BREAK CHAR DOUBLE  RETURN SWITCH CASE DEFAULT CONTINUE PRINTLN INCOP DECOP ASSIGNOP NOT LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD COMMA SEMICOLON
%token <symbol_info> ID INT FLOAT VOID ADDOP MULOP RELOP LOGICOP BITOP CONST_INT  CONST_FLOAT ERROR_FLOAT CONST_CHAR

%type <helper> start program unit variable  type_specifier func_declaration func_definition parameter_list

%destructor { free_memory_h($$);  }  <helper>
%destructor { free_memory_s($$);  }  <symbol_info>

%error-verbose

%union{
  SymbolInfo* symbol_info;
   SymbolHelper *helper;
    string* symbol_info_str;
    string* temp_str;
 

}


%%

input:              /* empty string */
    | input line
    ;
line: NEWLINE
    | expr NEWLINE           { cout<<"function"; }
      

expr: INT

%%


 main(int argc,char *argv[])
{
    if(argc!=2){
		printf("Please provide input file name and try again\n");
		return 0;
	}
	
	FILE *fin=fopen(argv[1],"r");
	if(fin==NULL){
		printf("Cannot open specified file\n");
		return 0;
	}

    logoutput.open("1805003_log.txt");
	erroroutput.open("error.txt");

    yyin=fin;
	yyparse();

 

    logoutput<<"Total lines: "<<line_no<<endl;
    logoutput<<"Total errors: "<<error_count<<endl;

    fclose(yyin);

    logoutput.close();
	erroroutput.close();

    exit(0);
}
