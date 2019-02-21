// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Prototype_SO/BearCharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBearCharacter() {}
// Cross Module References
	PROTOTYPE_SO_API UClass* Z_Construct_UClass_ABearCharacter_NoRegister();
	PROTOTYPE_SO_API UClass* Z_Construct_UClass_ABearCharacter();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_Prototype_SO();
	PROTOTYPE_SO_API UFunction* Z_Construct_UFunction_ABearCharacter_InteractFalse();
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	PROTOTYPE_SO_API UFunction* Z_Construct_UFunction_ABearCharacter_InteractTrue();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	PROTOTYPE_SO_API UFunction* Z_Construct_UFunction_ABearCharacter_MoveForward();
	PROTOTYPE_SO_API UFunction* Z_Construct_UFunction_ABearCharacter_MoveRight();
	ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
// End Cross Module References
	void ABearCharacter::StaticRegisterNativesABearCharacter()
	{
		UClass* Class = ABearCharacter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "InteractFalse", &ABearCharacter::execInteractFalse },
			{ "InteractTrue", &ABearCharacter::execInteractTrue },
			{ "MoveForward", &ABearCharacter::execMoveForward },
			{ "MoveRight", &ABearCharacter::execMoveRight },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ABearCharacter_InteractFalse_Statics
	{
		struct BearCharacter_eventInteractFalse_Parms
		{
			UPrimitiveComponent* OverlappedComp;
			AActor* OtherActor;
			UPrimitiveComponent* OtherComp;
			int32 OtherBodyIndex;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_OtherBodyIndex;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OtherComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherComp;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OverlappedComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OverlappedComp;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ABearCharacter_InteractFalse_Statics::NewProp_OtherBodyIndex = { UE4CodeGen_Private::EPropertyClass::Int, "OtherBodyIndex", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(BearCharacter_eventInteractFalse_Parms, OtherBodyIndex), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABearCharacter_InteractFalse_Statics::NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ABearCharacter_InteractFalse_Statics::NewProp_OtherComp = { UE4CodeGen_Private::EPropertyClass::Object, "OtherComp", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000080080, 1, nullptr, STRUCT_OFFSET(BearCharacter_eventInteractFalse_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ABearCharacter_InteractFalse_Statics::NewProp_OtherComp_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ABearCharacter_InteractFalse_Statics::NewProp_OtherComp_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ABearCharacter_InteractFalse_Statics::NewProp_OtherActor = { UE4CodeGen_Private::EPropertyClass::Object, "OtherActor", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(BearCharacter_eventInteractFalse_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABearCharacter_InteractFalse_Statics::NewProp_OverlappedComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ABearCharacter_InteractFalse_Statics::NewProp_OverlappedComp = { UE4CodeGen_Private::EPropertyClass::Object, "OverlappedComp", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000080080, 1, nullptr, STRUCT_OFFSET(BearCharacter_eventInteractFalse_Parms, OverlappedComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ABearCharacter_InteractFalse_Statics::NewProp_OverlappedComp_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ABearCharacter_InteractFalse_Statics::NewProp_OverlappedComp_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABearCharacter_InteractFalse_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABearCharacter_InteractFalse_Statics::NewProp_OtherBodyIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABearCharacter_InteractFalse_Statics::NewProp_OtherComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABearCharacter_InteractFalse_Statics::NewProp_OtherActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABearCharacter_InteractFalse_Statics::NewProp_OverlappedComp,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABearCharacter_InteractFalse_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "BearCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABearCharacter_InteractFalse_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABearCharacter, "InteractFalse", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00040401, sizeof(BearCharacter_eventInteractFalse_Parms), Z_Construct_UFunction_ABearCharacter_InteractFalse_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ABearCharacter_InteractFalse_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABearCharacter_InteractFalse_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ABearCharacter_InteractFalse_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABearCharacter_InteractFalse()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABearCharacter_InteractFalse_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABearCharacter_InteractTrue_Statics
	{
		struct BearCharacter_eventInteractTrue_Parms
		{
			UPrimitiveComponent* OverlappedComponent;
			AActor* OtherActor;
			UPrimitiveComponent* OtherComponent;
			int32 OtherBodyIndex;
			bool bFromSweep;
			FHitResult SweepResult;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SweepResult_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_SweepResult;
		static void NewProp_bFromSweep_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bFromSweep;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_OtherBodyIndex;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OtherComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherComponent;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OverlappedComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OverlappedComponent;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABearCharacter_InteractTrue_Statics::NewProp_SweepResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ABearCharacter_InteractTrue_Statics::NewProp_SweepResult = { UE4CodeGen_Private::EPropertyClass::Struct, "SweepResult", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010008008000182, 1, nullptr, STRUCT_OFFSET(BearCharacter_eventInteractTrue_Parms, SweepResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(Z_Construct_UFunction_ABearCharacter_InteractTrue_Statics::NewProp_SweepResult_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ABearCharacter_InteractTrue_Statics::NewProp_SweepResult_MetaData)) };
	void Z_Construct_UFunction_ABearCharacter_InteractTrue_Statics::NewProp_bFromSweep_SetBit(void* Obj)
	{
		((BearCharacter_eventInteractTrue_Parms*)Obj)->bFromSweep = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ABearCharacter_InteractTrue_Statics::NewProp_bFromSweep = { UE4CodeGen_Private::EPropertyClass::Bool, "bFromSweep", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(BearCharacter_eventInteractTrue_Parms), &Z_Construct_UFunction_ABearCharacter_InteractTrue_Statics::NewProp_bFromSweep_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ABearCharacter_InteractTrue_Statics::NewProp_OtherBodyIndex = { UE4CodeGen_Private::EPropertyClass::Int, "OtherBodyIndex", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(BearCharacter_eventInteractTrue_Parms, OtherBodyIndex), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABearCharacter_InteractTrue_Statics::NewProp_OtherComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ABearCharacter_InteractTrue_Statics::NewProp_OtherComponent = { UE4CodeGen_Private::EPropertyClass::Object, "OtherComponent", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000080080, 1, nullptr, STRUCT_OFFSET(BearCharacter_eventInteractTrue_Parms, OtherComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ABearCharacter_InteractTrue_Statics::NewProp_OtherComponent_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ABearCharacter_InteractTrue_Statics::NewProp_OtherComponent_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ABearCharacter_InteractTrue_Statics::NewProp_OtherActor = { UE4CodeGen_Private::EPropertyClass::Object, "OtherActor", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(BearCharacter_eventInteractTrue_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABearCharacter_InteractTrue_Statics::NewProp_OverlappedComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ABearCharacter_InteractTrue_Statics::NewProp_OverlappedComponent = { UE4CodeGen_Private::EPropertyClass::Object, "OverlappedComponent", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000080080, 1, nullptr, STRUCT_OFFSET(BearCharacter_eventInteractTrue_Parms, OverlappedComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ABearCharacter_InteractTrue_Statics::NewProp_OverlappedComponent_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ABearCharacter_InteractTrue_Statics::NewProp_OverlappedComponent_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABearCharacter_InteractTrue_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABearCharacter_InteractTrue_Statics::NewProp_SweepResult,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABearCharacter_InteractTrue_Statics::NewProp_bFromSweep,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABearCharacter_InteractTrue_Statics::NewProp_OtherBodyIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABearCharacter_InteractTrue_Statics::NewProp_OtherComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABearCharacter_InteractTrue_Statics::NewProp_OtherActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABearCharacter_InteractTrue_Statics::NewProp_OverlappedComponent,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABearCharacter_InteractTrue_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "BearCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABearCharacter_InteractTrue_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABearCharacter, "InteractTrue", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00440401, sizeof(BearCharacter_eventInteractTrue_Parms), Z_Construct_UFunction_ABearCharacter_InteractTrue_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ABearCharacter_InteractTrue_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABearCharacter_InteractTrue_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ABearCharacter_InteractTrue_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABearCharacter_InteractTrue()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABearCharacter_InteractTrue_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABearCharacter_MoveForward_Statics
	{
		struct BearCharacter_eventMoveForward_Parms
		{
			float AxisValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_AxisValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ABearCharacter_MoveForward_Statics::NewProp_AxisValue = { UE4CodeGen_Private::EPropertyClass::Float, "AxisValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(BearCharacter_eventMoveForward_Parms, AxisValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABearCharacter_MoveForward_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABearCharacter_MoveForward_Statics::NewProp_AxisValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABearCharacter_MoveForward_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "BearCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABearCharacter_MoveForward_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABearCharacter, "MoveForward", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00020401, sizeof(BearCharacter_eventMoveForward_Parms), Z_Construct_UFunction_ABearCharacter_MoveForward_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ABearCharacter_MoveForward_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABearCharacter_MoveForward_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ABearCharacter_MoveForward_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABearCharacter_MoveForward()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABearCharacter_MoveForward_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABearCharacter_MoveRight_Statics
	{
		struct BearCharacter_eventMoveRight_Parms
		{
			float AxisValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_AxisValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ABearCharacter_MoveRight_Statics::NewProp_AxisValue = { UE4CodeGen_Private::EPropertyClass::Float, "AxisValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(BearCharacter_eventMoveRight_Parms, AxisValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABearCharacter_MoveRight_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABearCharacter_MoveRight_Statics::NewProp_AxisValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABearCharacter_MoveRight_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "BearCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABearCharacter_MoveRight_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABearCharacter, "MoveRight", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00020401, sizeof(BearCharacter_eventMoveRight_Parms), Z_Construct_UFunction_ABearCharacter_MoveRight_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ABearCharacter_MoveRight_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABearCharacter_MoveRight_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ABearCharacter_MoveRight_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABearCharacter_MoveRight()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABearCharacter_MoveRight_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ABearCharacter_NoRegister()
	{
		return ABearCharacter::StaticClass();
	}
	struct Z_Construct_UClass_ABearCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SphereRadius_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_SphereRadius;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RadiusCollider_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_RadiusCollider;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CanBearRide_MetaData[];
#endif
		static void NewProp_CanBearRide_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_CanBearRide;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CameraPitch_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_CameraPitch;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CameraPositionX_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_CameraPositionX;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CameraHeight_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_CameraHeight;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABearCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_Prototype_SO,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ABearCharacter_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ABearCharacter_InteractFalse, "InteractFalse" }, // 162693897
		{ &Z_Construct_UFunction_ABearCharacter_InteractTrue, "InteractTrue" }, // 2451881297
		{ &Z_Construct_UFunction_ABearCharacter_MoveForward, "MoveForward" }, // 3885049920
		{ &Z_Construct_UFunction_ABearCharacter_MoveRight, "MoveRight" }, // 3591849511
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABearCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "BearCharacter.h" },
		{ "ModuleRelativePath", "BearCharacter.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABearCharacter_Statics::NewProp_SphereRadius_MetaData[] = {
		{ "Category", "BearCharacter" },
		{ "ModuleRelativePath", "BearCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABearCharacter_Statics::NewProp_SphereRadius = { UE4CodeGen_Private::EPropertyClass::Float, "SphereRadius", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(ABearCharacter, SphereRadius), METADATA_PARAMS(Z_Construct_UClass_ABearCharacter_Statics::NewProp_SphereRadius_MetaData, ARRAY_COUNT(Z_Construct_UClass_ABearCharacter_Statics::NewProp_SphereRadius_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABearCharacter_Statics::NewProp_RadiusCollider_MetaData[] = {
		{ "Category", "BearCharacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "BearCharacter.h" },
		{ "ToolTip", "Set to true deafault to debug" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABearCharacter_Statics::NewProp_RadiusCollider = { UE4CodeGen_Private::EPropertyClass::Object, "RadiusCollider", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000080009, 1, nullptr, STRUCT_OFFSET(ABearCharacter, RadiusCollider), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABearCharacter_Statics::NewProp_RadiusCollider_MetaData, ARRAY_COUNT(Z_Construct_UClass_ABearCharacter_Statics::NewProp_RadiusCollider_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABearCharacter_Statics::NewProp_CanBearRide_MetaData[] = {
		{ "Category", "BearCharacter" },
		{ "ModuleRelativePath", "BearCharacter.h" },
	};
#endif
	void Z_Construct_UClass_ABearCharacter_Statics::NewProp_CanBearRide_SetBit(void* Obj)
	{
		((ABearCharacter*)Obj)->CanBearRide = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ABearCharacter_Statics::NewProp_CanBearRide = { UE4CodeGen_Private::EPropertyClass::Bool, "CanBearRide", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(ABearCharacter), &Z_Construct_UClass_ABearCharacter_Statics::NewProp_CanBearRide_SetBit, METADATA_PARAMS(Z_Construct_UClass_ABearCharacter_Statics::NewProp_CanBearRide_MetaData, ARRAY_COUNT(Z_Construct_UClass_ABearCharacter_Statics::NewProp_CanBearRide_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABearCharacter_Statics::NewProp_CameraPitch_MetaData[] = {
		{ "Category", "Camera" },
		{ "ModuleRelativePath", "BearCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABearCharacter_Statics::NewProp_CameraPitch = { UE4CodeGen_Private::EPropertyClass::Float, "CameraPitch", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(ABearCharacter, CameraPitch), METADATA_PARAMS(Z_Construct_UClass_ABearCharacter_Statics::NewProp_CameraPitch_MetaData, ARRAY_COUNT(Z_Construct_UClass_ABearCharacter_Statics::NewProp_CameraPitch_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABearCharacter_Statics::NewProp_CameraPositionX_MetaData[] = {
		{ "Category", "Camera" },
		{ "ModuleRelativePath", "BearCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABearCharacter_Statics::NewProp_CameraPositionX = { UE4CodeGen_Private::EPropertyClass::Float, "CameraPositionX", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(ABearCharacter, CameraPositionX), METADATA_PARAMS(Z_Construct_UClass_ABearCharacter_Statics::NewProp_CameraPositionX_MetaData, ARRAY_COUNT(Z_Construct_UClass_ABearCharacter_Statics::NewProp_CameraPositionX_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABearCharacter_Statics::NewProp_CameraHeight_MetaData[] = {
		{ "Category", "Camera" },
		{ "ModuleRelativePath", "BearCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABearCharacter_Statics::NewProp_CameraHeight = { UE4CodeGen_Private::EPropertyClass::Float, "CameraHeight", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(ABearCharacter, CameraHeight), METADATA_PARAMS(Z_Construct_UClass_ABearCharacter_Statics::NewProp_CameraHeight_MetaData, ARRAY_COUNT(Z_Construct_UClass_ABearCharacter_Statics::NewProp_CameraHeight_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABearCharacter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABearCharacter_Statics::NewProp_SphereRadius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABearCharacter_Statics::NewProp_RadiusCollider,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABearCharacter_Statics::NewProp_CanBearRide,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABearCharacter_Statics::NewProp_CameraPitch,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABearCharacter_Statics::NewProp_CameraPositionX,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABearCharacter_Statics::NewProp_CameraHeight,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABearCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABearCharacter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ABearCharacter_Statics::ClassParams = {
		&ABearCharacter::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_ABearCharacter_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_ABearCharacter_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_ABearCharacter_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ABearCharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ABearCharacter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ABearCharacter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABearCharacter, 2765149013);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABearCharacter(Z_Construct_UClass_ABearCharacter, &ABearCharacter::StaticClass, TEXT("/Script/Prototype_SO"), TEXT("ABearCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABearCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
