#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


char board[8][8] = {
                    { 'R' , 'N' , 'B' , 'Q' , 'K' , 'B' , 'N' , 'R' },
                    { 'P' , 'P' , 'P' , 'P' , 'P' , 'P' , 'P' , 'P' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { 'p' , 'p' , 'p' , 'p' , 'p' , 'p' , 'p' , 'p' },
                    { 'r' , 'n' , 'b' , 'q' , 'k' , 'b' , 'n' , 'r' }
                    };
char eat_board[8][8]={
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' }
};

char black_white_b[8][8]={
                    { '-' , '.' , '-' , '.' , '-' , '.' , '-' , '.' },
                    { '.' , '-' , '.' , '-' , '.' , '-' , '.' , '-' },
                    { '-' , '.' , '-' , '.' , '-' , '.' , '-' , '.' },
                    { '.' , '-' , '.' , '-' , '.' , '-' , '.' , '-' },
                    { '-' , '.' , '-' , '.' , '-' , '.' , '-' , '.' },
                    { '.' , '-' , '.' , '-' , '.' , '-' , '.' , '-' },
                    { '-' , '.' , '-' , '.' , '-' , '.' , '-' , '.' },
                    { '.' , '-' , '.' , '-' , '.' , '-' , '.' , '-' },
};
int invalid_movesSmallBishop(int,int);
int invalid_movesSmallPawn(int,int);
int invalid_movesSmallRook(int,int);
int invalid_movesSmallQueen(int,int);
int invalid_movesSmallKnight(int,int);
int invalid_movesSmallKing(int,int);

int invalid_movesCapitalKnight(int ,int );
int invalid_movesCapitalBishop(int,int);
int invalid_movesCapitalPawn(int,int);
int invalid_movesCapitalRook(int,int);
int invalid_movesCapitalQueen(int,int);
int invalid_movesCapitalKing(int,int);


int checksmall(int ,int ,int ,int );
int checkcapital(int ,int ,int ,int );

void stalmate_capital_king(int ,int);
void stalemate_small_king(int ,int);
int threatenpiece_capital(int ,int);
int threatenpiece_small(int, int);
int checked_capital_king_aftermove();
int checked_small_king_aftermove();
int dead_position();

void undo(int);
void redo();

void display(void);

void promotion(int  ,int );
void display_pieces_board();
void display_eat_board();
int change( int , int , int , int ) ;
void eat_change(int  , int  , int , int);
void pawn (int ,int , int ,int );
void save( int );
void rook(int ,int  , int  , int );
void knight( int  , int  ,int  ,int  ) ;
void bishop( int  , int  ,int ,int );
void king( int , int ,int,int) ;
void queen( int  , int  ,int  ,int  ) ;
int load(char a[][8] ,char b[][8]);
int invalid_moves_small(int ,int);
int invalid_moves_capital(int ,int);
void player1();
void player2();
int check(int , int ) ;
int check2(int , int ) ;
int bwins=0;
int undodone =0;
int wwins=0;
int main()
{
int  x = 0 ;
char ch ;


    printf( "\n\tWELCOME TO CHESS GAME" ) ;

    getch();
    system( "cls" ) ;

 do
 {
 x++ ;
 system( "cls" ) ;

  int e;
  printf("eaten pieces :\n");
  display_eat_board();
   printf("\n");
  printf("the board of the game:\n");
  display_pieces_board();
  again5:
  printf("\nWrite choice number(1-save 2-redo 3-undo 4-play 5-play saved game):");
  scanf("%d",&e);
  if(e==1){save(x); break;}
 else if(e==3){ undo(x);}
 else if(e==2){ if(undodone==1) {redo(); }else{printf("there is no undo");}}
  else if(e==5){ if(load(board,eat_board)==1){player1();} else{ player2();}}
  else if(e==4){
 if( (x%2) == 0 ){
   player1();
       if(bwins==1){break;}
       if(dead_position()==1){printf("Drawn by deadposition"); break;}


 }else{

 player2();
       if(wwins==1){break;}
 if(dead_position()==1){printf("Drawn by deadposition"); break;}

 }}
 else{ printf("INVALID NUMBER"); goto again5;}

 printf( " \n\nPress Enter To Continue ! \n\n " ) ;
 ch = getch();
 }while( ch == 13 ) ;

}
void display_pieces_board()
{
    //to display chess board
    int i , j , k ;
    printf( " " ) ;
    for( i=0 ; i<8 ; i++ )
        printf("     %C" , 'A'+(i) ) ;
    printf( "\n" ) ;

    for( k=8 ; k>0 ; k-- ){
    printf( "  " ) ;
    for( i=0 ; i<50 ; i++ ) {
            printf( "-" ) ; } printf( "\n" ) ; printf( "%d " , k ) ;
    for( j=0 ; j<8 ; j++ ) { printf( "|| %c%c " , board[8-k][j],black_white_b[8-k][j] ) ; }
    printf( "|| \n" ) ;
    }

    printf( "  " ) ;
    for( i=0 ; i<50 ; i++ ) { printf( "-" ) ; } printf( "\n" ) ;
    for( i=0 ; i<8 ; i++ ) printf( "     %c" , 'A'+(i) ) ; printf( "\n" ) ;

}
void display_eat_board(){
    int i , j , k ;

 printf( " " ) ;

    for( k=0 ; k<8 ; k++ )
    {
    printf( "  " ) ;
    for( i=0 ; i<42 ; i++ ) { printf( "-" ) ; } printf( "\n" ) ; printf( "%d " , k+1 ) ;

    for( j=0 ; j<8 ; j++ ) { printf( "|| %c ",eat_board[k][j] ) ; }
    printf( "|| \n" ) ;
    }

    printf( "  " ) ;
    for( i=0 ; i<42 ; i++ ) { printf( "-" ) ; } printf( "\n" ) ;


}
//function used for eating pieces and writing them in eaten_board
int change( int r1 , int c1 , int r2 , int c2 )
{
    char temp ;

    temp = board[r1][c1] ;
    board[r1][c1] = board[r2][c2] ;
    board[r2][c2] = temp ;

}
////eat function ////////////////////////////////////
void eat_change(int r1 , int c1 , int r2 , int c2){
    char tmp;

    if(eat_board[r1][c1]!= ' '){

    tmp = board[r1][c1] ;
    board[r1][c1] =' ';
    ++r1;
    eat_board[r1][c1]= board[r2][c2];
    board[r2][c2] = tmp;

    }else if(eat_board[r1][c1]== ' '){

    tmp = board[r1][c1] ;
    eat_board[r1][c1]= board[r2][c2];
    board[r2][c2] = tmp;
    board[r1][c1] =' ';
    }

}
///////////////////////////////////KNIGHT//////////////////////////////

void knight( int r1 , int c1 ,int r2 ,int c2 ){
 //determine possible movements (it moves l in all directions)
 if( (r2==r1+2 &&c2==c1+1) || (r2==r1+2 && c2==c1-1) || (r2==r1-1&& c2==c1-2)||
       (r2==r1+1 && c2==c1+2) || (r2==r1-1 && c2==c1+2)|| (r2==r1-2&& c2==c1-1)||
       (r2==r1-2 && c2==c1+1) || (r2==r1+1 && c2==c1-2)  ){
            if (board[r1][c1]=='N'){
            if(board[r2][c2]==' '){
                    change(r1,c1,r2,c2);}
            else if(board[r2][c2]== 'K'||board[r2][c2]=='Q'||board[r2][c2]=='B'||board[r2][c2]=='R'||board[r2][c2]=='P')
                                                {printf("invalid place! TRY AGAIN");
                                                                   player1(); }
            else if(board[r2][c2]=='k'||'q'||'n'||'r'||'p'||'b'){
                    eat_change(r1,c1,r2,c2);}
            }
           else if (board[r1][c1]=='n'){
            if(board[r2][c2]==' '){
                    change(r1,c1,r2,c2);}
             else if(board[r2][c2]=='K'||board[r2][c2]=='Q'||board[r2][c2]=='N'||board[r2][c2]=='R'||
                     board[r2][c2]=='P'||board[r2][c2]=='B'){
                    eat_change(r1,c1,r2,c2);}
             else if(board[r2][c2]== 'k'||'q'||'b'||'r'||'p'){printf("invalid place! TRY AGAIN");
                                                                 player2(); }
            }}
            else{printf("Knight cannot move in that direction");
                  if(board[r1][c1]=='N'){player1();}
                  else if(board[r1][c1]=='n'){ player2();}
            }

}
/////////////////////////////////BISHOP//////////////////////////
void bishop( int r1 , int c1 ,int r2,int c2)
{    int count,i,j;
// determine possible movements for bishop
if(((c2-c1)==abs(r2-r1))){ count=0;
    if(r2>r1){for(i=r1+1,j=c1+1 ;i<r2 ,j<c2 ;i++,j++){
        if(board[i][j]==' '){count++;}
        else{printf("There is a piece in that direction"); if (board[r1][c1]=='B'){player1(); }
                                                            else if (board[r1][c1]=='b'){player2();}}
      }
       if(count+1==r2-r1 && count+1==c2-c1){
            if(board[r2][c2]== ' '){
                    change(r1,c1,r2,c2);}
            else if((board[r2][c2]== 'P' ||board[r2][c2]== 'K' || board[r2][c2]=='Q' ||
                 board[r2][c2]== 'N' || board[r2][c2]=='B' ||board[r2][c2]=='R') && (board[r1][c1]=='b') ){
                  eat_change(r1,c1,r2,c2);}
            else if((board[r2][c2]== 'p' || board[r2][c2]=='r' || board[r2][c2]=='n' ||
                 board[r2][c2]== 'b' ||board[r2][c2]== 'k' || board[r2][c2]=='q') && (board[r1][c1]== 'B')){
                   eat_change(r1,c1,r2,c2);}
           else if((board[r2][c2]== 'p' || board[r2][c2]=='r' || board[r2][c2]=='n' ||
                  board[r2][c2]=='b' || board[r2][c2]=='k' ||board[r2][c2]== 'q') && (board[r1][c1]== 'b')){
                    printf("position invalid "); player2();}
           else if((board[r2][c2]== 'P' || board[r2][c2]=='K' || board[r2][c2]=='Q' ||
                 board[r2][c2]== 'N' || board[r2][c2]=='B' ||board[r2][c2]== 'R') && (board[r1][c1]=='B') ){
                     printf("position invalid "); player1();}}
    }else if(r1>r2){
        for(i=r1-1,j=c1+1; i>r2,j<c2 ;i--,j++){
               if(board[i][j]==' '){count++;}
               else {printf("There is a piece in that direction"); if (board[r1][c1]=='B'){player1(); }
                                                            else if (board[r1][c1]=='b'){player2();}}

        }
         if((count+1==r1-r2)  && (count+1==c2-c1)){
           if(board[r2][c2]== ' '){
                change(r1,c1,r2,c2);}
           else if((board[r2][c2]== 'P' || board[r2][c2]== 'K' || board[r2][c2]=='Q' ||
                    board[r2][c2]=='N' || board[r2][c2]=='B' ||board[r2][c2]== 'R') && (board[r1][c1]=='b') ){
                  eat_change(r1,c1,r2,c2);}
           else if((board[r2][c2]== 'P' ||board[r2][c2]== 'K' ||board[r2][c2]== 'Q' ||
                    board[r2][c2]== 'N' || board[r2][c2]=='B' || board[r2][c2]=='R') && (board[r1][c1]=='B') ){
                        printf("position invalid TTT"); player1();}
           else if((board[r2][c2]== 'p' ||board[r2][c2]== 'r' ||board[r2][c2]== 'n' ||
                    board[r2][c2]== 'b' ||board[r2][c2]== 'k' ||board[r2][c2]== 'q') && (board[r1][c1]== 'b')){
                        printf("position invalid vvvv"); player2();}
           else if((board[r2][c2]== 'p' || board[r2][c2]=='r' || board[r2][c2]=='n' ||
                    board[r2][c2]== 'b' ||board[r2][c2]== 'k' ||board[r2][c2]== 'q') && (board[r1][c1]== 'B')){
                   eat_change(r1,c1,r2,c2);}
                    }}}
else if((c1-c2)==abs(r2-r1)){ count=0;
     if(r2>r1){for(i=r1+1,j=c1-1;i<r2,j>c2 ;i++,j--){
                if(board[i][j]==' '){count++;}
                else{printf("There is a piece in that direction"); if (board[r1][c1]=='B'){player1(); }
                                                            else if (board[r1][c1]=='b'){player2();}}
            }
            if(count+1==r2-r1 && count+1==c1-c2){

               if(board[r2][c2]== ' '){
                        change(r1,c1,r2,c2);}
            else if((board[r2][c2]== 'p' || board[r2][c2]=='r' || board[r2][c2]=='n' ||
                       board[r2][c2]== 'b' || board[r2][c2]=='k' || board[r2][c2]=='q') && (board[r1][c1]== 'b')){printf("position invalid vvvv");
                                                                                                                   player2();}
               else if((board[r2][c2]== 'p' ||board[r2][c2]== 'r' ||board[r2][c2]== 'n' ||
                       board[r2][c2]=='b' || board[r2][c2]=='k' || board[r2][c2]=='q') && (board[r1][c1]== 'B')){
                   eat_change(r1,c1,r2,c2);}
               else if((board[r2][c2]== 'P' || board[r2][c2]=='K' ||board[r2][c2]== 'Q' ||
                       board[r2][c2]== 'N' ||board[r2][c2]== 'B' ||board[r2][c2]== 'R') && (board[r1][c1]=='B') ){printf("position invalid TTT");
                                                                                                                   player1();}
               else if((board[r2][c2]== 'P' || board[r2][c2]=='K' || board[r2][c2]=='Q' ||
                        board[r2][c2]=='N' ||board[r2][c2]== 'B' || board[r2][c2]=='R') && (board[r1][c1]=='b') ){
                  eat_change(r1,c1,r2,c2);
                  }}}
    else if(r1>r2){count=0;
            for(i=r1-1, j=c1-1; i>r2,j>c2 ;i--,j--){
            if(board[i][j]==' '){count++;}
            else {printf("There is a piece in that direction"); if (board[r1][c1]=='B'){player1(); }
                                                            else if (board[r1][c1]=='b'){player2();}}
        }
        if(count+1==r1-r2 && count+1==c1-c2){
               if(board[r2][c2]== ' '){
                    change(r1,c1,r2,c2);}
               else if((board[r2][c2]== 'P' ||board[r2][c2]== 'K' ||board[r2][c2]== 'Q' ||
                        board[r2][c2]=='N' || board[r2][c2]=='B' ||board[r2][c2]== 'R') && (board[r1][c1]=='b') ){
                  eat_change(r1,c1,r2,c2);}
               else if((board[r2][c2]== 'P' || 'K' || 'Q' ||'N' || 'B' || 'R') && (board[r1][c1]=='B') ){
                     printf("position invalid TTT"); player1();}
              else if((board[r2][c2]== 'p' ||board[r2][c2]== 'r' ||board[r2][c2]== 'n' ||
                       board[r2][c2]== 'b' ||board[r2][c2]== 'k' ||board[r2][c2]== 'q') && (board[r1][c1]== 'b')){
                    printf("position invalid vvvv"); player2();}
              else if((board[r2][c2]== 'p' ||board[r2][c2]== 'r' ||board[r2][c2]== 'n' ||
                       board[r2][c2]=='b' ||board[r2][c2]== 'k' ||board[r2][c2]== 'q') && (board[r1][c1]== 'B')){
                   eat_change(r1,c1,r2,c2);
                   }}
   }}
else{
      //if user chose not in l direction
       printf("Bishop cannot move in that direction");
       if(board[r1][c1]=='B'){
          player1();
       }else if(board[r1][c1]== 'b'){
            player2();}}
}

//////////////////////KING/////////////////////////////
void king( int r1 , int c1 ,int r2 ,int c2){
    if( (r2==r1 && c2==c1+1)|| (r2==r1 &&c2==c1-1 ) || (r2==r1+1 &&c2==c1) ||(r2==r1-1 && c2==c1) ||
       (r2==r1+1 && c2==c1+1) || (r2==r1-1 && c2==c1-1) || (r2==r1+1 && c2==c1-1) ||(r2==r1-1 &&c2==c1+1)){
           if(board[r1][c1]=='K'){
            if(board[r2][c2]==' '){
                    change(r1,c1,r2,c2);

             }
             else if(board[r2][c2]=='n'||'r'||'q'||'b'||'p'){
                    eat_change(r1,c1,r2,c2);

             }
            else if (board[r2][c2]=='N'||'R' ||'Q'||'B'||'P' ){printf("invalid place ! TRY AGAIN");
                                                                player1();  }

            else if(board[r2][c2]=='k'){printf("king cannot eat the opponent king");}
            else{printf("invalid");}
           }
          else if(board[r1][c1]=='k'){
            if(board[r2][c2]==' ') {
                    change(r1,c1,r2,c2);

            }
            else if( board[r2][c2]=='N'||'R' ||'Q'||'B'||'P') {
                    eat_change(r1,c1,r2,c2);

            }
            else if(board[r2][c2]=='n'||'r'||'q'||'b'||'p'){printf("invalid place ! TRY AGAIN");
                                                                player2();  }
            else if(board[r2][c2]=='K'){printf("king cannot eat the opponent king");}
           }}
           //CASTLING
           else if(c2==c1+2 && r1==r2 && r1==7 && check(r2,c2)!=1){
               if(board[r1][c1]=='k' &&board[r1][c1+1]==' ' && board[r1][c1+2]== ' ' && board[r1][c1+3]== 'r' ){
                    change(r1,c1,r2,c2);
                    change(r1,c1+3,r2,c1+1);
               }else{printf("invalid");}
           }else if(c2==c1-2 && r1==r2 && r1==7 && check(r2,c2)!=1){
               if(board[r1][c1]=='k' &&board[r1][c1-1]==' ' && board[r1][c1-2]== ' ' && board[r1][c1-3]== ' ' && board[r1][c1-4]== 'r' ){
                change(r1,c1,r2,c2);
                change(r1,c1-4,r2,c1-1);
               }else{
                   printf("invalid");
               }
           }else if(c2==c1+2 && r1==r2 && r1==0 && check2(r2,c2)!=1){
               if(board[r1][c1]=='K' && board[r1][c1+1]==' ' && board[r1][c1+2]== ' ' && board[r1][c1+3]== 'R' ){
                    change(r1,c1,r2,c2);
                    change(r1,c1+3,r2,c1+1);
               }else{printf("invalid");}
           }else if(c2==c1-2 && r1==r2 && r1==0 && check2(r2,c2)!=1){
               if(board[r1][c1-1]==' ' && board[r1][c1-2]== ' ' && board[r1][c1-3]== ' ' && board[r1][c1-4]== 'R' ){
                change(r1,c1,r2,c2);
                change(r1,c1-4,r2,c1-1);
               }else{printf("invalid");}
           }
           else { printf("king cannot move in that direction ");
                   if(board[r1][c1]=='K'){ player1();}
                   else if(board[r1][c1]=='k'){player2();}
           }

}
/////////////////////QUEEN//////////////////////////////
void queen( int r1 , int c1 ,int r2 ,int c2 ){
      int i,j,count;
      //determine possible movements for queen
 if(r2==r1){
   if(c2>c1){ count=0;
        for(i=c1+1 ;i<c2;++i){
            if(board[r2][i]==' '){ count++;}
            else {printf("there is another piece in that direction"); {if(board[r1][c1]=='Q') player1();
                                                                       else if(board[r1][c1]=='q') player2();}} }
              if (count+1==c2-c1){
                 if(board[r2][c2] == ' '){
                    change(r1,c1,r2,c2);
                   }else if((board[r2][c2]== 'p' || board[r2][c2]=='r' ||board[r2][c2]== 'n' ||
                          board[r2][c2]== 'b' || board[r2][c2]=='k' ||board[r2][c2]== 'q') && (board[r1][c1]== 'Q')){
                    eat_change(r1,c1,r2,c2);
                 }else if((board[r2][c2]== 'P' || board[r2][c2]== 'K'  ||
                           board[r2][c2]==  'N' || board[r2][c2]== 'B' ||board[r2][c2]==  'R') && (board[r1][c1]=='Q') ){
                     printf("position invalid TTT"); player1();}
                 else if((board[r2][c2]== 'P' ||board[r2][c2]== 'K' || board[r2][c2]=='Q' ||
                           board[r2][c2]== 'N' ||board[r2][c2]== 'B' || board[r2][c2]=='R') && (board[r1][c1]=='q') ){
                    eat_change(r1,c1,r2,c2);
                }else if((board[r2][c2]== 'p' || 'r' || 'n' || 'b' || 'k' ) && (board[r1][c1]== 'q')){
                    printf("position invalid vvvv");  player2();}
            }}
  else if(c2<c1){ count=0;
        for(i=c1-1;i>c2;--i){
            if(board[r2][i]== ' '){count++; }
            else {printf("there is another piece in that direction"); {if(board[r1][c1]=='Q') player1();
                                                                       else if(board[r1][c1]=='q') player2(); }
                                                                           } }
              if (count+1==c1-c2){
                 if(board[r2][c2] == ' '){
                    change(r1,c1,r2,c2);
                }else if((board[r2][c2]== 'p' ||board[r2][c2]== 'r' || board[r2][c2]=='n' ||
                          board[r2][c2]=='b' || board[r2][c2]=='k' || board[r2][c2]=='q') && (board[r1][c1]== 'Q')){
                    eat_change(r1,c1,r2,c2);
                }else if((board[r2][c2]== 'P' ||board[r2][c2]== 'K' ||
                          board[r2][c2]=='N' || board[r2][c2]=='B' ||board[r2][c2]== 'R') && (board[r1][c1]=='Q') ){
                     printf("position invalid TTT");  player1();}
                 else if((board[r2][c2]== 'P' || board[r2][c2]=='K' || board[r2][c2]=='Q' ||
                           board[r2][c2]== 'N' || board[r2][c2]=='B' ||board[r2][c2]== 'R') && (board[r1][c1]=='q') ){
                    eat_change(r1,c1,r2,c2);
                }else if((board[r2][c2]== 'p' || 'r' || 'n' || 'b' || 'k' ) && (board[r1][c1]== 'q')){
                    printf("position invalid vvvv");
                    player2();}
        }}}
else if(c2==c1){

   if(r1>r2){ count=0;
        for(i=r1-1;i>r2;--i){
            if(board[i][c2]== ' '){count++;}
            else {printf("there is a piece in that direction"); {if(board[r1][c1]=='q') player2();
                                                                 else if (board[r1][c1]=='Q') player1();}
                                                                   }}
                 if(count+1==r1-r2){
                     if(board[r2][c2] == ' '){
                    change(r1,c1,r2,c2);}
                else if((board[r2][c2]== 'P' || board[r2][c2]=='K' ||board[r2][c2]=='Q'||
                         board[r2][c2]=='N' ||board[r2][c2]== 'B' ||board[r2][c2]== 'R') && (board[r1][c1]=='Q') ){
                     printf("position invalid TTT");
                    player1();}
                 else if((board[r2][c2]== 'P' || board[r2][c2]=='K' || board[r2][c2]=='Q' ||
                          board[r2][c2]== 'N' || board[r2][c2]=='B' ||board[r2][c2]== 'R') && (board[r1][c1]=='q') ){
                    eat_change(r1,c1,r2,c2);
                    for(i=0;i<8;++i){
                        check2(r2+i,c2);check2(r2,c2+i);check2(r2-i,c2);check2(r2,c2-i);
                           check2(r2+i,c2+i); check2(r2-i,c2-i);check2(r2+i,c2-i); check2(r2-i,c2+i);
                     }
                    }
                else if((board[r2][c2]== 'p' ||board[r2][c2]== 'r' ||board[r2][c2]== 'n' ||
                         board[r2][c2]=='b' || board[r2][c2]=='k' || board[r2][c2]=='q') && (board[r1][c1]== 'Q')){
                    eat_change(r1,c1,r2,c2);}
                else if((board[r2][c2]== 'p' || 'r' || 'n' || 'b' || 'k'||'q' ) && (board[r1][c1]== 'q')){
                    printf("position invalid vvvv");
                    player2();}
               }
                 }
 else if(r2>r1){ count=0;
    for(i=r1+1;i<r2;++i){
            if(board[i][c2]== ' '){ count++;}
            else {printf("there is a piece in that direction");
                      if(board[r1][c1]=='q'){ player2();}
                      else if (board[r1][c1]=='Q') {player1();}
                                                                }}
                if(count+1==r2-r1){
                   if(board[r2][c2] == ' '){
                    change(r1,c1,r2,c2);}
                 else if((board[r2][c2]== 'P' ||board[r2][c2]== 'K'  ||board[r2][c2]=='Q'||
                          board[r2][c2]== 'N' || board[r2][c2]=='B' ||board[r2][c2]== 'R') && (board[r1][c1]=='Q') ){
                     printf("position invalid TTT");
                    player1();}
                 else if((board[r2][c2]== 'P' ||board[r2][c2]== 'K' ||board[r2][c2]== 'Q' ||
                          board[r2][c2]== 'N' || board[r2][c2]=='B' || board[r2][c2]=='R') && (board[r1][c1]=='q') ){
                    eat_change(r1,c1,r2,c2);
                    for(i=0;i<8;++i){
                         check2(r2+i,c2);check2(r2,c2+i);check2(r2-i,c2);check2(r2,c2-i);
                           check2(r2+i,c2+i); check2(r2-i,c2-i);check2(r2+i,c2-i); check2(r2-i,c2+i);
                    }
                    }
                else if((board[r2][c2]== 'p' || board[r2][c2]=='r' ||board[r2][c2]== 'n' ||
                         board[r2][c2]=='b' || board[r2][c2]=='k' ||board[r2][c2]== 'q') && (board[r1][c1]== 'Q')){
                    eat_change(r1,c1,r2,c2);}
                else if((board[r2][c2]== 'p' || 'r' || 'n' || 'b' || 'k'||'q' ) && (board[r1][c1]== 'q')){
                    printf("position invalid vvvv");
                    player2();}}
        }
}
else if(((c2-c1)==abs(r2-r1))){ count=0;
    if(r2>r1){for(i=r1+1,j=c1+1 ;i<r2 ,j<c2 ;i++,j++){
        if(board[i][j]==' '){count++;}
        else{printf("There is a piece in that direction"); if (board[r1][c1]=='Q'){player1(); }
                                                            else if (board[r1][c1]=='q'){player2();}}
      }
       if(count+1==r2-r1 && count+1==c2-c1){
            if(board[r2][c2]== ' '){
                    change(r1,c1,r2,c2);
     }
            else if((board[r2][c2]== 'P' ||board[r2][c2]== 'K' || board[r2][c2]=='Q' ||
                 board[r2][c2]== 'N' || board[r2][c2]=='B' ||board[r2][c2]=='R') && (board[r1][c1]=='q') ){
                  eat_change(r1,c1,r2,c2);
                  for(i=0;i<8;++i){
                   check2(r2+i,c2);check2(r2,c2+i);check2(r2-i,c2);check2(r2,c2-i);
                           check2(r2+i,c2+i); check2(r2-i,c2-i);check2(r2+i,c2-i); check2(r2-i,c2+i);
                  }
                  }
            else if((board[r2][c2]== 'p' || board[r2][c2]=='r' || board[r2][c2]=='n' ||
                 board[r2][c2]== 'b' ||board[r2][c2]== 'k' || board[r2][c2]=='q') && (board[r1][c1]== 'Q')){
                   eat_change(r1,c1,r2,c2);
                   }
           else if((board[r2][c2]== 'p' || board[r2][c2]=='r' || board[r2][c2]=='n' ||
                  board[r2][c2]=='b' || board[r2][c2]=='k' ||board[r2][c2]== 'q') && (board[r1][c1]== 'q')){
                    printf("position invalid vvvv"); player2();}
           else if((board[r2][c2]== 'P' || board[r2][c2]=='K' || board[r2][c2]=='Q' ||
                 board[r2][c2]== 'N' || board[r2][c2]=='B' ||board[r2][c2]== 'R') && (board[r1][c1]=='Q') ){
                     printf("position invalid TTT"); player1();}}
    }else if(r1>r2){
        for(i=r1-1,j=c1+1; i>r2,j<c2 ;i--,j++){
               if(board[i][j]==' '){count++;}
               else {printf("There is a piece in that direction"); if (board[r1][c1]=='Q'){player1(); }
                                                            else if (board[r1][c1]=='q'){player2();}}

        }
         if((count+1==r1-r2)  && (count+1==c2-c1)){
           if(board[r2][c2]== ' '){
                    change(r1,c1,r2,c2);
           }
           else if((board[r2][c2]== 'P' || board[r2][c2]== 'K' || board[r2][c2]=='Q' ||
                    board[r2][c2]=='N' || board[r2][c2]=='B' ||board[r2][c2]== 'R') && (board[r1][c1]=='q') ){
                  eat_change(r1,c1,r2,c2);
                  for(i=0;i<8;++i){
                   check2(r2+i,c2);check2(r2,c2+i);check2(r2-i,c2);check2(r2,c2-i);
                           check2(r2+i,c2+i); check2(r2-i,c2-i);check2(r2+i,c2-i); check2(r2-i,c2+i);
                  }
                  }
           else if((board[r2][c2]== 'P' ||board[r2][c2]== 'K' ||board[r2][c2]== 'Q' ||
                    board[r2][c2]== 'N' || board[r2][c2]=='B' || board[r2][c2]=='R') && (board[r1][c1]=='Q') ){
                        printf("position invalid TTT"); player1();}
           else if((board[r2][c2]== 'p' ||board[r2][c2]== 'r' ||board[r2][c2]== 'n' ||
                    board[r2][c2]== 'b' ||board[r2][c2]== 'k' ||board[r2][c2]== 'q') && (board[r1][c1]== 'q')){
                        printf("position invalid vvvv"); player2();}
           else if((board[r2][c2]== 'p' || board[r2][c2]=='r' || board[r2][c2]=='n' ||
                    board[r2][c2]== 'b' ||board[r2][c2]== 'k' ||board[r2][c2]== 'q') && (board[r1][c1]== 'Q')){
                   eat_change(r1,c1,r2,c2);
                   }
                    }}}
else if((c1-c2)==abs(r2-r1)){ count=0;
     if(r2>r1){for(i=r1+1,j=c1-1;i<r2,j>c2 ;i++,j--){
                if(board[i][j]==' '){count++;}
                else{printf("There is a piece in that direction"); if (board[r1][c1]=='Q'){player1(); }
                                                            else if (board[r1][c1]=='q'){player2();}}
            }
            if(count+1==r2-r1 && count+1==c1-c2){

               if(board[r2][c2]== ' '){
                    change(r1,c1,r2,c2);

               }
            else if((board[r2][c2]== 'p' || board[r2][c2]=='r' || board[r2][c2]=='n' ||
                       board[r2][c2]== 'b' || board[r2][c2]=='k' || board[r2][c2]=='q') && (board[r1][c1]== 'q')){printf("position invalid vvvv");
                                                                                                                   player2();}
               else if((board[r2][c2]== 'p' ||board[r2][c2]== 'r' ||board[r2][c2]== 'n' ||
                       board[r2][c2]=='b' || board[r2][c2]=='k' || board[r2][c2]=='q') && (board[r1][c1]== 'Q')){
                   eat_change(r1,c1,r2,c2);
                   }

               else if((board[r2][c2]== 'P' || board[r2][c2]=='K' ||board[r2][c2]== 'Q' ||
                       board[r2][c2]== 'N' ||board[r2][c2]== 'B' ||board[r2][c2]== 'R') && (board[r1][c1]=='Q') ){printf("position invalid TTT");
                                                                                                                   player1();}
               else if((board[r2][c2]== 'P' || board[r2][c2]=='K' || board[r2][c2]=='Q' ||
                        board[r2][c2]=='N' ||board[r2][c2]== 'B' || board[r2][c2]=='R') && (board[r1][c1]=='q') ){
                  eat_change(r1,c1,r2,c2);
                  for(i=0;i<8;++i){
                check2(r2+i,c2);check2(r2,c2+i);check2(r2-i,c2);check2(r2,c2-i);
                           check2(r2+i,c2+i); check2(r2-i,c2-i);check2(r2+i,c2-i); check2(r2-i,c2+i);

                  }
                  }}}
    else if(r1>r2){count=0;
            for(i=r1-1, j=c1-1; i>r2,j>c2 ;i--,j--){
            if(board[i][j]==' '){count++;}
            else {printf("There is a piece in that direction"); if (board[r1][c1]=='Q'){player1(); }
                                                            else if (board[r1][c1]=='q'){player2();}}
        }
        if(count+1==r1-r2 && count+1==c1-c2){
               if(board[r2][c2]== ' '){
                        change(r1,c1,r2,c2);
               }
               else if((board[r2][c2]== 'P' ||board[r2][c2]== 'K' ||board[r2][c2]== 'Q' ||
                        board[r2][c2]=='N' || board[r2][c2]=='B' ||board[r2][c2]== 'R') && (board[r1][c1]=='q') ){
                  eat_change(r1,c1,r2,c2);
                  }
               else if((board[r2][c2]== 'P' || 'K' || 'Q' ||'N' || 'B' || 'R') && (board[r1][c1]=='Q') ){
                     printf("position invalid TTT"); player1();}
              else if((board[r2][c2]== 'p' ||board[r2][c2]== 'r' ||board[r2][c2]== 'n' ||
                       board[r2][c2]== 'b' ||board[r2][c2]== 'k' ||board[r2][c2]== 'q') && (board[r1][c1]== 'q')){
                    printf("position invalid vvvv"); player2();}
              else if((board[r2][c2]== 'p' ||board[r2][c2]== 'r' ||board[r2][c2]== 'n' ||
                       board[r2][c2]=='b' ||board[r2][c2]== 'k' ||board[r2][c2]== 'q') && (board[r1][c1]== 'Q')){
                   eat_change(r1,c1,r2,c2);
                   }}
   }}
else{

       printf("Queen cannot move in that direction");
       if(board[r1][c1]=='Q'){
          player1();
       }else if(board[r1][c1]== 'q'){
            player2();}}
}

/////////////////////////////PAWN////////////////////////////////////////////////
void pawn (int r1,int c1, int r2,int c2){
    //P CAPITAL
    if(board[r1][c1]=='P'){

if(r1==1){ if(r2==(r1+2) && c2==c1){
              if(board[r2][c2]==' ' && board[r1+1][c1]==' '){
                   change(r1,c1,r2,c2);

               }
              else{ printf("position is invalid");
                          player1();}
        }
         else if(board[r2][c2]== 'p' || 'r' || 'n' || 'b' || 'k' || 'q' ){
                    eat_change(r1,c1,r2,c2);

            }
        else if(r2==r1+1 && c2==c1+1 || r2==r1+1 && c2==c1-1){
            if (board[r2][c2]== 'P'||'R'||'N'||'B'||'K'||'Q' ){ printf("position is invalid");
                                                                      player1();}

            else if (board[r2][c2]==' '){ printf("Not allowed"); player1();}
            else{
                printf("invalid position");
            }

      } else if(r2==r1+1 && c2==c1){
                if(board[r2][c2]==' '){
                        change(r1,c1,r2,c2);
                }else{printf("invalid");}
                }else{ printf("position is invalid");
                         player1();}}
    else if(r2==r1+1 && c2==c1){
          if(board[r2][c2]==' '){
           change(r1,c1,r2,c2);
          }else{
                 printf("position is invalid");
                 player1();}
    }else if(r2==r1+1 && (c2==c1+1 || c2==c1-1)){
             if(board[r2][c2]== 'p' || board[r2][c2]== 'r' ||board[r2][c2]== 'n' ||board[r2][c2]== 'b' ||
                board[r2][c2]== 'k' ||board[r2][c2]== 'q' ){
                    eat_change(r1,c1,r2,c2);

                    }
             else if(board[r2][c2]== 'P'||'R'||'N'||'B'||'K'||'Q'){ printf("position is invalid");
                                                                      player1();}
            else if(board[r2][c2]==' '){printf("invalid"); player1();}    }
    else{ printf("Pawn cannot move in that direction");
                     player1();}
///// HAVE PROMOTION
        if(r2==7)  {
            if(board[r2][c2]== ' '){
            change(r1,c1,r2,c2);
          promotion(r2,c2);
            }else if(board[r2][c2]== 'p' || 'r' ||  'n' || 'b' || 'k' || 'q'){
                eat_change(r1,c1,r2,c2);
                promotion(r2,c2);
            }
      }

        }
        //p small
else if(board[r1][c1]=='p'){
   if(r1==6){
  if(r2==r1-2 && c2==c1){
        if(board[r2][c2]==' ' && board[r1-1][c1]==' '){
            change(r1,c1,r2,c2);
            }
        else{ printf("-position is invalid-");
                  player2();}}

  else if(r2==r1-1 && c2==c1-1 || r2==r1-1&& c2==c1+1){
      if(board[r2][c2]== 'p'||'q'||'n'||'b'||'r' || 'k'){
                 printf("*position is invalid");
                  player2();}
      else if(board[r2][c2]== 'P' || 'Q' || 'N' || 'B' || 'R' || 'K'){
           eat_change(r1,c1,r2,c2);
           }
      else{ printf("Pawn cannot move in that direction");
              player2();}}
  else if(r2==r1-1 && c2==c1){
          if(board[r2][c2]==' '){
           change(r1,c1,r2,c2);
          }else{
                 printf("-position is invalid");
                 player2();}}
                 else{
                    printf("invalid -position");
                    player2();
                 }
   }
      else if(r2==r1-1 && c2==c1){
          if(board[r2][c2]==' '){
           change(r1,c1,r2,c2);
          }else{
                 printf("position is invalid*");
                 player2();}
    }else if(r2==r1-1 && (c2==c1+1 || c2==c1-1)){
            if(board[r2][c2]== 'P' ||board[r2][c2]==  'R' || board[r2][c2]== 'N' ||board[r2][c2]==  'B' ||
               board[r2][c2]==  'K' || board[r2][c2]== 'Q' ){
                   eat_change(r1,c1,r2,c2);
                   }
             else if(board[r2][c2]== 'p'||'r'||'n'||'b'||'k'||'q'){
                 printf("position is invalid");
                  player2();}

            else if (board[r2][c2]=' ') {printf("invalid "); player2();
            }else{
                printf("invalid tytyt"); player2();
            }
            }else{ printf("Pawn cannot move in that direction");
                     player2();}
//// HAVE PROMOTION
     if(r2==0)  {
            if( board[r2][c2]== ' '){
            change(r1,c1,r2,c2);
            promotion2(r2,c2);
            }else if(board[r2][c2]== 'P' || 'Q' || 'N' || 'B' || 'R' || 'K'){
                eat_change(r1,c1,r2,c2);
               promotion2(r2,c2);
            }
      }

}
}

/////////////////////////////////////////////////END PAWN/////////////////////////////////
void rook(int r1,int c1 , int r2 , int c2){
    int i,count;
if(r2==r1){
   if(c2>c1){ count=0;
        for(i=c1+1 ;i<c2;++i){
            if(board[r2][i]==' '){ count++;}
            else {printf("there is another piece in that direction"); {if(board[r1][c1]=='R') player1();
                                                                       else if(board[r1][c1]=='r') player2();}} }
              if (count+1==c2-c1){
                 if(board[r2][c2] == ' '){
                    change(r1,c1,r2,c2);
                   }else if((board[r2][c2]== 'p' || board[r2][c2]=='r' ||board[r2][c2]== 'n' ||
                          board[r2][c2]== 'b' || board[r2][c2]=='k' ||board[r2][c2]== 'q') && (board[r1][c1]== 'R')){
                    eat_change(r1,c1,r2,c2);
                 }else if((board[r2][c2]== 'P' || board[r2][c2]== 'K' || board[r2][c2]== 'Q' ||
                           board[r2][c2]==  'N' || board[r2][c2]== 'B' ||board[r2][c2]==  'R') && (board[r1][c1]=='R') ){
                     printf("position invalid TTT"); player1();}
                 else if((board[r2][c2]== 'P' ||board[r2][c2]== 'K' || board[r2][c2]=='Q' ||
                           board[r2][c2]== 'N' ||board[r2][c2]== 'B' || board[r2][c2]=='R') && (board[r1][c1]=='r') ){
                    eat_change(r1,c1,r2,c2);
                }else if((board[r2][c2]== 'p' || 'r' || 'n' || 'b' || 'k' || 'q') && (board[r1][c1]== 'r')){
                    printf("position invalid vvvv");  player2();}
            }}
  else if(c2<c1){ count=0;
        for(i=c1-1;i>c2;--i){
            if(board[r2][i]== ' '){count++; }
            else {printf("there is another piece in that direction"); {if(board[r1][c1]=='R') player1();
                                                                       else if(board[r1][c1]=='r') player2(); }
                                                                           } }
              if (count+1==c1-c2){
                 if(board[r2][c2] == ' '){
                    change(r1,c1,r2,c2);
                }else if((board[r2][c2]== 'p' ||board[r2][c2]== 'r' || board[r2][c2]=='n' ||
                          board[r2][c2]=='b' || board[r2][c2]=='k' || board[r2][c2]=='q') && (board[r1][c1]== 'R')){
                    eat_change(r1,c1,r2,c2);
                }else if((board[r2][c2]== 'P' ||board[r2][c2]== 'K' ||board[r2][c2]== 'Q' ||
                          board[r2][c2]=='N' || board[r2][c2]=='B' ||board[r2][c2]== 'R') && (board[r1][c1]=='R') ){
                     printf("position invalid TTT");  player1();}
                 else if((board[r2][c2]== 'P' || board[r2][c2]=='K' || board[r2][c2]=='Q' ||
                           board[r2][c2]== 'N' || board[r2][c2]=='B' ||board[r2][c2]== 'R') && (board[r1][c1]=='r') ){
                    eat_change(r1,c1,r2,c2);
                     for(i=0;i<8;++i){
                         check2(r2+i,c2);check2(r2,c2+i);check2(r2-i,c2);check2(r2,c2-i);
                     }
                }else if((board[r2][c2]== 'p' || 'r' || 'n' || 'b' || 'k' || 'q') && (board[r1][c1]== 'r')){
                    printf("position invalid vvvv");
                    player2();}
        }}}
else if(c2==c1){

   if(r1>r2){ count=0;
        for(i=r1-1;i>r2;--i){
            if(board[i][c2]== ' '){count++;}
            else {printf("there is a piece in that direction"); {if(board[r1][c1]=='r') player2();
                                                                 else if (board[r1][c1]=='R') player1();}
                                                                   }}
                 if(count+1==r1-r2){
                     if(board[r2][c2] == ' '){
                    change(r1,c1,r2,c2);
                    }
                else if((board[r2][c2]== 'P' || board[r2][c2]=='K' ||board[r2][c2]== 'Q' ||
                         board[r2][c2]=='N' ||board[r2][c2]== 'B' ||board[r2][c2]== 'R') && (board[r1][c1]=='R') ){
                     printf("position invalid TTT");
                    player1();}
                 else if((board[r2][c2]== 'P' || board[r2][c2]=='K' || board[r2][c2]=='Q' ||
                          board[r2][c2]== 'N' || board[r2][c2]=='B' ||board[r2][c2]== 'R') && (board[r1][c1]=='r') ){
                    eat_change(r1,c1,r2,c2);
                    }
                else if((board[r2][c2]== 'p' ||board[r2][c2]== 'r' ||board[r2][c2]== 'n' ||
                         board[r2][c2]=='b' || board[r2][c2]=='k' || board[r2][c2]=='q') && (board[r1][c1]== 'R')){
                    eat_change(r1,c1,r2,c2);
                    }
                else if((board[r2][c2]== 'p' || 'r' || 'n' || 'b' || 'k' || 'q') && (board[r1][c1]== 'r')){
                    printf("position invalid vvvv");
                    player2();}
               }
                 }
 else if(r2>r1){ count=0;
    for(i=r1+1;i<r2;++i){
            if(board[i][c2]== ' '){ count++;}
            else {printf("there is a piece in that direction");
                      if(board[r1][c1]=='r'){ player2();}
                      else if (board[r1][c1]=='R') {player1();}
                                                                }}
                if(count+1==r2-r1){
                   if(board[r2][c2] == ' '){
                    change(r1,c1,r2,c2);
                    }
                 else if((board[r2][c2]== 'P' ||board[r2][c2]== 'K' || board[r2][c2]=='Q' ||
                          board[r2][c2]== 'N' || board[r2][c2]=='B' ||board[r2][c2]== 'R') && (board[r1][c1]=='R') ){
                     printf("position invalid TTT");
                    player1();}
                 else if((board[r2][c2]== 'P' ||board[r2][c2]== 'K' ||board[r2][c2]== 'Q' ||
                          board[r2][c2]== 'N' || board[r2][c2]=='B' || board[r2][c2]=='R') && (board[r1][c1]=='r') ){
                    eat_change(r1,c1,r2,c2);
                    }
                else if((board[r2][c2]== 'p' || board[r2][c2]=='r' ||board[r2][c2]== 'n' ||
                         board[r2][c2]=='b' || board[r2][c2]=='k' ||board[r2][c2]== 'q') && (board[r1][c1]== 'R')){
                    eat_change(r1,c1,r2,c2);
                    }
                else if((board[r2][c2]== 'p' || 'r' || 'n' || 'b' || 'k' || 'q') && (board[r1][c1]== 'r')){
                    printf("position invalid vvvv");
                    player2();}}
        }
}else{
       if(board[r1][c1]== 'r'){
         printf("position invalid yuyu"); player2();
       }else if(board[r1][c1]== 'R'){
           printf("position invalid rrT"); player1();}
   }
}
int j;
int row2[],col2[] , row1[],col1[];
int i;
int arr1[] ,arr2[] , arr3[] ,arr4[];
void player1(){
    int r1 , r2,i=0;
    char c1,c2;
    printf( "\nPLAYER 1 - Big Case\n" ) ;
    again1:
    printf( "\nEnter Position of Element to change and the position sent to: " ) ;
    scanf( "\n%c%d%c%d" ,&c1,&r1,&c2 ,&r2) ;
    // to prevent user to change any piece if it didn't cancel check if found
    if(check2(row2[j],col2[j])==1){change(8-r1,c1-65,8-r2,c2-65);
                                                             if(check2(row2[j],col2[j])==1){ printf("cancel check first");
                                                                                            goto again1;}
                                                                              change(8-r2,c2-65,8-r1,c1-65);
                                                                            }

    switch( board[8-r1][c1-65] )
    {
        case 'P': pawn( 8-r1 , c1-65,8-r2,c2-65);
                  break ;
        case 'R': rook(  8-r1 , c1-65,8-r2,c2-65) ;
                  break ;
        case 'N': knight(  8-r1 , c1-65,8-r2,c2-65);
                  break ;
        case 'B': bishop(  8-r1 , c1-65,8-r2,c2-65);
                  break ;
        case 'K': king( 8-r1 , c1-65,8-r2,c2-65) ;
                  break ;
        case 'Q': queen( 8-r1 , c1-65,8-r2,c2-65) ;
                  break ;
        default: printf("Invalid Position ! ") ; goto again1 ;
    }
    arr1[i]=8-r1; arr2[i]=c1-65; arr3[i]=8-r2; arr4[i]=c2-65;
    i++;
    if(check(8-r2,c2-65)==1){
        printf("check small king..\n");
    }
    invalid_moves_small(8-r2,c2-65);
     stalemate_small_king(8-r2,c2-65);

}

void player2()
{

    int  r1 , r2 ,j=0;
    char c1, c2;
    printf( "\nPLAYER 2 - Small Case \n") ;
    again2:
    printf( "\nEnter Position of Element to change and position sent to: " ) ;
    scanf( "\n%c%d%c%d" ,&c1,&r1,&c2 ,&r2) ;
    // to prevent entering any movement until canceling check on it if found
    if(check(arr3[i],arr4[i])==1){change(8-r1,c1-65,8-r2,c2-65);
                                                                    if(check(arr3[i],arr4[i])==1)
                                                                               { printf("cancel check first");
                                                                                  goto again2;}
                                                                              change(8-r2,c2-65,8-r1,r1-65);}

    switch( board[8-r1][c1-65] )
    {
        case 'p': pawn(  8-r1 , c1-65,8-r2,c2-65) ;
                  break ;
        case 'r': rook(  8-r1 , c1-65,8-r2,c2-65 ) ;
                  break ;
        case 'n': knight(  8-r1 , c1-65,8-r2,c2-65) ;
                  break ;
        case 'b': bishop(  8-r1 , c1-65,8-r2,c2-65) ;
                  break ;
        case 'k': king(  8-r1 , c1-65,8-r2,c2-65) ;
                  break ;
        case 'q': queen(  8-r1 , c1-65,8-r2,c2-65) ;
                  break ;
        default: printf( "Invalid Position ! " ) ; goto again2 ;
    }
    row2[j]=8-r2, col2[j]=c2-65; row1[j]=8-r1; col1[j]=c1-65;
    j++;
    if(check2(8-r2,c2-65)==1){printf("white(capital) king is checked (K)\n");}
    invalid_moves_capital(8-r2,c2-65);
    stalmate_capital_king(8-r2,c2-65);


}
//to know which king is checked
//SMALL KING
int check(int r2 , int c2 ){
    int chec=0 ,i;
    //determine if each piece movement can check king or not
    if(board[r2][c2]=='N'){
                if(board[r2+2][c2+1]=='k'|| board[r2+2][c2-1]=='k'||  board[r2-1][c2-2]=='k'||
                board[r2+1][c2+2]=='k' || board[r2-1][c2+2]=='k' || board[r2-2][c2-1]=='k' ||
                board[r2-2][c2+1]=='k' ||board[r2+1][c2-2]=='k')
                 { chec=1;}}
    if (board[r2][c2]=='B'){ int count=0;
           for(i=1;i<=8;++i){
                if(board[r2+i][c2+i]==' '){
                    count++;
           } else {break;}
           }if (board[r2+count+1][c2+count+1]=='k'){
               chec=1;}
           count=0;
           for(i=1;i<=8;++i){
                if(board[r2-i][c2-i]==' '){
                    count++;
           } else{break;} }
           if(board[r2-count-1][c2-count-1]=='k'){chec=1;}
           count=0;
           for (i=1;i<=8;i++){if(board[r2+i][c2-i]==' '){ count++;} else {break;}}if(board[r2+count+1][c2-count-1]=='k'){chec=1;}
           count=0;
           for (i=1;i<=8;i++){ if(board[r2-i][c2+i]==' ' ){ count++;} else {break;}} if (board[r2-count-1][c2+count+1]=='k'){chec=1;}}
    if(board[r2][c2]== 'Q'){
            int count=0;
            for(i=1;i<=8;++i){ if(board[r2+i][c2]==' '){count++; } else{break;}} if(board[r2+count+1][c2]=='k'){chec=1;}
        count=0;
            for(i=1;i<=8;++i){ if(board[r2][c2+i]==' '){count++;} else {break;}} if(board[r2][c2+count+1]=='k'){chec=1;}
        count=0;
           for(i=1;i<=8;++i){ if(board[r2-i][c2] ==' ' ){count++;} else {break;}}if (board[r2-i][c2]=='k'){chec=1;}
       count=0;
          for(i=1;i<=8;++i){ if(board[r2][c2-i]==' '){ count++;} else {break;}} if(board[r2][c2-i]=='k'){chec=1;}
        count=0;
          for(i=1;i<=8;++i){
                if(board[r2+i][c2+i]==' '){
                     count++;
          } else {break;}}
          if (board[r2+count+1][c2+count+1]=='k'){chec=1;}
        count=0;
           for(i=1;i<=8;++i){ if(board[r2-i][c2-i]==' '){ count++;} else{break;} }if(board[r2-count-1][c2-count-1]=='k'){chec=1;}
      count=0;
           for (i=1;i<=8;i++){if(board[r2+i][c2-i]==' '){ count++;} else {break;}}if(board[r2+count+1][c2-count-1]=='k'){chec=1;}
        count=0;
           for (i=1;i<=8;i++){ if(board[r2-i][c2+i]==' ' ){ count++;} else {break;}} if (board[r2-count-1][c2+count+1]=='k'){chec=1;}}
   if (board[r2][c2]=='P'){
            if (board[r2+1][c2+1]=='k' || board[r2+1][c2-1]=='k'){ chec=1;}}
    if (board[r2][c2]=='R'){ int count=0;
        for(i=1;i<=8;++i){ if(board[r2+i][c2]==' '){count++; } else{break;}} if(board[r2+count+1][c2]=='k'){chec=1;}
        count=0;
        for(i=1;i<=8;++i){ if(board[r2][c2+i]==' '){count++;} else {break;}} if(board[r2][c2+count+1]=='k'){chec=1;}
        count=0;
       for(i=1;i<=8;++i){ if(board[r2-i][c2] ==' ' ){count++;} else {break;}}if (board[r2-i][c2]=='k'){chec=1;}
       count=0;
      for(i=1;i<=8;++i){ if(board[r2][c2-i]==' '){ count++;} else {break;}} if(board[r2][c2-i]=='k'){chec=1;}}
  return chec;
}

int check2(int r2 , int c2 ){
    int check=0,i;
    // determine movements of small player if it can check capital king
    if (board[r2][c2]=='n'){
        if(board[r2+2][c2+1]=='K'|| board[r2+2][c2-1]=='K'||  board[r2-1][c2-2]=='K'||
                board[r2+1][c2+2]=='K' || board[r2-1][c2+2]=='K' || board[r2-2][c2-1]=='K' ||board[r2-2][c2+1]=='K' ||board[r2+1][c2-2]=='K')
                 { check=1;}}
    if (board[r2][c2]=='b'){ int count=0;
          for(i=1;i<8;++i){ if(board[r2+i][c2+i]==' '){ count++;} else {break;}}if (board[r2+count+1][c2+count+1]=='K'){check=1;}
           count=0;
           for(i=1;i<8;++i){ if(board[r2-i][c2-i]==' '){ count++;} else{break;} }if(board[r2-count-1][c2-count-1]=='K'){check=1;}
           count=0;
           for (i=1;i<8;i++){if(board[r2+i][c2-i]==' '){ count++;} else {break;}}if(board[r2+count+1][c2-count-1]=='K'){check=1;}
           count=0;
           for (i=1;i<8;i++){ if(board[r2-i][c2+i]==' ' ){ count++;} else {break;}} if (board[r2-count-1][c2+count+1]=='K'){check=1;}}
    if(board[r2][c2]== 'q'){ int count=0;
           for(i=1;i<8;++i){ if(board[r2+i][c2+i]==' '){ count++;} else {break;}}if (board[r2+count+1][c2+count+1]=='K'){check=1;}
       count=0;
           for(i=1;i<8;++i){ if(board[r2-i][c2-i]==' '){ count++;} else{break;} }if(board[r2-count-1][c2-count-1]=='K'){check=1;}
       count=0;
           for (i=1;i<8;i++){if(board[r2+i][c2-i]==' '){ count++;} else {break;}}if(board[r2+count+1][c2-count-1]=='K'){check=1;}
       count=0;
           for (i=1;i<8;i++){ if(board[r2-i][c2+i]==' ' ){ count++;} else {break;}} if (board[r2-count-1][c2+count+1]=='K'){check=1;}
       count=0;
           for(i=1;i<8;++i){ if(board[r2+i][c2]==' '){count++; } else{break;}} if(board[r2+count+1][c2]=='K'){check=1;}
       count=0;
          for(i=1;i<8;++i){ if(board[r2][c2+i]==' '){count++;} else {break;}} if(board[r2][c2+count+1]=='K'){check=1;}
       count=0;
       for(i=1;i<8;++i){ if(board[r2-i][c2] ==' ' ){count++;} else {break;}}if (board[r2-i][c2]=='K'){check=1;}
       count=0;
      for(i=1;i<8;++i){ if(board[r2][c2-i]==' '){ count++;} else {break;}} if(board[r2][c2-i]=='K'){check=1;}}
    if (board[r2][c2]=='p'){
            if (board[r2-1][c2+1]=='K' || board[r2-1][c2-1]=='K'){ check=1;}}

     if (board[r2][c2]=='r'){ int count=0;
          for(i=1;i<8;++i){ if(board[r2+i][c2]==' '){count++; } else{break;}} if(board[r2+count+1][c2]=='K'){check=1;}
        count=0;
        for(i=1;i<8;++i){ if(board[r2][c2+i]==' '){count++;} else {break;}} if(board[r2][c2+count+1]=='K'){check=1;}
        count=0;
       for(i=1;i<8;++i){ if(board[r2-i][c2] ==' ' ){count++;} else {break;}}if (board[r2-i][c2]=='K'){check=1;}
       count=0;
      for(i=1;i<8;++i){ if(board[r2][c2-i]==' '){ count++;} else {break;}} if(board[r2][c2-i]=='K'){check=1;}}
     return check;
}



/////Choosing the suitable promoted piece by the user
void promotion(int r2 ,int c2){
    char piece,tmp;
    again3:
    printf("Enter the piece that you want to promote the pawn to : ");
    scanf(" \n%c", &piece);
     if( (piece =='N' ) || (piece =='B' )|| (piece =='Q' ) || (piece =='R' ) ){

              tmp = board[r2][c2];
              board[r2][c2] = piece;
        }else{
             printf("invalid PIECE \n");goto again3;
        }
}

void promotion2(int r2,int c2){
    char piece,tmp;
    again3:
    printf("enter the piece that you want to promote the pawn to : ");
    scanf(" \n%c", &piece);

          if((piece =='n' ) || (piece =='b' )|| (piece =='q' ) || (piece =='r' )){
            tmp = board[r2][c2];
              board[r2][c2] = piece;
          }else{
             printf("invalid PIECE \n");goto again3;
        }
}
int o,l,p,q,d,f,g,h;
char boardBEFOREundo[8][8];
///////////////////////////////////////
void undo(int x){
    int i,j;
    for(i=0;i<8;i++){
        for (j=0;j<8;j++){
            boardBEFOREundo[i][j]=board[i][j];
        }
    }
    int o,l,p,q;
 if(x%2==1){
   //To determine the length of the array of input
   int n=sizeof *arr1/sizeof arr1[0];
    o=arr1[n-1];
    p=arr2[n-1];
    l=arr3[n-1];
    q=arr4[n-1];
  change(l,q,o,p);
   if(eat_board[arr1[n-1]][arr2[n-1]]=='P'||'R'||'N'||'B'||'Q'){
        char www=eat_board[arr1[n-1]][arr2[n-1]];
   eat_board[arr1[n-1]][arr2[n-1]]=' ';
   board[l][q]=www;
   }
   //make that places null in array after undo
   arr1[n-1]=arr2[n-1]=arr3[n-1]=arr4[n-1]=' ';
   player1();

 }else if(x%2==0){ int d,f,g,h;
    int m=sizeof *row1/sizeof row1[0];
    d=row1[m-1];
    f=col1[m-1];
    g=row2[m-1];
    h=col2[m-1];
   change(g,h,d,f);
   if(eat_board[row1[m-1]][col1[m-1]]=='p'||'r'||'n'||'b'||'q'){
        char done=eat_board[row1[m-1]][col1[m-1]];
   eat_board[row1[m-1]][col1[m-1]]=' ';
   board[g][h]=done;}
   row1[m-1]=col1[m-1]=row2[m-1]=col2[m-1]=' ';
   player2();
 }
 undodone=1;
}
////////////////////
void redo(){int i,j;
 for(i=0;i<8;i++){
    for(j=0;j<8;j++){
        board[i][j]=boardBEFOREundo[i][j];
    }
 }
}
//////////////////////////

//to save the played game
void save(int x){ char fileName[100],r;
   FILE *fpointer;

   printf("ENTER NAME OF THE FILE:");
   scanf("%c",&r);
   gets(fileName);

   fpointer=fopen(fileName,"w");
   //to save the last board of chess
   for(i=0;i<8;i++){
      for (j=0;j<8;j++){
        putc(board[i][j],fpointer);
      }
   }
   //to save the eaten board
   for(i=0;i<8;i++){
    for(j=0;j<8;j++){
        putc(eat_board[i][j],fpointer);
    }
   }
   //if player1(black) is the last player returns 0
   //if player2 (white) is the last player returns 1
   if(x%2==0){ putw(1,fpointer); }
   else { putw(0,fpointer); }

   fclose(fpointer);
}

//to load a previous game
int load(char board[8][8],char eat_board[8][8]){
  char fileName[100],l,i,j,k,r;
  FILE *fpointer;
  scanf("%c",&l);
  while(1){
    printf("Enter the name of the file:");
    gets(fileName);
    if(fpointer){ break;}
    else{printf("FILE IS NOT FOUND ");}
  }
  fpointer=fopen(fileName,"r");
  for(i=0;i<8;i++){
    for(j=0;j<8;j++){
        k=getc(fpointer);
        board[i][j]=k;
    }
  }
  for(i=0;i<8;i++){
    for(j=0;j<8;j++){
       r=getc(fpointer);
       eat_board[i][j]=r;
    }
  }
  //if it is one means its second player turn (white)
 if(getw(fpointer)==1){fclose(fpointer); return 1;}
 else{ fclose(fpointer); return 0;}
}

int invalid_moves_capital(int r2,int c2){
     if(invalid_movesCapitalBishop(r2,c2)==1 && invalid_movesCapitalKnight(r2,c2)==1 && invalid_movesCapitalRook(r2,c2)==1
       && invalid_movesCapitalQueen(r2,c2)==1 && invalid_movesCapitalPawn(r2,c2)==1 && invalid_movesCapitalKing(r2,c2)==1
       && check2(r2,c2)==1){
        printf("CHECKMATE..SMALL WINS..");wwins=1;
       }else{
           printf("VALID MOVE..\n");
       }
}
int invalid_movesCapitalKnight(int r2,int c2){
///search for capital knight
int count=0;int flag=0;
int n,m,i,j;
for(i=0;i<8;++i){
  for(j=0;j<8;++j){
        if(board[i][j]== 'N'){
            n=i;m=j;

    ///all possible moves

    if(board[n+2][m+1]!='Q'||'P'||'K'||'B'||'N'||'R'){
             count++;
                 change(n,m,n+2,m+1);
 if(check2(r2,c2)==1){
           ++flag;
      change(n+2,m+1,n,m);
        }else{

          change(n+2,m+1,n,m);
            }}

    if (board[n+2][m-1]!='Q'||'P'||'K'||'B'||'N'||'R'){
             count++;
                 change(n,m,n+2,m-1);
                  if(check2(r2,c2)==1){
                   ++flag;
              change(n+2,m-1,n,m);
                 }else{
                 change(n+2,m-1,n,m);
                     }}

    if(board[n-1][m-2]!='Q'||'P'||'K'||'B'||'N'||'R'){
             count++;
            change(n,m,n-1,m-2);
    if(check2(r2,c2)==1){
            ++flag;
    change(n-1,m-2,n,m);
    }else{
         change(n-1,m-2,n,m);}}

    if(board[n+1][m+2]!='Q'||'P'||'K'||'B'||'N'||'R'){
              count++;
            change(n,m,n+1,m+2);
        if(check2(r2,c2)==1){
            ++flag;
    change(n+1,m+2,n,m);
    }else{

         change(n+1,m+2,n,m);}}

    if(board[n-1][m+2]!='Q'||'P'||'K'||'B'||'N'||'R'){
              count++;
            change(n,m,n-1,m+2);
    if(check2(r2,c2)==1){
            ++flag;
    change(n-1,m+2,n,m);
    }else{ change(n-1,m+2,n,m); }}

    if(board[n-2][m-1]!='Q'||'P'||'K'||'B'||'N'||'R'){
             count++;
            change(n,m,n-2,m-1);
    if(check2(r2,c2)==1){
            ++flag;
    change(n-2,m-1,n,m);
    }else{ change(n-2,m-1,n,m); }}

    if(board[n-2][m+1]!='Q'||'P'||'K'||'B'||'N'||'R'){
             count++;
            change(n,m,n-2,m+1);
    if(check2(r2,c2)==1){
            ++flag;
    change(n-2,m+1,n,m);
    }else{ change(n-2,m+1,n,m); }}

    if(board[n+1][m-2]!='Q'||'P'||'K'||'B'||'N'||'R'){
             count++;
            change(n,m,n+1,m-2);
    if(check2(r2,c2)==1){
          ++flag;
    change(n+1,m-2,n,m);
     }else{change(n+1,m-2,n,m); }}



        }

    }

}
if(count==flag){
    return 1;}
}
int invalid_movesCapitalPawn(int r2,int c2){

    int count ,flag;
        ///search for capital pawns
         int x,y;
count=0;flag=0;
         for(i=0;i<8;++i){
            for(j=0;j<8;++j){
             if(board[i][j]== 'P'){
                    x=i;  y=j;
                    //all possible moves of small pawns
   if( board[x+1][y]=' '){
        count++;
        char temp=board[x+1][y];
        board[x][y]=' ';
        board[x+1][y]='P';
   if(check2(r2,c2)==1){
        ++flag;
   }
   board[x][y]='P';
    board[x+1][y]=temp;
   }

   else if( board[x+2][y]== ' ' && x==1){
           count++;
        char temp=board[x+2][y];
        board[x][y]=' ';
        board[x+2][y]='P';
   if(check2(r2,c2)==1){
        ++flag;
   } board[x][y]='P';
    board[x+2][y]=temp;}

   else if(board[x+1][y+1]== 'b' || 'n' || 'p' || 'k' || 'q' || 'r'){
               count++;
        char temp=board[x+1][y+1];
        board[x][y]=' ';
        board[x+1][y+1]='P';
   if(check2(r2,c2)==1){
        ++flag;
   } board[x][y]='P';
    board[x+1][y+1]=temp;}

   else if(board[x+1][y-1]== 'b' || 'n' || 'p' || 'k' || 'q' || 'r'){
          count++;
        char temp=board[x+1][y-1];
        board[x][y]=' ';
        board[x+1][y-1]='P';
   if(check2(r2,c2)==1){
        ++flag;
   } board[x][y]='P';
    board[x+1][y-1]=temp;}
}
            }

         }
         if(count==flag){
              return 1;}


}
int invalid_movesCapitalQueen(int r2,int c2){

int count,flag;
int i,j,r,c;
count=0;flag=0;
///search for capital queen

for(i=0;i<8;i++){
   for(j=0;j<8;++j){
        if(board[i][j]== 'Q'){
            ///all possible moves of small queen
for(int t=1;i+t<8,j+t<8;++t){
        int v=i+t;
        int e=j+t;
    if(board[v][e]!= 'Q' || 'R' || 'B' || 'N' || 'K' || 'P'){
            ++count;

            char tmp=board[v][e];
            board[i][j]=' ';
            board[v][e]='Q';
            if(check(r2,c2)==1){
                ++flag;
            }
             board[i][j]='Q';
             board[v][e]=tmp;}
             if( board[v][e]!=' '){
                    break;}
  }

  for(int w=1;i+w<=8,j-w>=0;++w){
      int f=i+w;
      int s=j-w;
      if(board[f][s]!= 'Q' || 'R' || 'B' || 'N' || 'K' || 'P'){
            ++count;

            char tmp=board[f][s];
            board[i][j]=' ';
            board[f][s]='Q';
            if(check2(r2,c2)==1){
                ++flag;
            }
             board[i][j]='Q';
             board[f][s]=tmp;}
             if( board[f][s]!=' '){
                    break;}
  }



  for(int o=1;i-o<=0,j+o<8;++o){
      int h=i-o;
      int x=j+o;
      if(board[h][x]!='R' || 'P' || 'Q' || 'K' || 'B' || 'N'){
            ++count;

            char tmp=board[h][x];
            board[i][j]=' ';
            board[h][x]='Q';
            if(check2(r2,c2)==1){
                ++flag;
            }
             board[i][j]='Q';
             board[h][x]=tmp;}
             if( board[h][x]!=' '){
                    break;}

  }

   for(int l=1;i-l>=0,j-l>=0;++l){
    int y=i-l;
    int a=j-l;
    if(board[y][a]!= 'R' || 'P' || 'Q' || 'K' || 'B' || 'N'){
            ++count;

            char tmp=board[y][a];
            board[i][j]=' ';
            board[y][a]='Q';
            if(check2(r2,c2)==1){
                ++flag;
            }
             board[i][j]='Q';
             board[y][a]=tmp;}
             if( board[y][a]!=' '){
                    break;}
      }

      for(int t=1;i-t>=0;i++){

           int m=i-t;
    if(board[m][j]!= 'R' || 'P' || 'Q' || 'K' || 'B' || 'N'){
           ++count;
           char tmp=board[m][j];
           board[i][j]= ' ';
           board[m][j]='Q';
           if(check2(r2,c2)==1){
            ++flag;
           }
           board[i][j]='Q';
           board[m][j]=tmp;
            }
            if(board[m][j]!=' '){
                break;}
        }
    for(int y=1;i+y<8;++i){
        int g=i+y;
    if(board[g][j]!= 'R' || 'P' || 'Q' || 'K' || 'B' || 'N'){
            ++count;
        int tmp=board[g][j];
        board[i][j]=' ';
        board[g][j]='Q';
        if(check2(r2,c2)==1){
            ++flag;
        }
     board[i][j]='Q';
           board[g][j]=tmp;
        }if(board[g][j]!=' '){
                break;}
    }
for(int h=1;j+h<8;++h){
    int u=j+h;
    if(board[i][u]!= 'R' || 'P' || 'Q' || 'K' || 'B' || 'N'){
            ++count;
        int tmp=board[i][u];
        board[i][j]=' ';
        board[i][u]='Q';
        if(check2(r2,c2)==1){
            ++flag;
        }
     board[i][j]='Q';
    board[i][u]=tmp;
}if(board[i][u]!=' '){
                break;}
        }

for(int z=1;j-z>=0;++z){
     int a=j-z;
    if(board[i][a]!= 'R' || 'P' || 'Q' || 'K' || 'B' || 'N'){
           ++count;
        int tmp=board[i][a];
        board[i][j]=' ';
        board[i][a]='Q';
        if(check2(r2,c2)==1){
            ++flag;
        }
     board[i][j]='Q';
           board[i][a]=tmp;
}if(board[i][a]!=' '){
                break;}


}


         }}}


         if(count==flag){
    return 1;
   }

}
int invalid_movesCapitalKing(int r2,int c2){
    int i,j,r,c,count,flag;
    count=0;flag=0;
    ///search for capital king
    for(i=0;i<8;++i){
        for(j=0;j<8;++j){
            if(board[i][j]== 'K'){
    if(board[i+1][j]== ' ' || 'p' || 'b' || 'k' || 'q' || 'r' || 'n' ){
            ++count;
          char tmp=board[i+1][j];
          board[i][j]=' ';
          board[i+1][j]='K';
    if(check2(r2,c2)==1){
     ++flag;
   }
   board[i][j]='K';
   board[i+1][j]=tmp;
    }


   else if(board[i][j+1]== ' ' || 'p' || 'b' || 'k' || 'q' || 'r' || 'n'){
             ++count;
          char tmp=board[i][j+1];
          board[i][j+1]=' ';
          board[i][j+1]='K';
    if(check2(r2,c2)==1){
     ++flag;
   }
   board[i][j]='K';
   board[i][j+1]=tmp;}

   else if(board[i][j-1]== ' ' || 'p' || 'b' || 'k' || 'q' || 'r' || 'n'){
             ++count;
          char tmp=board[i][j-1];
          board[i][j]=' ';
          board[i][j-1]='K';
    if(check2(r2,c2)==1){
     ++flag;
   }
   board[i][j]='K';
   board[i][j-1]=tmp;}


   else if(board[i-1][j]== ' ' || 'p' || 'b' || 'k' || 'q' || 'r' || 'n'){
            ++count;
          char tmp=board[i-1][j];
          board[i][j]=' ';
          board[i-1][j]='K';
    if(check2(r2,c2)==1){
     ++flag;
   }
   board[i][j]='K';
   board[i-1][j]=tmp;}

   else if(board[i+1][j+1]== ' ' || 'p' || 'b' || 'k' || 'q' || 'r' || 'n'){
             ++count;
          char tmp=board[i+1][j+1];
          board[i][j]=' ';
          board[i+1][j+1]='K';
    if(check2(r2,c2)==1){
     ++flag;
   }
   board[i][j]='K';
  board[i+1][j+1]=tmp;}


   else if(board[i-1][j+1]== ' ' || 'p' || 'b' || 'k' || 'q' || 'r' || 'n'){
            ++count;
          char tmp=board[i-1][j+1];
          board[i][j]=' ';
          board[i-1][j+1]='K';
    if(check2(r2,c2)==1){
     ++flag;
   }
   board[i][j]='K';
   board[i-1][j+1]=tmp;}

    else if(board[i-1][j-1]== ' ' || 'p' || 'b' || 'k' || 'q' || 'r' || 'n'){
              ++count;
          char tmp=board[i-1][j-1];
          board[i][j]=' ';
          board[i-1][j-1]='K';
    if(check2(r2,c2)==1){
     ++flag;
   }
   board[i][j]='K';
   board[i-1][j-1]=tmp;}

    else if(board[i+1][j-1]== ' ' || 'p' || 'b' || 'k' || 'q' || 'r' || 'n'){
            ++count;
          char tmp=board[i+1][j-1];
          board[i][j]=' ';
          board[i+1][j-1]='K';
    if(check2(r2,c2)==1){
     ++flag;
   }
   board[i][j]='K';
   board[i+1][j-1]=tmp;}

   }
        }
    }
    if(count==flag){
        return 1;
    }

}
int invalid_movesCapitalBishop(int r2,int c2){
//search for capital bishop
int r,c;

int count=0;int flag=0;
for(i=0;i<8;i++){
    for(j=0;j<8;++j){
        if(board[i][j]== 'B'){
            ///all possible moves of bishop
for(int t=1;i+t<8,j+t<8;++t){
        int v=i+t;
        int e=j+t;
    if(board[v][e]!= 'Q' || 'R' || 'B' || 'N' || 'K' || 'P'){
            ++count;

            char tmp=board[v][e];
            board[i][j]=' ';
            board[v][e]='B';
            if(check(r2,c2)==1){
                ++flag;
            }
             board[i][j]='B';
             board[v][e]=tmp;}
             if( board[v][e]!=' '){
                    break;}
  }

  for(int w=1;i+w<=8,j-w>=0;++w){
      int f=i+w;
      int s=j-w;
      if(board[f][s]!= 'Q' || 'R' || 'B' || 'N' || 'K' || 'P'){
            ++count;

            char tmp=board[f][s];
            board[i][j]=' ';
            board[f][s]='B';
            if(check2(r2,c2)==1){
                ++flag;
            }
             board[i][j]='B';
             board[f][s]=tmp;}
             if( board[f][s]!=' '){
                    break;}
  }



  for(int o=1;i-o<=0,j+o<8;++o){
      int h=i-o;
      int x=j+o;
      if(board[h][x]!='R' || 'P' || 'Q' || 'K' || 'B' || 'N'){
            ++count;

            char tmp=board[h][x];
            board[i][j]=' ';
            board[h][x]='B';
            if(check2(r2,c2)==1){
                ++flag;
            }
             board[i][j]='B';
             board[h][x]=tmp;}
             if( board[h][x]!=' '){
                    break;}

  }

   for(int l=1;i-l>=0,j-l>=0;++l){
    int y=i-l;
    int a=j-l;
    if(board[y][a]!= 'R' || 'P' || 'Q' || 'K' || 'B' || 'N'){
            ++count;

            char tmp=board[y][a];
            board[i][j]=' ';
            board[y][a]='B';
            if(check2(r2,c2)==1){
                ++flag;
            }
             board[i][j]='B';
             board[y][a]=tmp;}
             if( board[y][a]!=' '){
                    break;}
      }


        }}}
        if(count==flag){
           return 1;
        }


}
int invalid_movesCapitalRook(int r2,int c2){
    ////search for capital rook
    int flag,count;
        int n,m;

        count=0; flag=0;

    for(i=0;i<8;++i){
       for(j=0;j<8;++j){
            if(board[i][j]== 'R'){

    for(int t=1;i-t>=0;t++){

            m=i-t;
    if(board[m][j]!= 'R' || 'P' || 'Q' || 'K' || 'B' || 'N'){
           ++count;
           char tmp=board[m][j];
           board[i][j]= ' ';
           board[m][j]='R';
           if(check2(r2,c2)==1){
            ++flag;
           }
           board[i][j]='R';
           board[m][j]=tmp;
            }
            if(board[m][j]!=' '){
                break;}
        }
    for(int y=1;i+y<=8;++y){
        int g=i+y;
    if(board[g][j]!= 'R' || 'P' || 'Q' || 'K' || 'B' || 'N'){
            ++count;
        int tmp=board[g][j];
        board[i][j]=' ';
        board[g][j]='R';
        if(check2(r2,c2)==1){
            ++flag;
        }
     board[i][j]='R';
           board[g][j]=tmp;
        }if(board[g][j]!=' '){
                break;}
    }
for(int h=1;j+h<=8;++h){
    int u=j+h;
    if(board[i][u]!= 'R' || 'P' || 'Q' || 'K' || 'B' || 'N'){
            ++count;
        int tmp=board[i][u];
        board[i][j]=' ';
        board[i][u]='R';
        if(check2(r2,c2)==1){
            ++flag;
        }
     board[i][j]='R';
           board[i][u]=tmp;
}if(board[i][u]!=' '){
                break;}}

for(int z=1;j-z>=0;++z){
     int a=j-z;
    if(board[i][a]!= 'R' || 'P' || 'Q' || 'K' || 'B' || 'N'){
           ++count;
        int tmp=board[i][a];
        board[i][j]=' ';
        board[i][a]='R';
        if(check2(r2,c2)==1){
            ++flag;
        }
     board[i][j]='R';
           board[i][a]=tmp;
}if(board[i][a]!=' '){
                break;}
}


}}}
    if(count==flag){
        return 1;
    }

}
int invalid_moves_small(int r2,int c2){

    if(invalid_movesSmallBishop(r2,c2)==1 && invalid_movesSmallKnight(r2,c2)==1 && invalid_movesSmallRook(r2,c2)==1
      && invalid_movesSmallPawn(r2,c2)==1 && invalid_movesSmallKing(r2,c2)==1
       && check(r2,c2)==1){
        printf("CHECKMATE..CAPITAL WINS");bwins=1;
       }else{
           printf("VALID MOVE\n");
       }


}
int invalid_movesSmallKing(int r2,int c2){
    int i,j,count,flag;
    count=0;flag=0;
    ///search for small king
    for(i=0;i<8;++i){
        for(j=0;j<8;++j){
            if(board[i][j]== 'k'){
    if(board[i+1][j]== ' ' || 'P' || 'B' || 'K' || 'Q' || 'R' || 'N' ){
            ++count;
          char tmp=board[i+1][j];
          board[i][j]=' ';
          board[i+1][j]='k';
    if(check(r2,c2)==1){
     ++flag;
   }
   board[i][j]='k';
   board[i+1][j]=tmp;
    }


   else if(board[i][j+1]== ' ' || 'P' || 'B' || 'K' || 'Q' || 'R' || 'N'){
             ++count;
          char tmp=board[i][j+1];
          board[i][j+1]=' ';
          board[i][j+1]='k';
    if(check(r2,c2)==1){
     ++flag;
   }
   board[i][j]='k';
   board[i][j+1]=tmp;}

   else if(board[i][j-1]== ' ' || 'P' || 'B' || 'K' || 'Q' || 'R' || 'N'){
             ++count;
          char tmp=board[i][j-1];
          board[i][j]=' ';
          board[i][j-1]='k';
    if(check(r2,c2)==1){
     ++flag;
   }
   board[i][j]='k';
   board[i][j-1]=tmp;}


   else if(board[i-1][j]== ' ' || 'P' || 'B' || 'K' || 'Q' || 'R' || 'N'){
            ++count;
          char tmp=board[i-1][j];
          board[i][j]=' ';
          board[i-1][j]='k';
    if(check(r2,c2)==1){
     ++flag;
   }
   board[i][j]='k';
   board[i-1][j]=tmp;}

   else if(board[i+1][j+1]== ' ' || 'P' || 'B' || 'K' || 'Q' || 'R' || 'N'){
             ++count;
          char tmp=board[i+1][j+1];
          board[i][j]=' ';
          board[i+1][j+1]='k';
    if(check(r2,c2)==1){
     ++flag;
   }
   board[i][j]='k';
   board[i+1][j+1]=tmp;}


   else if(board[i-1][j+1]== ' ' || 'P' || 'B' || 'K' || 'Q' || 'R' || 'N'){
            ++count;
          char tmp=board[i-1][j+1];
          board[i][j]=' ';
          board[i-1][j+1]='k';
    if(check(r2,c2)==1){
     ++flag;
   }
   board[i][j]='k';
   board[i-1][j+1]=tmp;}

    else if(board[i-1][j-1]== ' ' || 'P' || 'B' || 'K' || 'Q' || 'R' || 'N'){
              ++count;
          char tmp=board[i-1][j-1];
          board[i][j]=' ';
          board[i-1][j-1]='k';
    if(check(r2,c2)==1){
     ++flag;
   }
   board[i][j]='k';
   board[i-1][j-1]=tmp;}

    else if(board[i+1][j-1]== ' ' || 'P' || 'B' || 'K' || 'Q' || 'R' || 'N'){
            ++count;
          char tmp=board[i+1][j-1];
          board[i][j]=' ';
          board[i+1][j-1]='k';
    if(check(r2,c2)==1){
     ++flag;
   }
   board[i][j]='k';
   board[i+1][j-1]=tmp;}

   }
        }
    }
    if(count==flag){
        return 1;
    }

}
/////////////////
int invalid_movesSmallRook(int r2,int c2){
    ////search for small rook
    int flag,count;
        int n,m;

        count=0; flag=0;

    for(i=0;i<8;++i){
       for(j=0;j<8;++j){
            if(board[i][j]== 'r'){

    for(int t=1;i-t>=0;t++){

            m=i-t;
    if(board[m][j]!= 'r' || 'p' || 'q' || 'k' || 'b' || 'n'){
           ++count;
           char tmp=board[m][j];
           board[i][j]= ' ';
           board[m][j]='r';
           if(check(r2,c2)==1){
            ++flag;
           }
           board[i][j]='r';
           board[m][j]=tmp;
            }
            if(board[m][j]!=' '){
                break;}
        }
    for(int y=1;i+y<=8;++y){
        int g=i+y;
    if(board[g][j]!= 'r' || 'p' || 'q' || 'k' || 'b' || 'n'){
            ++count;
        int tmp=board[g][j];
        board[i][j]=' ';
        board[g][j]='r';
        if(check(r2,c2)==1){
            ++flag;
        }
     board[i][j]='r';
           board[g][j]=tmp;
        }if(board[g][j]!=' '){
                break;}
    }
for(int h=1;j+h<=8;++h){
    int u=j+h;
    if(board[i][u]!= 'r' || 'p' || 'q' || 'k' || 'b' || 'n'){
            ++count;
        int tmp=board[i][u];
        board[i][j]=' ';
        board[i][u]='r';
        if(check(r2,c2)==1){
            ++flag;
        }
     board[i][j]='r';
           board[i][u]=tmp;
}if(board[i][u]!=' '){
                break;}}

for(int z=1;j-z>=0;++z){
     int a=j-z;
    if(board[i][a]!= 'r' || 'p' || 'q' || 'k' || 'b' || 'n'){
           ++count;
        int tmp=board[i][a];
        board[i][j]=' ';
        board[i][a]='r';
        if(check(r2,c2)==1){
            ++flag;
        }
     board[i][j]='r';
           board[i][a]=tmp;
}if(board[i][a]!=' '){
                break;}
}


}}}
    if(count==flag){
        return 1;
    }

}
/// / / //////////////////
int invalid_movesSmallBishop(int r2,int c2){
//search for small bishop
int r,c;

int count=0;int flag=0;
for(i=0;i<8;i++){
    for(j=0;j<8;++j){
        if(board[i][j]== 'b'){
    ///all possible moves of bishop

  for(int t=1;i+t<8,j+t<8;++t){
        int v=i+t;
        int e=j+t;
    if(board[v][e]!= 'Q' || 'R' || 'B' || 'N' || 'K' || 'P'){
            ++count;

            char tmp=board[v][e];
            board[i][j]=' ';
            board[v][e]='b';
            if(check(r2,c2)==1){
                ++flag;
            }
             board[i][j]='b';
             board[v][e]=tmp;}
             if( board[v][e]!=' '){
                    break;}
  }

  for(int w=1;i+w<=8,j-w>=0;++w){
      int f=i+w;
      int s=j-w;
      if(board[f][s]!= 'Q' || 'R' || 'B' || 'N' || 'K' || 'P'){
            ++count;

            char tmp=board[f][s];
            board[i][j]=' ';
            board[f][s]='b';
            if(check(r2,c2)==1){
                ++flag;
            }
             board[i][j]='b';
             board[f][s]=tmp;}
             if( board[f][s]!=' '){
                    break;}
  }



  for(int o=1;i-o<=0,j+o<8;++o){
      int h=i-o;
      int x=j+o;
      if(board[h][x]!= 'Q' || 'R' || 'B' || 'N' || 'K' || 'P'){
            ++count;

            char tmp=board[h][x];
            board[i][j]=' ';
            board[h][x]='b';
            if(check(r2,c2)==1){
                ++flag;
            }
             board[i][j]='b';
             board[h][x]=tmp;}
             if( board[h][x]!=' '){
                    break;}

  }

   for(int l=1;i-l>=0,j-l>=0;++l){
    int y=i-l;
    int a=j-l;
    if(board[y][a]!= 'Q' || 'R' || 'B' || 'N' || 'K' || 'P'){
            ++count;

            char tmp=board[y][a];
            board[i][j]=' ';
            board[y][a]='b';
            if(check(r2,c2)==1){
                ++flag;
            }
             board[i][j]='b';
             board[y][a]=tmp;}
             if( board[y][a]!=' '){
                    break;}
      }

        }}}
        if(count==flag){
            return 1;
        }


}
//////////////////////
int invalid_movesSmallQueen(int r2,int c2){

int count, flag;
int i,j,r,c;
///search for small queen
flag=0;count=0;
for(i=0;i<8;i++){
   for(j=0;j<8;++j){
        if(board[i][j]== 'q'){
            ///all possible moves of small queen
for(int t=1;i+t<8,j+t<8;++t){
        int v=i+t;
        int e=j+t;
    if(board[v][e]!= 'q' || 'r' || 'b' || 'n' || 'k' || 'p'){
            ++count;

            char tmp=board[v][e];
            board[i][j]=' ';
            board[v][e]='q';
            if(check(r2,c2)==1){
                ++flag;
            }
             board[i][j]='q';
             board[v][e]=tmp;}
             if( board[v][e]!=' '){
                    break;}
  }

  for(int w=1;i+w<=8,j-w>=0;++w){
      int f=i+w;
      int s=j-w;
      if(board[f][s]!= 'q' || 'r' || 'b' || 'n' || 'k' || 'p'){
            ++count;

            char tmp=board[f][s];
            board[i][j]=' ';
            board[f][s]='q';
            if(check(r2,c2)==1){
                ++flag;
            }
             board[i][j]='q';
             board[f][s]=tmp;}
             if( board[f][s]!=' '){
                    break;}
  }



  for(int o=1;i-o<=0,j+o<8;++o){
      int h=i-o;
      int x=j+o;
      if(board[h][x]!= 'q' || 'r' || 'b' || 'n' || 'k' || 'p'){
            ++count;

            char tmp=board[h][x];
            board[i][j]=' ';
            board[h][x]='q';
            if(check(r2,c2)==1){
                ++flag;
            }
             board[i][j]='q';
             board[h][x]=tmp;}
             if( board[h][x]!=' '){
                    break;}

  }

   for(int l=1;i-l>=0,j-l>=0;++l){
    int y=i-l;
    int a=j-l;
    if(board[y][a]!= 'q' || 'r' || 'b' || 'n' || 'k' || 'p'){
            ++count;

            char tmp=board[y][a];
            board[i][j]=' ';
            board[y][a]='q';
            if(check(r2,c2)==1){
                ++flag;
            }
             board[i][j]='q';
             board[y][a]=tmp;}
             if( board[y][a]!=' '){
                    break;}
      }
      for(int t=1;i-t>=0;t++){

           int m=i-t;
    if(board[m][j]!= 'r' || 'p' || 'q' || 'k' || 'b' || 'n'){
           ++count;
           char tmp=board[m][j];
           board[i][j]= ' ';
           board[m][j]='q';
           if(check(r2,c2)==1){
            ++flag;
           }
           board[i][j]='q';
           board[m][j]=tmp;
            }
            if(board[m][j]!=' '){
                break;}
        }
    for(int y=1;i+y<8;++y){
        int g=i+y;
    if(board[g][j]!= 'r' || 'p' || 'q' || 'k' || 'b' || 'n'){
            ++count;
        int tmp=board[g][j];
        board[i][j]=' ';
        board[g][j]='q';
        if(check(r2,c2)==1){
            ++flag;
        }
     board[i][j]='q';
           board[g][j]=tmp;
        }if(board[g][j]!=' '){
                break;}
    }
for(int h=1;j+h<8;++h){
    int u=j+h;
    if(board[i][u]!= 'r' || 'p' || 'q' || 'k' || 'b' || 'n'){
            ++count;
        int tmp=board[i][u];
        board[i][j]=' ';
        board[i][u]='q';
        if(check(r2,c2)==1){
            ++flag;
        }
     board[i][j]='q';
           board[i][u]=tmp;
}if(board[i][u]!=' '){
                break;}}

for(int z=1;j-z>=0;++z){
     int a=j-z;
    if(board[i][a]!= 'r' || 'p' || 'q' || 'k' || 'b' || 'n'){
           ++count;
        int tmp=board[i][a];
        board[i][j]=' ';
        board[i][a]='q';
        if(check(r2,c2)==1){
            ++flag;
        }
     board[i][j]='q';
           board[i][a]=tmp;
}if(board[i][a]!=' '){
                break;}


}



        }}}

         if(count==flag){
    return 1;
   }

}
int invalid_movesSmallPawn(int r2,int c2){

    int count ,flag;
        ///search for small pawns
         int x,y;
count=0;flag=0;
         for(i=0;i<8;++i){
            for(j=0;j<8;++j){
             if(board[i][j]== 'p'){
                    x=i;  y=j;
                    //all possible moves of small pawns
   if(board[x-1][y]= ' '){
        count++;
        char temp=board[x-1][y];
        board[x][y]=' ';
        board[x-1][y]='p';
   if(check(r2,c2)==1){
        ++flag;
   }
   board[x][y]='p';
    board[x-1][y]=temp;
   }

   else if( board[x-2][y]== ' ' && x==6){
           count++;
        char temp=board[x-2][y];
        board[x][y]=' ';
        board[x-2][y]='p';
   if(check(r2,c2)==1){
        ++flag;
   } board[x][y]='p';
    board[x-2][y]=temp;}

   else if(board[x-1][y-1]== 'B' || 'N' || 'P' || 'K' || 'Q' || 'R'){
               count++;
        char temp=board[x-1][y-1];
        board[x][y]=' ';
        board[x-1][y-1]='p';
   if(check(r2,c2)==1){
        ++flag;
   } board[x][y]='p';
    board[x-1][y-1]=temp;}

   else if(board[x-1][y+1]== 'B' || 'N' || 'P' || 'K' || 'Q' || 'R'){
          count++;
        char temp=board[x-1][y+1];
        board[x][y]=' ';
        board[x-1][y+1]='p';
   if(check(r2,c2)==1){
        ++flag;
   } board[x][y]='p';
    board[x-1][y+1]=temp;}
}
            }

         }
         if(count==flag)
              return 1;


}
///////////////////////////
int invalid_movesSmallKnight(int r2,int c2){
///search for small knight
int checkmate=0;
int count=0;int flag=0;
int n,m,i,j;
for(i=1;i<=8;++i){
  for(j=1;j<=8;++j){
        if(board[i][j]== 'n'){
            n=i;m=j;

    ///all possible moves

    if(board[n+2][m+1]!='q'||'n'||'p'||'k'||'b'||'r'){
             count++;
                 change(n,m,n+2,m+1);
 if(check(r2,c2)==1){
           ++flag;
      change(n+2,m+1,n,m);
        }else{

          change(n+2,m+1,n,m);
            }}

    if (board[n+2][m-1]!='q'||'p'||'n'||'k'||'b'||'r'){
             count++;
                 change(n,m,n+2,m-1);
                  if(check(r2,c2)==1){
                   ++flag;
              change(n+2,m-1,n,m);
                 }else{
                 change(n+2,m-1,n,m);
                     }}

    if(board[n-1][m-2]!='q'||'p'||'k'||'n'||'b'||'r'){
             count++;
            change(n,m,n-1,m-2);
    if(check(r2,c2)==1){
            ++flag;
    change(n-1,m-2,n,m);
    }else{
         change(n-1,m-2,n,m);}}

    if(board[n+1][m+2]!='q'||'p'||'k'||'b'||'n'||'r'){
              count++;
            change(n,m,n+1,m+2);
        if(check(r2,c2)==1){
            ++flag;
    change(n+1,m+2,n,m);
    }else{

         change(n+1,m+2,n,m);}}

    if(board[n-1][m+2]!='q'||'n'||'p'||'k'||'b'||'r'){
              count++;
            change(n,m,n-1,m+2);
    if(check(r2,c2)==1){
            ++flag;
    change(n-1,m+2,n,m);
    }else{ change(n-1,m+2,n,m); }}

    if(board[n-2][m-1]!='q'||'p'||'n'||'k'||'b'||'r'){
             count++;
            change(n,m,n-2,m-1);
    if(check(r2,c2)==1){
            ++flag;
    change(n-2,m-1,n,m);
    }else{ change(n-2,m-1,n,m); }}

    if(board[n-2][m+1]!='q'||'p'||'k'||'n'||'b'||'r'){
             count++;
            change(n,m,n-2,m+1);
    if(check(r2,c2)==1){
            ++flag;
    change(n-2,m+1,n,m);
    }else{ change(n-2,m+1,n,m); }}

    if(board[n+1][m-2]!='q'||'p'||'k'||'b'||'n'||'r'){
             count++;
            change(n,m,n+1,m-2);
    if(check(r2,c2)==1){
          ++flag;
    change(n+1,m-2,n,m);
     }else{change(n+1,m-2,n,m); }}



        }

    }

}
if(count==flag){
        checkmate=1;
    }else{
        checkmate=0;
    }
    return checkmate;
}


int dead_position(){
    int count=0,deadposition=0;
 for(i=0;i<8;i++){
    for(j=0;j<8;j++){
        if(board[i][j]==' '){
            count++;
        }
    }
 }
  if(count==62){int kingfound=0;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
           if(board[i][j]=='k'||board[i][j]=='K'){ kingfound++;}
        }
    }
if(kingfound==2 ){ deadposition=1;}}

 else if(count==61){int kingfound=0, knightfound=0, bishopfound=0;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(board[i][j]=='k'||board[i][j]=='K'){kingfound++;}
            else if(board[i][j]=='B'||board[i][j]=='b'){bishopfound++;}
            else if(board[i][j]=='n'||board[i][j]=='N'){knightfound++;}
        }
    }
    if(kingfound==2 && bishopfound==1){deadposition=1; }
    else if(kingfound==2 && knightfound==1){deadposition=1;}
 }
 else if(count==60){int kingfound=0, twobishops=0,found1=0, nn,kk,uu,yy;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(board[i][j]=='k'||board[i][j]=='K'){kingfound++;}
            else if(board[i][j]=='b'){  uu=i ;
                 yy=j; found1++; }
            else if(board[i][j]=='B'){found1++; nn=i;  kk=j;}
        }
    }
    //to determine that two bishops are on the same colour
   if(found1==2){ if(black_white_b[uu][yy]=='-'&& black_white_b[nn][kk]=='-'){ twobishops++; if(twobishops==1 && kingfound==2){deadposition=1;} }
    else if(black_white_b[uu][yy]=='.' && black_white_b[nn][kk]=='.'){twobishops++;
    if(twobishops==1 && kingfound==2){deadposition=1;}}}
 }
