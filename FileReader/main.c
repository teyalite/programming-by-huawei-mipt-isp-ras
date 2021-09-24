#include <stdio.h>
#include <stdlib.h>
#include "QuickSort.h"

typedef char* Buffer;

enum Separator {
    SEPARATOR_SIZE = 5,
    SEPARATOR_CHAR = '/'
};

struct FileInfo {
    long numberOfLine;
    long size;
};

typedef struct FileInfo FileInfo;

struct FileData {
    Buffer buffer;
    FileInfo fileInfo;
    Line* lines;
};

typedef struct FileData FileData;


Buffer GetBuffer(FILE* file, FileInfo* fileInfo, Line* array) {

    Buffer buffer = malloc(fileInfo->size + 1);

    int currentChar = fgetc(file);
    long index = 0, arrayIndex = 0;

    array[arrayIndex].start = &buffer[0];

    while (currentChar != EOF) {

        if (currentChar == '\n') {
            array[arrayIndex].end = &buffer[index - 1];
            array[++arrayIndex].start = &buffer[index + 1];
        }

        buffer[index] = currentChar;
        currentChar = fgetc(file);
        ++index;
    }

    array[arrayIndex].end = &buffer[index - 1];
    buffer[fileInfo->size] = 0;

    return buffer;
}

void writeLine(Line line, FILE* file) {
    while (line.start != line.end) {
        fputc(*line.start, file);
        ++line.start;
    }
    fputc(*line.end, file);
    fputc('\n', file);
}

void separator(FILE* file) {
    for (long i = 0; i < SEPARATOR_SIZE; ++i)
        fputc(SEPARATOR_CHAR, file);
    fputc('\n', file);
}

FileInfo getFileInfo(FILE* file) {
    FileInfo fileInfo = {.size = 0, .numberOfLine = 1};
    int currentChar = fgetc(file);

    while (currentChar != EOF) {

        ++fileInfo.size;

        if (currentChar == '\n')
            ++fileInfo.numberOfLine;

        currentChar = fgetc(file);
    }

    fseek(file, 0, SEEK_SET);

    return fileInfo;
}

FileData readFile (const char* fileName) {

    FILE* file = fopen(fileName, "r");

    if (file != NULL) {

        FileData fileData;

        fileData.fileInfo = getFileInfo(file);

        fileData.lines = malloc(fileData.fileInfo.numberOfLine * sizeof(Line));

        fileData.buffer = GetBuffer(file, &fileData.fileInfo, fileData.lines);

        fclose(file);

        printf("Successfully read the file.\n");

        return fileData;
    } else {

        printf("Couldn't open the file named %s", fileName);
        exit(0);
    }
}

void writeFile(const char* fileName, FileData* fileData) {

    FILE* file = fopen(fileName, "w");

    if (file != NULL) {

        QuickSort(fileData->lines, 0, fileData->fileInfo.numberOfLine, LeftToRight);

        for (long i = 0; i < fileData->fileInfo.numberOfLine; ++i) {
            writeLine(fileData->lines[i], file);
        }

        separator(file);

        QuickSort(fileData->lines, 0, fileData->fileInfo.numberOfLine, RightToLeft);

        for (long i = 0; i < fileData->fileInfo.numberOfLine; ++i) {
            writeLine(fileData->lines[i], file);
        }

        separator(file);

        fputs(fileData->buffer, file);

        fclose(file);

        printf("Successfully write in the file.\n");

    } else {

        printf("Couldn't open the file named %s", fileName);
        exit(0);
    }
}

int main() {

    const char* inputFileName = "text.txt";
    const char* outputFileName = "result.txt";

    FileData fileData = readFile(inputFileName);

    writeFile(outputFileName, &fileData);

    free(fileData.buffer);
    free(fileData.lines);

    return 0;
}