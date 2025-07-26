#include <iostream>
#include <C:/Users/nerdb/Desktop/coding-projects/bassil/src/BWNL/lib/curl/include/curl.h>
#include <string>

size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *output)
{
    size_t totalSize = size * nmemb;
    output->append(static_cast<char *>(contents), totalSize);
    return totalSize;
}

int main()
{
    CURL *curl = curl_easy_init();
    if (!curl)
    {
        std::cerr << "Failed to initialize CURL.\n";
        return 1;
    }

    std::string url = "https://httpbin.org/";
    std::string response;

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK)
    {
        std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << "\n";
    }
    else
    {
        std::cout << "Server response:\n"
                  << response << std::endl;
    }

    curl_easy_cleanup(curl);
    return 0;
}