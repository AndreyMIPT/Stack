
#include "stack.h"


typedef struct
{
	int elem_size;
	int num;
	int count;
}st_info;

struct stack
{ 
	void* data; 
	void* peek;
	st_info* info;
};

#include "stack.h"

stack* st_creat ( int numb ) 
{
	stack* st = (stack *)calloc (1, sizeof (stack));
	if (st == NULL)
		return NULL;
		
	st->info = (st_info *) calloc(1,sizeof (st_info));
	if (st->info == NULL)
	{
		free (st);
		return NULL;
	}
	st->info->count = 1;
	st->info->elem_size = numb;
	st->info->num = 0;
	
	st->data = calloc (1, st->info->elem_size);
    if (st->data == NULL) { 
        free (st->info);
        free (st);
        return NULL;
    }

    st->peek = st->data;
    return st;
};

int st_clear (stack* st) 
{
	if (st == NULL) {
        return 1;
    }

    free (st->info);
    st->info = NULL;
    free (st->data);
    st->data = NULL;
    st->peek = NULL;
    return 0;
};

static int st_resize (stack* st, int count) 
{
    void* tmp = realloc (st->data, count * st->info->elem_size);
    if (tmp == NULL) {
        return 2;
    }
    st->data = tmp;
    st->peek = st->data + st->info->num * st->info->elem_size;
    st->info->count = count;
    return 0;
}

int st_push (stack* st, void* data) 
{
	
    if (st == NULL || data == NULL) 
    {
        return 1;
    }
     if (st->info->num + 1 > st->info->count) 
        if (st_resize (st, ++st->info->count) != 0) 
            return 2;
    
    
    memcpy (st->peek, data, st->info->elem_size);
    st->peek += st->info->elem_size;
    st->info->num++;
    return 0;
}

int st_pop (stack* st, void* data) 
{
    if (st == NULL || data == NULL) {
        return 1;
    }
    if (st->info->num == 0)
        return 3;
    memcpy (data, st->peek - st->info->elem_size, st->info->elem_size);
    if ( st->info->num != 1)	
		if(st_resize (st , --st->info->count) != 0)
			return 2;
    st->peek -= st->info->elem_size;
    st->info->num--;
    return 0;
}

int st_get_num (stack* st) {
    if (st == NULL) 
    {
        return -1;
    }
    return st->info->num;
}
 
	
		








