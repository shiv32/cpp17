OVERLOADING THE MEMORY ALLOCATION AND DEALLOCATION OPERATORS

    Unless you know a lot about memory allocation strategies, 
    attempts to overload the memory allocation routines are rarely worth the trouble. 
    Don’t overload them just because it sounds like a neat idea. 
    Only do so if you have a genuine requirement and the necessary knowledge.

How new and delete Really Work

The New-Expression and operator new
    There are six different forms of the new-expression, 
    each of which has a corresponding operator new.

The Delete-Expression and operator delete
    There are only two different forms of the delete-expression that you can call: 
    delete, and delete[]; 
    there are no nothrow or placement forms.