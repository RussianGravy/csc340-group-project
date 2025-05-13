#pragma once
#include <string>
#include <iostream>

/**
    read.h

    * Simplify reading user input
    * Simplify reading input from a file
*/

// Reads a whole line of text, analogue to getline
inline std::string readline(const std::string prompt = "", char delimiter = '\n') {
	// Eliminate a common bug when switching from >> to getline, the >> will leave a newline in the input buffer
	std::string retval;
	std::cout << prompt;
	std::cin >> std::ws;
	std::getline(std::cin,retval,delimiter);
	if (std::cin.eof()) // We reached the end of file, or the user hit ctrl-d
		return retval;
	return retval;
}

template<class T>
inline T read(const std::string prompt = "") {
	while (true) {
		if (std::cin.eof()) // We reached the end of file, or the user hit ctrl-d
			return T(); // Alternatively, we could throw an exception
		T retval;
		std::cout << prompt;
		std::cin >> retval;
		if (!std::cin) {
			std::cin.clear(); // Clear error code
			std::string s;
			std::cin >> s; // Remove the word that caused the error
			continue;
		}
		return retval;
	}
}

// Read a T from a file, so no prompt
template<class T>
inline T read(std::istream &ins) {
	while (true) {
		if (ins.eof()) // We reached the end of file, or the user hit ctrl-d
			return T();
		T retval;
		ins >> retval;
		if (!ins) {
			ins.clear(); // Clear error code
			std::string s;
			ins >> s; // Remove the word that caused the error
			continue;
		}
		return retval;
	}
}

// Getline equivalent for reading from a file
inline std::string readline(std::istream &ins, char delimiter = '\n') {
	std::string retval;
	ins >> std::ws;
	std::getline(ins,retval,delimiter);
	if (ins.eof()) // We reached the end of file, or the user hit ctrl-d
		return retval;
	return retval;
}

struct Reader {
	Reader(std::istream& ins_, const std::string& prompt_) : ins(ins_), prompt(prompt_) {}
	template<class T>
    operator T() {
        while(true) {
            if(ins.eof()) // We reached the end of file, or the user hit ctrl-d
                return T(); //Alternatively, we could throw an exception
            T retval;
            std::cout << prompt;
            ins >> retval; //If this fails, it's because you need a operator>> defined for your type
            if(!ins) {
                ins.clear(); //Clear error code
                std::string s;
                ins >> s; // Remove the word that caused the error
                continue;
            }
            return retval;
        }
    }
	std::istream &ins;
	const std::string prompt;
};

inline Reader read(const std::string prompt = "") {
	return Reader(std::cin,prompt);
}
inline Reader read(std::istream &ins) {
	return Reader(ins,"");
}