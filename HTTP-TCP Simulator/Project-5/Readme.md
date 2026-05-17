HTTP/TCP simulator using POCO C++ Libraries & C++17

-----------------------------------------------------
Right now your globals (g_name, g_routes, g_factory) are the weak point.
We’ll replace them with a Context object that:

    owns shared state
    owns routes
    owns command factory
    is passed cleanly to handlers

No globals. 
No hidden dependencies.

What changes conceptually

Before:
    Handler → global data

After:
    Handler → Context → (state + routes + factory)

This is how real backends are structured.

What you just achieved (this is big)
You now have:
    No globals
    Central Context object
    Clean dependency flow
    Extensible command system

This is structurally very close to:
    backend frameworks
    game engines
    microservice cores

Why this matters (real insight)
Now you can:
    Swap storage (memory → SQLite) without touching commands much
    Add logging, metrics into Context
    Inject dependencies cleanly

------------------------------------------------------

Run
    ./sim

or

    ./sim 127.0.0.1:9000
-------------------------------------------------------
Test
    Set name

    curl -X POST http://localhost:8080/user \
    -H "Content-Type: application/json" \
    -d '{"name":"Shiv"}'

    Get name

    curl http://localhost:8080/user