#ifndef SIT_CALLBACK_H_INCLUDED
#define SIT_CALLBACK_H_INCLUDED

// A generic callback suitable for attaching to the perc query tree.
// This has a next field, so it's also a linked list node.
typedef struct sit_callback {
  void                 (*handler)(struct sit_callback *self, void *data);
  void                  *user_data;
  struct sit_callback   *next;
  long                   id;
  void                 (*free)(struct sit_callback* cb);
} sit_callback;

sit_callback *
sit_callback_new();

void
sit_callback_free(sit_callback *);

#endif