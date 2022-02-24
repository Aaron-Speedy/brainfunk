Each line is a function. The first line is not a function but rather a function caller   
Each function has a pointer. Each function does not have its own array.   

^ to move the function pointer up   
v to move the function pointer down   
: to call the function   
! to reset the pointer of the current function pointed to by the function pointer   
[...] Like a normal loop but it works in the caller function    
{...} like [] but it checks if a function is there  
; ends the function
c duplicate the current function to the end of the function array  
r delete the current function   

Implementation: 
 - 8 bit cells
 - Unbounded memory 
 - Moving to negative cell indexes wraps it around 
 
Example program:
	```brainfuck
	:;
	+[+.];
	```
