sudo apt update; 
sudo apt-get install boost. build-essential git sudo g++ -y;
#git clone https://github.com/microsoft/ProcDump-for-Linux.git;
g++ ccfinder-linux.cpp -o ccfinder -lboost_filesystem -lboost_system -lboost_iostreams -lboost_regex;
sudo chmod +x ccfinder;
sudo cp ccfinder /usr/sbin/ccfinder -r;
#cd ProcDump-for-Linux;
#make -j8 && sudo make install;
#cd ..;
