#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <ctype.h>

#define BUFFER_SIZE 100

int pipefd[2];

void *server_thread(void *arg) {
    char message[] = "Hello, client!";
    write(pipefd[1], message, sizeof(message));
    close(pipefd[1]);
    pthread_exit(NULL);
}

void *client_thread(void *arg) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read = read(pipefd[0], buffer, BUFFER_SIZE);
    close(pipefd[0]);
    if (bytes_read > 0) {
        for (int i = 0; i < bytes_read; i++) {
            buffer[i] = toupper(buffer[i]);
        }
        printf("Received from server: %s\n", buffer);
    } else {
        printf("Failed to receive message from server.\n");
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t server_tid, client_tid;
    
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    if (pthread_create(&server_tid, NULL, server_thread, NULL) != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    if (pthread_create(&client_tid, NULL, client_thread, NULL) != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    if (pthread_join(server_tid, NULL) != 0) {
        perror("pthread_join");
        exit(EXIT_FAILURE);
    }

    if (pthread_join(client_tid, NULL) != 0) {
        perror("pthread_join");
        exit(EXIT_FAILURE);
    }

    return 0;
}

