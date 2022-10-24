//
// timer.cpp
// ~~~~~~~~~
//
// Copyright (c) 2003-2021 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <iostream>
#include <boost/asio.hpp>

void print()
{
  std::cout << "Hello, world!" << std::endl;
}

void print2()
{
  std::cout << "Hello, world2!" << std::endl;
}

int main()
{
  boost::asio::io_context io;

  //boost::asio::steady_timer t(io, boost::asio::chrono::seconds(10));
  //boost::asio::steady_timer tt(io, boost::asio::chrono::seconds(5));
  //boost::asio::steady_timer ttt(io, boost::asio::chrono::seconds(5));
  //t.async_wait(&print);
  //tt.async_wait(&print2);
  //ttt.wait();
  io.post(print);
  io.dispatch(print2);
  std::cout << "hello timer2" <<std::endl;
  io.run();
  //io.post(print2);
  std::cout << "hello timer2++++++++" <<std::endl;
  return 0;
}
