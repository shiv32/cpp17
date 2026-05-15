Small POC (manual reflection idea)
    Let’s build a tiny reflection-like system using a map.

Idea:
    We store property names → pointers, so we can access them dynamically.

What just happened?
    You simulated reflection:
        Accessed members using string names
        Modified object without hardcoding field access

Limitations of this approach
    This is NOT real reflection because:
        You manually registered properties
        No automatic discovery
        No function introspection
        No type safety

How real systems do it
    Engines/frameworks:
        Use macros + code generation
        Build metadata tables at compile time

--------------------------------------------
Game example term
    Health  → keeps you alive
    Mana    → lets you use powers “how much magical energy the player has”
                eg. int fuel;   // in a car simulation
                    int battery; // in a device
--------------------------------------------

