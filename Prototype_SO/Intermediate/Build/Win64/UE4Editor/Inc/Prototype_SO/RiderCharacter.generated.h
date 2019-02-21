// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROTOTYPE_SO_RiderCharacter_generated_h
#error "RiderCharacter.generated.h already included, missing '#pragma once' in RiderCharacter.h"
#endif
#define PROTOTYPE_SO_RiderCharacter_generated_h

#define Prototype_SO_Source_Prototype_SO_RiderCharacter_h_14_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execMoveRight) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_AxisValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->MoveRight(Z_Param_AxisValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMoveForward) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_AxisValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->MoveForward(Z_Param_AxisValue); \
		P_NATIVE_END; \
	}


#define Prototype_SO_Source_Prototype_SO_RiderCharacter_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execMoveRight) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_AxisValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->MoveRight(Z_Param_AxisValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMoveForward) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_AxisValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->MoveForward(Z_Param_AxisValue); \
		P_NATIVE_END; \
	}


#define Prototype_SO_Source_Prototype_SO_RiderCharacter_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesARiderCharacter(); \
	friend struct Z_Construct_UClass_ARiderCharacter_Statics; \
public: \
	DECLARE_CLASS(ARiderCharacter, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Prototype_SO"), NO_API) \
	DECLARE_SERIALIZER(ARiderCharacter)


#define Prototype_SO_Source_Prototype_SO_RiderCharacter_h_14_INCLASS \
private: \
	static void StaticRegisterNativesARiderCharacter(); \
	friend struct Z_Construct_UClass_ARiderCharacter_Statics; \
public: \
	DECLARE_CLASS(ARiderCharacter, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Prototype_SO"), NO_API) \
	DECLARE_SERIALIZER(ARiderCharacter)


#define Prototype_SO_Source_Prototype_SO_RiderCharacter_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ARiderCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ARiderCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARiderCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARiderCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ARiderCharacter(ARiderCharacter&&); \
	NO_API ARiderCharacter(const ARiderCharacter&); \
public:


#define Prototype_SO_Source_Prototype_SO_RiderCharacter_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ARiderCharacter(ARiderCharacter&&); \
	NO_API ARiderCharacter(const ARiderCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARiderCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARiderCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ARiderCharacter)


#define Prototype_SO_Source_Prototype_SO_RiderCharacter_h_14_PRIVATE_PROPERTY_OFFSET
#define Prototype_SO_Source_Prototype_SO_RiderCharacter_h_11_PROLOG
#define Prototype_SO_Source_Prototype_SO_RiderCharacter_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Prototype_SO_Source_Prototype_SO_RiderCharacter_h_14_PRIVATE_PROPERTY_OFFSET \
	Prototype_SO_Source_Prototype_SO_RiderCharacter_h_14_RPC_WRAPPERS \
	Prototype_SO_Source_Prototype_SO_RiderCharacter_h_14_INCLASS \
	Prototype_SO_Source_Prototype_SO_RiderCharacter_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Prototype_SO_Source_Prototype_SO_RiderCharacter_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Prototype_SO_Source_Prototype_SO_RiderCharacter_h_14_PRIVATE_PROPERTY_OFFSET \
	Prototype_SO_Source_Prototype_SO_RiderCharacter_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	Prototype_SO_Source_Prototype_SO_RiderCharacter_h_14_INCLASS_NO_PURE_DECLS \
	Prototype_SO_Source_Prototype_SO_RiderCharacter_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Prototype_SO_Source_Prototype_SO_RiderCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
