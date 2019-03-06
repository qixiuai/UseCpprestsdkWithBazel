
#include "cpprest/http_client.h"
#include "cpprest/filestream.h"
#include "cpprest/json.h"
#include "cpprest/http_listener.h"
#include "cpprest/uri.h"
#include "cpprest/asyncrt_utils.h"
#include "cpprest/filestream.h"
#include "cpprest/containerstream.h"
#include "cpprest/producerconsumerstream.h"

using namespace utility;
using namespace web;
using namespace web::http;
using namespace web::http::client;
using namespace concurrency::streams;


void JsonCall(http_client& client) {
  //  http_client client(U("http://192.168.3.27:80001"));
  json::value data = json::value::object();
  data[U("Report/Leg/NumPlm")] = json::value(0);
  http_request message(methods::POST);
  message.headers().set_content_type(U("application/json"));
  message.set_request_uri(U("/"));
  message.set_body(data);
  client.request(message).then([](http_response resp){
      ucout << "extract json\n";
      return resp.extract_json();
    }).then([](json::value event_json){
	ucout << "fetch json: " << event_json << '\n';
      }).wait();
}


int main() {
  http_client client(U("http://192.168.3.27:8002"));
  //  http_client client(U("http://120.55.53.161:8000"));
  JsonCall(client);
  return 0;
}




