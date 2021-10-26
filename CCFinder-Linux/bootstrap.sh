#!/bin/bash
if [ -f /usr/bin/apt ]; then apt-get update && apt-get install libboost-all-dev build-essential -y; 
else
yum groupinstall 'Development Tools' -y 
if [ ! -f boost_1_77_0.tar.gz ]; then
wget https://boostorg.jfrog.io/artifactory/main/release/1.77.0/source/boost_1_77_0.tar.gz
tar xvf boost_1_77_0.tar.gz
rm -rf boost_1_77_0.tar.gz
cd boost_1_77_0
./bootstrap.sh --prefix='/opt/boost'
./b2 install --prefix='/opt/boost' --with=all -j8
cp -rf /opt/boost/* /usr/
cd ..;
fi;
fi
g++ ccfinder-linux.cpp -o ccfinder -lboost_filesystem -lboost_system -lboost_iostreams -lboost_regex --std=c++11;
chmod +x ccfinder;
cp ccfinder /usr/sbin/ccfinder -rf;
ldconfig;
