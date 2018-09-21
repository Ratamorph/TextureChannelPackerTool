// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TextureChannelPackerTool/Public/TextureChannelPackerSettings.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTextureChannelPackerSettings() {}
// Cross Module References
	TEXTURECHANNELPACKERTOOL_API UEnum* Z_Construct_UEnum_TextureChannelPackerTool_TextureChannel();
	UPackage* Z_Construct_UPackage__Script_TextureChannelPackerTool();
	TEXTURECHANNELPACKERTOOL_API UScriptStruct* Z_Construct_UScriptStruct_FTextureChannelPackerSettings();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	TEXTURECHANNELPACKERTOOL_API UClass* Z_Construct_UClass_UTextureChannelPackerSettingsObject_NoRegister();
	TEXTURECHANNELPACKERTOOL_API UClass* Z_Construct_UClass_UTextureChannelPackerSettingsObject();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
// End Cross Module References
	static UEnum* TextureChannel_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_TextureChannelPackerTool_TextureChannel, Z_Construct_UPackage__Script_TextureChannelPackerTool(), TEXT("TextureChannel"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_TextureChannel(TextureChannel_StaticEnum, TEXT("/Script/TextureChannelPackerTool"), TEXT("TextureChannel"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_TextureChannelPackerTool_TextureChannel_CRC() { return 1024636438U; }
	UEnum* Z_Construct_UEnum_TextureChannelPackerTool_TextureChannel()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_TextureChannelPackerTool();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("TextureChannel"), 0, Get_Z_Construct_UEnum_TextureChannelPackerTool_TextureChannel_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "Red", (int64)Red },
				{ "Green", (int64)Green },
				{ "Blue", (int64)Blue },
				{ "Alpha", (int64)Alpha },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "Alpha.DisplayName", "Alpha" },
				{ "Blue.DisplayName", "Blue" },
				{ "Green.DisplayName", "Green" },
				{ "ModuleRelativePath", "Public/TextureChannelPackerSettings.h" },
				{ "Red.DisplayName", "Red" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_TextureChannelPackerTool,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"TextureChannel",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::Regular,
				"TextureChannel",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
class UScriptStruct* FTextureChannelPackerSettings::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern TEXTURECHANNELPACKERTOOL_API uint32 Get_Z_Construct_UScriptStruct_FTextureChannelPackerSettings_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FTextureChannelPackerSettings, Z_Construct_UPackage__Script_TextureChannelPackerTool(), TEXT("TextureChannelPackerSettings"), sizeof(FTextureChannelPackerSettings), Get_Z_Construct_UScriptStruct_FTextureChannelPackerSettings_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FTextureChannelPackerSettings(FTextureChannelPackerSettings::StaticStruct, TEXT("/Script/TextureChannelPackerTool"), TEXT("TextureChannelPackerSettings"), false, nullptr, nullptr);
static struct FScriptStruct_TextureChannelPackerTool_StaticRegisterNativesFTextureChannelPackerSettings
{
	FScriptStruct_TextureChannelPackerTool_StaticRegisterNativesFTextureChannelPackerSettings()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("TextureChannelPackerSettings")),new UScriptStruct::TCppStructOps<FTextureChannelPackerSettings>);
	}
} ScriptStruct_TextureChannelPackerTool_StaticRegisterNativesFTextureChannelPackerSettings;
	struct Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_aSourceChannel_MetaData[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_aSourceChannel;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_aChannelTargetSlot_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_aChannelTargetSlot;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bSourceChannel_MetaData[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_bSourceChannel;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bChannelTargetSlot_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_bChannelTargetSlot;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_gSourceChannel_MetaData[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_gSourceChannel;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_gChannelTargetSlot_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_gChannelTargetSlot;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_rSourceChannel_MetaData[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_rSourceChannel;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_rChannelTargetSlot_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_rChannelTargetSlot;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_targetTextureHeight_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_targetTextureHeight;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_targetTextureWidth_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_targetTextureWidth;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/TextureChannelPackerSettings.h" },
		{ "ToolTip", "//UCLASS()\n//class TEXTURECHANNELPACKERTOOL_API UTextureChannelPackerSettings : public UObject" },
	};
#endif
	void* Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FTextureChannelPackerSettings>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_aSourceChannel_MetaData[] = {
		{ "Category", "TextureChannelPacker" },
		{ "ModuleRelativePath", "Public/TextureChannelPackerSettings.h" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_aSourceChannel = { UE4CodeGen_Private::EPropertyClass::Byte, "aSourceChannel", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FTextureChannelPackerSettings, aSourceChannel), Z_Construct_UEnum_TextureChannelPackerTool_TextureChannel, METADATA_PARAMS(Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_aSourceChannel_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_aSourceChannel_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_aChannelTargetSlot_MetaData[] = {
		{ "Category", "TextureChannelPacker" },
		{ "ModuleRelativePath", "Public/TextureChannelPackerSettings.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_aChannelTargetSlot = { UE4CodeGen_Private::EPropertyClass::Object, "aChannelTargetSlot", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FTextureChannelPackerSettings, aChannelTargetSlot), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_aChannelTargetSlot_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_aChannelTargetSlot_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_bSourceChannel_MetaData[] = {
		{ "Category", "TextureChannelPacker" },
		{ "ModuleRelativePath", "Public/TextureChannelPackerSettings.h" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_bSourceChannel = { UE4CodeGen_Private::EPropertyClass::Byte, "bSourceChannel", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FTextureChannelPackerSettings, bSourceChannel), Z_Construct_UEnum_TextureChannelPackerTool_TextureChannel, METADATA_PARAMS(Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_bSourceChannel_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_bSourceChannel_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_bChannelTargetSlot_MetaData[] = {
		{ "Category", "TextureChannelPacker" },
		{ "ModuleRelativePath", "Public/TextureChannelPackerSettings.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_bChannelTargetSlot = { UE4CodeGen_Private::EPropertyClass::Object, "bChannelTargetSlot", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FTextureChannelPackerSettings, bChannelTargetSlot), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_bChannelTargetSlot_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_bChannelTargetSlot_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_gSourceChannel_MetaData[] = {
		{ "Category", "TextureChannelPacker" },
		{ "ModuleRelativePath", "Public/TextureChannelPackerSettings.h" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_gSourceChannel = { UE4CodeGen_Private::EPropertyClass::Byte, "gSourceChannel", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FTextureChannelPackerSettings, gSourceChannel), Z_Construct_UEnum_TextureChannelPackerTool_TextureChannel, METADATA_PARAMS(Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_gSourceChannel_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_gSourceChannel_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_gChannelTargetSlot_MetaData[] = {
		{ "Category", "TextureChannelPacker" },
		{ "ModuleRelativePath", "Public/TextureChannelPackerSettings.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_gChannelTargetSlot = { UE4CodeGen_Private::EPropertyClass::Object, "gChannelTargetSlot", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FTextureChannelPackerSettings, gChannelTargetSlot), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_gChannelTargetSlot_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_gChannelTargetSlot_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_rSourceChannel_MetaData[] = {
		{ "Category", "TextureChannelPacker" },
		{ "ModuleRelativePath", "Public/TextureChannelPackerSettings.h" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_rSourceChannel = { UE4CodeGen_Private::EPropertyClass::Byte, "rSourceChannel", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FTextureChannelPackerSettings, rSourceChannel), Z_Construct_UEnum_TextureChannelPackerTool_TextureChannel, METADATA_PARAMS(Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_rSourceChannel_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_rSourceChannel_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_rChannelTargetSlot_MetaData[] = {
		{ "Category", "TextureChannelPacker" },
		{ "ModuleRelativePath", "Public/TextureChannelPackerSettings.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_rChannelTargetSlot = { UE4CodeGen_Private::EPropertyClass::Object, "rChannelTargetSlot", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FTextureChannelPackerSettings, rChannelTargetSlot), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_rChannelTargetSlot_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_rChannelTargetSlot_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_targetTextureHeight_MetaData[] = {
		{ "Category", "TextureChannelPacker" },
		{ "ModuleRelativePath", "Public/TextureChannelPackerSettings.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_targetTextureHeight = { UE4CodeGen_Private::EPropertyClass::Int, "targetTextureHeight", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FTextureChannelPackerSettings, targetTextureHeight), METADATA_PARAMS(Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_targetTextureHeight_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_targetTextureHeight_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_targetTextureWidth_MetaData[] = {
		{ "Category", "TextureChannelPacker" },
		{ "ModuleRelativePath", "Public/TextureChannelPackerSettings.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_targetTextureWidth = { UE4CodeGen_Private::EPropertyClass::Int, "targetTextureWidth", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FTextureChannelPackerSettings, targetTextureWidth), METADATA_PARAMS(Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_targetTextureWidth_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_targetTextureWidth_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_aSourceChannel,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_aChannelTargetSlot,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_bSourceChannel,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_bChannelTargetSlot,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_gSourceChannel,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_gChannelTargetSlot,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_rSourceChannel,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_rChannelTargetSlot,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_targetTextureHeight,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::NewProp_targetTextureWidth,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_TextureChannelPackerTool,
		nullptr,
		&NewStructOps,
		"TextureChannelPackerSettings",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		sizeof(FTextureChannelPackerSettings),
		alignof(FTextureChannelPackerSettings),
		Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::PropPointers),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FTextureChannelPackerSettings()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FTextureChannelPackerSettings_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_TextureChannelPackerTool();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("TextureChannelPackerSettings"), sizeof(FTextureChannelPackerSettings), Get_Z_Construct_UScriptStruct_FTextureChannelPackerSettings_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FTextureChannelPackerSettings_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FTextureChannelPackerSettings_CRC() { return 1495967602U; }
	void UTextureChannelPackerSettingsObject::StaticRegisterNativesUTextureChannelPackerSettingsObject()
	{
	}
	UClass* Z_Construct_UClass_UTextureChannelPackerSettingsObject_NoRegister()
	{
		return UTextureChannelPackerSettingsObject::StaticClass();
	}
	struct Z_Construct_UClass_UTextureChannelPackerSettingsObject_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Settings_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Settings;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UTextureChannelPackerSettingsObject_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_TextureChannelPackerTool,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTextureChannelPackerSettingsObject_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "TextureChannelPackerSettings.h" },
		{ "ModuleRelativePath", "Public/TextureChannelPackerSettings.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTextureChannelPackerSettingsObject_Statics::NewProp_Settings_MetaData[] = {
		{ "Category", "TextureChannelPackerSettings" },
		{ "ModuleRelativePath", "Public/TextureChannelPackerSettings.h" },
		{ "ShowOnlyInnerProperties", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UTextureChannelPackerSettingsObject_Statics::NewProp_Settings = { UE4CodeGen_Private::EPropertyClass::Struct, "Settings", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UTextureChannelPackerSettingsObject, Settings), Z_Construct_UScriptStruct_FTextureChannelPackerSettings, METADATA_PARAMS(Z_Construct_UClass_UTextureChannelPackerSettingsObject_Statics::NewProp_Settings_MetaData, ARRAY_COUNT(Z_Construct_UClass_UTextureChannelPackerSettingsObject_Statics::NewProp_Settings_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UTextureChannelPackerSettingsObject_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTextureChannelPackerSettingsObject_Statics::NewProp_Settings,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UTextureChannelPackerSettingsObject_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UTextureChannelPackerSettingsObject>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UTextureChannelPackerSettingsObject_Statics::ClassParams = {
		&UTextureChannelPackerSettingsObject::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x000000A0u,
		nullptr, 0,
		Z_Construct_UClass_UTextureChannelPackerSettingsObject_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UTextureChannelPackerSettingsObject_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UTextureChannelPackerSettingsObject_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UTextureChannelPackerSettingsObject_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UTextureChannelPackerSettingsObject()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UTextureChannelPackerSettingsObject_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UTextureChannelPackerSettingsObject, 3821894837);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UTextureChannelPackerSettingsObject(Z_Construct_UClass_UTextureChannelPackerSettingsObject, &UTextureChannelPackerSettingsObject::StaticClass, TEXT("/Script/TextureChannelPackerTool"), TEXT("UTextureChannelPackerSettingsObject"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UTextureChannelPackerSettingsObject);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
