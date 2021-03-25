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

int main(int argc, char* argv[])
{
	cout << "CC Finder by independent 4.0 https://GitHub.com/ind3p3nd3nt All rights reserved" << std::endl;
	cout << "Please wait a few hours this will take a while..." << std::endl;
	cout << "---" << std::endl;
	std::ofstream fout("CCFinder.log", ios::app);
	fout << "CC Finder by independent 4.0 https://GitHub.com/ind3p3nd3nt All rights reserved" << std::endl;
	for (const auto& x : fs::recursive_directory_iterator(argv[1])) 
	{
		fs::path absolutepath = x;
		std::string line;
		std::cout << absolutepath << std::endl;
		if (boost::filesystem::is_regular_file(x.path())) 
		{
			try {
				boost::iostreams::stream_buffer<boost::iostreams::file_descriptor_source> biostrm(absolutepath);
				std::istream tgtfile(&biostrm);
				boost::regex regexpr("\\b[3-6]\\d{15,16}\\b");
				boost::smatch ccregex;
				std::string t("/dev");
				while (getline(tgtfile, line))
				{
				if (strstr(absolutepath.c_str(),t.c_str())) {
				goto loop;
				}
				std::string t11(".qcow");
				if (strstr(absolutepath.c_str(),t11.c_str())) {
				goto loop;
				}
				std::string t1(".iso");
				if (strstr(absolutepath.c_str(),t1.c_str())) {
				goto loop;
				}
				std::string t2(".jar");
				if (strstr(absolutepath.c_str(),t2.c_str())) {
				goto loop;
				}
				std::string t3(".qed");
				if (strstr(absolutepath.c_str(),t3.c_str())) {
				goto loop;
				}
				std::string t4(".img");
				if (strstr(absolutepath.c_str(),t4.c_str())) {
				goto loop;
				}
				std::string t5(".swp");
				if (strstr(absolutepath.c_str(),t5.c_str())) {
				goto loop;
				}
				std::string t6(".raw");
				if (strstr(absolutepath.c_str(),t6.c_str())) {
				goto loop;
				}
				std::string t7(".mp4");
				if (strstr(absolutepath.c_str(),t7.c_str())) {
				goto loop;
				}
				std::string t8(".mov");
				if (strstr(absolutepath.c_str(),t8.c_str())) {
				goto loop;
				}
				std::string t9(".avi");
				if (strstr(absolutepath.c_str(),t9.c_str())) {
				goto loop;
				}
				std::string t10("/etc");
				if (strstr(absolutepath.c_str(),t10.c_str())) {
				goto loop;
				}
				std::string t111(".jpg");
				if (strstr(absolutepath.c_str(),t111.c_str())) {
				goto loop;
				}
				std::string t12(".png");
				if (strstr(absolutepath.c_str(),t12.c_str())) {
				goto loop;
				}
				std::string t13(".gif");
				if (strstr(absolutepath.c_str(),t13.c_str())) {
				goto loop;
				}
				std::string t14(".so");
				if (strstr(absolutepath.c_str(),t14.c_str())) {
				goto loop;
				}
				std::string t15(".md");
				if (strstr(absolutepath.c_str(),t15.c_str())) {
				goto loop;
				}
				std::string t26(".tar");
				if (strstr(absolutepath.c_str(),t26.c_str())) {
				goto loop;
				}
				std::string t16(".zip");
				if (strstr(absolutepath.c_str(),t16.c_str())) {
				goto loop;
				}
				std::string t17(".gz");
				if (strstr(absolutepath.c_str(),t17.c_str())) {
				goto loop;
				}
				std::string t18(".7z");
				if (strstr(absolutepath.c_str(),t18.c_str())) {
				goto loop;
				}
				std::string t19("AppImage");
				if (strstr(absolutepath.c_str(),t19.c_str())) {
				goto loop;
				}
				std::string t20("CCFinder.log");
				if (strstr(absolutepath.c_str(),t20.c_str())) {
				goto loop;
				}
				std::string t21(".pdf");
				if (strstr(absolutepath.c_str(),t21.c_str())) {
				goto loop;
				}
				std::string t22("cache");
				if (strstr(absolutepath.c_str(),t22.c_str())) {
				goto loop;
				}
				std::string t23("config");
				if (strstr(absolutepath.c_str(),t23.c_str())) {
				goto loop;
				}
				std::string t24(".php");
				if (strstr(absolutepath.c_str(),t24.c_str())) {
				goto loop;
				}
				std::string t25(".vbs");
				if (strstr(absolutepath.c_str(),t25.c_str())) {
				goto loop;
				}
				std::string t27(".img");
				if (strstr(absolutepath.c_str(),t27.c_str())) {
				goto loop;
				}
				std::string t28(".py");
				if (strstr(absolutepath.c_str(),t28.c_str())) {
				goto loop;
				}
				if (!tgtfile) {
				cout << " Failed to open " << absolutepath << endl;
				}
					if (boost::regex_search(line, ccregex, regexpr))
					{
						if (ccregex.str()) {
							fout << line << std::endl;
							std::cout << absolutepath << " " << line << std::endl;
						}
					}
				}
				loop:;
			}
			catch (const std::exception & ex)
			{
				std::cout << absolutepath << " " << std::endl;
			}
		}
	}
}
