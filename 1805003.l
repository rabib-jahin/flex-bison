%option noyywrap
%x INSIDE_STRING
%x START_STRING
%x END_STRING 



%{
#include<bits/stdc++.h>
#include<fstream>

#include "SymbolHelper2.h"
#include "y.tab.h"

using namespace std;


ofstream token;
extern ofstream erroroutput;
extern ofstream logoutput;
extern YYSTYPE yylval;
extern int error_count;
int line_no = 1;

void yyerror(char *);

string str="";
string createDesiredString(const char* p) {
	int length = strlen(p);
	string str = "";

	int i=0;

  while (i<length) {

		if(p[i] != '\\') {
			str.append(1u, p[i]); 
			i+=1;
		} else {
			if(p[i+1] == 'n') {
				str.append(1u, '\n');
			} else if(p[i+1] == 't') {
				str.append(1u, '\t');
			} else if(p[i+1] == 'v') {
				str.append(1u, '\v');
			} else if(p[i+1] == 'f') {
				str.append(1u, '\f');
			} else if(p[i+1] == 'r') {
				str.append(1u, '\r');
			} else if(p[i+1] == 'a') {
				str.append(1u, '\a');
			} else if(p[i+1] == 'b') {
				str.append(1u, '\b');
			} else if(p[i+1] == '0') {
				str.append(1u, '\0');
			} else if(p[i+1] == '\'') {
				str.append(1u, '\'');
			} else if(p[i+1] == '\\') {
				if(p[i+2] == '\n') {
					if(p[i+3] == 'n') {
						str.append(1u, '\n');
					} else if(p[i+3] == 't') {
						str.append(1u, '\t');
					} else if(p[i+3] == 'v') {
						str.append(1u, '\v');
					} else if(p[i+3] == 'f') {
						str.append(1u, '\f');
					} else if(p[i+3] == 'r') {
						str.append(1u, '\r');
					} else if(p[i+3] == 'a') {
						str.append(1u, '\a');
					} else if(p[i+3] == 'b') {
						str.append(1u, '\b');
					} else if(p[i+3] == '0') {
						str.append(1u, '\0');
					} else if(p[i+3] == '\\') {
						str.append(1u, '\\');
					} else if(p[i+3] == '\"') {
						str.append(1u, '\"');
					} else if(p[i+3] == '\'') {
						str.append(1u, '\'');
					} else if(p[i+3] == '?') {
						str.append(1u, '\?');
					} else if(p[i+3] == 'e') {
						str.append(1u, '\e');
					} else {
						str.append(1u, p[i+3]);
					}
					
					i+=4;
					line_no++;
					continue;
				} else {
					str.append(1u, '\\');
				}
			} else if(p[i+1] == '\"') {
				str.append(1u, '\"');
			}  else if(p[i+1] == '?') {
				str.append(1u, '\?');
			} else if(p[i+1] == 'e') {
				str.append(1u, '\e');
			} else if(p[i+1] == '\n') {
				line_no++;
			
			
			
			} else {
				str.append(1u, p[i+1]);  
			}
			
				i+=2;
			

		}
	}
	
	return str;
}

char lexemeToChar(const char* p) {



	if(p[1] != '\\') {
		return p[1];
	}
	
	if(p[1] == '\\') {
	
		if(p[2] == 'n') {
			return (char) 10;
		} else if(p[2] == 't') {
			return (char) 9;
		} else if(p[2] == 'v') {
			return (char) 11;
		} else if(p[2] == 'f') {
			return (char) 12;
		} else if(p[2] == 'r') {
			return (char) 13;
		} else if(p[2] == 'a') {
			return (char) 7;
		} else if(p[2] == 'b') {
			return (char) 8;
		} else if(p[2] == '0') {
			return (char) 0;
		} else if(p[2] == '\\') {
			return (char) 92;
		} else if(p[2] == '\"') {
			return (char) 34;
		} else if(p[2] == '\'') {
			return (char) 39;
		}  else if(p[2] == 'e') {
			return (char) 27;
		} else {
			return p[2];
		}
	}
}

void countNewLine(const char* p) {
	
	int len = strlen(p);

	
	
	for(int i=0; i<len; i++) {

		if(p[i] == '\n') {
			line_no++;
		
		}
	}
	
	return ;
}

string makeUpperCase(string str)
{
	for(auto &ch:str) {
		
		ch = toupper(ch);

		}

	return str;
}

%}

