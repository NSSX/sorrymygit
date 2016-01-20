#include "fillit.h"

t_var *assign(t_var *v, int length, char *chaine, char *piece)
{
  v = (t_var *)malloc(sizeof(t_var) * 2);
  v->length = length + 1;
  v->count = 0;
  v->chaine = chaine;
  v->piece = piece;
  return (v);
}

int returned_try(int count)
{
  if (count == 4)
    return (1);
  return (0);
}
