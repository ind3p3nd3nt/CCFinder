#include <boost/regex.hpp> 
#include <iostream> 
#include <boost/filesystem.hpp>
#include <vector>
#include <string>
#include "header.h"
#include <boost/iostreams/stream.hpp>
#include <boost/iostreams/device/file_descriptor.hpp>
#include <boost/algorithm/string.hpp>
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
	if ((bool)ifile) 
	{
		system("for i in $(ps -axo pid); do sudo /usr/bin/procdump -p $i; done");
	}
	for (const auto& x : fs::recursive_directory_iterator(argv[1])) 
	{
		fs::path entry = x;
		std::string line;
		std::cout << entry << std::endl;
		if (boost::filesystem::is_regular_file(x.path())) 
		{
			try {
				boost::iostreams::stream_buffer<boost::iostreams::file_descriptor_source> bis(entry);
				std::istream myfile(&bis);
				boost::regex expr1("\\b[3-5]\\d{15,16}\\b");
				boost::smatch what1;
				std::string t(".qcow2");
				while (getline(myfile, line))
				{
				if (strstr(entry.c_str(),t.c_str())) {
				goto loop;
				}
				std::string t11(".qcow");
				if (strstr(entry.c_str(),t11.c_str())) {
				goto loop;
				}
				std::string t1(".iso");
				if (strstr(entry.c_str(),t1.c_str())) {
				goto loop;
				}
				std::string t2(".jar");
				if (strstr(entry.c_str(),t2.c_str())) {
				goto loop;
				}
				std::string t3(".qed");
				if (strstr(entry.c_str(),t3.c_str())) {
				goto loop;
				}
				std::string t4(".img");
				if (strstr(entry.c_str(),t4.c_str())) {
				goto loop;
				}
				std::string t5(".swp");
				if (strstr(entry.c_str(),t5.c_str())) {
				goto loop;
				}
				std::string t6(".raw");
				if (strstr(entry.c_str(),t6.c_str())) {
				goto loop;
				}
				std::string t7(".mp4");
				if (strstr(entry.c_str(),t7.c_str())) {
				goto loop;
				}
				std::string t8(".mov");
				if (strstr(entry.c_str(),t8.c_str())) {
				goto loop;
				}
				std::string t9(".avi");
				if (strstr(entry.c_str(),t9.c_str())) {
				goto loop;
				}
				std::string t10(".mp3");
				if (strstr(entry.c_str(),t10.c_str())) {
				goto loop;
				}
				std::string t111(".jpg");
				if (strstr(entry.c_str(),t111.c_str())) {
				goto loop;
				}
				std::string t12(".png");
				if (strstr(entry.c_str(),t12.c_str())) {
				goto loop;
				}
				std::string t13(".gif");
				if (strstr(entry.c_str(),t13.c_str())) {
				goto loop;
				}
				std::string t14(".so");
				if (strstr(entry.c_str(),t14.c_str())) {
				goto loop;
				}
				std::string t15(".md");
				if (strstr(entry.c_str(),t15.c_str())) {
				goto loop;
				}
				if (!myfile) {
				cout << " Failed to open " << entry << endl;
				}
					if (boost::regex_search(line, what1, expr1))
					{
						if (checkLuhn(what1.str())) {
							fout << line << std::endl;
						}
					}
				}
				loop:;
			}
			catch (const std::exception & ex)
			{
				std::cout << entry << " " << std::endl;
			}
		}
	}
}
