/*
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
*/

#ifndef RS232_H_
#define RS232_H_

#include <cstring>

#ifndef __LINUX__
//windows
#include <Windows.h>
#define WIN32_LEAN_AND_MEAN

#else
//linux
#include <cstdio>

#include <termios.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>

#endif //__LINUX__

//-------------Class Declaration----------------//
namespace RS232
{
	class SerialConnection
	{
	public:
		~SerialConnection(); //closes any ports on destruction

		//attempts to open port at given baud. Port numbers start at 0, returns 1 if error
		int OpenPort(const unsigned short port, unsigned baud);
		//attempts to read a single byte from port. returns 0 if successful
		//else returns 1 if failed or no bytes to read. received data is stored in byte. blocking
		int ReadByte(const unsigned short port, unsigned char& byte);
		//fills buffer with any received bytes up to size and returns number of bytes received
		//or -1 if port is invalid. blocking.
		int ReadByteArray(const unsigned short port, unsigned char* buffer, unsigned short size);
		//attempts to send byte on port if port is open. returns 1 on failure
		int SendByte(const unsigned short port, unsigned char byte);
		//attempts to send an array of bytes up to size on port if port is open. returns -1 on error
		//else returns number of bytes sent. blocking.
		int SendByteArray(const unsigned short port, unsigned char* buffer, unsigned short size);
		//closes port if port is open
		int ClosePort(const unsigned short port);

	private:
#ifndef __LINUX__
		//HANDLEs of available COM ports
		HANDLE m_comPortHandles[16];
		//struct to hold port settings when opening a new port
		DCB m_portSettings;
		//timeout struct
		COMMTIMEOUTS m_commTimeouts;

		static const char m_comPorts[16][10];
		char m_baudRate[64];
#else
		//linux members
		int m_comPortHandles[30], error;
		termios m_newPortSettings, m_oldPortSettings[30];
		static const char m_comPorts[30][16];

#endif //__LINUX__
	};
};




#endif //RS232_H_
