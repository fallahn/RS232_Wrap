RS232::SerialConnection - C++ Wrapper class for creating and maintaining COM port connections
---------------------------------------------------------------------------------------------

This class acts as a C++ style OO wrapper around OS native C functions for both Win32API and
Linux kernel. The aim of this class is to easily open and close COM ports and send/receive data
over them. Multiple connections can be maintained at once up to the supported number connections
available on the current hardware. To use this under Linux define __LINUX__ in the preprocessor
directives. For an example of use see the included main.cpp. This class is tested to work under
Windows with VC10 and Mingw GCC and on debian Linux using GCC4.7.

NOTE the read functions are blocking and will not return until some data has been received. It
is recommended that these be handled in their own thread using a library like boost or C++11
threads.

---------------------------------------------------------------------------------------------

Version 1.0
-----------
Initial release. Tested to be stable on both Windows and Linux platforms. Might even work on
Unix variants, but not tested so good luck with that.


---------------------------------------------------------------------------------------------

The MIT License (MIT)

Copyright (c) 2013 Matt Marchant - https://github.com/fallahn

Permission is hereby granted, free of charge, to any person obtaining a copy 
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights 
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell 
copies of the Software, and to permit persons to whom the Software is furnished
 to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all 
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT 
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION 
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.