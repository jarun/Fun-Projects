# TicTacToe
Checks the state of a Tic-Tac-Toe game  
  
The board is represented by 3 bytes. Each row is represented by 6 MSBs of a byte. The 2 LSB bits are ignored.  
  
Each square is represented using 2 bits. The meaning of the binary values are:  
00: Empty square  
01: Tick  
10: Cross  
11: Invalid
  
  
# License  
  
GPLv3.0
