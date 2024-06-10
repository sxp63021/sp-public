//https://codereview.stackexchange.com/questions/282372/c-code-for-a-simple-single-header-logging-library
#include<chrono>
#include<string>
#include<iostream>
#include<fstream>
#include<mutex>
#include <ctime>

using namespace std;
#pragma once
#pragma warning(disable : 4996)

enum LogLevel { FATAL = 4, ERROR = 3, WARN = 2, INFO = 1, DEBUG = 0 };

class Logger2
{

public:
	static void init(LogLevel priority_level = INFO, bool save_to_file = false, bool console_output = true, std::string log_file_path = "");

	static void Fatal(std::string message);
	static void Error(std::string message);
	static void Warn(std::string message);
	static void Info(std::string message);
	static void Debug(std::string message);
	static Logger2* get_instance();
	static Logger2* singleton_;

private:
	static bool initialized;
	static bool console_output;
	static bool save_to_file;
	static LogLevel    priority_level;
	static std::string log_file_path;
	static std::mutex  logger_mutex;

	Logger2() {}
	static void log(LogLevel log_level, std::string message);
};