NEWLINE (\r\n|\r|\n)
WHITESPACE [ \t\f\r\v]+ 
ALPHANUM [a-z_A-Z0-9]
LETTER [a-z_A-Z]
DIGIT [0-9]
DIGITS {DIGIT}+
CHAR_CONST (\\[^\r\n\f\r\v\t\e\a]|[^\\'\r\n])

CHARACTER ('{CHAR_CONST}')
UNFINISHED_CHAR ('{CHAR_CONST}*) 


%%

{WHITESPACE} { }
{NEWLINE} {


	line_no++;

	
}


"if" {return IF;}
"else" {return ELSE;}
"for" {return FOR;}
"while" {return WHILE;}
"do" {return DO;}
"break" {return BREAK;}
"int" { SymbolInfo *s= new  SymbolInfo(yytext, "INT"); yylval.symbol_info=s; return INT;}
"char" {return CHAR;}
"float" { SymbolInfo *s= new  SymbolInfo(yytext, "FLOAT"); yylval.symbol_info = s; return FLOAT;} 
"double" {return DOUBLE;}
"void" { SymbolInfo *s= new  SymbolInfo(yytext, "VOID"); yylval.symbol_info = s; return VOID;}
"return" {return RETURN;}
"switch" {return SWITCH;}
"case" {return CASE;}
"default" {return DEFAULT;}
"continue" {return CONTINUE;}
"printf"	{return PRINTLN;}


{DIGIT}+ {
SymbolInfo *si=new SymbolInfo(yytext,"CONST_INT");
yylval.symbol_info = si;
return CONST_INT;

}

(\.{DIGIT}+|{DIGIT}+(\.{DIGIT}+)?)([Ee][+-]?{DIGIT}+)? {
	        
	 SymbolInfo *si=new SymbolInfo(yytext,"CONST_FLOAT");

	yylval.symbol_info = si;
	return CONST_FLOAT;
	
}

{CHARACTER} {

	char ch=lexemeToChar(yytext);

	SymbolInfo *s= new  SymbolInfo(yytext, "CONST_CHAR"); 
	yylval.symbol_info = s; 
		


	 return CONST_CHAR;
}

			
"+"|"-"	{
	 	SymbolInfo *s= new  SymbolInfo(yytext, "ADDOP"); yylval.symbol_info = s; return ADDOP;
		
		}
"*"|"/"|"%"	{
			SymbolInfo *s= new  SymbolInfo(yytext, "MULOP"); yylval.symbol_info = s; return MULOP;
		
		}
"++"	{
			return INCOP;
		}
"--" {
		return DECOP;	
}
"<"|"<="|">"|">="|"=="|"!="	{
			SymbolInfo *s= new  SymbolInfo(yytext, "RELOP"); yylval.symbol_info = s; return RELOP;
		}
"="	{
			return ASSIGNOP;
		}
"&&"|"||"	{

	SymbolInfo *s= new  SymbolInfo(yytext, "LOGICOP"); yylval.symbol_info = s; return LOGICOP;
			
		}
"&"|"|"|"^"|"<<"|">>"	{
			 SymbolInfo *s= new  SymbolInfo(yytext, "BITOP"); yylval.symbol_info = s; return BITOP;
			
		}
"!"	{
		return NOT;
	}
"("	{
		return LPAREN;
	}
")"	{
		return RPAREN;
	}
"{"	{
		return LCURL;
	}
"}"	{
		return RCURL;
	}
"["	{
		return LTHIRD;
	}
"]"	{
		return RTHIRD;
	}
","	{
		return COMMA;
	}
";"	{
	   	return SEMICOLON;
	}
{LETTER}{ALPHANUM}* {
	 	SymbolInfo *s= new  SymbolInfo(yytext, "ID");
		yylval.symbol_info = s;
		return ID;
}

\"([^\"\r\n]|[\\]([a]|[^a]))*\" {



		logoutput << "Line no " << line_no << ": Token <STRING> Lexeme " << yytext << " found --> <String, " ;
		
		string s=createDesiredString(yytext);
		s=s.substr(1);
		s=s.substr(0,s.length()-1);	
		logoutput<<s << "> "<< endl;
       SymbolInfo *si= new  SymbolInfo(s, "STRING");
		yylval.symbol_info = si;
		return STRING;

}




\/\/([^\r\n]*([\\][\r\n])?[^\r\n]*)*	{
				  
				   logoutput << "Line no " << line_no << ": Token <COMMENT> Lexeme " << yytext << " found" << endl;
				   countNewLine(yytext);
				}


\/\*([^\*]|([\*]+[^\/]))*[\*]*\*\/ {

	logoutput << "Line no " << line_no << ": Token <COMMENT> Lexeme "  << yytext  << " found" << endl;
			countNewLine(yytext);


}

({DIGIT}*[\.][\.]+{DIGIT}*|({DIGIT}*[\.]{DIGIT}*){2,})+([Ee][+-]?{DIGIT}+)? {
	logoutput << "Error at line " << line_no << ": Too many decimal point " << yytext << endl;
	erroroutput << "Error at line " << line_no << ": Too many decimal point " << yytext << endl;
	
	error_count++;
	SymbolInfo *s= new  SymbolInfo("0", "ERROR_FLOAT");
	yylval.symbol_info = s;
	return ERROR_FLOAT;
}
({DIGIT}*[\.]*{DIGIT}*)*([Ee][\.]+[+-]?{DIGIT}*|[Ee][+-]?({DIGIT}*[\.]{DIGIT}*)*) {
	logoutput<<"Error at line no "<< line_no <<": Ill formed number "<<yytext<<"\n"<<endl;
	erroroutput<<"Error at line no "<< line_no <<": Ill formed number "<<yytext<<"\n"<<endl;
	
	error_count++;
	SymbolInfo *s= new  SymbolInfo("0", "ERROR_FLOAT");
	yylval.symbol_info = s;
	return ERROR_FLOAT;


}





{DIGITS}{LETTER}{ALPHANUM}* {
					logoutput << "Error at line " << line_no << ": Invalid prefix on ID or invalid suffix on Number " << yytext << endl;
				erroroutput << "Error at line " << line_no << ": Invalid prefix on ID or invalid suffix on Number " << yytext << endl;
				
					error_count++;
					SymbolInfo *s= new  SymbolInfo(yytext, "ID");
	                yylval.symbol_info = s;
	                return ID;
					
				}
'{CHAR_CONST}{2,}' {

logoutput<< "Error at line " << line_no << ": Multi character constant error " << yytext << endl;

erroroutput<< "Error at line " << line_no << ": Multi character constant error " << yytext << endl;
		
		error_count++;
		SymbolInfo *s= new  SymbolInfo("\0", "CONST_CHAR");
	    yylval.symbol_info = s;
		return CONST_CHAR;

}
{UNFINISHED_CHAR} {

logoutput<< "Error at line " << line_no << ": Unfinished character error " << yytext << endl;
erroroutput<< "Error at line " << line_no << ": Unfinished character error " << yytext << endl;
			
	error_count++;	
	SymbolInfo *s= new SymbolInfo("\0", "CONST_CHAR");
	yylval.symbol_info = s;
	return CONST_CHAR;

}
\"([^\"\r\n]|[\\]([\r\n]|[^\r\n]))* {

logoutput<< "Error at line " << line_no << ": Unfinished string error " << yytext << endl;
erroroutput<< "Error at line " << line_no << ": Unfinished string error " << yytext << endl;
createDesiredString(yytext);
error_count++;	


}
'' {
logoutput<< "Error at line " << line_no << ":Empty character constant error " << yytext << endl;
erroroutput<< "Error at line " << line_no << ":Empty character constant error " << yytext << endl;
error_count++;	
SymbolInfo *s= new SymbolInfo("\0", "CONST_CHAR");
yylval.symbol_info = s;
return CONST_CHAR;

}
\/\*([^\*]|([\*]+[^*/]))*[\*]* {

logoutput<< "Error at line " << line_no << ": Unfinished comment error " << yytext << endl;
erroroutput<< "Error at line " << line_no << ": Unfinished comment error " << yytext << endl;
		
		countNewLine(yytext);	

		error_count++;		
}


. {

	logoutput<<"Error at line no "<< line_no <<": Unrecognized character "<<yytext<<"\n"<<endl;
erroroutput<<"Error at line no "<< line_no <<": Unrecognized character "<<yytext<<"\n"<<endl;

error_count++;
}

%%

