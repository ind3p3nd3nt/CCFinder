#!/bin/bash
# file: bootstrap.sh
sudo apt-get update && sudo apt-get install libboost-all-dev git g++ zlibc make gdb -y  && chmod +x configure;
git clone https://github.com/microsoft/ProcDump-for-Linux.git;
cd ProcDump-for-Linux;
make;
sudo make install;
cd ..;
g++ ./ccfinder-linux.cpp -o ccfinder -lboost_filesystem -lboost_system -lboost_iostreams -lboost_regex;
sudo cp ./ccfinder /usr/sbin;
cp ./ProcDump-for-Linux/procdump /usr/bin/procdump;
echo "Cleaning up...";
rm -rf ./ProcDump-for-Linux/;
sudo apt-get clean && sudo apt-get autoremove -y;
echo "You're all done! Now call the program like this: sudo ./ccfinder /";
echo "REMEMBER I AM NOT RESPONSIBLE FOR THE ACTIONS YOU MAKE WITH THIS PROGRAM!!!";