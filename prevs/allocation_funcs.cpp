// #include <cstddef>
// #include <cstdlib>
// #include <stdio.h>
// #include <execinfo.h>

// #include "allocation_funcs.h"
// #include "general.h"



// void **alloc_stack = NULL;
// void **alloc_stack_curptr = NULL;

// alloc_info *construct_alloc_elem() {
//     alloc_info *elem = (alloc_info *) calloc(1, sizeof(alloc_info));
// }
// void *ni_calloc__(size_t nmemb, size_t size, const char func_name[]) {
//     if (alloc_stack == NULL) {
//         alloc_stack = (void **) realloc(alloc_stack, ALLOC_STACK_MAXSZ * sizeof(void *));
//         alloc_stack_curptr = alloc_stack;
//     }
//     void *ptr = calloc(nmemb, size);
//     if (ptr == NULL) {
//         alloc_stack_clear();
//         return NULL;
//     }

//     return ptr;
//     printf("name: %s\n", func_name);
// }

// void test() {
//     // const int size = 10;
//     // void *bufer[size];

//     // int backtrace_cnt = backtrace(bufer, size);
//     // char** name = backtrace_symbols(bufer, size);

//     // for (int i = 0; i < backtrace_cnt; i++)
//     // printf("name: %s\n", name[i]);
//     printf("name: %s\n", __FUNCTION__);
// }

// int alloc_stack_clear() {
//     while (*alloc_stack_curptr != NULL) {
//         FREE(*alloc_stack_curptr--);
//     }
//     return RETURN_TRUE;
// }

// // void *ni_realloc(void *ptr, size_t general_size) { // FIXME: мб использовать бинпоиск для поиска указателя?
// //     void *old_ptr = ptr;
// //     void **alloc_stack_pos = alloc_stack_curptr;
// //     void *new_ptr = (char **) realloc(ptr, general_size);
// //     while (1) {
// //         if (*alloc_stack_curptr == NULL) {
// //             debug("ni_realloc hasn't find old_ptr\n");
// //             return NULL;
// //         }
// //         if (*alloc_stack_pos == old_ptr) {
// //             *alloc_stack_pos-- = new_ptr;
// //         }
// //     }
// //     return new_ptr;
// // }

// // void printf_alloc_stack() {
// //     void **ptr = alloc_stack;
// //     while (ptr != NULL) {
// //         printf("%s", typeof(1));
// //         printf("[%5s] ", (char *) *ptr++);
// //     }
// //     printf("\n");
// // }


