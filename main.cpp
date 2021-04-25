#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>
#include <cstring>
#include <sstream>
#include <array>
#include <limits.h>

#include <sys/types.h>
#include <sys/sysinfo.h>
#include <X11/Xlib.h>


Display *ourDisplay;

void flush() {
	XFlush(ourDisplay); // Flush display
	sleep(2); // Wait 2 seconds
}
int main() {
	ourDisplay=XOpenDisplay(NULL);
	if (ourDisplay==NULL) {
		std::cout << "Error connection graphic terminal" << std::endl;
		return 1;
	};

	char hostname[HOST_NAME_MAX];
	char username[LOGIN_NAME_MAX];

	gethostname(hostname, HOST_NAME_MAX);
	getlogin_r(username, LOGIN_NAME_MAX);

	std::string user;
	std::stringstream ss;
	std::stringstream ww;

	ss << username;
	ww << hostname;

	user = ss.str() + "@" + ww.str();

	char* userhost = strdup(user.c_str());

	std::cout << "Simple Status Changer for dwm" << std::endl;
	XStoreName(ourDisplay, DefaultRootWindow(ourDisplay), "I use dwm btw");
	flush();
	XStoreName(ourDisplay, DefaultRootWindow(ourDisplay), "/dev/ass");
	flush();
	XStoreName(ourDisplay, DefaultRootWindow(ourDisplay), userhost);
	flush();
	XCloseDisplay(ourDisplay);
	return 0;
}
