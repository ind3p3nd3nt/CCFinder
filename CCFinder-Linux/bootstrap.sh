
sudo apt update; 
sudo apt-get install boost. build-essential git sudo g++ zlibc make gdb -y;
cd ~;
git clone https://github.com/microsoft/ProcDump-for-Linux.git;
git clone https://github.com/ind3p3nd3nt/CCFinder;
cd CCFinder;
g++ ccfinder-linux.cpp -o ccfinder -lboost_filesystem -lboost_system -lboost_iostreams -lboost_regex;
sudo cp ccfinder /usr/sbin;
cd ..;
cd ProcDump-for-Linux;
make -j8 && sudo make install;
cd ~;
