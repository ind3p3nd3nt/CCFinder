#!/bin/bash
if [ -f /usr/bin/apt ]; then apt-get update && apt-get install libboost-dev build-essential git g++ -y; else yum install c++ boost-devel; fi;
g++ ccfinder-linux.cpp -o ccfinder -lboost_filesystem -lboost_system -lboost_iostreams -lboost_regex;
chmod +x ccfinder;
cp ccfinder /usr/sbin/ccfinder -r;
