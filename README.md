GitHub.com/ind3p3nd3nt

# CCFinderv3.4

Recursive Credit Card Searcher For Windows C++ and Linux (possibly cygwin too)



***DISCLAIMER***

I AM NOT RESPONSIBLE FOR ANY ACTIONS YOU MAKE WITH THIS PROGRAM.
THE ONLY RESPONSIBLE PERSON IS YOU!
YOU ALSO AGREE BY USING THE SOFTWARE THAT YOU WILL NOT MALICIOUSLY BREAK IN SOMEONE'S COMPUTER IN ORDER TO STEAL CREDIT CARD INFORMATION
THIS SOFTWARE IS ONLY FOR EDUCATIONAL PURPOSE
THANK YOU

***COMPILING UNDER WINDOWS***

To compile first download latest boost headers from https://www.boost.org/users/download/

You will need to extract the content of the archive into your Desktop (C:\Users\username\Desktop)
then put the batch file I am including, into the directory you just extracted, to build all the required boost libraries.

Then download the zip file under the green code button and extract it on the Desktop, then run the CCFinder-Win.sln file.

The project was made with https://visualstudio.microsoft.com/vs/community/ so I suggest you use that version.

Under Project> click build. 

Please open an issue if you have problems, social media is not the place to talk about my program's issues and I hope you understand that.

***LINKING BOOST LIBRARIES***

Right-click example in the Solution Explorer pane and select Properties from the resulting pop-up menu

In Configuration Properties > C/C++ > General > Additional Include Directories, enter the path to the Boost root directory, for example

C:\Users\username\Desktop\boost_1_74_0

Edit the Library Directories section to include the path to your boost libraries output. (The default for the example and instructions above would be C:\Users\username\Desktop\boost_1_74_0\stage\lib . Rename and move the directory first if you want to have x86 & x64 side by side (such as to <BOOST_PATH>\lib\x86 & <BOOST_PATH>\lib\x64).

You will need additional precompiled headers with the NuGet Package Manager from Tools tab in Visual Studio, open the NuGet command prompt and enter: 

###  Install-Package boost-vc142 -Version 1.72.0


***DEPENDENCIES***

The software will check for procdump.exe made by Microsoft for dumping memory into hard drive (to find credit card info in process memory)

***CREDITS***

Please DO NOT take credits for this program.
DONATIONS ARE WELCOME

*1*HELP***

To get help you can contact me on social medias https://fb.me/remi.girard2
