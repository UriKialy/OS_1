#include <iostream>
#include <unistd.h>
#include <cstring>
#include <sys/types.h>
#include <sys/wait.h>

#define PHONEBOOK_FILE "phonebook.txt"

void execute_command_chain(const char* name) {
    int pipe1[2], pipe2[2], pipe3[2];

    // Create first pipe
    if (pipe(pipe1) == -1) {
        perror("pipe1");
        exit(1);
    }

    // Fork first process (cat)
    if (fork() == 0) {
        // Redirect stdout to pipe1 write end
        dup2(pipe1[1], STDOUT_FILENO);
        close(pipe1[0]);
        close(pipe1[1]);
        execlp("cat", "cat", PHONEBOOK_FILE, NULL);
        perror("execlp cat");
        exit(1);
    }

    // Create second pipe
    if (pipe(pipe2) == -1) {
        perror("pipe2");
        exit(1);
    }

    // Fork second process (grep)
    if (fork() == 0) {
        // Redirect stdin to pipe1 read end
        dup2(pipe1[0], STDIN_FILENO);
        // Redirect stdout to pipe2 write end
        dup2(pipe2[1], STDOUT_FILENO);
        close(pipe1[0]);
        close(pipe1[1]);
        close(pipe2[0]);
        close(pipe2[1]);
        execlp("grep", "grep", name, NULL);
        perror("execlp grep");
        exit(1);
    }

    close(pipe1[0]);
    close(pipe1[1]);

    // Create third pipe
    if (pipe(pipe3) == -1) {
        perror("pipe3");
        exit(1);
    }

    // Fork third process (sed)
    if (fork() == 0) {
        // Redirect stdin to pipe2 read end
        dup2(pipe2[0], STDIN_FILENO);
        // Redirect stdout to pipe3 write end
        dup2(pipe3[1], STDOUT_FILENO);
        close(pipe2[0]);
        close(pipe2[1]);
        close(pipe3[0]);
        close(pipe3[1]);
        execlp("sed", "sed", "s/.*,//", NULL);
        perror("execlp sed");
        exit(1);
    }

    close(pipe2[0]);
    close(pipe2[1]);

    // Fork fourth process (awk)
    if (fork() == 0) {
        // Redirect stdin to pipe3 read end
        dup2(pipe3[0], STDIN_FILENO);
        close(pipe3[0]);
        close(pipe3[1]);
        execlp("awk", "awk", "{print $1}", NULL);
        perror("execlp awk");
        exit(1);
    }

    close(pipe3[0]);
    close(pipe3[1]);

    // Wait for all child processes to finish
    for (int i = 0; i < 4; i++) {
        wait(NULL);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <name>" << std::endl;
        return 1;
    }

    execute_command_chain(argv[1]);
    return 0;
}
