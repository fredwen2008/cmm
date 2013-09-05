#ifndef _object_h
#define _object_h

#include <cmm/gc.h>

#define New(Type, Ptr)			Object_new(__GC__, sizeof(Type), (void **)&(Ptr))
#define Release(Obj)			Object_release(__GC__, (void *)(Obj))
#define Copy(LObj, RObj) 		Object_copy(__GC__, (void **)&(LObj), (void *)(RObj));

typedef struct ObjectHeader {
	uintptr_t ref_count;
} ObjectHeader;

void Object_new(GC *gc, size_t type_size, void **obj);
void Object_release(GC *gc, void *obj);
void Object_copy(GC *gc, void **lobj, void *robj);

#endif
