HTTP/TCP simulator using POCO C++ Libraries & C++17

-----------------------------------------------------
Instead of:

    if (action == "SET_NAME") { ... }
    else if (action == "GET_NAME") { ... }

we’ll do:

    action → command object → execute()

No more branching in the handler.

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