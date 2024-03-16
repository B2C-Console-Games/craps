/*
 * Title: The annotated BASIC Listing
 *
 *  Listing of /home/alan/dev/BasicGames/source/base/craps/basic/craps.bas: 
 *
                   ++---- Routine IDs (Empty field=Inaccessible code, A=Main program).
                   || +-- Target status (G-GOSUB, T-GOTO, B-Both GOSUB and GOTO)
        Program    || |
        Address    vv v Original BASIC statement
    -------------- -- - ------------------------------------------------------------------------------
    0x55f5aea37d10 ---------A   01000 REM THIS PROGRAM SIMULATES THE GAME OF CRAPS
    0x55f5aea37de0 ---------A   01010 RANDOMIZE
    0x55f5aea37f30 ---------A T 01020 PRINT"FOR RULES, TYPE 'RULES', OTHERWISE TYPE 'GO'"
    0x55f5aea380a0 ---------A   01030 INPUT R$
    0x55f5aea38290 ---------A   01040 IF R$="RULES" THEN 1080
    0x55f5aea384a0 ---------A   01050 IF R$="GO" THEN 1130
    0x55f5aea385e0 ---------A   01060 PRINT"INVALID COMMAND"
    0x55f5aea38670 ---------A   01070 GOTO 1020
    0x55f5aea387c0 ---------A T 01080 PRINT"A 7 OR 11 ON THE FIRST THROW WINS"
    0x55f5aea382f0 ---------A   01090 PRINT"YOU CAN ALSO WIN BY THROWING A 4,5,6,8,9,10"
    0x55f5aea38ae0 ---------A   01100 PRINT"AND MATCHING IT BEFORE THROWING A 7, IF ON"
    0x55f5aea3ceb0 ---------A   01110 PRINT"THE FIRST THROW A 2,3, OR A 12 COMES UP"
    0x55f5aea3cfc0 ---------A   01120 PRINT"YOU LOSE AUTOMATICALLY"
    0x55f5aea3d1b0 ---------A T 01130 LET J=0
    0x55f5aea3d220 ---------A T 01140 GOSUB 1480
    0x55f5aea3d440 ---------A   01150 LET D1=N
    0x55f5aea3d4b0 ---------A   01160 GOSUB 1480
    0x55f5aea3d760 ---------A   01170 LET D2=N
    0x55f5aea3d9b0 ---------A   01180 LET D3=D1+D2
    0x55f5aea3dbc0 ---------A   01190 LET J=J+1
    0x55f5aea3dd70 ---------A   01200 IF J=1 THEN 1250
    0x55f5aea3df70 ---------A   01210 IF D3=D4 THEN 1440
    0x55f5aea3e140 ---------A   01220 IF D3=7 THEN 1460
    0x55f5aea3e300 ---------A T 01230 PRINT"YOU THROW A ";D3
    0x55f5aea3e370 ---------A   01240 GOTO 1140
    0x55f5aea3e510 ---------A T 01250 IF D3=7 THEN 1320
    0x55f5aea3e6d0 ---------A   01260 IF D3=2 THEN 1340
    0x55f5aea3e890 ---------A   01270 IF D3=3 THEN 1340
    0x55f5aea3ea50 ---------A   01280 IF D3=12 THEN 1340
    0x55f5aea3ec10 ---------A   01290 IF D3=11 THEN 1320
    0x55f5aea3ed50 ---------A   01300 LET D4=D3
    0x55f5aea3edd0 ---------A   01310 GOTO 1230
    0x55f5aea3f050 ---------A T 01320 PRINT"YOU THROW A ";D3;" YOU WIN"
    0x55f5aea3f2e0 ---------A   01330 GOTO 1350
    0x55f5aea3f560 ---------A T 01340 PRINT"YOU THROW A ";D3;" YOU LOSE"
    0x55f5aea3f5f0 ---------A T 01350 PRINT
    0x55f5aea3f730 ---------A   01360 PRINT"TO CONTINUE TYPE 'Y', IF NOT TYPE'N'"
    0x55f5aea3f890 ---------A   01370 INPUT L$
    0x55f5aea3fa80 ---------A   01380 IF L$="Y" THEN 1420
    0x55f5aea3fc80 ---------A   01390 IF L$="N" THEN 1400
    0x55f5aea3fde0 ---------A T 01400 PRINT"WHAT? QUITTING ALREADY, CRAP OUT DID YOU?"
    0x55f5aea3fe30 ---------A   01410 STOP
    0x55f5aea3feb0 ---------A T 01420 PRINT
    0x55f5aea3ff40 ---------A   01430 GOTO 1130
    0x55f5aea401c0 ---------A T 01440 PRINT"YOU THROW A ";D3;" YOU WIN BY MATCHING"
    0x55f5aea40250 ---------A   01450 GOTO 1350
    0x55f5aea404d0 ---------A T 01460 PRINT"YOU THROW A ";D3;" SORRY, YOU LOSE"
    0x55f5aea40540 ---------A   01470 GOTO 1350
    0x55f5aea40980 ---------B G 01480 LET N=1+INT(6*RND)
    0x55f5aea409d0 ---------B   01490 RETURN
    0x55f5aea40a30 ---------A   01500 END
 */

