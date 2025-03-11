#include "network_utils.h"
#include <iostream>

namespace simplecpp {

    HttpClient::HttpClient(const HttpClientConfig& config) : config(config) {
        hSession = WinHttpOpen(config.userAgent.c_str(), WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);
    }

    HttpClient::~HttpClient() {
        if (hSession) WinHttpCloseHandle(hSession);
    }

    void HttpClient::setDefaultHeaders(const std::map<std::wstring, std::wstring>& headers) {
        config.defaultHeaders = headers;
    }

    void HttpClient::setTimeouts(int connect, int send, int receive) {
        config.timeoutConnect = connect;
        config.timeoutSend = send;
        config.timeoutReceive = receive;
    }

    std::string HttpClient::request(const std::wstring& method, const std::wstring& url, const std::string& data, const std::map<std::wstring, std::wstring>& headers) {
        if (!hSession) return "Error: Failed to open session";

        URL_COMPONENTS urlComp = { 0 };
        urlComp.dwStructSize = sizeof(urlComp);
        urlComp.dwSchemeLength = -1;
        urlComp.dwHostNameLength = -1;
        urlComp.dwUrlPathLength = -1;
        urlComp.dwExtraInfoLength = -1;

        std::wstring urlCopy = url;
        if (!WinHttpCrackUrl(urlCopy.c_str(), 0, 0, &urlComp)) {
            return "Error: Failed to parse URL";
        }

        std::wstring host(urlComp.lpszHostName, urlComp.dwHostNameLength);
        std::wstring path(urlComp.lpszUrlPath, urlComp.dwUrlPathLength);
        bool useHttps = (urlComp.nScheme == INTERNET_SCHEME_HTTPS);

        HINTERNET hConnect = WinHttpConnect(hSession, host.c_str(), urlComp.nPort, 0);
        if (!hConnect) return "Error: Failed to connect";

        HINTERNET hRequest = WinHttpOpenRequest(hConnect, method.c_str(), path.c_str(), NULL, WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES,
            useHttps ? WINHTTP_FLAG_SECURE : 0);
        if (!hRequest) return "Error: Failed to open request";

        std::wstring headerString;
        for (const auto& header : config.defaultHeaders) {
            headerString += header.first + L": " + header.second + L"\r\n";
        }
        for (const auto& header : headers) {
            headerString += header.first + L": " + header.second + L"\r\n";
        }

        if (!WinHttpSendRequest(hRequest, headerString.c_str(), headerString.length(),
            data.empty() ? WINHTTP_NO_REQUEST_DATA : (LPVOID)data.c_str(), (DWORD)data.length(), (DWORD)data.length(), 0) ||
            !WinHttpReceiveResponse(hRequest, NULL)) {
            return "Error: Request failed";
        }

        DWORD size = 0;
        std::string response;
        do {
            WinHttpQueryDataAvailable(hRequest, &size);
            if (size > 0) {
                char* buffer = new char[size + 1];
                ZeroMemory(buffer, size + 1);
                DWORD bytesRead;
                WinHttpReadData(hRequest, buffer, size, &bytesRead);
                response.append(buffer, bytesRead);
                delete[] buffer;
            }
        } while (size > 0);

        WinHttpCloseHandle(hRequest);
        WinHttpCloseHandle(hConnect);
        return response.empty() ? "Error: No data received" : response;
    }

    std::string HttpClient::get(const std::wstring& url, const std::map<std::wstring, std::wstring>& headers) {
        return request(L"GET", url, "", headers);
    }

    std::string HttpClient::post(const std::wstring& url, const std::string& data, const std::map<std::wstring, std::wstring>& headers) {
        return request(L"POST", url, data, headers);
    }

    std::string HttpClient::put(const std::wstring& url, const std::string& data, const std::map<std::wstring, std::wstring>& headers) {
        return request(L"PUT", url, data, headers);
    }

    std::string HttpClient::del(const std::wstring& url, const std::map<std::wstring, std::wstring>& headers) {
        return request(L"DELETE", url, "", headers);
    }

} // namespace simplecpp
