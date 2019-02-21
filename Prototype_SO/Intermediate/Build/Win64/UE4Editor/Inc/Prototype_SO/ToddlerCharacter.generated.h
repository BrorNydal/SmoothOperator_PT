// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FHitResult;
#ifdef PROTOTYPE_SO_ToddlerCharacter_generated_h
#error "ToddlerCharacter.generated.h already included, missing '#pragma once' in ToddlerCharacter.h"
#endif
#define PROTOTYPE_SO_ToddlerCharacter_generated_h

#define Prototype_SO_Source_Prototype_SO_ToddlerCharacter_h_16_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execInteractFalse) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->InteractFalse(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execInteractTrue) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComponent); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->InteractTrue(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComponent,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	} \
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


#define Prototype_SO_Source_Prototype_SO_ToddlerCharacter_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execInteractFalse) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->InteractFalse(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execInteractTrue) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComponent); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->InteractTrue(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComponent,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	} \
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


#define Prototype_SO_Source_Prototype_SO_ToddlerCharacter_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAToddlerCharacter(); \
	friend struct Z_Construct_UClass_AToddlerCharacter_Statics; \
public: \
	DECLARE_CLASS(AToddlerCharacter, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Prototype_SO"), NO_API) \
	DECLARE_SERIALIZER(AToddlerCharacter)


#define Prototype_SO_Source_Prototype_SO_ToddlerCharacter_h_16_INCLASS \
private: \
	static void StaticRegisterNativesAToddlerCharacter(); \
	friend struct Z_Construct_UClass_AToddlerCharacter_Statics; \
public: \
	DECLARE_CLASS(AToddlerCharacter, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Prototype_SO"), NO_API) \
	DECLARE_SERIALIZER(AToddlerCharacter)


#define Prototype_SO_Source_Prototype_SO_ToddlerCharacter_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AToddlerCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AToddlerCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AToddlerCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AToddlerCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AToddlerCharacter(AToddlerCharacter&&); \
	NO_API AToddlerCharacter(const AToddlerCharacter&); \
public:


#define Prototype_SO_Source_Prototype_SO_ToddlerCharacter_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AToddlerCharacter(AToddlerCharacter&&); \
	NO_API AToddlerCharacter(const AToddlerCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AToddlerCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AToddlerCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AToddlerCharacter)


#define Prototype_SO_Source_Prototype_SO_ToddlerCharacter_h_16_PRIVATE_PROPERTY_OFFSET
#define Prototype_SO_Source_Prototype_SO_ToddlerCharacter_h_13_PROLOG
#define Prototype_SO_Source_Prototype_SO_ToddlerCharacter_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Prototype_SO_Source_Prototype_SO_ToddlerCharacter_h_16_PRIVATE_PROPERTY_OFFSET \
	Prototype_SO_Source_Prototype_SO_ToddlerCharacter_h_16_RPC_WRAPPERS \
	Prototype_SO_Source_Prototype_SO_ToddlerCharacter_h_16_INCLASS \
	Prototype_SO_Source_Prototype_SO_ToddlerCharacter_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Prototype_SO_Source_Prototype_SO_ToddlerCharacter_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Prototype_SO_Source_Prototype_SO_ToddlerCharacter_h_16_PRIVATE_PROPERTY_OFFSET \
	Prototype_SO_Source_Prototype_SO_ToddlerCharacter_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	Prototype_SO_Source_Prototype_SO_ToddlerCharacter_h_16_INCLASS_NO_PURE_DECLS \
	Prototype_SO_Source_Prototype_SO_ToddlerCharacter_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Prototype_SO_Source_Prototype_SO_ToddlerCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