return deadposition;
}

void stalmate_capital_king(int r2,int c2){
    if( check2(r2,c2)==0  && (checked_capital_king_aftermove()==1 &&  threatenpiece_capital(r2,c2)==1) ){
        printf("draw by stalemate...");wwins=1;
    }
}
int threatenpiece_capital(int r2, int c2){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[i][j]=='K'){
                 if(((r2+1==i+1)&& (c2+1==j+1) && (board[i+1][j+1]== ' ')  ) ||
            ((r2+1==i+1) && (c2+1==j-1) && (board[i+1][j-1]==' ')) ||
            ((r2+1==i-1) && (c2+1==j-1) && (board[i-1][j-1]==' ')) ||
            ((r2+1==i-1) && (c2+1==j+1) && (board[i-1][j+1]==' ')) ||
            ((r2+1==i-1) && (c2+1==j) && (board[i-1][j]==' ')) ||
            ((r2+1==i) && (c2+1==j+1) && (board[i][j+1]==' '))||
            ((r2+1==i) && (c2+1==j-1) && (board[i][j-1]==' ')) ||
            ((r2+1==i-1) && (c2+1==j) && (board[i-1][j]==' '))){
                return 1;
            }
            if(((r2+1==i+1)&& (c2-1==j+1) && (board[i+1][j+1]== ' ')) ||
            ((r2+1==i+1) && (c2-1==j-1) && (board[i+1][j-1]==' '))||
            ((r2+1==i-1) && (c2-1==j-1) && (board[i-1][j-1]==' ')) ||
            ((r2+1==i-1) && (c2-1==j+1) && (board[i-1][j+1]==' ')) ||
            ((r2+1==i-1) && (c2-1==j) && (board[i-1][j]==' ')) ||
            ((r2+1==i) && (c2-1==j+1) && (board[i][j+1]==' ')) ||
            ((r2+1==i) && (c2-1==j-1) && (board[i][j-1]==' ')) ||
            ((r2+1==i-1) && (c2-1==j) && (board[i-1][j]==' '))){
                 return 1;
            }
            if(((r2-1==i+1)&& (c2+1==j+1) && (board[i+1][j+1]== ' ' ) ) ||
            ((r2-1==i+1) && (c2+1==j-1) && (board[i+1][j-1]==' ')) ||
            ((r2-1==i-1) && (c2+1==j-1) && (board[i-1][j-1]==' '))||
            ((r2-1==i-1) && (c2+1==j+1) && (board[i-1][j+1]==' ')) ||
            ((r2-1==i-1) && (c2+1==j) && (board[i-1][j]==' ')) ||
            ((r2-1==i) && (c2+1==j+1) && (board[i][j+1]==' ')) ||
            ((r2-1==i) && (c2+1==j-1) && (board[i][j-1]==' ')) ||
            ((r2-1==i-1) && (c2+1==j) && (board[i-1][j]==' '))){
                 return 1;
            }
            if(((r2-1==i+1)&& (c2-1==j+1) && (board[i+1][j+1]== ' ' ) ) ||
            ((r2-1==i+1) && (c2-1==j-1) && (board[i+1][j-1]==' ')) ||
            ((r2-1==i-1) && (c2-1==j-1) && (board[i-1][j-1]==' ')) ||
            ((r2-1==i-1) && (c2-1==j+1) && (board[i-1][j+1]==' ')) ||
            ((r2-1==i-1) && (c2-1==j) && (board[i-1][j]==' ')) ||
            ((r2-1==i) && (c2-1==j+1) && (board[i][j+1]==' ')) ||
            ((r2-1==i) && (c2-1==j-1) && (board[i][j-1]==' ')) ||
            ((r2-1==i-1) && (c2-1==j) && (board[i-1][j]==' '))){
                return 1;
            }
            if(((r2==i+1)&& (c2+1==j+1) && (board[i+1][j+1]== ' ')  ) ||
            ((r2==i+1) && (c2+1==j-1) && (board[i+1][j-1]==' ')) ||
            ((r2==i-1) && (c2+1==j-1) && (board[i-1][j-1]==' ')) ||
            ((r2==i-1) && (c2+1==j+1) && (board[i-1][j+1]==' ') )||
            ((r2==i-1) && (c2+1==j) && (board[i-1][j]==' ')) ||
            ((r2==i) && (c2+1==j+1) && (board[i][j+1]==' ') )||
            ((r2==i) && (c2+1==j-1) && (board[i][j-1]==' ')) ||
            ((r2==i-1) && (c2+1==j) && (board[i-1][j]==' '))){
                return 1;
            }
            if(((r2==i+1)&& (c2-1==j+1) && (board[i+1][j+1]== ' ')  ) ||
            ((r2==i+1) && (c2-1==j-1) && (board[i+1][j-1]==' ')) ||
            ((r2==i-1) && (c2-1==j-1) && (board[i-1][j-1]==' ')) ||
            ((r2==i-1) && (c2-1==j+1) && (board[i-1][j+1]==' ')) ||
            ((r2==i-1) && (c2-1==j) && (board[i-1][j]==' ')) ||
            ((r2==i) && (c2-1==j+1) && (board[i][j+1]==' ')) ||
            ((r2==i) && (c2-1==j-1) && (board[i][j-1]==' ')) ||
            ((r2==i-1) && (c2-1==j) && (board[i-1][j]==' '))){
                return 1;
            }
            if(((r2+1==i+1)&& (c2==j+1) && (board[i+1][j+1]== ' ' ) ) ||
            ((r2+1==i+1) && (c2==j-1) && (board[i+1][j-1]==' ')) ||
            ((r2+1==i-1) && (c2==j-1) && (board[i-1][j-1]==' ')) ||
            ((r2+1==i-1) && (c2==j+1) && (board[i-1][j+1]==' ')) ||
            ((r2+1==i-1) && (c2==j) && (board[i-1][j]==' ')) ||
            ((r2+1==i) && (c2==j+1) && (board[i][j+1]==' ')) ||
            ((r2+1==i) && (c2==j-1) && (board[i][j-1]==' ')) ||
            ((r2+1==i-1) && (c2==j) && (board[i-1][j]==' '))){
                return 1;
            }
            if(((r2-1==i+1)&& (c2==j+1) && (board[i+1][j+1]== ' ')  ) ||
            ((r2-1==i+1) && (c2==j-1) && (board[i+1][j-1]==' ')) ||
            ((r2-1==i-1) && (c2==j-1) && (board[i-1][j-1]==' ')) ||
            ((r2-1==i-1) && (c2==j+1) && (board[i-1][j+1]==' ')) ||
            ((r2-1==i-1) && (c2==j) && (board[i-1][j]==' ')) ||
            ((r2-1==i) && (c2==j+1) && (board[i][j+1]==' ') )||
            ((r2-1==i) && (c2==j-1) && (board[i][j-1]==' ')) ||
            ((r2-1==i-1) && (c2==j) && (board[i-1][j]==' '))){
                 return 1;
            }

        }
    }
    }


}
int checked_capital_king_aftermove(){
    int count=0, flag=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;++j){
            if(board[i][j]=='K'){
                if((board[i+1][j]== ' ') || (board[i+1][j]=='p') || (board[i+1][j]=='b')  ||
                   (board[i+1][j]=='q') || (board[i+1][j]=='r') || (board[i+1][j]=='n') ){
                      ++count;

                   char tmp=board[i+1][j];
                    board[i][j]=' ';
                    board[i+1][j]='K';
                    int x=i+1;int z=j;
                    int o=0,a=0, g=0 ,h=0,f=0,e=0,w=0,m=0;
                    for(int t=0;t<8;++t){
                           if(board[x+t][z]==' '){
                                o++;}else{break;}}
                        for(int u=0;u<8;++u){
                            if(board[x+u][z+u]==' '){
                                    a++;}else{break;}}
                    for(int s=0;s<8;++s){
                            if(board[x+s][z-s]==' '){
                                ++g;
                            }else{break;}}
                   for(int d=0;d<8;++d){
                            if(board[x-d][z-d]==' '){
                                ++h;
                            }else{break;}}
                    for(int v=0;v<8;++v){
                            if(board[x-v][z+v]==' '){
                                ++f;
                            }else{break;}}
                     for(int r=0;r<8;++r){
                            if(board[x-r][z]==' '){
                                ++e;
                            }else{break;}}
                     for(int l=0;l<8;++l){
                            if(board[x][l+1]==' '){
                                ++w;
                            }else{break;}}
                     for(int n=0;n<8;++n){
                            if(board[x][n-1]==' '){
                                ++m;
                            }else{break;}}
              if( board[x+2][z+1]=='n'|| board[x+2][z-1]=='n'||  board[x-1][z-2]=='n'||
                board[x+1][z+2]=='n' || board[x-1][z+2]=='n' || board[x-2][z-1]=='n' ||
                board[x-2][z+1]=='n' || board[x+1][z-2]=='n' || board[x+1][z+1]=='p' ||
                board[x+1][z-1]=='p' || board[x+o+1][z]=='q' || board[x+a+1][z+a+1]=='q' ||
                board[x+g+1][z-g-1]=='q' || board[x-h-1][z-h-1]=='q' || board[x-f-1][z+f+1]=='q' ||
                board[x-e-1][z]=='q' || board[x][z+w+1]=='q' || board[x][z-m-1]=='q' || board[x+a+1][z+a+1]=='b' ||
                board[x-h-1][z-h-1]=='b' || board[x+g+1][z-g-1]=='b' || board[x-f-1][z+f+1]=='b' || board[x+o+1][z]=='r' ||
                 board[x-e-1][z]=='r' || board[x][z+w+1]=='r' || board[x][z-m-1]=='r' ){
             ++flag;

   }
                  board[x-1][z]='K';
                  board[x][z]=tmp;}

 if(count==flag){return 1;}
                            count=0;flag=0;
      if((board[i][j+1]== ' ') || (board[i][j+1]=='p') || (board[i][j+1]=='b')  ||
          (board[i][j+1]=='q') || (board[i][j+1]=='r') || (board[i][j+1]=='n')){
             ++count;

          char tmp=board[i][j+1];
          board[i][j+1]=' ';
          board[i][j+1]='K';
          int x=i;int z=j+1;
                   int o=0,a=0, g=0 ,h=0,f=0,e=0,w=0,m=0;
                    for(int t=0;t<8;++t){
                           if(board[x+t][z]==' '){
                                o++;}else{break;}}
                        for(int u=0;u<8;++u){
                            if(board[x+u][z+u]==' '){
                                    a++;}else{break;}}
                    for(int s=0;s<8;++s){
                            if(board[x+s][z-s]==' '){
                                ++g;
                            }else{break;}}
                   for(int d=0;d<8;++d){
                            if(board[x-d][z-d]==' '){
                                ++h;
                            }else{break;}}
                    for(int v=0;v<8;++v){
                            if(board[x-v][z+v]==' '){
                                ++f;
                            }else{break;}}
                     for(int r=0;r<8;++r){
                            if(board[x-r][z]==' '){
                                ++e;
                            }else{break;}}
                     for(int l=0;l<8;++l){
                            if(board[x][l+1]==' '){
                                ++w;
                            }else{break;}}
                     for(int n=0;n<8;++n){
                            if(board[x][n-1]==' '){
                                ++m;
                            }else{break;}}
              if( board[x+2][z+1]=='n'|| board[x+2][z-1]=='n'||  board[x-1][z-2]=='n'||
                board[x+1][z+2]=='n' || board[x-1][z+2]=='n' || board[x-2][z-1]=='n' ||
                board[x-2][z+1]=='n' || board[x+1][z-2]=='n' || board[x+1][z+1]=='p' ||
                board[x+1][z-1]=='p' || board[x+o+1][z]=='q' || board[x+a+1][z+a+1]=='q' ||
                board[x+g+1][z-g-1]=='q' || board[x-h-1][z-h-1]=='q' || board[x-f-1][z+f+1]=='q' ||
                board[x-e-1][z]=='q' || board[x][z+w+1]=='q' || board[x][z-m-1]=='q' || board[x+a+1][z+a+1]=='b' ||
                board[x-h-1][z-h-1]=='b' || board[x+g+1][z-g-1]=='b' || board[x-f-1][z+f+1]=='b' || board[x+o+1][z]=='r' ||
                 board[x-e-1][z]=='r' || board[x][z+w+1]=='r' || board[x][z-m-1]=='r' ){
                            ++flag;

                            }
                        board[x][z-1]='K';
                        board[x][z]=tmp;}
 if(count==flag){return 1;}
                            count=0;flag=0;
       if((board[i][j-1]== ' ') || (board[i][j-1]=='p') || (board[i][j-1]=='b')  || (board[i][j-1]=='q') ||
           (board[i][j-1]=='r') || (board[i][j-1]=='n')){
                               ++count;

          char tmp=board[i][j-1];
          board[i][j]=' ';
          board[i][j-1]='K';
                 int x=i;int z=j-1;
                   int o=0,a=0, g=0 ,h=0,f=0,e=0,w=0,m=0;
                    for(int t=0;t<8;++t){
                           if(board[x+t][z]==' '){
                                o++;}else{break;}}
                        for(int u=0;u<8;++u){
                            if(board[x+u][z+u]==' '){
                                    a++;}else{break;}}
                    for(int s=0;s<8;++s){
                            if(board[x+s][z-s]==' '){
                                ++g;
                            }else{break;}}
                   for(int d=0;d<8;++d){
                            if(board[x-d][z-d]==' '){
                                ++h;
                            }else{break;}}
                    for(int v=0;v<8;++v){
                            if(board[x-v][z+v]==' '){
                                ++f;
                            }else{break;}}
                     for(int r=0;r<8;++r){
                            if(board[x-r][z]==' '){
                                ++e;
                            }else{break;}}
                     for(int l=0;l<8;++l){
                            if(board[x][l+1]==' '){
                                ++w;
                            }else{break;}}
                     for(int n=0;n<8;++n){
                            if(board[x][n-1]==' '){
                                ++m;
                            }else{break;}}
              if( board[x+2][z+1]=='n'|| board[x+2][z-1]=='n'||  board[x-1][z-2]=='n'||
                board[x+1][z+2]=='n' || board[x-1][z+2]=='n' || board[x-2][z-1]=='n' ||
                board[x-2][z+1]=='n' || board[x+1][z-2]=='n' || board[x+1][z+1]=='p' ||
                board[x+1][z-1]=='p' || board[x+o+1][z]=='q' || board[x+a+1][z+a+1]=='q' ||
                board[x+g+1][z-g-1]=='q' || board[x-h-1][z-h-1]=='q' || board[x-f-1][z+f+1]=='q' ||
                board[x-e-1][z]=='q' || board[x][z+w+1]=='q' || board[x][z-m-1]=='q' || board[x+a+1][z+a+1]=='b' ||
                board[x-h-1][z-h-1]=='b' || board[x+g+1][z-g-1]=='b' || board[x-f-1][z+f+1]=='b' || board[x+o+1][z]=='r' ||
                 board[x-e-1][z]=='r' || board[x][z+w+1]=='r' || board[x][z-m-1]=='r' ){
                      ++flag;

                       }
                  board[x][z+1]='K';
                      board[x][z]=tmp;}

 if(count==flag){return 1;}
                            count=0;flag=0;
     if((board[i-1][j]== ' ') || (board[i-1][j]=='p') || (board[i-1][j]=='b')  ||
         (board[i-1][j]=='q') || (board[i-1][j]=='r') || (board[i-1][j]=='n')){
            ++count;

          char tmp=board[i-1][j];
          board[i][j]=' ';
          board[i-1][j]='K';
    int x=i-1;int z=j;
                   int o=0,a=0, g=0 ,h=0,f=0,e=0,w=0,m=0;
                    for(int t=0;t<8;++t){
                           if(board[x+t][z]==' '){
                                o++;}else{break;}}
                        for(int u=0;u<8;++u){
                            if(board[x+u][z+u]==' '){
                                    a++;}else{break;}}
                    for(int s=0;s<8;++s){
                            if(board[x+s][z-s]==' '){
                                ++g;
                            }else{break;}}
                   for(int d=0;d<8;++d){
                            if(board[x-d][z-d]==' '){
                                ++h;
                            }else{break;}}
                    for(int v=0;v<8;++v){
                            if(board[x-v][z+v]==' '){
                                ++f;
                            }else{break;}}
                     for(int r=0;r<8;++r){
                            if(board[x-r][z]==' '){
                                ++e;
                            }else{break;}}
                     for(int l=0;l<8;++l){
                            if(board[x][l+1]==' '){
                                ++w;
                            }else{break;}}
                     for(int n=0;n<8;++n){
                            if(board[x][n-1]==' '){
                                ++m;
                            }else{break;}}
              if( board[x+2][z+1]=='n'|| board[x+2][z-1]=='n'||  board[x-1][z-2]=='n'||
                board[x+1][z+2]=='n' || board[x-1][z+2]=='n' || board[x-2][z-1]=='n' ||
                board[x-2][z+1]=='n' || board[x+1][z-2]=='n' || board[x+1][z+1]=='p' ||
                board[x+1][z-1]=='p' || board[x+o+1][z]=='q' || board[x+a+1][z+a+1]=='q' ||
                board[x+g+1][z-g-1]=='q' || board[x-h-1][z-h-1]=='q' || board[x-f-1][z+f+1]=='q' ||
                board[x-e-1][z]=='q' || board[x][z+w+1]=='q' || board[x][z-m-1]=='q' || board[x+a+1][z+a+1]=='b' ||
                board[x-h-1][z-h-1]=='b' || board[x+g+1][z-g-1]=='b' || board[x-f-1][z+f+1]=='b' || board[x+o+1][z]=='r' ||
                 board[x-e-1][z]=='r' || board[x][z+w+1]=='r' || board[x][z-m-1]=='r' ){
                              ++flag;

                                }
                          board[x+1][z]='K';
                          board[x][z]=tmp;}
 if(count==flag){return 1;}
                            count=0;flag=0;
           if((board[i+1][j+1]== ' ') || (board[i+1][j+1]=='p') || (board[i+1][j+1]=='b')  ||
               (board[i+1][j+1]=='q') || (board[i+1][j+1]=='r') || (board[i+1][j+1]=='n')){
             ++count;
          char tmp=board[i+1][j+1];
          board[i][j]=' ';
          board[i+1][j+1]='K';
   int x=i+1;int z=j+1;
                   int o=0,a=0, g=0 ,h=0,f=0,e=0,w=0,m=0;
                    for(int t=0;t<8;++t){
                           if(board[x+t][z]==' '){
                                o++;}else{break;}}
                        for(int u=0;u<8;++u){
                            if(board[x+u][z+u]==' '){
                                    a++;}else{break;}}
                    for(int s=0;s<8;++s){
                            if(board[x+s][z-s]==' '){
                                ++g;
                            }else{break;}}
                   for(int d=0;d<8;++d){
                            if(board[x-d][z-d]==' '){
                                ++h;
                            }else{break;}}
                    for(int v=0;v<8;++v){
                            if(board[x-v][z+v]==' '){
                                ++f;
                            }else{break;}}
                     for(int r=0;r<8;++r){
                            if(board[x-r][z]==' '){
                                ++e;
                            }else{break;}}
                     for(int l=0;l<8;++l){
                            if(board[x][l+1]==' '){
                                ++w;
                            }else{break;}}
                     for(int n=0;n<8;++n){
                            if(board[x][n-1]==' '){
                                ++m;
                            }else{break;}}
              if( board[x+2][z+1]=='n'|| board[x+2][z-1]=='n'||  board[x-1][z-2]=='n'||
                board[x+1][z+2]=='n' || board[x-1][z+2]=='n' || board[x-2][z-1]=='n' ||
                board[x-2][z+1]=='n' || board[x+1][z-2]=='n' || board[x+1][z+1]=='p' ||
                board[x+1][z-1]=='p' || board[x+o+1][z]=='q' || board[x+a+1][z+a+1]=='q' ||
                board[x+g+1][z-g-1]=='q' || board[x-h-1][z-h-1]=='q' || board[x-f-1][z+f+1]=='q' ||
                board[x-e-1][z]=='q' || board[x][z+w+1]=='q' || board[x][z-m-1]=='q' || board[x+a+1][z+a+1]=='b' ||
                board[x-h-1][z-h-1]=='b' || board[x+g+1][z-g-1]=='b' || board[x-f-1][z+f+1]=='b' || board[x+o+1][z]=='r' ||
                 board[x-e-1][z]=='r' || board[x][z+w+1]=='r' || board[x][z-m-1]=='r' ){
                                 ++flag;

                                              }
                             board[x-1][z-1]='K';
                            board[x][z]=tmp;}

 if(count==flag){return 1;}
                            count=0;flag=0;
    if((board[i-1][j+1]== ' ') || (board[i-1][j+1]=='p') || (board[i-1][j+1]=='b')  ||
        (board[i-1][j+1]=='q') || (board[i-1][j+1]=='r') || (board[i-1][j+1]=='n')){
            ++count;

          char tmp=board[i-1][j+1];
          board[i][j]=' ';
          board[i-1][j+1]='K';
   int x=i-1;int z=j+1;
                   int o=0,a=0, g=0 ,h=0,f=0,e=0,w=0,m=0;
                    for(int t=0;t<8;++t){
                           if(board[x+t][z]==' '){
                                o++;}else{break;}}
                        for(int u=0;u<8;++u){
                            if(board[x+u][z+u]==' '){
                                    a++;}else{break;}}
                    for(int s=0;s<8;++s){
                            if(board[x+s][z-s]==' '){
                                ++g;
                            }else{break;}}
                   for(int d=0;d<8;++d){
                            if(board[x-d][z-d]==' '){
                                ++h;
                            }else{break;}}
                    for(int v=0;v<8;++v){
                            if(board[x-v][z+v]==' '){
                                ++f;
                            }else{break;}}
                     for(int r=0;r<8;++r){
                            if(board[x-r][z]==' '){
                                ++e;
                            }else{break;}}
                     for(int l=0;l<8;++l){
                            if(board[x][l+1]==' '){
                                ++w;
                            }else{break;}}
                     for(int n=0;n<8;++n){
                            if(board[x][n-1]==' '){
                                ++m;
                            }else{break;}}
              if( board[x+2][z+1]=='n'|| board[x+2][z-1]=='n'||  board[x-1][z-2]=='n'||
                board[x+1][z+2]=='n' || board[x-1][z+2]=='n' || board[x-2][z-1]=='n' ||
                board[x-2][z+1]=='n' || board[x+1][z-2]=='n' || board[x+1][z+1]=='p' ||
                board[x+1][z-1]=='p' || board[x+o+1][z]=='q' || board[x+a+1][z+a+1]=='q' ||
                board[x+g+1][z-g-1]=='q' || board[x-h-1][z-h-1]=='q' || board[x-f-1][z+f+1]=='q' ||
                board[x-e-1][z]=='q' || board[x][z+w+1]=='q' || board[x][z-m-1]=='q' || board[x+a+1][z+a+1]=='b' ||
                board[x-h-1][z-h-1]=='b' || board[x+g+1][z-g-1]=='b' || board[x-f-1][z+f+1]=='b' || board[x+o+1][z]=='r' ||
                 board[x-e-1][z]=='r' || board[x][z+w+1]=='r' || board[x][z-m-1]=='r' ){
                                ++flag;

                                       }
                         board[x+1][z-1]='K';
                         board[x][z]=tmp;}
 if(count==flag){return 1;}
                            count=0;flag=0;
       if((board[i-1][j-1]== ' ') || (board[i-1][j-1]=='p') || (board[i-1][j-1]=='b')  ||
           (board[i-1][j-1]=='q') || (board[i-1][j-1]=='r') || (board[i-1][j-1]=='n')){
              ++count;

          char tmp=board[i-1][j-1];
          board[i][j]=' ';
          board[i-1][j-1]='K';
   int x=i-1;int z=j-1;
                   int o=0,a=0, g=0 ,h=0,f=0,e=0,w=0,m=0;
                    for(int t=0;t<8;++t){
                           if(board[x+t][z]==' '){
                                o++;}else{break;}}
                        for(int u=0;u<8;++u){
                            if(board[x+u][z+u]==' '){
                                    a++;}else{break;}}
                    for(int s=0;s<8;++s){
                            if(board[x+s][z-s]==' '){
                                ++g;
                            }else{break;}}
                   for(int d=0;d<8;++d){
                            if(board[x-d][z-d]==' '){
                                ++h;
                            }else{break;}}
                    for(int v=0;v<8;++v){
                            if(board[x-v][z+v]==' '){
                                ++f;
                            }else{break;}}
                     for(int r=0;r<8;++r){
                            if(board[x-r][z]==' '){
                                ++e;
                            }else{break;}}
                     for(int l=0;l<8;++l){
                            if(board[x][l+1]==' '){
                                ++w;
                            }else{break;}}
                     for(int n=0;n<8;++n){
                            if(board[x][n-1]==' '){
                                ++m;
                            }else{break;}}
              if( board[x+2][z+1]=='n'|| board[x+2][z-1]=='n'||  board[x-1][z-2]=='n'||
                board[x+1][z+2]=='n' || board[x-1][z+2]=='n' || board[x-2][z-1]=='n' ||
                board[x-2][z+1]=='n' || board[x+1][z-2]=='n' || board[x+1][z+1]=='p' ||
                board[x+1][z-1]=='p' || board[x+o+1][z]=='q' || board[x+a+1][z+a+1]=='q' ||
                board[x+g+1][z-g-1]=='q' || board[x-h-1][z-h-1]=='q' || board[x-f-1][z+f+1]=='q' ||
                board[x-e-1][z]=='q' || board[x][z+w+1]=='q' || board[x][z-m-1]=='q' || board[x+a+1][z+a+1]=='b' ||
                board[x-h-1][z-h-1]=='b' || board[x+g+1][z-g-1]=='b' || board[x-f-1][z+f+1]=='b' || board[x+o+1][z]=='r' ||
                 board[x-e-1][z]=='r' || board[x][z+w+1]=='r' || board[x][z-m-1]=='r' ){
                          ++flag;

                              }
                          board[x+1][z+1]='K';
                      board[x][z]=tmp;}
                       if(count==flag){return 1;}
                            count=0;flag=0;
     if((board[i+1][j-1]== ' ') || (board[i+1][j-1]=='p') || (board[i+1][j-1]=='b') || (board[i+1][j-1]=='k') ||
         (board[i+1][j-1]=='q') || (board[i+1][j-1]=='r') || (board[i+1][j-1]=='n')){
            ++count;

          char tmp=board[i+1][j-1];
          board[i][j]=' ';
          board[i+1][j-1]='K';
     int x=i+1;int z=j-1;
                   int o=0,a=0, g=0 ,h=0,f=0,e=0,w=0,m=0;
                    for(int t=0;t<8;++t){
                           if(board[x+t][z]==' '){
                                o++;}else{break;}}
                        for(int u=0;u<8;++u){
                            if(board[x+u][z+u]==' '){
                                    a++;}else{break;}}
                    for(int s=0;s<8;++s){
                            if(board[x+s][z-s]==' '){
                                ++g;
                            }else{break;}}
                   for(int d=0;d<8;++d){
                            if(board[x-d][z-d]==' '){
                                ++h;
                            }else{break;}}
                    for(int v=0;v<8;++v){
                            if(board[x-v][z+v]==' '){
                                ++f;
                            }else{break;}}
                     for(int r=0;r<8;++r){
                            if(board[x-r][z]==' '){
                                ++e;
                            }else{break;}}
                     for(int l=0;l<8;++l){
                            if(board[x][l+1]==' '){
                                ++w;
                            }else{break;}}
                     for(int n=0;n<8;++n){
                            if(board[x][n-1]==' '){
                                ++m;
                            }else{break;}}
              if( board[x+2][z+1]=='n'|| board[x+2][z-1]=='n'||  board[x-1][z-2]=='n'||
                board[x+1][z+2]=='n' || board[x-1][z+2]=='n' || board[x-2][z-1]=='n' ||
                board[x-2][z+1]=='n' || board[x+1][z-2]=='n' || board[x+1][z+1]=='p' ||
                board[x+1][z-1]=='p' || board[x+o+1][z]=='q' || board[x+a+1][z+a+1]=='q' ||
                board[x+g+1][z-g-1]=='q' || board[x-h-1][z-h-1]=='q' || board[x-f-1][z+f+1]=='q' ||
                board[x-e-1][z]=='q' || board[x][z+w+1]=='q' || board[x][z-m-1]=='q' || board[x+a+1][z+a+1]=='b' ||
                board[x-h-1][z-h-1]=='b' || board[x+g+1][z-g-1]=='b' || board[x-f-1][z+f+1]=='b' || board[x+o+1][z]=='r' ||
                 board[x-e-1][z]=='r' || board[x][z+w+1]=='r' || board[x][z-m-1]=='r' ){
                                  ++flag;

                                     }
                            board[x-1][z+1]='K';
                            board[x][z]=tmp;}
 if(count==flag){return 1;}

}}}

}

