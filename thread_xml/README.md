# Fun calculator  
  
Problem statement: XML Parsing with Multithreading.

Write a program that will parse the following XML document. (The program may use any XML library/tools you wish.) The program should work as follows:

1. The program starts.
2. The program spawns three (3) worker threads.
3. Each worker thread independently parses its own "copy" of the provided XML document
4. Each worker thread prints results as they are available. The worker should print its thread ID along with any results, so we know what results go with what thread.

The XML document is below. Each worker should go through the document, find each "Car" object, and then print the ID, color, year, make, and model of the car.

Example:

"Worker threadID 0x3382: Found car with ID 2343, Color Blue, Year 1998, Make Chevrolet, Model Aveo" 
"Worker threadID 0x3382: Found car with ID 2659, Color Red, Year 2001, Make Dodge, Model Ram" 
"Worker threadID 0x1639: Found car with ID 2343, Color Blue, Year 1998, Make Chevrolet, Model Aveo" 


XML:

<?xml version="1.0" encoding="UTF-8"?> 
<CarDealership> 
<Car id="2343"> 
<Color>Blue</Color> 
<Year>1998</Year> 
<Make>Chevrolet</Make> 
<Model>Aveo</Model> 
</Car> 
<Car id="2659"> 
<Color>Red</Color> 
<Year>2001</Year> 
<Make>Dodge</Make> 
<Model>Ram</Model> 
</Car> 
<Car id="2638"> 
<Color>Green</Color> 
<Year>2007</Year> 
<Make>BMW</Make> 
<Model>318i</Model> 
</Car> 
<Car id="2323"> 
<Color>Green</Color> 
<Year>1997</Year> 
<Make>Chevrolet</Make> 
<Model>Aveo</Model> 
</Car> 
<Car id="2639"> 
<Color>Red</Color> 
<Year>2002</Year> 
<Make>Dodge</Make> 
<Model>Ram Pickup</Model> 
</Car> 
<Car id="16338"> 
<Color>Yellow</Color> 
<Year>2007</Year> 
<Make>BMW</Make> 
<Model>318i</Model> 
</Car>  
<Car id="16332"> 
<Color>Black</Color> 
<Year>2007</Year> 
<Make>Ford</Make> 
<Model>Crown Victoria</Model> 
</Car> 
</CarDealership> 
  
# License  
  
GPLv3.0
