#include <iostream>
#include <hiredis/hiredis.h>

int main()
{
    redisContext *c = redisConnect("127.0.0.1", 6379);

    redisReply *reply;

    // SET
    reply = (redisReply *)redisCommand(c, "SET %s %s", "key", "value");
    freeReplyObject(reply);

    // GET
    reply = (redisReply *)redisCommand(c, "GET %s", "key");
    if (reply->type == REDIS_REPLY_STRING)
    {
        std::cout << reply->str << std::endl;
    }

    freeReplyObject(reply);
    redisFree(c);

    return EXIT_SUCCESS;
}