void stalemate_small_king(int r2,int c2){

    if((threatenpiece_small( r2,  c2)==1) && (check(r2,c2)==0) && (checked_small_king_aftermove()==1) ){

               printf("..........draw by stalemate...");bwins=1;

    }

}

int threatenpiece_small(int r2, int c2){

    for(int i=0;i<8;i++){

        for(int j=0;j<8;j++){

            if(board[i][j]=='k'){

                 if(((r2+1==i+1)&& (c2+1==j+1) && (board[i+1][j+1]== ' ')  ) ||

            ((r2+1==i+1) && (c2+1==j-1) && (board[i+1][j-1]==' ')) ||

            ((r2+1==i-1) && (c2+1==j-1) && (board[i-1][j-1]==' ')) ||

            ((r2+1==i-1) && (c2+1==j+1) && (board[i-1][j+1]==' ')) ||

            ((r2+1==i-1) && (c2+1==j) && (board[i-1][j]==' ')) ||

            ((r2+1==i) && (c2+1==j+1) && (board[i][j+1]==' '))||

            ((r2+1==i) && (c2+1==j-1) && (board[i][j-1]==' ')) ||

            ((r2+1==i-1) && (c2+1==j) && (board[i-1][j]==' '))){

                return 1;

            }

            if(((r2+1==i+1)&& (c2-1==j+1) && (board[i+1][j+1]== ' ')) ||

            ((r2+1==i+1) && (c2-1==j-1) && (board[i+1][j-1]==' '))||

            ((r2+1==i-1) && (c2-1==j-1) && (board[i-1][j-1]==' ')) ||

            ((r2+1==i-1) && (c2-1==j+1) && (board[i-1][j+1]==' ')) ||

            ((r2+1==i-1) && (c2-1==j) && (board[i-1][j]==' ')) ||

            ((r2+1==i) && (c2-1==j+1) && (board[i][j+1]==' ')) ||

            ((r2+1==i) && (c2-1==j-1) && (board[i][j-1]==' ')) ||

            ((r2+1==i-1) && (c2-1==j) && (board[i-1][j]==' '))){

                 return 1;

            }

            if(((r2-1==i+1)&& (c2+1==j+1) && (board[i+1][j+1]== ' ' ) ) ||

            ((r2-1==i+1) && (c2+1==j-1) && (board[i+1][j-1]==' ')) ||

            ((r2-1==i-1) && (c2+1==j-1) && (board[i-1][j-1]==' '))||

            ((r2-1==i-1) && (c2+1==j+1) && (board[i-1][j+1]==' ')) ||

            ((r2-1==i-1) && (c2+1==j) && (board[i-1][j]==' ')) ||

            ((r2-1==i) && (c2+1==j+1) && (board[i][j+1]==' ')) ||

            ((r2-1==i) && (c2+1==j-1) && (board[i][j-1]==' ')) ||

            ((r2-1==i-1) && (c2+1==j) && (board[i-1][j]==' '))){

                 return 1;

            }

            if(((r2-1==i+1)&& (c2-1==j+1) && (board[i+1][j+1]== ' ' ) ) ||

            ((r2-1==i+1) && (c2-1==j-1) && (board[i+1][j-1]==' ')) ||

            ((r2-1==i-1) && (c2-1==j-1) && (board[i-1][j-1]==' ')) ||

            ((r2-1==i-1) && (c2-1==j+1) && (board[i-1][j+1]==' ')) ||

            ((r2-1==i-1) && (c2-1==j) && (board[i-1][j]==' ')) ||

            ((r2-1==i) && (c2-1==j+1) && (board[i][j+1]==' ')) ||

            ((r2-1==i) && (c2-1==j-1) && (board[i][j-1]==' ')) ||

            ((r2-1==i-1) && (c2-1==j) && (board[i-1][j]==' '))){

                return 1;

            }

            if(((r2==i+1)&& (c2+1==j+1) && (board[i+1][j+1]== ' ')  ) ||

            ((r2==i+1) && (c2+1==j-1) && (board[i+1][j-1]==' ')) ||

            ((r2==i-1) && (c2+1==j-1) && (board[i-1][j-1]==' ')) ||

            ((r2==i-1) && (c2+1==j+1) && (board[i-1][j+1]==' ') )||

            ((r2==i-1) && (c2+1==j) && (board[i-1][j]==' ')) ||

            ((r2==i) && (c2+1==j+1) && (board[i][j+1]==' ') )||

            ((r2==i) && (c2+1==j-1) && (board[i][j-1]==' ')) ||

            ((r2==i-1) && (c2+1==j) && (board[i-1][j]==' '))){

                return 1;

            }

            if(((r2==i+1)&& (c2-1==j+1) && (board[i+1][j+1]== ' ')  ) ||

            ((r2==i+1) && (c2-1==j-1) && (board[i+1][j-1]==' ')) ||

            ((r2==i-1) && (c2-1==j-1) && (board[i-1][j-1]==' ')) ||

            ((r2==i-1) && (c2-1==j+1) && (board[i-1][j+1]==' ')) ||

            ((r2==i-1) && (c2-1==j) && (board[i-1][j]==' ')) ||

            ((r2==i) && (c2-1==j+1) && (board[i][j+1]==' ')) ||

            ((r2==i) && (c2-1==j-1) && (board[i][j-1]==' ')) ||

            ((r2==i-1) && (c2-1==j) && (board[i-1][j]==' '))){

                return 1;

            }

            if(((r2+1==i+1)&& (c2==j+1) && (board[i+1][j+1]== ' ' ) ) ||

            ((r2+1==i+1) && (c2==j-1) && (board[i+1][j-1]==' ')) ||

            ((r2+1==i-1) && (c2==j-1) && (board[i-1][j-1]==' ')) ||

            ((r2+1==i-1) && (c2==j+1) && (board[i-1][j+1]==' ')) ||

            ((r2+1==i-1) && (c2==j) && (board[i-1][j]==' ')) ||

            ((r2+1==i) && (c2==j+1) && (board[i][j+1]==' ')) ||

            ((r2+1==i) && (c2==j-1) && (board[i][j-1]==' ')) ||

            ((r2+1==i-1) && (c2==j) && (board[i-1][j]==' '))){

                return 1;

            }

            if(((r2-1==i+1)&& (c2==j+1) && (board[i+1][j+1]== ' ')  ) ||

            ((r2-1==i+1) && (c2==j-1) && (board[i+1][j-1]==' ')) ||

            ((r2-1==i-1) && (c2==j-1) && (board[i-1][j-1]==' ')) ||

            ((r2-1==i-1) && (c2==j+1) && (board[i-1][j+1]==' ')) ||

            ((r2-1==i-1) && (c2==j) && (board[i-1][j]==' ')) ||

            ((r2-1==i) && (c2==j+1) && (board[i][j+1]==' ') )||

            ((r2-1==i) && (c2==j-1) && (board[i][j-1]==' ')) ||

            ((r2-1==i-1) && (c2==j) && (board[i-1][j]==' '))){

                 return 1;

            }



        }}}

}



