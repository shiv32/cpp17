HTTP/TCP simulator using POCO C++ Libraries & C++17

Run
    ./sim

or

    ./sim 127.0.0.1:9000

Test
    curl http://localhost:8080/hello

        {"msg":"Hello World"}

    curl -X POST http://localhost:8080/user

        {"status":"User Created"}