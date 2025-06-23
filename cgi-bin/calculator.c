#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.141592653589793

double to_radians(double degrees) {
    return degrees * PI / 180.0;
}

double factorial(int n) {
    if (n < 0) return -1; // error
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

void decode_url(char *src) {
    char *dst = src;
    while (*src) {
        if (*src == '+') {
            *dst++ = ' ';
        } else if (*src == '%' && *(src + 1) && *(src + 2)) {
            char hex[3] = {src[1], src[2], '\0'};
            *dst++ = (char) strtol(hex, NULL, 16);
            src += 2;
        } else {
            *dst++ = *src;
        }
        src++;
    }
    *dst = '\0';
}

int main() {
    char *query = getenv("QUERY_STRING");
    char expr[256];

    printf("Content-Type: text/html\n\n");
    printf("<html><body><h2>Result:</h2>");

    if (query == NULL || strlen(query) == 0) {
        printf("No input provided</body></html>");
        return 0;
    }

    sscanf(query, "expr=%255s", expr);
    decode_url(expr);  // Decode URL-encoded characters

    double result = 0;

    if (strstr(expr, "sin(")) {
        double val;
        sscanf(expr, "sin(%lf)", &val);
        result = sin(to_radians(val));
    } else if (strstr(expr, "cos(")) {
        double val;
        sscanf(expr, "cos(%lf)", &val);
        result = cos(to_radians(val));
    } else if (strstr(expr, "tan(")) {
        double val;
        sscanf(expr, "tan(%lf)", &val);
        result = tan(to_radians(val));
    } else if (strstr(expr, "sqrt(")) {
        double val;
        sscanf(expr, "sqrt(%lf)", &val);
        result = sqrt(val);
    } else if (strstr(expr, "log(")) {
        double val;
        sscanf(expr, "log(%lf)", &val);
        result = log(val);
    } else if (strstr(expr, "exp(")) {
        double val;
        sscanf(expr, "exp(%lf)", &val);
        result = exp(val);
    } else if (strstr(expr, "factorial(")) {
        int val;
        sscanf(expr, "factorial(%d)", &val);
        result = factorial(val);
    } else if (strstr(expr, "^")) {
        double base, power;
        sscanf(expr, "%lf^%lf", &base, &power);
        result = pow(base, power);
    } else if (strchr(expr, '+')) {
        double a, b;
        sscanf(expr, "%lf+%lf", &a, &b);
        result = a + b;
    } else if (strchr(expr, '-') && expr[0] != '-') {
        double a, b;
        sscanf(expr, "%lf-%lf", &a, &b);
        result = a - b;
    } else if (strchr(expr, '*')) {
        double a, b;
        sscanf(expr, "%lf*%lf", &a, &b);
        result = a * b;
    } else if (strchr(expr, '/')) {
        double a, b;
        sscanf(expr, "%lf/%lf", &a, &b);
        if (b == 0) {
            printf("Division by zero error");
            return 0;
        }
        result = a / b;
    } else if (strcmp(expr, "pi") == 0 || strcmp(expr, "Pi") == 0) {
        result = PI;
    } else {
        printf("Unsupported expression: %s", expr);
        return 0;
    }

    printf("<p><strong>Expression:</strong> %s</p>", expr);
    printf("<p><strong>Output:</strong> %.6f</p>", result);
    printf("</body></html>");
    return 0;
}
