// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from full_name_messages:srv/FullNameSumService.idl
// generated code does not contain a copyright notice

#ifndef FULL_NAME_MESSAGES__SRV__DETAIL__FULL_NAME_SUM_SERVICE__STRUCT_H_
#define FULL_NAME_MESSAGES__SRV__DETAIL__FULL_NAME_SUM_SERVICE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'last_name'
// Member 'name'
// Member 'first_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/FullNameSumService in the package full_name_messages.
typedef struct full_name_messages__srv__FullNameSumService_Request
{
  rosidl_runtime_c__String last_name;
  rosidl_runtime_c__String name;
  rosidl_runtime_c__String first_name;
} full_name_messages__srv__FullNameSumService_Request;

// Struct for a sequence of full_name_messages__srv__FullNameSumService_Request.
typedef struct full_name_messages__srv__FullNameSumService_Request__Sequence
{
  full_name_messages__srv__FullNameSumService_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} full_name_messages__srv__FullNameSumService_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'full_name'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/FullNameSumService in the package full_name_messages.
typedef struct full_name_messages__srv__FullNameSumService_Response
{
  rosidl_runtime_c__String full_name;
} full_name_messages__srv__FullNameSumService_Response;

// Struct for a sequence of full_name_messages__srv__FullNameSumService_Response.
typedef struct full_name_messages__srv__FullNameSumService_Response__Sequence
{
  full_name_messages__srv__FullNameSumService_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} full_name_messages__srv__FullNameSumService_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FULL_NAME_MESSAGES__SRV__DETAIL__FULL_NAME_SUM_SERVICE__STRUCT_H_
