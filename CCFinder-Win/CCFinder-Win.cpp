#include <boost/regex.hpp> 
#include <iostream> 
#include <boost/filesystem.hpp>
#include <vector>
#include <string>
#include "header.h"
#include <boost/iostreams/stream.hpp>
#include <boost/iostreams/device/file_descriptor.hpp>
#include <fstream>

using namespace std;
using namespace boost::filesystem;
namespace fs = boost::filesystem;
namespace io = boost::iostreams;


bool checkLuhn(const string& cardNo)
{
	int nDigits = cardNo.length();

	int nSum = 0, isSecond = false;
	for (int i = nDigits - 1; i >= 0; i--) {

		int d = cardNo[i] - '0';

		if (isSecond == true)
			d = d * 2;
		nSum += d / 10;
		nSum += d % 10;

		isSecond = !isSecond;
	}
	return (nSum % 10 == 0);
}

int main(int argc, char* argv[])
{
	cout << "CC Finder by independent 3.3 https://GitHub.com/independentcod All rights reserved" << std::endl;
	cout << "Please wait a few hours this will take a while..." << std::endl;
	cout << "---" << std::endl;
	std::ofstream fout("CCFinder.log", ios::app);
	fout << "CC Finder by independent 3.3 https://GitHub.com/independentcod All rights reserved" << std::endl;
	std::ifstream ifile("/usr/bin/procdump");
	if ((bool)ifile) {
		system("for i in $(ps -axo pid); do sudo /usr/bin/procdump -p $i; done");
	}
	for (const auto& x : fs::recursive_directory_iterator(argv[1])) {
		if (boost::filesystem::is_regular_file(x.path())) {
			boost::filesystem::absolute(x.path().filename());
			fs::path entry = x;
			std::string line;
			std::cout << entry << std::endl;
			if (x.path().extension() != ".svg" || x.path().extension() != ".jpg" || x.path().extension() != ".mp4" || x.path().extension() != ".mpeg" || x.path().extension() != ".iso" || x.path().extension() != ".so" || x.path().extension() != ".lib" || x.path().extension() != ".py" || x.path().extension() != ".sh" || x.path().extension() != ".js" || x.path().extension() != ".json" || x.path().extension() != ".css" || x.path().extension() != ".html" || x.path().extension() != ".htm") { 
				try {
					boost::iostreams::stream_buffer<boost::iostreams::file_descriptor_source> bis(entry);
					std::istream myfile(&bis);
					boost::regex expr1("\\b[3-5]\\d{15,16}\\b");
					boost::smatch what1;
					if (!myfile) {
						cout << " Failed to open " << entry << endl;
					}
					while (getline(myfile, line))
					{
						if (boost::regex_search(line, what1, expr1))
						{
							if (checkLuhn(what1.str())) {
								fout << line << std::endl;
							}
						}
					}
				}
				catch (const std::exception & ex)
				{
					std::cout << entry << " " << std::endl;
				}
			}
		}
	}
}
