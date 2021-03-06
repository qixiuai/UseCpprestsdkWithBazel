
#include "cpprest/json.h"

using namespace web;

DataFlowServer::DataFlowServer() {}

DataFlowServer::DataFlowServer(utility::string_t url): m_listener(url) {
  m_listener.support(methods::GET,  std::bind(&DataFlowServer::handle_get,    this, std::placeholders::_1));
  m_listener.support(methods::PUT,  std::bind(&DataFlowServer::handle_put,    this, std::placeholders::_1));
  m_listener.support(methods::POST, std::bind(&DataFlowServer::handle_post,   this, std::placeholders::_1));
  m_listener.support(methods::DEL,  std::bind(&DataFlowServer::handle_delete, this, std::placeholders::_1));
}

DataFlowServer::~DataFlowServer() {
  // release resources
}

void DataFlowServer::handle_error(pplx::task<void>& t) {
  try {
    t.get();
  }
  catch(...) {
    fprintf(stderr, "from handle error\n");
  }
}

void DataFlowServer::handle_get(http_request message) {
  ucout << message.to_string() << endl;
  auto path = http::uri::decode(message.relative_uri().path());
  std::string no_root_path(path.begin()+1, path.end());
  message.reply(status_codes::OK, no_root_path);
  return;
}

void DataFlowServer::handle_put(http_request message) {
  ucout << message.to_string() << endl;
  message.reply(status_codes::OK);
  message.extract_vector().then([&](std::vector<unsigned char> data) {
      ucout << data.size() << '\n';
    });

  return;
}

void DataFlowServer::handle_post(http_request message) {
  ucout << message.to_string() << endl;
  message.extract_json().then([&](json::value data) {
      message.reply(status_codes::OK);
    });
  return;
}

void DataFlowServer::handle_delete(http_request message) {
  ucout << message.to_string() << endl;
  message.reply(status_codes::OK, message.extract_json().get());
  return;
}

