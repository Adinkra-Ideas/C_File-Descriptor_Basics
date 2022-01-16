# get_next_line
Get_Next_Line is a project where we were required to code 
a program that reads the text content of a file using a 
dynamic buffer and the file descriptor of a given file. 

* Allowed functions are Malloc(), Free() and Read(). 
* The program must read using a buffer on each call (using 
  any possible buffer value given to it).  
* The program must return a new line from the file regardless 
  on each call. 
* No memory leaks must be present upon completion.

MOULINETTE TIP
* If you know what Moulinette is :) then it is better you write
* your own GNL program from scratch so that you improve your
* programming knowledge. But if you need the easy way :) out, be
* aware that moulinette uses a script to free() the returned 
* pointer upon each call to GNL.
* In this my implementation of GNL, the program is self-dependent
* and handles its own calls to free() by itself. Thus, it wont pass
* The Moulinette test unless you add a little tweak at the bottom 
* of the get_next_line() so it first copies the processed line to 
* a malloc-ed pointer, and then return that pointer on each call.
*  

