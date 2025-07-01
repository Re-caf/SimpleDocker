#include <stdlib.h>
#include <stdio.h>
#include <fcgi_stdio.h>

int main(void) {

    while (FCGI_Accept() >= 0) {
        printf("Content-type: text/html\r\n\r\n");
        printf("<html>\n<body>\n");
        printf("<h1>Hello World!</h1>\n");
        printf("</body>\n</html>\n");
        fflush(stdout);
        exit(0); // Exit after serving one request
    }

    return 0;
}