/*
 * Line reference table:
 *

    Target
   Line Num.    Referencing line number (Reference is T-GOTO or G-GOSUB).
   ---------    -------------------------------------------------------------------
     01020      01070T
     01080      01040T
     01130      01050T, 01430T
     01140      01240T
     01230      01310T
     01250      01200T
     01320      01250T, 01290T
     01340      01260T, 01270T, 01280T
     01350      01330T, 01450T, 01470T
     01400      01390T
     01420      01380T
     01440      01210T
     01460      01220T
     01480      01140G, 01160G

 */

/* 
 * Routine Start, Target, Return and End Program Addresses 
 * 

  Rtn      Start           Target           Return             End    
  --- --------------   --------------   --------------   -------------- 
   A) 0x55f5aea37d10   0x55f5aea37d10   0x55f5aea40a30   0x55f5aea40a30 
   B) 0x55f5aea40980   0x55f5aea40980   0x55f5aea409d0   0x55f5aea409d0 

    NOTE: Routine B overlaps, or is tangled with, routine A!

 */



/*
 * Free line number map.
 *
     Start    End    # Lines in Gap
     -----   -----   ------------------
     00000 - 00990     100 
     01510 - 10000    8500 

 */



/*
 *  Symbol Table Listing for '/home/alan/dev/BasicGames/source/base/craps/basic/craps.bas'
 *
    D1             Integer 
    D2             Integer 
    D3             Integer 
    D4             Integer 
    INT   Function Integer     args=1, float 
    J              Integer 
    L$             String  
    N              Integer 
    R$             String  
    RND   Function Integer     args=1, int   

 */


