#include <stdio.h>
#include <curl/curl.h>

int main(void)
{
    CURL* curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://mikeguzman.info/api/progra2/pacientes.json");

        /* Forcing HTTP/3 will make the connection fail if the server isn't
           accessible over QUIC + HTTP/3 on the given host and port.
           Consider using CURLOPT_ALTSVC instead! */
        curl_easy_setopt(curl, CURLOPT_HTTP_VERSION, (long)CURL_HTTP_VERSION_3);

        /* Perform the request, res will get the return code */
        res = curl_easy_perform(curl);
        /* Check for errors */
        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        /* always cleanup */
        curl_easy_cleanup(curl);
    }
    return 0;
}