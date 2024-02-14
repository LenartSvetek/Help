// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VoxelTest/Public/WorldGenNew.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWorldGenNew() {}
// Cross Module References
	REALTIMEMESHCOMPONENT_API UClass* Z_Construct_UClass_ARealtimeMeshActor();
	UPackage* Z_Construct_UPackage__Script_VoxelTest();
	VOXELTEST_API UClass* Z_Construct_UClass_AWorldGenNew();
	VOXELTEST_API UClass* Z_Construct_UClass_AWorldGenNew_NoRegister();
// End Cross Module References
	void AWorldGenNew::StaticRegisterNativesAWorldGenNew()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AWorldGenNew);
	UClass* Z_Construct_UClass_AWorldGenNew_NoRegister()
	{
		return AWorldGenNew::StaticClass();
	}
	struct Z_Construct_UClass_AWorldGenNew_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AWorldGenNew_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ARealtimeMeshActor,
		(UObject* (*)())Z_Construct_UPackage__Script_VoxelTest,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AWorldGenNew_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWorldGenNew_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "WorldGenNew.h" },
		{ "ModuleRelativePath", "Public/WorldGenNew.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AWorldGenNew_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AWorldGenNew>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AWorldGenNew_Statics::ClassParams = {
		&AWorldGenNew::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AWorldGenNew_Statics::Class_MetaDataParams), Z_Construct_UClass_AWorldGenNew_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AWorldGenNew()
	{
		if (!Z_Registration_Info_UClass_AWorldGenNew.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AWorldGenNew.OuterSingleton, Z_Construct_UClass_AWorldGenNew_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AWorldGenNew.OuterSingleton;
	}
	template<> VOXELTEST_API UClass* StaticClass<AWorldGenNew>()
	{
		return AWorldGenNew::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AWorldGenNew);
	AWorldGenNew::~AWorldGenNew() {}
	struct Z_CompiledInDeferFile_FID_Projects_UProjects_VoxelTest_Source_VoxelTest_Public_WorldGenNew_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_UProjects_VoxelTest_Source_VoxelTest_Public_WorldGenNew_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AWorldGenNew, AWorldGenNew::StaticClass, TEXT("AWorldGenNew"), &Z_Registration_Info_UClass_AWorldGenNew, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AWorldGenNew), 4023773887U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_UProjects_VoxelTest_Source_VoxelTest_Public_WorldGenNew_h_787287036(TEXT("/Script/VoxelTest"),
		Z_CompiledInDeferFile_FID_Projects_UProjects_VoxelTest_Source_VoxelTest_Public_WorldGenNew_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_UProjects_VoxelTest_Source_VoxelTest_Public_WorldGenNew_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
