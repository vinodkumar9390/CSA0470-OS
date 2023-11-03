#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    // Shared memory key
    key_t key = 1234;
    int shmid;
    int *shared_memory, *ptr;

    // Create shared memory segment
    shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Attach shared memory segment
    shared_memory = (int *)shmat(shmid, NULL, 0);
    if (shared_memory == (int *)-1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // Write to shared memory
    *shared_memory = 42;
    printf("Parent Process: Shared memory value set to %d\n", *shared_memory);

    // Fork a child process
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        printf("Child Process: Shared memory value read: %d\n", *shared_memory);

        // Modify shared memory value
        *shared_memory = 100;
        printf("Child Process: Shared memory value changed to %d\n", *shared_memory);

        // Detach shared memory segment from this process
        shmdt(shared_memory);
    } else if (pid > 0) {
        // Parent process
        // Wait for the child to complete
        wait(NULL);

        // Print the final value from shared memory
        printf("Parent Process: Shared memory value after child process: %d\n", *shared_memory);

        // Detach shared memory segment from this process
        shmdt(shared_memory);

        // Remove the shared memory segment
        shmctl(shmid, IPC_RMID, NULL);
    } else {
        // Fork failed
        perror("fork");
        exit(EXIT_FAILURE);
    }

    return 0;
}
