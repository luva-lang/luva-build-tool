#ifndef LUVA_BUILD_TOOL__TYPE_H_
#define LUVA_BUILD_TOOL__TYPE_H_

typedef enum {
	LBT_PRIMITIVE_TYPE_ANY,
	LBT_PRIMITIVE_TYPE_BOOL,
	LBT_PRIMITIVE_TYPE_NUMBER,
	LBT_PRIMITIVE_TYPE_STRING,
} primitive_type_t;

typedef struct {
	primitive_type_t primitive_type;
	int size;
} array_type_t;

#endif // LUVA_BUILD_TOOL__TYPE_H_