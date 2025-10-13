#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct header {
  uint64_t size;
  struct header *next;
  int id;
};

void initialize_block(struct header *block, uint64_t size, struct header *next,
                      int id) {
  block->size = size;
  block->next = next;
  block->id = id;
}

int find_first_fit(struct header *free_list_ptr, uint64_t size) {
  while (1) {
    if (free_list_ptr->size >= size) {
      return free_list_ptr->id;
    } else if (free_list_ptr->next == NULL) {
      perror("Linked list did not contain a large enough node.");
      break;
    } else {
      free_list_ptr = free_list_ptr->next;
    }
  }
  return -1;
}

int find_best_fit(struct header *free_list_ptr, uint64_t size) {
  int best_fit_id = -1;
  int best_size_difference = INT_MAX;
  while (1) {
    if (free_list_ptr->size >= size) {
      int size_difference = free_list_ptr->size - size;
      if (size_difference < best_size_difference) {
        best_size_difference = size_difference;
        best_fit_id = free_list_ptr->id;
      }
      if (free_list_ptr->next == NULL) {
        break;
      } else {
        free_list_ptr = free_list_ptr->next;
      }
    } else if (free_list_ptr->next == NULL) {
      break;
    } else {
      free_list_ptr = free_list_ptr->next;
    }
  }

  if (best_fit_id == -1) {
    perror("Linked list did not contain a large enough node.");
  }

  return best_fit_id;
}

int find_worst_fit(struct header *free_list_ptr, uint64_t size) {
  int worst_fit_id = -1; 
  int worst_size_difference = 0;
  while (1) {
    if (free_list_ptr->size >= size) {
      int size_difference = free_list_ptr->size - size;
      if (size_difference > worst_size_difference) {
        worst_size_difference = size_difference;
        worst_fit_id = free_list_ptr->id;
      }
      if (free_list_ptr->next == NULL) {
        break;
      } else {
        free_list_ptr = free_list_ptr->next;
      }

    } else if (free_list_ptr->next == NULL) {
      break;
    } else {
      free_list_ptr = free_list_ptr->next;
    }
  }

  if (worst_fit_id == -1) {
    perror("Linked list did not contain a large enough node.");
  }

  return worst_fit_id;
}

int main(void) {

  struct header *free_block1 = (struct header *)malloc(sizeof(struct header));
  struct header *free_block2 = (struct header *)malloc(sizeof(struct header));
  struct header *free_block3 = (struct header *)malloc(sizeof(struct header));
  struct header *free_block4 = (struct header *)malloc(sizeof(struct header));
  struct header *free_block5 = (struct header *)malloc(sizeof(struct header));

  initialize_block(free_block1, 6, free_block2, 1);
  initialize_block(free_block2, 12, free_block3, 2);
  initialize_block(free_block3, 24, free_block4, 3);
  initialize_block(free_block4, 8, free_block5, 4);
  initialize_block(free_block5, 4, NULL, 5);

  struct header *free_list_ptr = free_block1;

  int first_fit_id = find_first_fit(free_list_ptr, 7);
  int best_fit_id = find_best_fit(free_list_ptr, 7);
  int worst_fit_id = find_worst_fit(free_list_ptr, 7);
 
  printf("The ID for First-Fit algorithm is: %d\n", first_fit_id);
  printf("The ID for Best-Fit algorithm is: %d\n", best_fit_id);
  printf("The ID for Worst-Fit algorithm is: %d\n", worst_fit_id);

  return 0;
}

// Part 2
// I'm assuming that even though these blocks are "freed", they retain their location
// pointers and next pointers.
//
// if freed_block_new->next is empty
//  merge(freed_block_new, freed_block_new->next
// for header *node = linked_list_head; node->next != NULL; node = node->next
//  if node->next = freed_block_new
//   if node is empty
//    merge(node, node->next)
//
