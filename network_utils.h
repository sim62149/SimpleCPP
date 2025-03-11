#pragma once
#include <string>
#include <map>
#include <windows.h>
#include <winhttp.h>

#pragma comment(lib, "winhttp.lib")

namespace simplecpp {

    struct HttpClientConfig {
        std::wstring userAgent = L"SimpleCpp/1.0";
        std::map<std::wstring, std::wstring> defaultHeaders;
        int timeoutConnect = 30000; // 30 sec
        int timeoutSend = 30000;
        int timeoutReceive = 30000;
    };

    class HttpClient {
    public:
        HttpClient(const HttpClientConfig& config = {});
        ~HttpClient();

        void setDefaultHeaders(const std::map<std::wstring, std::wstring>& headers);
        void setTimeouts(int connect, int send, int receive);

        std::string request(const std::wstring& method, const std::wstring& url, const std::string& data = "", const std::map<std::wstring, std::wstring>& headers = {});
        std::string get(const std::wstring& url, const std::map<std::wstring, std::wstring>& headers = {});
        std::string post(const std::wstring& url, const std::string& data, const std::map<std::wstring, std::wstring>& headers = {});
        std::string put(const std::wstring& url, const std::string& data, const std::map<std::wstring, std::wstring>& headers = {});
        std::string del(const std::wstring& url, const std::map<std::wstring, std::wstring>& headers = {});

    private:
        HINTERNET hSession;
        HttpClientConfig config;
    };

} // namespace simplecpp
