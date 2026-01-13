#include <httplib.h>
#include <nlohmann/json.hpp>

#include <iostream>
#include <vector>
#include <string>
#include <mutex>

using json = nlohmann::json;

/* ---------------- DATA MODEL ---------------- */

struct Task {
    int id;
    std::string title;
    bool completed;
};

/* ---------------- GLOBAL STATE ---------------- */

std::vector<Task> tasks;
int nextId = 1;
std::mutex taskMutex;

/* ---------------- HELPERS ---------------- */

json to_json(const Task& t)
{
    return {
        {"id", t.id},
        {"title", t.title},
        {"completed", t.completed}
    };
}

void print_tasks()
{
    std::cout << "\n📋 Current Tasks:\n";
    for (const auto& t : tasks) {
        std::cout << "  [" << t.id << "] "
                  << t.title
                  << " | completed=" << std::boolalpha
                  << t.completed << "\n";
    }
    std::cout << "-------------------------\n";
}

/* ---------------- MAIN ---------------- */

int main()
{
    httplib::Server server;

    /* -------- GET ALL TASKS -------- */
    server.Get("/tasks", [](const httplib::Request&, httplib::Response& res) {
        std::lock_guard<std::mutex> lock(taskMutex);

        json arr = json::array();
        for (const auto& t : tasks) {
            arr.push_back(to_json(t));
        }

        res.set_content(arr.dump(2), "application/json");
    });

    /* -------- GET TASK BY ID -------- */
    server.Get(R"(/tasks/(\d+))", [](const httplib::Request& req, httplib::Response& res) {
        int id = std::stoi(req.matches[1]);
        std::lock_guard<std::mutex> lock(taskMutex);

        for (const auto& t : tasks) {
            if (t.id == id) {
                res.set_content(to_json(t).dump(2), "application/json");
                return;
            }
        }
        res.status = 404;
    });

    /* -------- CREATE TASK -------- */
    server.Post("/tasks", [](const httplib::Request& req, httplib::Response& res) {
        auto body = json::parse(req.body);

        Task t;
        t.id = nextId++;
        t.title = body["title"];
        t.completed = body.value("completed", false);

        {
            std::lock_guard<std::mutex> lock(taskMutex);
            tasks.push_back(t);
            print_tasks();
        }

        res.status = 201;
    });

    /* -------- UPDATE TASK -------- */
    server.Put(R"(/tasks/(\d+))", [](const httplib::Request& req, httplib::Response& res) {
        int id = std::stoi(req.matches[1]);
        auto body = json::parse(req.body);

        std::lock_guard<std::mutex> lock(taskMutex);

        for (auto& t : tasks) {
            if (t.id == id) {
                t.title = body["title"];
                t.completed = body["completed"];
                print_tasks();
                res.status = 200;
                return;
            }
        }
        res.status = 404;
    });

    /* -------- DELETE TASK -------- */
    server.Delete(R"(/tasks/(\d+))", [](const httplib::Request& req, httplib::Response& res) {
        int id = std::stoi(req.matches[1]);

        std::lock_guard<std::mutex> lock(taskMutex);

        tasks.erase(
            std::remove_if(tasks.begin(), tasks.end(),
                [&](const Task& t) { return t.id == id; }),
            tasks.end()
        );

        print_tasks();
        res.status = 204;
    });

    std::cout << "REST Server running at http://localhost:8080\n";

    server.listen("0.0.0.0", 8080);
}
