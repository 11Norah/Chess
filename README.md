# Chess
Features:

•Twoplayers:

​Human vs. Human.

> UserInterface:

➔You should represent black and white squares using different ASCII characters, e.g.“.”for black squares and “-” for white squares.

➔White  pieces are represented by “p” ,“r” ,“n” ,“b” ,“q” ,“k” for pawns ,rooks ,knights ,bishops ,queen and king respectively. Black pieces are represented by the same letters but capitalized.

➔You should display next to the game board the pieces that are currently taken out from both players.

➔You should display the characters from ‘A’ to ‘H’ to denote the columns above and below the board, along with the numbers from 1 to 8 to denote the rows to the right and left of the board.

>Rules:

➔Your program should support promotion and stalemate. 

➔The game is won by checkmate. 

➔The game may end in a draw by stalemate. 

>Movement:

As shown in the Wikipedia page, each square is indexed by a character and a number (e.g.D1,C3,...etc.). 
The user specifies his next move by entering the index of the piece he wishes to move,followed by the index of the square he wishes to move it to.(e.g.A3B4 will move the piece at A3 to the square B4).
The only exception is in the case of promotion,where the user must specify an additional character indicating the desired piece.(e.g.H7H8B will promote the pawn to a bishop).

>Undo and Redo:

​The game could be undone till the first move.

>Save and Load:

➔At anytime, the game could be saved to a file 

➔A saved game could be loaded and continued 

➔No need to save the undo data.

>GameFlow

​Loop till the end of the game:
(a)Read a move from ​Player1.

(b)Check if it’s a validmove. 

(c)If not valid,ask for another move.

(d)Do the move.

(e)If the move takes out one of the pieces of the other player,add this piece to the list of takenout pieces displayed.

(f)Check if the move results in a ​Check/Checkmate/Stalemate/Promotion​and display a​message​accordingly.
(g)Repeat the same logic for ​Player2
