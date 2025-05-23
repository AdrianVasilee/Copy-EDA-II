#include "common.h"
#include "document.h"
#include "linked.h"
#include "sample_lib.h"
#include "search.h"

void createaleak() {
  char *foo = malloc(20 * sizeof(char));
  printf("Allocated leaking string: %s", foo);
}

int main() {
  printf("*****************\nWelcome to EDA 2!\n*****************\n");

  // how to import and call a function
  // printf("Factorial of 4 is %d\n", fact(4));

  // uncomment and run "make v" to see how valgrind detects memory leaks
  // createaleak();

  start_database();

  LinkedList *files = get_files(WIKIPEDIA540);
  show_list(*files);

  LinkedList document_title;
  initialize_list(&document_title, STRING);

  Document *d = linear_search_title(*files, "Aging in cats");

  print_document(d);

  free_list(files);
  free_database();

  return 0;
}
