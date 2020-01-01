Tested on last Ubuntu version, experimental in Centos.

***CLONING IN DEBIAN/UBUNTU***

sudo apt update && sudo apt install git -y && git clone -b Linux-version https://github.com/independentcod/CCFinder.git

***CLONING IN CENTOS***

sudo yum install git  -y && git clone -b Linux-version https://github.com/independentcod/CCFinder.git

***COMPILING IN DEBIAN/UBUNTU***

Simply run this command:

sudo sh bootsrap.sh

And you are done!

Else you can do the following command:

g++ ccfinder.cpp -o ccfinder -lboost_filesystem -lboost_system -lboost_iostreams -lboost_regex

This will produce ccfinder binary.

***COMPILING IN CENTOS (untested)***

sudo yum upgrade -y && sudo yum install boost-devel libboost-devel -y
g++ ccfinder.cpp -o ccfinder -lboost_filesystem -lboost_system -lboost_iostreams -lboost_regex

***RUNNING***

sudo ./ccfinder <directory>

Example:

sudo ./ccfinder /

***COMPILING WITH VISUAL STUDIO REMOTE SSH***

Simply load the project and build it, all is automatic! :)))