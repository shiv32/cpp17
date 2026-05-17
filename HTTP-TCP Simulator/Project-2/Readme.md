HTTP/TCP simulator using POCO C++ Libraries & C++17


Run
    ./sim

or

    ./sim 127.0.0.1:9000

Test
    Set name

    curl -X POST http://localhost:8080/user \
    -H "Content-Type: application/json" \
    -d '{"name":"Shiv"}'

    Get name

    curl http://localhost:8080/user