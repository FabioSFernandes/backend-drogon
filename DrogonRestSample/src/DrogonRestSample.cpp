#include "DrogonRestSample.h"
#include <drogon/drogon.h>
#include <json/json.h> // jsoncpp

int main() {
    drogon::app().registerHandler("/hello",
        [](const drogon::HttpRequestPtr& req,
            std::function<void(const drogon::HttpResponsePtr&)>&& callback) {
                Json::Value jsonResp;
                jsonResp["message"] = "Hello, Drogon!";

                auto resp = drogon::HttpResponse::newHttpJsonResponse(jsonResp);
                callback(resp);
        });

    drogon::app().addListener("127.0.0.1", 8848);
    drogon::app().run();
    return 0;
}
