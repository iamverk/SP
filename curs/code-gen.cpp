//for k13
#include "code-gen.h"
using namespace std;

int tCG::p01(){ // S -> PROG
  string header ="/*  " + lex.Authentication()+"   */\n";
  header += "#include \"mlisp.h\"\n";
  
  header += declarations;
  header += "//________________ \n";
  S1->obj = header + S1->obj;
	return 0;}


int tCG::p02(){ //   PROG -> CALCS
	S1->obj = "int main(){\n" + S1->obj
    + " std::cin.get();\n return 0;\n}\n";
	return 0;}

int tCG::p03(){ //   PROG -> DEFS
	S1->obj += "int main(){\n"
    " display(\"No calculations!\");newline();\n"
    " std::cin.get();\n return 0;\n}\n";
	return 0;}

int tCG::p04(){ //   PROG -> DEFS CALCS
	S1->obj += "int main(){\n" + S2->obj
    + " std::cin.get();\n return 0;\n}\n";
	return 0;}

//E -> $id
int tCG::p05(){ 
	S1->obj = decor(S1->name);
	return 0;}

//E -> $int
int tCG::p06(){ 
	S1->obj = S1->name + ".";
	return 0;}
// E -> $dec
int tCG::p07(){ 
    S1->obj = S1->name;
	return 0;}
//E -> ADD
int tCG::p08(){ 
	return 0;}
//E -> SUB
int tCG::p09(){ 
	return 0;}
// E -> DIV
int tCG::p10(){      
	return 0;}
//E -> MUL
int tCG::p11(){       
	return 0;}
//E -> COND
int tCG::p12(){       
	return 0;}

//E -> EASYLET

int tCG::p13(){       
	return 0;}

//E -> CPROC
int tCG::p14(){ 
	return 0;}


//ADD -> HADD E )
int tCG::p15(){ 
 if(S1->count==0)
    S1->obj = S2->obj;
 else            
    S1->obj += S2->obj + ")";
 S1->count =0;
	return 0;}

//HADD -> ( +
int tCG::p16(){ 
	S1->obj = "(";
	return 0;}

//HADD -> HADD E
int tCG::p17(){ 
 S1->obj += S2->obj + " + ";
 ++S1->count;
	return 0;}

//SUB -> ( - E )
int tCG::p18(){ 
    S1->obj = "( -" + S3->obj + " )";
	return 0;}


//DIV -> ( / E )
int tCG::p19(){ 
	S1->obj = "(1 / " + S3->obj + " )";
	return 0;}

//MUL -> HMUL E )
int tCG::p20(){ 
    S1->obj += " * " + S2->obj + ")";
    return 0;}

//HMUL -> ( *
int tCG::p21(){ 
	  S1->obj = "(";
    S1->count = 0;
    return 0;}


//HMUL -> HMUL E
int tCG::p22(){ 
	if (S1->count != 0)
    {
        S1->obj += " * ";
    }
    S1->obj += S2->obj;
    S1->count++;
    return 0;
}

//COND -> HCOND CLAUS )
int tCG::p23(){
    S1->obj = S1->obj + S2->obj + ": _infinity" ")))";
	return 0;}

//HCOND -> ( cond CLAUS
int tCG::p24(){  
	S1->obj = "(" + S3->obj + " : ";
	return 0;}


//CLAUS -> ( BOOL E )
int tCG::p25(){ 
	S1->obj = "(" + S2->obj + " ? " + S3->obj;
	return 0;}


//EASYLET -> HEASYL E )
int tCG::p26(){ 
   if (S1->count != 0)
        S1->obj += S2->obj + ";\n";
    S1->obj += S2->obj;
    ++(S1->count);
    return 0;}


// HEASYL -> ( let ( )
int tCG::p27(){ 
	//S1->obj += "(";
	return 0;}

// HEASYL -> HEASYL INTER
int tCG::p28(){ 
	S1->obj += S2->obj + ", ";
	return 0;}

//STR -> $str	
int tCG::p29(){ 
	 S1->obj = decor(S1->name);
	return 0;}
	
//STR -> SIF	
int tCG::p30(){ 
	return 0;}

//SIF -> ( if BOOL STR STR )	
int tCG::p31(){ 
	S1->obj = S3->obj  + " ? " + S4->obj + " : " + S5->obj; //+ " : ";
	return 0;}

//CPROC -> HCPROC )
int tCG::p32(){ 
    S1->obj += ")";
	return 0;}