int checked_small_king_aftermove(){

    int count=0, flag=0;

    for(int i=0;i<8;i++){

        for(int j=0;j<8;++j){

            if(board[i][j]=='k'){

                if((board[i+1][j]== ' ') || (board[i+1][j]=='P') || (board[i+1][j]=='B')  ||

                   (board[i+1][j]=='Q') || (board[i+1][j]=='R') || (board[i+1][j]=='N') ){

                      ++count;



                   char tmp=board[i+1][j];

                    board[i][j]=' ';

                    board[i+1][j]='k';

                    int x=i+1;int z=j;

                    int o=0,a=0, g=0 ,h=0,f=0,e=0,w=0,m=0;

                    for(int t=0;t<8;++t){

                           if(board[x+t][z]==' '){

                                o++;}else{break;}}

                        for(int u=0;u<8;++u){

                            if(board[x+u][z+u]==' '){

                                    a++;}else{break;}}

                    for(int s=0;s<8;++s){

                            if(board[x+s][z-s]==' '){

                                ++g;

                            }else{break;}}

                   for(int d=0;d<8;++d){

                            if(board[x-d][z-d]==' '){

                                ++h;

                            }else{break;}}

                   for(int v=0;v<8;++v){

                            if(board[x-v][z+v]==' '){

                                ++f;

                            }else{break;}}

                     for(int r=0;r<8;++r){

                            if(board[x-r][z]==' '){

                                ++e;

                            }else{break;}}

                     for(int l=0;l<8;++l){

                            if(board[x][l+1]==' '){

                                ++w;

                            }else{break;}}

                     for(int n=0;n<8;++n){

                            if(board[x][n-1]==' '){

                                ++m;

                            }else{break;}}

              if( board[x+2][z+1]=='N'|| board[x+2][z-1]=='N'||  board[x-1][z-2]=='N'||

                board[x+1][z+2]=='N' || board[x-1][z+2]=='N' || board[x-2][z-1]=='N' ||

                board[x-2][z+1]=='N' || board[x+1][z-2]=='N' || board[x-1][z+1]=='P' ||

                board[x-1][z-1]=='P' || board[x+o+1][z]=='q' || board[x+a+1][z+a+1]=='Q' ||

                board[x+g+1][z-g-1]=='Q' || board[x-h-1][z-h-1]=='Q' || board[x-f-1][z+f+1]=='Q' ||

                board[x-e-1][z]=='Q' || board[x][z+w+1]=='Q' || board[x][z-m-1]=='Q' || board[x+a+1][z+a+1]=='B' ||

                board[x-h-1][z-h-1]=='B' || board[x+g+1][z-g-1]=='B' || board[x-f-1][z+f+1]=='B' || board[x+o+1][z]=='R' ||

                 board[x-e-1][z]=='R' || board[x][z+w+1]=='R' || board[x][z-m-1]=='R' ){

             ++flag;



   }

                  board[x-1][z]='k';

                  board[x][z]=tmp;}



if(count==flag){return 1;}

                            count=0;flag=0;

      if((board[i][j+1]== ' ') || (board[i][j+1]=='P') || (board[i][j+1]=='B')  ||

          (board[i][j+1]=='Q') || (board[i][j+1]=='R') || (board[i][j+1]=='N')){

             ++count;



          char tmp=board[i][j+1];

          board[i][j+1]=' ';

          board[i][j+1]='k';

          int x=i;int z=j+1;

                   int o=0,a=0, g=0 ,h=0,f=0,e=0,w=0,m=0;

                    for(int t=0;t<8;++t){

                           if(board[x+t][z]==' '){

                                o++;}else{break;}}

                        for(int u=0;u<8;++u){

                            if(board[x+u][z+u]==' '){

                                    a++;}else{break;}}

                    for(int s=0;s<8;++s){

                            if(board[x+s][z-s]==' '){

                               ++g;

                            }else{break;}}

                   for(int d=0;d<8;++d){

                            if(board[x-d][z-d]==' '){

                                ++h;

                            }else{break;}}

                    for(int v=0;v<8;++v){

                            if(board[x-v][z+v]==' '){

                                ++f;

                            }else{break;}}

                     for(int r=0;r<8;++r){

                            if(board[x-r][z]==' '){

                                ++e;

                            }else{break;}}

                     for(int l=0;l<8;++l){

                            if(board[x][l+1]==' '){

                                ++w;

                            }else{break;}}

                     for(int n=0;n<8;++n){

                            if(board[x][n-1]==' '){

                                ++m;

                            }else{break;}}

              if( board[x+2][z+1]=='N'|| board[x+2][z-1]=='N'||  board[x-1][z-2]=='N'||

                board[x+1][z+2]=='N' || board[x-1][z+2]=='N' || board[x-2][z-1]=='N' ||

                board[x-2][z+1]=='N' || board[x+1][z-2]=='N' || board[x-1][z+1]=='P' ||

                board[x-1][z-1]=='P' || board[x+o+1][z]=='Q' || board[x+a+1][z+a+1]=='Q' ||

                board[x+g+1][z-g-1]=='Q' || board[x-h-1][z-h-1]=='Q' || board[x-f-1][z+f+1]=='Q' ||

                board[x-e-1][z]=='Q' || board[x][z+w+1]=='Q' || board[x][z-m-1]=='Q' || board[x+a+1][z+a+1]=='B' ||

                board[x-h-1][z-h-1]=='B' || board[x+g+1][z-g-1]=='B' || board[x-f-1][z+f+1]=='B' || board[x+o+1][z]=='R' ||

                 board[x-e-1][z]=='R' || board[x][z+w+1]=='R' || board[x][z-m-1]=='R' ){

                            ++flag;



                            }

                        board[x][z-1]='k';

                        board[x][z]=tmp;}

if(count==flag){return 1;}

                            count=0;flag=0;

       if((board[i][j-1]== ' ') || (board[i][j-1]=='P') || (board[i][j-1]=='B')  || (board[i][j-1]=='Q') ||

           (board[i][j-1]=='R') || (board[i][j-1]=='N')){

                               ++count;



          char tmp=board[i][j-1];

          board[i][j]=' ';

          board[i][j-1]='k';

                 int x=i;int z=j-1;

                   int o=0,a=0, g=0 ,h=0,f=0,e=0,w=0,m=0;

                    for(int t=0;t<8;++t){

                           if(board[x+t][z]==' '){

                                o++;}else{break;}}

                        for(int u=0;u<8;++u){

                            if(board[x+u][z+u]==' '){

                                    a++;}else{break;}}

                    for(int s=0;s<8;++s){

                            if(board[x+s][z-s]==' '){

                                ++g;

                            }else{break;}}

                   for(int d=0;d<8;++d){

                            if(board[x-d][z-d]==' '){

                                ++h;

                            }else{break;}}

                    for(int v=0;v<8;++v){

                            if(board[x-v][z+v]==' '){

                                ++f;

                            }else{break;}}

                     for(int r=0;r<8;++r){

                            if(board[x-r][z]==' '){

                                ++e;

                            }else{break;}}

                     for(int l=0;l<8;++l){

                            if(board[x][l+1]==' '){

                                ++w;

                            }else{break;}}

                     for(int n=0;n<8;++n){

                            if(board[x][n-1]==' '){

                                ++m;

                            }else{break;}}

              if( board[x+2][z+1]=='N'|| board[x+2][z-1]=='N'||  board[x-1][z-2]=='N'||

                board[x+1][z+2]=='N' || board[x-1][z+2]=='N' || board[x-2][z-1]=='N' ||

                board[x-2][z+1]=='N' || board[x+1][z-2]=='N' || board[x-1][z+1]=='P' ||

                board[x-1][z-1]=='P' || board[x+o+1][z]=='Q' || board[x+a+1][z+a+1]=='Q' ||

                board[x+g+1][z-g-1]=='Q' || board[x-h-1][z-h-1]=='Q' || board[x-f-1][z+f+1]=='Q' ||

                board[x-e-1][z]=='Q' || board[x][z+w+1]=='Q' || board[x][z-m-1]=='Q' || board[x+a+1][z+a+1]=='B' ||

                board[x-h-1][z-h-1]=='B' || board[x+g+1][z-g-1]=='B' || board[x-f-1][z+f+1]=='B' || board[x+o+1][z]=='R' ||

                 board[x-e-1][z]=='R' || board[x][z+w+1]=='R' || board[x][z-m-1]=='R' ){

                      ++flag;



                       }

                  board[x][z+1]='k';

                      board[x][z]=tmp;}



if(count==flag){return 1;}

                            count=0;flag=0;

     if((board[i-1][j]== ' ') || (board[i-1][j]=='P') || (board[i-1][j]=='B')  ||

         (board[i-1][j]=='Q') || (board[i-1][j]=='R') || (board[i-1][j]=='N')){

            ++count;



          char tmp=board[i-1][j];

          board[i][j]=' ';

          board[i-1][j]='k';

    int x=i-1;int z=j;

                   int o=0,a=0, g=0 ,h=0,f=0,e=0,w=0,m=0;

                    for(int t=0;t<8;++t){

                           if(board[x+t][z]==' '){

                                o++;}else{break;}}

                        for(int u=0;u<8;++u){

                            if(board[x+u][z+u]==' '){

                                    a++;}else{break;}}

                    for(int s=0;s<8;++s){

                            if(board[x+s][z-s]==' '){

                                ++g;

                            }else{break;}}

                   for(int d=0;d<8;++d){

                            if(board[x-d][z-d]==' '){

                                ++h;

                            }else{break;}}

                    for(int v=0;v<8;++v){

                            if(board[x-v][z+v]==' '){

                                ++f;

                            }else{break;}}

                     for(int r=0;r<8;++r){

                            if(board[x-r][z]==' '){

                                ++e;

                            }else{break;}}

                     for(int l=0;l<8;++l){

                            if(board[x][l+1]==' '){

                                ++w;

                            }else{break;}}

                     for(int n=0;n<8;++n){

                            if(board[x][n-1]==' '){

                                ++m;

                            }else{break;}}

              if( board[x+2][z+1]=='N'|| board[x+2][z-1]=='N'||  board[x-1][z-2]=='N'||

                board[x+1][z+2]=='N' || board[x-1][z+2]=='N' || board[x-2][z-1]=='N' ||

                board[x-2][z+1]=='N' || board[x+1][z-2]=='N' || board[x-1][z+1]=='P' ||

                board[x-1][z-1]=='P' || board[x+o+1][z]=='Q' || board[x+a+1][z+a+1]=='Q' ||

                board[x+g+1][z-g-1]=='Q' || board[x-h-1][z-h-1]=='Q' || board[x-f-1][z+f+1]=='Q' ||

                board[x-e-1][z]=='Q' || board[x][z+w+1]=='Q' || board[x][z-m-1]=='Q' || board[x+a+1][z+a+1]=='B' ||

                board[x-h-1][z-h-1]=='B' || board[x+g+1][z-g-1]=='B' || board[x-f-1][z+f+1]=='B' || board[x+o+1][z]=='R' ||

                 board[x-e-1][z]=='R' || board[x][z+w+1]=='R' || board[x][z-m-1]=='R' ){

                              ++flag;



                                }

                          board[x+1][z]='k';

                          board[x][z]=tmp;}

if(count==flag){return 1;}

                            count=0;flag=0;

           if((board[i+1][j+1]== ' ') || (board[i+1][j+1]=='P') || (board[i+1][j+1]=='B')  ||

               (board[i+1][j+1]=='Q') || (board[i+1][j+1]=='R') || (board[i+1][j+1]=='N')){

             ++count;

          char tmp=board[i+1][j+1];

          board[i][j]=' ';

          board[i+1][j+1]='k';

   int x=i+1;int z=j+1;

                   int o=0,a=0, g=0 ,h=0,f=0,e=0,w=0,m=0;

                    for(int t=0;t<8;++t){

                           if(board[x+t][z]==' '){

                                o++;}else{break;}}

                        for(int u=0;u<8;++u){

                            if(board[x+u][z+u]==' '){

                                    a++;}else{break;}}

                    for(int s=0;s<8;++s){

                            if(board[x+s][z-s]==' '){

                                ++g;

                            }else{break;}}

                   for(int d=0;d<8;++d){

                            if(board[x-d][z-d]==' '){

                                ++h;

                            }else{break;}}

                    for(int v=0;v<8;++v){

                            if(board[x-v][z+v]==' '){

                                ++f;

                            }else{break;}}

                     for(int r=0;r<8;++r){

                            if(board[x-r][z]==' '){

                                ++e;

                            }else{break;}}

                     for(int l=0;l<8;++l){

                            if(board[x][l+1]==' '){

                                ++w;

                            }else{break;}}

                     for(int n=0;n<8;++n){

                            if(board[x][n-1]==' '){

                                ++m;

                            }else{break;}}

              if( board[x+2][z+1]=='N'|| board[x+2][z-1]=='N'||  board[x-1][z-2]=='N'||

                board[x+1][z+2]=='N' || board[x-1][z+2]=='N' || board[x-2][z-1]=='N' ||

                board[x-2][z+1]=='N' || board[x+1][z-2]=='N' || board[x-1][z+1]=='P' ||

                board[x-1][z-1]=='P' || board[x+o+1][z]=='Q' || board[x+a+1][z+a+1]=='Q' ||

                board[x+g+1][z-g-1]=='Q' || board[x-h-1][z-h-1]=='Q' || board[x-f-1][z+f+1]=='Q' ||

                board[x-e-1][z]=='Q' || board[x][z+w+1]=='Q' || board[x][z-m-1]=='Q' || board[x+a+1][z+a+1]=='B' ||

                board[x-h-1][z-h-1]=='B' || board[x+g+1][z-g-1]=='B' || board[x-f-1][z+f+1]=='B' || board[x+o+1][z]=='R' ||

                 board[x-e-1][z]=='R' || board[x][z+w+1]=='R' || board[x][z-m-1]=='R' ){

                                 ++flag;



                                              }

                             board[x-1][z-1]='k';

                            board[x][z]=tmp;}



if(count==flag){return 1;}

                            count=0;flag=0;

    if((board[i-1][j+1]== ' ') || (board[i-1][j+1]=='P') || (board[i-1][j+1]=='B')  ||

        (board[i-1][j+1]=='Q') || (board[i-1][j+1]=='R') || (board[i-1][j+1]=='N')){

            ++count;



          char tmp=board[i-1][j+1];

          board[i][j]=' ';

          board[i-1][j+1]='k';

   int x=i-1;int z=j+1;

                   int o=0,a=0, g=0 ,h=0,f=0,e=0,w=0,m=0;

                    for(int t=0;t<8;++t){

                           if(board[x+t][z]==' '){

                                o++;}else{break;}}

                        for(int u=0;u<8;++u){

                            if(board[x+u][z+u]==' '){

                                    a++;}else{break;}}

                    for(int s=0;s<8;++s){

                            if(board[x+s][z-s]==' '){

                                ++g;

                            }else{break;}}

                   for(int d=0;d<8;++d){

                            if(board[x-d][z-d]==' '){

                                ++h;

                            }else{break;}}

                    for(int v=0;v<8;++v){

                            if(board[x-v][z+v]==' '){

                                ++f;

                            }else{break;}}

                     for(int r=0;r<8;++r){

                            if(board[x-r][z]==' '){

                                ++e;

                            }else{break;}}

                     for(int l=0;l<8;++l){

                            if(board[x][l+1]==' '){

                                ++w;

                            }else{break;}}

                     for(int n=0;n<8;++n){

                            if(board[x][n-1]==' '){

                                ++m;

                            }else{break;}}

              if( board[x+2][z+1]=='N'|| board[x+2][z-1]=='N'||  board[x-1][z-2]=='N'||

                board[x+1][z+2]=='N' || board[x-1][z+2]=='N' || board[x-2][z-1]=='N' ||

                board[x-2][z+1]=='N' || board[x+1][z-2]=='N' || board[x-1][z+1]=='P' ||

                board[x-1][z-1]=='P' || board[x+o+1][z]=='q' || board[x+a+1][z+a+1]=='q' ||

                board[x+g+1][z-g-1]=='Q' || board[x-h-1][z-h-1]=='Q' || board[x-f-1][z+f+1]=='Q' ||

                board[x-e-1][z]=='Q' || board[x][z+w+1]=='Q' || board[x][z-m-1]=='Q' || board[x+a+1][z+a+1]=='B' ||

                board[x-h-1][z-h-1]=='B' || board[x+g+1][z-g-1]=='B' || board[x-f-1][z+f+1]=='B' || board[x+o+1][z]=='R' ||

                 board[x-e-1][z]=='R' || board[x][z+w+1]=='R' || board[x][z-m-1]=='R' ){

                                ++flag;



                                       }

                         board[x+1][z-1]='k';

                         board[x][z]=tmp;}

if(count==flag){return 1;}

                            count=0;flag=0;

       if((board[i-1][j-1]== ' ') || (board[i-1][j-1]=='P') || (board[i-1][j-1]=='B')  ||

           (board[i-1][j-1]=='Q') || (board[i-1][j-1]=='R') || (board[i-1][j-1]=='N')){

              ++count;



          char tmp=board[i-1][j-1];

          board[i][j]=' ';

          board[i-1][j-1]='k';

   int x=i-1;int z=j-1;

                   int o=0,a=0, g=0 ,h=0,f=0,e=0,w=0,m=0;

                    for(int t=0;t<8;++t){

                           if(board[x+t][z]==' '){

                                o++;}else{break;}}

                        for(int u=0;u<8;++u){

                            if(board[x+u][z+u]==' '){

                                    a++;}else{break;}}

                    for(int s=0;s<8;++s){

                            if(board[x+s][z-s]==' '){

                                ++g;

                            }else{break;}}

                   for(int d=0;d<8;++d){

                            if(board[x-d][z-d]==' '){

                                ++h;

                            }else{break;}}

                    for(int v=0;v<8;++v){

                            if(board[x-v][z+v]==' '){

                                ++f;

                            }else{break;}}

                     for(int r=0;r<8;++r){

                            if(board[x-r][z]==' '){

                                ++e;

                            }else{break;}}

                     for(int l=0;l<8;++l){

                            if(board[x][l+1]==' '){

                                ++w;

                            }else{break;}}

                     for(int n=0;n<8;++n){

                            if(board[x][n-1]==' '){

                                ++m;

                            }else{break;}}

              if( board[x+2][z+1]=='N'|| board[x+2][z-1]=='N'||  board[x-1][z-2]=='N'||

                board[x+1][z+2]=='N' || board[x-1][z+2]=='N' || board[x-2][z-1]=='N' ||

                board[x-2][z+1]=='N' || board[x+1][z-2]=='N' || board[x-1][z+1]=='P' ||

                board[x-1][z-1]=='P' || board[x+o+1][z]=='q' || board[x+a+1][z+a+1]=='q' ||

                board[x+g+1][z-g-1]=='Q' || board[x-h-1][z-h-1]=='Q' || board[x-f-1][z+f+1]=='Q' ||

                board[x-e-1][z]=='Q' || board[x][z+w+1]=='Q' || board[x][z-m-1]=='Q' || board[x+a+1][z+a+1]=='B' ||

                board[x-h-1][z-h-1]=='B' || board[x+g+1][z-g-1]=='B' || board[x-f-1][z+f+1]=='B' || board[x+o+1][z]=='R' ||

                 board[x-e-1][z]=='R' || board[x][z+w+1]=='R' || board[x][z-m-1]=='R' ){

                          ++flag;



                              }

                          board[x+1][z+1]='k';

                      board[x][z]=tmp;}

                       if(count==flag){return 1;}

                            count=0;flag=0;

     if((board[i+1][j-1]== ' ') || (board[i+1][j-1]=='P') || (board[i+1][j-1]=='B') || (board[i+1][j-1]=='K') ||

         (board[i+1][j-1]=='Q') || (board[i+1][j-1]=='R') || (board[i+1][j-1]=='N')){

            ++count;



          char tmp=board[i+1][j-1];

          board[i][j]=' ';

          board[i+1][j-1]='k';

     int x=i+1;int z=j-1;

                   int o=0,a=0, g=0 ,h=0,f=0,e=0,w=0,m=0;

                    for(int t=0;t<8;++t){

                           if(board[x+t][z]==' '){

                                o++;}else{break;}}

                        for(int u=0;u<8;++u){

                            if(board[x+u][z+u]==' '){

                                    a++;}else{break;}}

                    for(int s=0;s<8;++s){

                            if(board[x+s][z-s]==' '){

                                ++g;

                            }else{break;}}

                   for(int d=0;d<8;++d){

                            if(board[x-d][z-d]==' '){

                                ++h;

                            }else{break;}}

                    for(int v=0;v<8;++v){

                            if(board[x-v][z+v]==' '){

                                ++f;

                            }else{break;}}

                     for(int r=0;r<8;++r){

                            if(board[x-r][z]==' '){

                                ++e;

                            }else{break;}}

                     for(int l=0;l<8;++l){

                            if(board[x][l+1]==' '){

                                ++w;

                            }else{break;}}

                     for(int n=0;n<8;++n){

                            if(board[x][n-1]==' '){

                                ++m;

                            }else{break;}}

              if( board[x+2][z+1]=='N'|| board[x+2][z-1]=='N'||  board[x-1][z-2]=='N'||

                board[x+1][z+2]=='N' || board[x-1][z+2]=='N' || board[x-2][z-1]=='N' ||

                board[x-2][z+1]=='N' || board[x+1][z-2]=='N' || board[x-1][z+1]=='P' ||

                board[x-1][z-1]=='P' || board[x+o+1][z]=='Q' || board[x+a+1][z+a+1]=='Q' ||

                board[x+g+1][z-g-1]=='Q' || board[x-h-1][z-h-1]=='Q' || board[x-f-1][z+f+1]=='Q' ||

                board[x-e-1][z]=='Q' || board[x][z+w+1]=='Q' || board[x][z-m-1]=='Q' || board[x+a+1][z+a+1]=='B' ||

                board[x-h-1][z-h-1]=='B' || board[x+g+1][z-g-1]=='B' || board[x-f-1][z+f+1]=='B' || board[x+o+1][z]=='R' ||

                 board[x-e-1][z]=='R' || board[x][z+w+1]=='R' || board[x][z-m-1]=='R' ){

                                  ++flag;
                                     }
                           board[x-1][z+1]='k';

                            board[x][z]=tmp;}

if(count==flag){return 1;}

}}}

}
