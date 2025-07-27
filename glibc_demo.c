#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

/* Example: malloc and free */
void memory_demo() {
    char *buffer = (char *)malloc(100);
    if (buffer) {
        strcpy(buffer, "Hello, glibc!");
        printf("Buffer: %s\n", buffer);
        free(buffer);
    }
}

/* Example: strlen and strcpy */
void string_demo() {
    const char *src = "glibc example";
    char dest[50];
    strcpy(dest, src);
    printf("Copied string: %s (length: %zu)\n", dest, strlen(dest));
}

/* Example: fopen and fclose */
void file_demo() {
    FILE *fp = fopen("test.txt", "w");
    if (fp) {
        fprintf(fp, "Written using glibc functions!\n");
        fclose(fp);
    }
}

/* Example: pthread_create */
void* thread_func(void* arg) {
    printf("Hello from thread! Arg: %s\n", (char*)arg);
    return NULL;
}

void thread_demo() {
    pthread_t tid;
    char message[] = "Thread argument";
    pthread_create(&tid, NULL, thread_func, message);
    pthread_join(tid, NULL);
}

int main() {
    printf("glibc major functions demo:\n");
    memory_demo();
    string_demo();
    file_demo();
    thread_demo();
    return 0;
}