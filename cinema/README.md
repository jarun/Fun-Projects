# Fun calculator  
  
Problem statement: Write a program that simulates an electronic calculator. The program should follow these rules:  
  
A cinema contains eight ( 8 ) identical theater rooms. Assume that the same movie is shown in all eight rooms. Each theater room can hold a maximum of 200 customers.  When a movie ticket is sold, the computer system uses a simple algorithm to determine which theater the customer should be assigned to.  The algorithm is designed to make customers as comfortable as possible by not crowding the theater rooms unless absolutely necessary.  The rules function like this:

1. Fill Theater #1 to 70% capacity.  Once it has reached 70% capacity, begin filling Theater 2. Repeat until all eight theaters are at 70%.
2.  Once all theaters are at 70% capacity, fill Theater #1 to 85% capacity.  Once it has reached 85% capacity, begin filling theater #2.  Repeat until all theaters are at 85% capacity.
3.  Once all theaters are at 85% capacity, fill Theater #1 to 100% capacity.  Repeat until all theaters are at 100% capacity.
4.  If all theaters are filled at 100% capacity and someone tries to buy a ticket, an error is returned and no ticket is issued.

Program specs:  
A.  Each time a ticket sale is attempted, the system should print out a message indicating what theater the customer was assigned to, the current number of people in that theater, and the percentage of capacity used in said theater. Example:  
  
"A ticket was sold. Customer sent to Theater 1. It contains 100 customers, which is 66.6667% capacity".  
  
The ticket sale should be recorded in a variable or structure so that a summary can be generated later (see spec "B" below). Print an error message if a ticket sale is attempted and all theaters are full.  
  
B. After the simulated ticket sales are all complete, the program should print out a summary indicating how many people are in each theater, and the capacity used for each. Example:  
  
"Theater 1 contains 140 customers.  It is 70% full."  
"Theater 2 contains 140 customers.  It is 70% full."  
...  
"Theater 8 contains 50 customers.  It is 25% full."  
  
Write a program that simulates trying to sell tickets using this algorithm.  Run the program once to simulate 1000 ticket sales.  Run it again to simulate  1800 ticket sales.
  
# License  
  
GPLv3.0
