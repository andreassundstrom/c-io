#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>

#define MY_FILENAME "my-file.txt"

void read_file()
{
  FILE *file = fopen(MY_FILENAME, "r");
  char buffer[250];

  while (fgets(buffer, 255, file))
  {
    printf("%s", buffer);
  }

  fclose(file);
}

void write_file()
{
  FILE *file = fopen(MY_FILENAME, "a+");

  fprintf(file, "1: Hello world!\n");
  fprintf(file, "2: Hello again\n");
  fprintf(file, "3: Good bye\n");

  fclose(file);
}

int main(int argc, char const *argv[])
{
  // Remove file if exists
  remove(MY_FILENAME);

  write_file();
  read_file();

  return 0;
}
