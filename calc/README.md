# Fun calculator

Problem statement: Write a program that simulates an electronic calculator. The program should follow these rules:

1. The user will always provide input via the command line and then will hit 'ENTER'. Thus, the program should read from console input.

2. If the input is a number (either positive or negative), then the program should add this number to a "stack". Numbers can be whole numbers (3, 5, 7..) or decimals (3.5, 3.823).

3. If the input is any of the following symbols: +, -, , then the program should apply that 'operation' to the "stack" and then print the result. For example, if the user entered '*' and the stack contained the numbers 10, 15, and 20, then the program should do 10  15  20 and then print the result. The program should always "narrate" what it is about to do: ("Multipling 10  15 * 20.  Result is 3000).

4. If the input is the letter 'C' (either capital or lowercase) then the program should "clear" the stack (erase all numbers).

## License

GPLv3.0
