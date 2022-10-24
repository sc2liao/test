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
#include <fstream>

using std::cout; using std::ofstream;
using std::endl; using std::string;
void writefile()
{
    string filename("tmp.txt");
    ofstream file_out;

    file_out.open(filename, std::ios_base::app);//need to modify
    for(int i=0;i<2000000;i++)
        file_out << "Some random text to append." << endl;//need to modify

//open more file ex 200
//c10m connection 10m
}
int main()
{
  boost::asio::io_context io;

  io.post(writefile);
  cout << "asio start" <<endl;
  io.run();
  
  //io.dispatch(writefile);
  cout <<"asio end" << endl;
  return 0;
}
