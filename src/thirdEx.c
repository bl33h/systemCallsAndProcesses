/*---------------------------------------------------------------------------
Copyright (C), 2024-2025, Sara Echeverria (bl33h)
@author Sara Echeverria
FileName: thirdEx.c
@version: I
Creation: 19/01/2024
Last modification: 19/01/2024
------------------------------------------------------------------------------*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {
    int file_descriptor = -1;
    int file_descriptor_dest = -1;

    // correct number arguments checker
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    char* origin = argv[1];
    char* destination = argv[2];

    // open the source file
    file_descriptor = open(origin, O_RDONLY);
    file_descriptor_dest = open(destination, O_WRONLY | O_CREAT | O_TRUNC, 0666);

	char buffer[BUFFER_SIZE];
    ssize_t bytesRead, bytesWritten;
    bytesRead = read(file_descriptor, buffer, sizeof(buffer));

	// error management
    if (file_descriptor == -1) {
        perror("Error opening source file");
        return 1;
    }

    if (file_descriptor_dest == -1) {
        perror("Error opening/creating destination file");
        close(file_descriptor);
        return 1;
    }

    if (bytesRead == -1) {
        perror("Error reading from source file");
        close(file_descriptor);
        close(file_descriptor_dest);
        return 1;
    }

    int textLen = bytesRead;
    bytesWritten = write(file_descriptor_dest, buffer, textLen);

	// bytes written function
    if (bytesWritten == -1) {
        perror("Error writing to destination file");
        close(file_descriptor);
        close(file_descriptor_dest);
        return 1;
    }

    printf("Bytes written: %zd\n", bytesWritten);
    close(file_descriptor);
    close(file_descriptor_dest);

    return 0;
}