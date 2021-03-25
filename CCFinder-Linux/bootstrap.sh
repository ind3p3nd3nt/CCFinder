#!/bin/bash
sudo apt update; 
sudo apt-get install libboost. build-essential git sudo g++ -y;
g++ ccfinder-linux.cpp -o ccfinder -lboost_filesystem -lboost_system -lboost_iostreams -lboost_regex;
sudo chmod +x ccfinder;
sudo cp ccfinder /usr/sbin/ccfinder -r;