/*
 * Title: Display of final 'clean' BASIC listing.
 *
 *  Listing of /home/alan/dev/BasicGames/source/base/craps/basic/craps.bas: 
 *
                   ++---- Routine IDs (Empty field=Inaccessible code, A=Main program).
                   || +-- Target status (G-GOSUB, T-GOTO, B-Both GOSUB and GOTO)
        Program    || |
        Address    vv v Original BASIC statement
    -------------- -- - ------------------------------------------------------------------------------
    0x55f5aea37d10 ---------A   01000 REM THIS PROGRAM SIMULATES THE GAME OF CRAPS
    0x55f5aea37de0 ---------A   01010 RANDOMIZE
    0x55f5aea37f30 ---------A T 01020 PRINT"FOR RULES, TYPE 'RULES', OTHERWISE TYPE 'GO'"
    0x55f5aea380a0 ---------A   01030 INPUT R$
    0x55f5aea38290 ---------A   01040 IF R$="RULES" THEN 1080
    0x55f5aea384a0 ---------A   01050 IF R$="GO" THEN 1130
    0x55f5aea385e0 ---------A   01060 PRINT"INVALID COMMAND"
    0x55f5aea38670 ---------A   01070 GOTO 1020
    0x55f5aea387c0 ---------A T 01080 PRINT"A 7 OR 11 ON THE FIRST THROW WINS"
    0x55f5aea382f0 ---------A   01090 PRINT"YOU CAN ALSO WIN BY THROWING A 4,5,6,8,9,10"
    0x55f5aea38ae0 ---------A   01100 PRINT"AND MATCHING IT BEFORE THROWING A 7, IF ON"
    0x55f5aea3ceb0 ---------A   01110 PRINT"THE FIRST THROW A 2,3, OR A 12 COMES UP"
    0x55f5aea3cfc0 ---------A   01120 PRINT"YOU LOSE AUTOMATICALLY"
    0x55f5aea3d1b0 ---------A T 01130 LET J=0
    0x55f5aea3d220 ---------A T 01140 GOSUB 1490
    0x55f5aea3d440 ---------A   01150 LET D1=N
    0x55f5aea3d4b0 ---------A   01160 GOSUB 1490
    0x55f5aea3d760 ---------A   01170 LET D2=N
    0x55f5aea3d9b0 ---------A   01180 LET D3=D1+D2
    0x55f5aea3dbc0 ---------A   01190 LET J=J+1
    0x55f5aea3dd70 ---------A   01200 IF J=1 THEN 1250
    0x55f5aea3df70 ---------A   01210 IF D3=D4 THEN 1440
    0x55f5aea3e140 ---------A   01220 IF D3=7 THEN 1460
    0x55f5aea3e300 ---------A T 01230 PRINT"YOU THROW A ";D3
    0x55f5aea3e370 ---------A   01240 GOTO 1140
    0x55f5aea3e510 ---------A T 01250 IF D3=7 THEN 1320
    0x55f5aea3e6d0 ---------A   01260 IF D3=2 THEN 1340
    0x55f5aea3e890 ---------A   01270 IF D3=3 THEN 1340
    0x55f5aea3ea50 ---------A   01280 IF D3=12 THEN 1340
    0x55f5aea3ec10 ---------A   01290 IF D3=11 THEN 1320
    0x55f5aea3ed50 ---------A   01300 LET D4=D3
    0x55f5aea3edd0 ---------A   01310 GOTO 1230
    0x55f5aea3f050 ---------A T 01320 PRINT"YOU THROW A ";D3;" YOU WIN"
    0x55f5aea3f2e0 ---------A   01330 GOTO 1350
    0x55f5aea3f560 ---------A T 01340 PRINT"YOU THROW A ";D3;" YOU LOSE"
    0x55f5aea3f5f0 ---------A T 01350 PRINT
    0x55f5aea3f730 ---------A   01360 PRINT"TO CONTINUE TYPE 'Y', IF NOT TYPE'N'"
    0x55f5aea3f890 ---------A   01370 INPUT L$
    0x55f5aea3fa80 ---------A   01380 IF L$="Y" THEN 1420
    0x55f5aea3fc80 ---------A   01390 IF L$="N" THEN 1400
    0x55f5aea3fde0 ---------A T 01400 PRINT"WHAT? QUITTING ALREADY, CRAP OUT DID YOU?"
    0x55f5aea3fe30 ---------A   01410 STOP
    0x55f5aea3feb0 ---------A T 01420 PRINT
    0x55f5aea3ff40 ---------A   01430 GOTO 1130
    0x55f5aea401c0 ---------A T 01440 PRINT"YOU THROW A ";D3;" YOU WIN BY MATCHING"
    0x55f5aea40250 ---------A   01450 GOTO 1350
    0x55f5aea404d0 ---------A T 01460 PRINT"YOU THROW A ";D3;" SORRY, YOU LOSE"
    0x55f5aea40540 ---------A   01470 GOTO 1350
    0x55f5aea40a30 ---------A   01480 END
    0x55f5aea40980 ---------B G 01490 LET N=1+INT(6*RND)
    0x55f5aea409d0 ---------B   01500 RETURN
 */

//---------------------------------------------------------------------------
// $Header$ 
//
// NOTE: This program has been automatically tranlated by b2c
//
// $Log$ 
// 
//---------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
//---------------------------------------------------------------------------
// Global data area.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------




typedef enum {TYPE_None,TYPE_Integer,TYPE_Float,TYPE_String}t_type;
typedef struct{
    int    LineNum;
    int    Size;
    char** SData;
}t_data;
t_data ProgramData[] = {
    {    0,  0,nullptr       }
};

#include "intrinsics.h"


//---------------------------------------------------------------------------
// Global variable area.
//
// NOTE: Variable names are long to allow for easy editing.
//---------------------------------------------------------------------------
int   D1_int;       // Comments?
int   D2_int;       // Comments?
int   D3_int;       // Comments?
int   D4_int;       // Comments?
int   J_int;        // Comments?
char* L_str;        // Comments?
int   N_int;        // Comments?
char* R_str;        // Comments?
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
char* GLBpStr=nullptr;
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// Subroutine Prototypes.
//---------------------------------------------------------------------------
void Routine_01490();

