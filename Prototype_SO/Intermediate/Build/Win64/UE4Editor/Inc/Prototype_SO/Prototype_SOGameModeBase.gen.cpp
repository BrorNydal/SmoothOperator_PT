// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Prototype_SO/Prototype_SOGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePrototype_SOGameModeBase() {}
// Cross Module References
	PROTOTYPE_SO_API UClass* Z_Construct_UClass_APrototype_SOGameModeBase_NoRegister();
	PROTOTYPE_SO_API UClass* Z_Construct_UClass_APrototype_SOGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_Prototype_SO();
// End Cross Module References
	void APrototype_SOGameModeBase::StaticRegisterNativesAPrototype_SOGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_APrototype_SOGameModeBase_NoRegister()
	{
		return APrototype_SOGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_APrototype_SOGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APrototype_SOGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_Prototype_SO,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APrototype_SOGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "Prototype_SOGameModeBase.h" },
		{ "ModuleRelativePath", "Prototype_SOGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_APrototype_SOGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APrototype_SOGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APrototype_SOGameModeBase_Statics::ClassParams = {
		&APrototype_SOGameModeBase::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009002A8u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_APrototype_SOGameModeBase_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_APrototype_SOGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APrototype_SOGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APrototype_SOGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APrototype_SOGameModeBase, 2690402773);
	static FCompiledInDefer Z_CompiledInDefer_UClass_APrototype_SOGameModeBase(Z_Construct_UClass_APrototype_SOGameModeBase, &APrototype_SOGameModeBase::StaticClass, TEXT("/Script/Prototype_SO"), TEXT("APrototype_SOGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APrototype_SOGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
