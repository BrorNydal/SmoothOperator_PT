// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Prototype_SO/RiderCharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRiderCharacter() {}
// Cross Module References
	PROTOTYPE_SO_API UClass* Z_Construct_UClass_ARiderCharacter_NoRegister();
	PROTOTYPE_SO_API UClass* Z_Construct_UClass_ARiderCharacter();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_Prototype_SO();
	PROTOTYPE_SO_API UFunction* Z_Construct_UFunction_ARiderCharacter_MoveForward();
	PROTOTYPE_SO_API UFunction* Z_Construct_UFunction_ARiderCharacter_MoveRight();
// End Cross Module References
	void ARiderCharacter::StaticRegisterNativesARiderCharacter()
	{
		UClass* Class = ARiderCharacter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "MoveForward", &ARiderCharacter::execMoveForward },
			{ "MoveRight", &ARiderCharacter::execMoveRight },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ARiderCharacter_MoveForward_Statics
	{
		struct RiderCharacter_eventMoveForward_Parms
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
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ARiderCharacter_MoveForward_Statics::NewProp_AxisValue = { UE4CodeGen_Private::EPropertyClass::Float, "AxisValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RiderCharacter_eventMoveForward_Parms, AxisValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ARiderCharacter_MoveForward_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ARiderCharacter_MoveForward_Statics::NewProp_AxisValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ARiderCharacter_MoveForward_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "RiderCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ARiderCharacter_MoveForward_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ARiderCharacter, "MoveForward", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00020401, sizeof(RiderCharacter_eventMoveForward_Parms), Z_Construct_UFunction_ARiderCharacter_MoveForward_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ARiderCharacter_MoveForward_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ARiderCharacter_MoveForward_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ARiderCharacter_MoveForward_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ARiderCharacter_MoveForward()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ARiderCharacter_MoveForward_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ARiderCharacter_MoveRight_Statics
	{
		struct RiderCharacter_eventMoveRight_Parms
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
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ARiderCharacter_MoveRight_Statics::NewProp_AxisValue = { UE4CodeGen_Private::EPropertyClass::Float, "AxisValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RiderCharacter_eventMoveRight_Parms, AxisValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ARiderCharacter_MoveRight_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ARiderCharacter_MoveRight_Statics::NewProp_AxisValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ARiderCharacter_MoveRight_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "RiderCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ARiderCharacter_MoveRight_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ARiderCharacter, "MoveRight", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00020401, sizeof(RiderCharacter_eventMoveRight_Parms), Z_Construct_UFunction_ARiderCharacter_MoveRight_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ARiderCharacter_MoveRight_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ARiderCharacter_MoveRight_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ARiderCharacter_MoveRight_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ARiderCharacter_MoveRight()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ARiderCharacter_MoveRight_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ARiderCharacter_NoRegister()
	{
		return ARiderCharacter::StaticClass();
	}
	struct Z_Construct_UClass_ARiderCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
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
	UObject* (*const Z_Construct_UClass_ARiderCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_Prototype_SO,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ARiderCharacter_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ARiderCharacter_MoveForward, "MoveForward" }, // 1224763256
		{ &Z_Construct_UFunction_ARiderCharacter_MoveRight, "MoveRight" }, // 196946428
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARiderCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "RiderCharacter.h" },
		{ "ModuleRelativePath", "RiderCharacter.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARiderCharacter_Statics::NewProp_CameraPitch_MetaData[] = {
		{ "Category", "Camera" },
		{ "ModuleRelativePath", "RiderCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ARiderCharacter_Statics::NewProp_CameraPitch = { UE4CodeGen_Private::EPropertyClass::Float, "CameraPitch", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(ARiderCharacter, CameraPitch), METADATA_PARAMS(Z_Construct_UClass_ARiderCharacter_Statics::NewProp_CameraPitch_MetaData, ARRAY_COUNT(Z_Construct_UClass_ARiderCharacter_Statics::NewProp_CameraPitch_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARiderCharacter_Statics::NewProp_CameraPositionX_MetaData[] = {
		{ "Category", "Camera" },
		{ "ModuleRelativePath", "RiderCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ARiderCharacter_Statics::NewProp_CameraPositionX = { UE4CodeGen_Private::EPropertyClass::Float, "CameraPositionX", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(ARiderCharacter, CameraPositionX), METADATA_PARAMS(Z_Construct_UClass_ARiderCharacter_Statics::NewProp_CameraPositionX_MetaData, ARRAY_COUNT(Z_Construct_UClass_ARiderCharacter_Statics::NewProp_CameraPositionX_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARiderCharacter_Statics::NewProp_CameraHeight_MetaData[] = {
		{ "Category", "Camera" },
		{ "ModuleRelativePath", "RiderCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ARiderCharacter_Statics::NewProp_CameraHeight = { UE4CodeGen_Private::EPropertyClass::Float, "CameraHeight", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(ARiderCharacter, CameraHeight), METADATA_PARAMS(Z_Construct_UClass_ARiderCharacter_Statics::NewProp_CameraHeight_MetaData, ARRAY_COUNT(Z_Construct_UClass_ARiderCharacter_Statics::NewProp_CameraHeight_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ARiderCharacter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARiderCharacter_Statics::NewProp_CameraPitch,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARiderCharacter_Statics::NewProp_CameraPositionX,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARiderCharacter_Statics::NewProp_CameraHeight,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ARiderCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARiderCharacter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ARiderCharacter_Statics::ClassParams = {
		&ARiderCharacter::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_ARiderCharacter_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_ARiderCharacter_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_ARiderCharacter_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ARiderCharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ARiderCharacter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ARiderCharacter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ARiderCharacter, 3592442178);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ARiderCharacter(Z_Construct_UClass_ARiderCharacter, &ARiderCharacter::StaticClass, TEXT("/Script/Prototype_SO"), TEXT("ARiderCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARiderCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