//---------------------------------------------------------------------------
// Program Functions.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// Program Subroutines.
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// Routine B
//---------------------------------------------------------------------------

void Routine_01490(){
    // 01490 LET N=1+INT(6*RND)
    N_int = 1+INT(6*RND());
    // 01500 RETURN
    return;
};

//---------------------------------------------------------------------------
// Main Program.
//---------------------------------------------------------------------------
#pragma argsused
int main(int argc,char *argv[])
{
    // 01000 REM THIS PROGRAM SIMULATES THE GAME OF CRAPS
    // 01010 RANDOMIZE
    RANDOMIZE();

  Lbl_01020:
    // 01020 PRINT"FOR RULES, TYPE 'RULES', OTHERWISE TYPE 'GO'"
    b2c_fprintf(stdout,"FOR RULES, TYPE 'RULES', OTHERWISE TYPE 'GO'"); b2c_fprintf(stdout,"\n");
    // 01030 INPUT R$
    // Start of Basic INPUT statement 01030
    printf(" ? ");
    char inpbuf_01030[100];
    if(fgets(inpbuf_01030,100,stdin)==nullptr){
        fprintf(stderr,"ERROR: End of file on input.\n");
        exit(2);
    }else{
        char *ps_01030=strtok(inpbuf_01030," ,\t\n");
        // This may cause problems if BASIC programmer expected
        // input strings to be copied instead of just pointing
        // to the input buffer (ie. strings can be over written).
        if(ps_01030==nullptr){
            R_str = "";
        }else{
            R_str = ps_01030;
        };
    }; // End of Basic INPUT statement 01030
    // 01040 IF R$="RULES" THEN 1080
    if(strcmp(R_str,"RULES")==0)goto Lbl_01080;
    // 01050 IF R$="GO" THEN 1130
    if(strcmp(R_str,"GO")==0)goto Lbl_01130;
    // 01060 PRINT"INVALID COMMAND"
    b2c_fprintf(stdout,"INVALID COMMAND"); b2c_fprintf(stdout,"\n");
    // 01070 GOTO 1020
    goto Lbl_01020;

  Lbl_01080:
    // 01080 PRINT"A 7 OR 11 ON THE FIRST THROW WINS"
    b2c_fprintf(stdout,"A 7 OR 11 ON THE FIRST THROW WINS"); b2c_fprintf(stdout,"\n");
    // 01090 PRINT"YOU CAN ALSO WIN BY THROWING A 4,5,6,8,9,10"
    b2c_fprintf(stdout,"YOU CAN ALSO WIN BY THROWING A 4,5,6,8,9,10"); b2c_fprintf(stdout,"\n");
    // 01100 PRINT"AND MATCHING IT BEFORE THROWING A 7, IF ON"
    b2c_fprintf(stdout,"AND MATCHING IT BEFORE THROWING A 7, IF ON"); b2c_fprintf(stdout,"\n");
    // 01110 PRINT"THE FIRST THROW A 2,3, OR A 12 COMES UP"
    b2c_fprintf(stdout,"THE FIRST THROW A 2,3, OR A 12 COMES UP"); b2c_fprintf(stdout,"\n");
    // 01120 PRINT"YOU LOSE AUTOMATICALLY"
    b2c_fprintf(stdout,"YOU LOSE AUTOMATICALLY"); b2c_fprintf(stdout,"\n");

  Lbl_01130:
    // 01130 LET J=0
    J_int = 0;

  Lbl_01140:
    // 01140 GOSUB 1490
    Routine_01490();
    // 01150 LET D1=N
    D1_int = N_int;
    // 01160 GOSUB 1490
    Routine_01490();
    // 01170 LET D2=N
    D2_int = N_int;
    // 01180 LET D3=D1+D2
    D3_int = D1_int+D2_int;
    // 01190 LET J=J+1
    J_int = J_int+1;
    // 01200 IF J=1 THEN 1250
    if(J_int==1)goto Lbl_01250;
    // 01210 IF D3=D4 THEN 1440
    if(D3_int==D4_int)goto Lbl_01440;
    // 01220 IF D3=7 THEN 1460
    if(D3_int==7)goto Lbl_01460;

  Lbl_01230:
    // 01230 PRINT"YOU THROW A ";D3
    b2c_fprintf(stdout,"YOU THROW A  %d ",D3_int); b2c_fprintf(stdout,"\n");
    // 01240 GOTO 1140
    goto Lbl_01140;

  Lbl_01250:
    // 01250 IF D3=7 THEN 1320
    if(D3_int==7)goto Lbl_01320;
    // 01260 IF D3=2 THEN 1340
    if(D3_int==2)goto Lbl_01340;
    // 01270 IF D3=3 THEN 1340
    if(D3_int==3)goto Lbl_01340;
    // 01280 IF D3=12 THEN 1340
    if(D3_int==12)goto Lbl_01340;
    // 01290 IF D3=11 THEN 1320
    if(D3_int==11)goto Lbl_01320;
    // 01300 LET D4=D3
    D4_int = D3_int;
    // 01310 GOTO 1230
    goto Lbl_01230;

  Lbl_01320:
    // 01320 PRINT"YOU THROW A ";D3;" YOU WIN"
    b2c_fprintf(stdout,"YOU THROW A  %d  YOU WIN",D3_int); b2c_fprintf(stdout,"\n");
    // 01330 GOTO 1350
    goto Lbl_01350;

  Lbl_01340:
    // 01340 PRINT"YOU THROW A ";D3;" YOU LOSE"
    b2c_fprintf(stdout,"YOU THROW A  %d  YOU LOSE",D3_int); b2c_fprintf(stdout,"\n");

  Lbl_01350:
    // 01350 PRINT
    b2c_fprintf(stdout,""); b2c_fprintf(stdout,"\n");
    // 01360 PRINT"TO CONTINUE TYPE 'Y', IF NOT TYPE'N'"
    b2c_fprintf(stdout,"TO CONTINUE TYPE 'Y', IF NOT TYPE'N'"); b2c_fprintf(stdout,"\n");
    // 01370 INPUT L$
    // Start of Basic INPUT statement 01370
    printf(" ? ");
    char inpbuf_01370[100];
    if(fgets(inpbuf_01370,100,stdin)==nullptr){
        fprintf(stderr,"ERROR: End of file on input.\n");
        exit(2);
    }else{
        char *ps_01370=strtok(inpbuf_01370," ,\t\n");
        // This may cause problems if BASIC programmer expected
        // input strings to be copied instead of just pointing
        // to the input buffer (ie. strings can be over written).
        if(ps_01370==nullptr){
            L_str = "";
        }else{
            L_str = ps_01370;
        };
    }; // End of Basic INPUT statement 01370
    // 01380 IF L$="Y" THEN 1420
    if(strcmp(L_str,"Y")==0)goto Lbl_01420;
    // 01390 IF L$="N" THEN 1400
    if(strcmp(L_str,"N")==0)goto Lbl_01400;

  Lbl_01400:
    // 01400 PRINT"WHAT? QUITTING ALREADY, CRAP OUT DID YOU?"
    b2c_fprintf(stdout,"WHAT? QUITTING ALREADY, CRAP OUT DID YOU?"); b2c_fprintf(stdout,"\n");
    // 01410 STOP
    exit(1);

  Lbl_01420:
    // 01420 PRINT
    b2c_fprintf(stdout,""); b2c_fprintf(stdout,"\n");
    // 01430 GOTO 1130
    goto Lbl_01130;

  Lbl_01440:
    // 01440 PRINT"YOU THROW A ";D3;" YOU WIN BY MATCHING"
    b2c_fprintf(stdout,"YOU THROW A  %d  YOU WIN BY MATCHING",D3_int); b2c_fprintf(stdout,"\n");
    // 01450 GOTO 1350
    goto Lbl_01350;

  Lbl_01460:
    // 01460 PRINT"YOU THROW A ";D3;" SORRY, YOU LOSE"
    b2c_fprintf(stdout,"YOU THROW A  %d  SORRY, YOU LOSE",D3_int); b2c_fprintf(stdout,"\n");
    // 01470 GOTO 1350
    goto Lbl_01350;
    // 01480 END
   return(0);
};

//---------------------------------------------------------------------------
// End of $RCSfile$ 
//---------------------------------------------------------------------------
