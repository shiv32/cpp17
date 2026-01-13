#include <catch2/catch_test_macros.hpp>
#include <httplib.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

static httplib::Client client("localhost", 8080);

/* ---------------- POST ---------------- */

TEST_CASE("POST /tasks - create task")
{
    json body = {
        {"title", "Test Task"},
        {"completed", false}
    };

    auto res = client.Post("/tasks", body.dump(), "application/json");

    REQUIRE(res);
    REQUIRE(res->status == 201);
}

/* ---------------- GET ALL ---------------- */

TEST_CASE("GET /tasks - list tasks")
{
    auto res = client.Get("/tasks");

    REQUIRE(res);
    REQUIRE(res->status == 200);

    auto arr = json::parse(res->body);
    
    REQUIRE(arr.is_array());
    REQUIRE(arr.size() >= 1);
}

/* ---------------- GET BY ID ---------------- */

TEST_CASE("GET /tasks/{id} - get single task")
{
    auto res = client.Get("/tasks");

    REQUIRE(res);
    auto arr = json::parse(res->body);
    REQUIRE(arr.size() > 0);

    int id = arr[0]["id"];

    auto getById = client.Get(("/tasks/" + std::to_string(id)).c_str());

    REQUIRE(getById);
    REQUIRE(getById->status == 200);

    auto task = json::parse(getById->body);
    REQUIRE(task["id"] == id);
}

/* ---------------- PUT ---------------- */

TEST_CASE("PUT /tasks/{id} - update task")
{
    auto res = client.Get("/tasks");
    REQUIRE(res);

    auto arr = json::parse(res->body);
    REQUIRE(arr.size() > 0);

    int id = arr[0]["id"];

    json update = {
        {"title", "Updated Task"},
        {"completed", true}
    };

    auto put = client.Put(
        ("/tasks/" + std::to_string(id)).c_str(),
        update.dump(),
        "application/json"
    );

    REQUIRE(put);
    REQUIRE(put->status == 200);

    auto verify = client.Get(("/tasks/" + std::to_string(id)).c_str());
    auto task = json::parse(verify->body);

    REQUIRE(task["title"] == "Updated Task");
    REQUIRE(task["completed"] == true);
}

/* ---------------- DELETE ---------------- */

TEST_CASE("DELETE /tasks/{id} - remove task")
{
    auto res = client.Get("/tasks");
    REQUIRE(res);

    auto arr = json::parse(res->body);
    REQUIRE(arr.size() > 0);

    int id = arr[0]["id"];

    auto del = client.Delete(("/tasks/" + std::to_string(id)).c_str());

    REQUIRE(del);
    REQUIRE(del->status == 204);

    auto verify = client.Get(("/tasks/" + std::to_string(id)).c_str());
    REQUIRE(verify);
    REQUIRE(verify->status == 404);
}
