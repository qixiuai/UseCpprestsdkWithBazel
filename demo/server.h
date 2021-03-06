#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <fstream>
#include <random>

#include "cpprest/json.h"
#include "cpprest/http_listener.h"
#include "cpprest/uri.h"
#include "cpprest/asyncrt_utils.h"
#include "cpprest/filestream.h"
#include "cpprest/containerstream.h"
#include "cpprest/producerconsumerstream.h"

using namespace std;
using namespace web;
using namespace http;
using namespace utility;
using namespace http::experimental::listener;


class DataFlowServer {
public:
  DataFlowServer();
  DataFlowServer(utility::string_t url);
  ~DataFlowServer();

  pplx::task<void> open() {return m_listener.open();}
  pplx::task<void> close() {return m_listener.close();}

private:
  void handle_get(http_request message);
  void handle_put(http_request message);
  void handle_post(http_request message);
  void handle_delete(http_request message);
  void handle_error(pplx::task<void>& t);
  http_listener m_listener;
  psg::Api api;
};
