#include <boost/regex.hpp> 
#include <iostream> 
#include <windows.h>
#include <boost/filesystem.hpp>
#include <vector>
#include <string>
#include "header.h"
#include <boost/iostreams/stream.hpp>
#include <boost/iostreams/device/file_descriptor.hpp>
#include <tlhelp32.h>
#include <tchar.h>
#include <Psapi.h>
#include <boost/lexical_cast.hpp>
#include <fstream>

using namespace std;
using namespace boost::filesystem;
namespace fs = boost::filesystem;
namespace io = boost::iostreams;


template<typename ValueType>
std::string ConvertToStringUsingBoost(ValueType const& v)
{
	try
	{

#ifdef UNITTEST
		if (unittest == case_fail) {
			throw boost::bad_lexical_cast();
		}
#endif
		return boost::lexical_cast<std::string, ValueType>(v);
	}
	catch (boost::bad_lexical_cast const& e)
	{
		return std::string();
	}
}




int main()
{
	cout << "CC Finder by independent 4.0 https://GitHub.com/ind3p3nd3nt All rights reserved" << std::endl;
	cout << "Please wait a few hours this will take a while..." << std::endl;
	cout << "---" << std::endl;
	std::ofstream fout("CCFinder.log", ios::app);
	fout << "CC Finder by independent 4.0 https://GitHub.com/ind3p3nd3nt All rights reserved" << std::endl;
	string mystr;
	cout << "What drive/directory should we scan? Example: C:\\USERS\\ .\n";
	getline(cin, mystr);
	for (auto& x : fs::recursive_directory_iterator(mystr)) {
		if (x.path().extension() == ".txt" || x.path().extension() == ".RTX" || x.path().extension() == ".FPT" || x.path().extension() == ".DOC" || x.path().extension() == ".RFT" || x.path().extension() == ".ODM" || x.path().extension() == ".QBL" || x.path().extension() == ".DOCX" || x.path().extension() == ".FODT" || x.path().extension() == ".ADOC" || x.path().extension() == ".SAVE" || x.path().extension() == ".RTF" || x.path().extension() == ".DOC" || x.path().extension() == "" || x.path().extension() == ".csv" || x.path().extension() == ".lst" || x.path().extension() == ".text" || x.path().extension() == ".dat" || x.path().extension() == ".log" || x.path().extension() == ".db" || x.path().extension() == ".mdb" || x.path().extension() == ".xml" ) {
			if (boost::filesystem::is_regular_file(x.path())) {
				fs::path absolutepath = x;
				std::string line;
				std::string logfile("CCFinder.log");
				std::cout << absolutepath << std::endl;
				std::string leaf(x.path().filename().generic_string());
				try
				{
					boost::iostreams::stream_buffer<boost::iostreams::file_descriptor_source> biostrm(absolutepath);
					std::istream tgtfile(&biostrm);
					boost::regex regexexpr("\\b[3-6]\\d{15,16}\\b");
					boost::smatch ccregex;
					if (strstr(leaf.c_str(), logfile.c_str())) {
						goto loop2;
					}
					if (!tgtfile) {
						cout << " Failed to open " << absolutepath << endl;
					}
					while (getline(tgtfile, line))
					{
						if (boost::regex_search(line, ccregex, regexexpr))
						{
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
								fout << line << std::endl;
								std::cout << line << std::endl;
								for (int i(0); i < ccregex.size(); i++) {
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
									std::cout << ccregex[i] << std::endl;
								}
						}

					}
				loop2:;
				}
				catch (const std::exception& ex)
				{

					std::cout << absolutepath << " " << ex.what() << std::endl;
				}
			}
		}
	}
}
