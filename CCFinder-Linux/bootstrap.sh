#!/bin/bash
sudo apt update; 
sudo apt-get install libboost. build-essential git sudo g++ -y;
if [ ! -f "/usr/bin/procdump" ]; then
wget -O procdump.deb https://github.com/microsoft/ProcDump-for-Linux/releases/download/1.1.1/procdump_1.1.1-220_amd64.deb
sudo dpkg -i procdump.deb
sudo apt -f install -y
rm -rf procdump.deb;
fi
g++ ccfinder-linux.cpp -o ccfinder -lboost_filesystem -lboost_system -lboost_iostreams -lboost_regex;
sudo chmod +x ccfinder;
sudo cp ccfinder /usr/sbin/ccfinder -r;
