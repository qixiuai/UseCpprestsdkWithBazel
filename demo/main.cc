
#include <iostream>

#include "psg/restapi/server.h"


std::unique_ptr<DataFlowServer> g_httpHandler;

void on_initialze(const string_t& address) {
  uri_builder uri(address);

  auto addr = uri.to_uri().to_string();
  g_httpHandler = std::unique_ptr<DataFlowServer>(new DataFlowServer(addr));
  g_httpHandler->open().wait();

  ucout << utility::string_t(U("Listening for requests at: ")) << addr << std::endl;

  return;
}

void on_shutdown() {
  g_httpHandler->close().wait();
  return;
}

int main(int argc, char* argv[]) {
  utility::string_t address = U("http://localhost:8002");

  on_initialze(address);
  std::cout<< "Press ENTER to exit." << std::endl;
  
  std::string line;
  std::getline(std::cin, line);

  on_shutdown();
  return 0;
}



