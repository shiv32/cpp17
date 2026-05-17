HTTP/TCP simulator using POCO C++ Libraries & C++17

-------------------------------------------------------------
127.0.0.1 (localhost)
    This is the loopback address
    Means: “this machine only”
    Traffic never leaves your system
Example
    ./sim 127.0.0.1:8080

Only you (same machine) can access:

    curl http://127.0.0.1:8080

Other devices (phone, other PC) cannot connect

0.0.0.0 (all interfaces)
    Means: “listen on all network interfaces”
    Includes:
        localhost (127.0.0.1)
        your LAN IP (e.g. 192.168.x.x)
        possibly public IP

Example
    ./sim 0.0.0.0:8080

Now accessible from:
    Your machine → 127.0.0.1
    Same WiFi → 192.168.x.x:8080
    Other devices (if network allows)
-----------------------------------------------------------------
Key difference (simple)
    127.0.0.1 → private (only me)
    0.0.0.0 → public (any interface)

Real-world analogy
    127.0.0.1 = talking to yourself
    0.0.0.0 = opening your door to everyone in your house/network
----------------------------------------------------------------
When to use what

Use 127.0.0.1
    Local development
    Security (no external access)
    Testing only on your machine

Use 0.0.0.0
    Testing from mobile / other PCs
    Running server in LAN
    Docker / VM setups
--------------------------------------------------------------
In simulator context

If you run:

    ./sim 127.0.0.1:8080

Only your terminal can hit it

If you run:

    ./sim 0.0.0.0:8080

Your phone can hit it too (same WiFi)
-------------------------------------------------------------
Important detail (many miss this)

You never connect to 0.0.0.0

This will NOT work:

    curl http://0.0.0.0:8080

Instead use:

    curl http://127.0.0.1:8080

or

    curl http://192.168.x.x:8080
--------------------------------------------------------------
Final truth
They are not interchangeable:
    One is a specific address (loopback)
    One is a binding instruction (all interfaces)
----------------------------------------------------------------