//HCPROC -> ( $id	
int tCG::p33(){ 
    S1->count = 0;
    S1->obj = decor(S2->name) + "(";
    return 0;}

//HCPROC -> HCPROC E
int tCG::p34(){ 
    if(S1->count) {
        S1->obj += ", ";
    }
    S1->obj += S2->obj;
    ++S1->count;
	return 0;}

//BOOL -> $bool	
int tCG::p35(){ 
	if (S1->name == "#t") {
        S1->obj = "true";
    } else if (S1->name == "#f") {
        S1->obj = "false";
    }
    return 0;}

//BOOL -> $idq    
int tCG::p36(){ 
	S1->obj = decor(S1->name);
	return 0;}

//BOOL -> REL	
int tCG::p37(){ 
	 S1->obj =  S1->obj ;
	return 0;}

//BOOL -> OR
int tCG::p38(){ 
	return 0;}

//BOOL -> CPRED
int tCG::p39(){ 
	return 0;}

//CPRED -> HCPRED )	
int tCG::p40(){ 
	S1->obj += ")";
	return 0;}

//HCPRED -> ( $idq	
int tCG::p41(){ 
	S1->obj = decor(S2->name) + "(";
	return 0;}

//HCPRED -> HCPRED ARG	
int tCG::p42(){ 
	if(S1->count) {
        S1->obj += ", ";
    }
    S1->obj += S2->obj;
    ++S1->count;
	return 0;}

//ARG -> E	
int tCG::p43(){ 
	return 0;}

//ARG -> BOOL	
int tCG::p44(){ 
	return 0;}

//REL -> ( = E E )	
int tCG::p45(){ 
	S1->obj = S3->obj + " == " + S4->obj;
	return 0;}

//REL -> ( < E E )	
int tCG::p46(){
	S1->obj = S3->obj + " < " + S4->obj;
	return 0;}

//OR -> HOR BOOL )
int tCG::p47() { 
    S1->obj += S2->obj + ")";
    return 0;}

//HOR -> ( or
int tCG::p48() { 
    S1->obj = "(";
    return 0;}

//HOR -> HOR BOOL
int tCG::p49() { 
    S1->obj += S2->obj + " || ";
    //++S1->count;
    return 0;}

//SET -> HSET E )
int tCG::p50(){ 
    S1->obj += S2->obj; 
	return 0;}

//HSET -> ( set! $id	
int tCG::p51(){ 
    S1->obj = decor(S3->name) + " = ";
    S1->name = S3->name;
	return 0;}

//DISPSET -> ( display E )	
int tCG::p52(){ 
	S1->obj = "display(" + S3->obj + ")";
	return 0;}
//DISPSET -> ( display BOOL )
int tCG::p53(){ 
	S1->obj = "display(" + S3->obj + ")";
	return 0;}
//DISPSET -> ( display STR )
int tCG::p54(){ 
	S1->obj = "display(" + S3->obj + ")";
	return 0;}
//DISPSET -> ( newline )	
int tCG::p55(){ 
	S1->obj = "newline()";
	return 0;}
//DISPSET -> SET
int tCG::p56(){ 
	return 0;}
//INTER -> DISPSET
int tCG::p57(){ 
	return 0;}
//INTER -> E
int tCG::p58(){ 
	return 0;}
//CALCS -> CALC
int tCG::p59(){ 
	return 0;}

//CALCS -> CALCS CALC	
int tCG::p60(){ 
 S1->obj += S2->obj;
	return 0;}

//CALC -> E	
int tCG::p61(){ 
S1->obj = "display(" + S1->obj + "); newline();\n\t";
	return 0;}

//   CALC -> BOOL	
int tCG::p62(){ 
	S1->obj = "display(" + S1->obj + "); newline();\n\t";
	return 0;}

//CALC -> STR	
int tCG::p63(){ 
	S1->obj = "display(" + S1->obj + "); newline();\n\t";
	return 0;}

//CALC -> DISPSET	
int tCG::p64(){ 
    S1->obj += ";\n\t";
	return 0;}

//DEFS -> DEF
int tCG::p65(){ 
	return 0;}
//DEFS -> DEFS DEF

int tCG::p66(){ 
	S1->obj += S2->obj;
	return 0;}
//DEF -> PRED
int tCG::p67(){ 
	return 0;}
//DEF -> VAR
int tCG::p68(){ 
	return 0;}
