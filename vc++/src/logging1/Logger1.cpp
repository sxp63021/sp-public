#include "Logger1.h"

#if 0
Logger1::Logger1() {
	try {
		m_fs.open("logging1.log", ios::app);
	}
	catch (...) {
		cout << "Error in opening a file to log messages" << endl;
	}
}

shared_ptr<Logger1> Logger1::getInstance() {
	if (instancePtr == nullptr) {
		Logger1 *l1 = new Logger1();
		instancePtr = std::make_shared<Logger1>(l1);
	}

	return instancePtr;
}

template<typename T>
Logger1& Logger1::operator<< (const T& data)
{
	auto now = std::chrono::system_clock::now();
	auto now_time_t = std::chrono::system_clock::to_time_t(now); //Uhhg, C APIs...
	auto now_tm = std::localtime(&now_time_t); //More uhhg, C style... 

	/*
	if (_next_is_begin)
		_out_stream << _log_header << "(" << now_tm->tm_hour << ":" << now_tm->tm_min << ":" << now_tm->tm_sec << "): " << data;
	else
		_out_stream << data;

	_next_is_begin = false;
	*/
	try {
		m_fs << data << endl;
	}
	catch (...) {
		cout << "Error in writing output to a file" << endl;
	}
	return *this;
}
#endif