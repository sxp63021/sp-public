// curl_proj_try2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define CURL_STATICLIB
#include <curl\curl.h>

#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>



// #include <winhttp.h>
using namespace std;


static size_t my_write(void* buffer, size_t size, size_t nmemb, void* param)
{
	std::string& text = *static_cast<std::string*>(param);
	size_t totalsize = size * nmemb;
	text.append(static_cast<char*>(buffer), totalsize);
	return totalsize;
}

void fn_get(string url) {
	std::string result;
	CURL* curl;
	CURLcode res;
	curl_global_init(CURL_GLOBAL_DEFAULT);
	curl = curl_easy_init();
	if (curl) {
		//curl_easy_setopt(curl, CURLOPT_URL, "https://tcno.co/hello.txt");
		//curl_easy_setopt(curl, CURLOPT_URL, "http://127.0.0.1:8181/");
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, my_write);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);
		curl_easy_setopt(curl, CURLOPT_VERBOSE, 0L);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
		if (CURLE_OK != res) {
			std::cerr << "CURL error: " << res << '\n';
		}
		else {
			std::cout << "Success: " << res << '\n';
		}
	}


	curl_global_cleanup();
	std::cout << "printing result \n" << result << "\n\n";
}

/* seek callback function */
static int my_seek(void *userp, curl_off_t offset, int origin)
{
	FILE *fp = (FILE *)userp;

	if (-1 == fseek(fp, (long)offset, origin))
		/* could not seek */
		return CURL_SEEKFUNC_CANTSEEK;

	return CURL_SEEKFUNC_OK; /* success! */
}

/* read callback function, fread() look alike 
static size_t read_callback(char *ptr, size_t size, size_t nmemb, void *stream)
{
	ssize_t retcode;
	unsigned long nread;

	retcode = fread(ptr, size, nmemb, stream);

	if (retcode > 0) {
		nread = (unsigned long)retcode;
		fprintf(stderr, "*** We read %lu bytes from file\n", nread);
	}

	return retcode;
} */

// Callback function to capture the API response
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
	size_t total_size = size * nmemb;
	std::string* response = (std::string*)userp;
	response->append((char*)contents, total_size);
	return total_size;
}


void fn_put(string url) {
	std::string result;
	CURL* curl;
	CURLcode res;
	curl_global_init(CURL_GLOBAL_DEFAULT);
	// Create a JSON payload (you can customize this payload)
	const char* json_data = "{\"workStationID\": \"LAPTOP2\", \"user\": \"satish2\"}";

	curl = curl_easy_init();
	if (curl) {

		// Set the HTTP headers
		struct curl_slist* headers = NULL;
		// Create a string to store the response from the API
		std::string response;

		headers = curl_slist_append(headers, "Content-Type: application/json");
		//headers = curl_slist_append(headers, "Accept: application/json");
		//curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
		// end of setting the header stuff

		// Set the PUT request type
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PUT");

		// Set the URL
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

		// Set the request data
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_data);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)strlen(json_data));

		// Set the callback function to capture the response data
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

		// Set the headers
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

		// Perform the PUT request
		res = curl_easy_perform(curl);

		// Check for errors
		if (res != CURLE_OK) {
			fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
		}
		else {
			// Process the response
			std::cout << "API Response: " << response << std::endl;
		}

		// Clean up libcurl and release resources
		curl_slist_free_all(headers);
		curl_easy_cleanup(curl);

#if 0
		/* we want to use our own read function */
		curl_easy_setopt(curl, CURLOPT_READFUNCTION, read_callback);

		/* which file to upload */
		curl_easy_setopt(curl, CURLOPT_READDATA, (void *)fp);

		/* set the seek function */
		curl_easy_setopt(curl, CURLOPT_SEEKFUNCTION, my_seek);

		/* pass the file descriptor to the seek callback as well */
		curl_easy_setopt(curl, CURLOPT_SEEKDATA, (void *)fp);

		
		/* and give the size of the upload, this supports large file sizes
	   on systems that have general support for it */
		curl_easy_setopt(curl, CURLOPT_INFILESIZE_LARGE,
			(curl_off_t)file_info.st_size);


		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, my_write);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);
		curl_easy_setopt(curl, CURLOPT_VERBOSE, 0L);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);

		if (CURLE_OK != res) {
			std::cerr << "fn_put CURL error: " << res << '\n';
		}
		else {
			std::cout << "fn_put Success: " << res << '\n';
		}
#endif
	}


	curl_global_cleanup();
	std::cout << "fn_put printing result \n" << result << "\n\n";
}

int main()
{
	std::cout << "Hello World!\n";
	//fn_get("http://127.0.0.1:8181/");
	//fn_get("http://127.0.0.1:8181/licenses");
	//fn_get("http://127.0.0.1:8181/license/1");
	fn_put("http://127.0.0.1:8181/checkout");
	//fn_put("http://127.0.0.1:8181/checkin");




	/*
#if 0
	CURL *curl;
	curl = curl_easy_init();
	curl_easy_cleanup(curl);
#else 
	std::string result;
	CURL* curl;
	CURLcode res;
	curl_global_init(CURL_GLOBAL_DEFAULT);
	curl = curl_easy_init();
	if (curl) {
		//curl_easy_setopt(curl, CURLOPT_URL, "https://tcno.co/hello.txt");
		curl_easy_setopt(curl, CURLOPT_URL, "http://127.0.0.1:8181/");
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, my_write);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);
		curl_easy_setopt(curl, CURLOPT_VERBOSE, 0L);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
		if (CURLE_OK != res) {
			std::cerr << "CURL error: " << res << '\n';
		}
		else {
			std::cout << "Success: " << res << '\n';
		}
	}


	curl_global_cleanup();
	std::cout << "printing result \n" << result << "\n\n";
#endif
*/
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