//DEF -> PROC
int tCG::p69(){ 
	return 0;}

//PRED -> HPRED BOOL )
int tCG::p70(){ 
    S1->obj += "return " + S2->obj + ";\n}\n";
	return 0;}

//HPRED -> PDPAR )
int tCG::p71(){ 
    S1->obj += ")";
    declarations += S1->obj + ";\n";
    S1->obj += "{\n";
	return 0;}

//PDPAR -> ( define ( $idq
int tCG::p72(){ 
    S1->obj = "bool " + decor(S4->name) + "(";
	S1->count = 0;
	S1->name = S4->name;
	return 0;}

//PDPAR -> PDPAR $idq
int tCG::p73(){ 
    if (S1->count) 
        S1->obj += ", ";
    S1->obj += "bool ";
    S1->obj += decor(S2->name);
    ++(S1->count);
	return 0;}

//PDPAR -> PDPAR $id
int tCG::p74(){ 
    if(S1->count) S1->obj += ", ";
	S1->obj += "double " + decor(S2->name);
	S1->count++;
	return 0;}

//VAR -> VARDCL E )
int tCG::p75(){ 
   S1->obj += " = " + S2->obj + ";\n";
    declarations += S1->obj;
    S1->obj = "";
    return 0;}

//VARDCL -> ( define $id
int tCG::p76(){ 
   S1->obj += "double " + decor(S3->name) + "  ";
	return 0;}

//PROC -> HPROC BLOCK ) 
int tCG::p77(){ 
	if (S1->count == 0)
    {
        S1->obj += "{\n";
    }
    S1->obj = S1->obj + S2->obj + "\n}\n";
    return 0;}

//PROC -> HPROC E ) 
int tCG::p78(){ 
	if (S1->count == 0)
    {
        S1->obj += "\n";
    }
    S1->obj += "return " + S2->obj + ";\n}\n";
    return 0;}

//HPROC -> PCPAR ) 
int tCG::p79(){ 
	S1->obj += ")";
 	declarations += S1->obj + ";\n";
 	S1->obj += "{\n";
	return 0;}

//HPROC -> HPROC INTER
int tCG::p80(){  
   if (S1->count == 0)
    {
        S1->obj += "{\n";
    }
    S1->obj += S2->obj + ";\n";
    S1->count++;
    return 0;}

//PCPAR -> ( define ( $id
int tCG::p81(){    
	S1->obj = "double " + decor(S4->name) + "(";
 	S1->count = 0;
 	S1->name = S4->name;
	return 0;}

//PCPAR -> PCPAR $id
int tCG::p82(){      
	if(S1->count)
		S1->obj += ", ";
 	S1->obj += "double " + decor(S2->name);
 	++(S1->count);
	return 0;}

//BLOCK -> HBLOCK E ) 
int tCG::p83(){ 
   S1->obj = "{\n" + S1->obj + "return " + S2->obj + ";\n}\n";
	return 0;}

//HBLOCK -> BLVAR )
int tCG::p84(){  
	
	return 0;}

//HBLOCK -> HBLOCK INTER
int tCG::p85(){   
	S1->obj += S2->obj + ";\n";
	return 0;}

//BLVAR -> ( let ( LOCDEF
int tCG::p86(){   
	S1->obj += S4->obj;
	return 0;}

//BLVAR -> BLVAR LOCDEF
int tCG::p87(){   
	
	S1->obj +=  S2->obj + "\n";
	return 0;}

//LOCDEF -> ( $id E )
int tCG::p88(){   
    S1->obj = "double " + decor(S2->name) + " = " + S3->obj + ";\n";
	return 0;}

int tCG::p89(){return 0;} 
int tCG::p90(){return 0;} int tCG::p91(){return 0;} 
int tCG::p92(){return 0;} int tCG::p93(){return 0;} 
int tCG::p94(){return 0;} int tCG::p95(){return 0;} 
int tCG::p96(){return 0;} int tCG::p97(){return 0;} 
int tCG::p98(){return 0;} int tCG::p99(){return 0;} 
int tCG::p100(){return 0;} int tCG::p101(){return 0;} 
int tCG::p102(){return 0;} int tCG::p103(){return 0;} 
int tCG::p104(){return 0;} int tCG::p105(){return 0;} 
int tCG::p106(){return 0;} int tCG::p107(){return 0;} 
int tCG::p108(){return 0;} int tCG::p109(){return 0;} 
int tCG::p110(){return 0;} 

