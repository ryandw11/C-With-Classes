#pragma once
#ifndef CWC_ClASSES
#define CWC_CLASSES

#define begin_class(CLASS_NAME) typedef struct CLASS_NAME##_cwc CLASS_NAME;
#define class(NAME) struct NAME ## _cwc
#define class_declartions(NAME) NAME ## _cwc_default = {
#define func(NAME, ...) (*NAME)(##__VA_ARGS__)
#define sfunc(CLASS_NAME, NAME, ...) (*NAME)(CLASS_NAME*, ##__VA_ARGS__)
#define vfunc(NAME) (*NAME)(void)
#define svfunc(CLASS_NAME, NAME) (*NAME)(CLASS_NAME*)
#define class_field(DEFAULT_VALUE) DEFAULT_VALUE,
#define class_func(CLASS_NAME, FUNC_NAME) cwc_##CLASS_NAME##_impl_##FUNC_NAME,
#define decl_class_func(CLASS_NAME, FUNC_NAME, ...) cwc_##CLASS_NAME##_impl_##FUNC_NAME(##__VA_ARGS__)
#define decl_class_sfunc(CLASS_NAME, FUNC_NAME, ...) cwc_##CLASS_NAME##_impl_##FUNC_NAME(CLASS_NAME* self, ##__VA_ARGS__)
#define decl_class_svfunc(CLASS_NAME, FUNC_NAME) cwc_##CLASS_NAME##_impl_##FUNC_NAME(CLASS_NAME* self)
#define end_class(CLASS_NAME) };

#define new(CLASS_NAME) malloc(sizeof(CLASS_NAME));
#define default_class(CLASS_NAME, VAR_NAME) memcpy(VAR_NAME, & ## CLASS_NAME ## _cwc_default, sizeof(CLASS_NAME));

#define call(VAR_NAME, FUNC_NAME, ...) VAR_NAME->FUNC_NAME(VAR_NAME, ##__VA_ARGS__)

#endif