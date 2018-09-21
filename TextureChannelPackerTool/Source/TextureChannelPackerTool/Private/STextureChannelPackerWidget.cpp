// Fill out your copyright notice in the Description page of Project Settings.

#include "STextureChannelPackerWidget.h"
#include "SlateOptMacros.h"
#include "LevelEditor.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Input/SButton.h"
#include "PropertyEditorModule.h"
#include "Modules/ModuleManager.h"
#include "ContentBrowserModule.h"
#include "IContentBrowserSingleton.h"
#include "IDetailsView.h"
#include "AssetRegistryModule.h"
#include "IAssetTools.h"
#include "AssetToolsModule.h"
#include "Factories/TextureFactory.h"
#include "Materials/MaterialInterface.h"

//#include "UObjectGlobals.h"

#define LOCTEXT_NAMESPACE "STextureChannelPackerWidget"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void STextureChannelPackerWidget::Construct(const FArguments& InArgs)
{
    CreateSettingsView();

    TextureChannelPackerSettings = UTextureChannelPackerSettingsObject::Get();
    SettingsView->SetObject(TextureChannelPackerSettings);

    FText WidgetHelpText = LOCTEXT("WidgetReadyText", "Ready to package");

    if(!ValidTargetTextureSize())
    {
        WidgetHelpText = LOCTEXT("WidgetBatTargetSizeText", "Target texture size must be > 0");
    }
    else if(!TexturesArePropperSizeForTarget())
    {
        WidgetHelpText = LOCTEXT("WidgetNullTextureInSlotErrorText", "You must assign a texture to each slot");
    }
    else if(!TexturesArePropperSizeForTarget()) {
        WidgetHelpText = LOCTEXT("WidgetTextureSizeErrorText", "Source textures must be equal size than target texture");
    }

	ChildSlot
	[
        SNew(SVerticalBox)

        + SVerticalBox::Slot()
        .AutoHeight()
        .HAlign(HAlign_Left)
        .Padding(0, 0, 0, 0)
        [
            SettingsView->AsShared()
        ]

        +SVerticalBox::Slot()
        .AutoHeight()
        .HAlign(HAlign_Left)
        .Padding(0, 0, 0, 0)
        [
            SNew(STextBlock)
            .Text(WidgetHelpText)
        ]

        +SVerticalBox::Slot()
        .AutoHeight()
        .VAlign(VAlign_Bottom)
        .HAlign(HAlign_Right)
        .Padding(0, 0, 0, 0)
        [
            SNew(SButton)
            .Text(LOCTEXT("PackChannels", "Pack Texture Channels"))
            .OnClicked(this, &STextureChannelPackerWidget::OnPackTextureChannelsClicked)
            .IsEnabled_Lambda([this]() -> bool { return this->CanPackTextureChannels();})
        ]
	];


}

FReply STextureChannelPackerWidget::OnPackTextureChannelsClicked()
{

    const FString defaultAssetName = FPackageName::FilenameToLongPackageName(FPaths::ProjectContentDir() + TEXT("NewPackedTexture"));

    if(defaultAssetName.Len() > 0)
    {
        const FString defaultPath = FPackageName::GetLongPackagePath(defaultAssetName);
        const FString defaultName = FPackageName::GetShortName(defaultAssetName);

        //initialize save file dialog
        FSaveAssetDialogConfig saveAssetDialogConfig;
        saveAssetDialogConfig.DialogTitleOverride = LOCTEXT("CreatePackedChannelTexture", "Create Packed Channel Texture");
        saveAssetDialogConfig.DefaultPath = defaultPath;
        saveAssetDialogConfig.DefaultAssetName = defaultName;
        saveAssetDialogConfig.ExistingAssetPolicy = ESaveAssetDialogExistingAssetPolicy::AllowButWarn;

        FContentBrowserModule& contentBrowserModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");
        FString saveObjectPath = contentBrowserModule.Get().CreateModalSaveAssetDialog(saveAssetDialogConfig);

        if(!saveObjectPath.IsEmpty())
        {
            const FString packageName = FPackageName::ObjectPathToPackageName(saveObjectPath);
            const FString longPackagePath = FPackageName::GetLongPackagePath(saveObjectPath);
            const FString filenameToLongPackageName= FPackageName::FilenameToLongPackageName(saveObjectPath);

            UE_LOG(LogTemp, Log, TEXT( "saveObjectPath: %s" ), *saveObjectPath);
            UE_LOG(LogTemp, Log, TEXT( "longPackagePath: %s" ), *longPackagePath);

            UE_LOG(LogTemp, Log, TEXT( "filenameToLongPackageName: %s" ), *filenameToLongPackageName);
            UE_LOG(LogTemp, Log, TEXT( "Package name: %s" ), *packageName);

            CreatePackedTexture(packageName);
            //create the texture at saveObjectPath here
        }
        else
        {
            //create the texture at defaultAssetName here
        }


    }

    return FReply::Handled();
}

bool STextureChannelPackerWidget::CanPackTextureChannels()
{
    if(TextureChannelPackerSettings != nullptr)
    {
        if(ValidTargetTextureSize()
        && TextureSlotsAsigned()
        && TexturesArePropperSizeForTarget())
            return true;
    }
    return false;
}

bool STextureChannelPackerWidget::ValidTargetTextureSize()
{
    if(TextureChannelPackerSettings != nullptr) {
        if (TextureChannelPackerSettings->Settings.targetTextureWidth > 0
            && TextureChannelPackerSettings->Settings.targetTextureHeight > 0)
            return true;
    }
    return false;
}

bool STextureChannelPackerWidget::TextureSlotsAsigned()
{
    if(TextureChannelPackerSettings != nullptr)
    {
        if(TextureChannelPackerSettings->Settings.rChannelTargetSlot != nullptr
           && TextureChannelPackerSettings->Settings.gChannelTargetSlot != nullptr
           && TextureChannelPackerSettings->Settings.bChannelTargetSlot != nullptr
           && TextureChannelPackerSettings->Settings.aChannelTargetSlot != nullptr)
                return true;
    }
    return false;
}

bool STextureChannelPackerWidget::TexturesArePropperSizeForTarget()
{
    if(TextureChannelPackerSettings != nullptr && TextureSlotsAsigned()) {
        if (TextureChannelPackerSettings->Settings.rChannelTargetSlot->PlatformData->SizeX ==
            TextureChannelPackerSettings->Settings.targetTextureWidth
            && TextureChannelPackerSettings->Settings.rChannelTargetSlot->PlatformData->SizeY ==
               TextureChannelPackerSettings->Settings.targetTextureHeight
            && TextureChannelPackerSettings->Settings.gChannelTargetSlot->PlatformData->SizeX ==
               TextureChannelPackerSettings->Settings.targetTextureWidth
            && TextureChannelPackerSettings->Settings.gChannelTargetSlot->PlatformData->SizeY ==
               TextureChannelPackerSettings->Settings.targetTextureHeight
            && TextureChannelPackerSettings->Settings.bChannelTargetSlot->PlatformData->SizeX ==
               TextureChannelPackerSettings->Settings.targetTextureWidth
            && TextureChannelPackerSettings->Settings.bChannelTargetSlot->PlatformData->SizeY ==
               TextureChannelPackerSettings->Settings.targetTextureHeight
            && TextureChannelPackerSettings->Settings.aChannelTargetSlot->PlatformData->SizeX ==
               TextureChannelPackerSettings->Settings.targetTextureWidth
            && TextureChannelPackerSettings->Settings.aChannelTargetSlot->PlatformData->SizeY ==
               TextureChannelPackerSettings->Settings.targetTextureHeight)
            return true;
    }
    return false;
}

void STextureChannelPackerWidget::CreatePackedTexture(const FString& filePath)
{
    if(CanPackTextureChannels())
    {
        FString FileName = FPackageName::GetShortName(*filePath);

        UE_LOG(LogTemp, Log, TEXT( "FileName: %s" ), *FileName);

        int width = TextureChannelPackerSettings->Settings.targetTextureWidth;
        int height = TextureChannelPackerSettings->Settings.targetTextureHeight;

        UTexture2D * rSourceTexture = TextureChannelPackerSettings->Settings.rChannelTargetSlot;
        UTexture2D * gSourceTexture = TextureChannelPackerSettings->Settings.gChannelTargetSlot;
        UTexture2D * bSourceTexture = TextureChannelPackerSettings->Settings.bChannelTargetSlot;
        UTexture2D * aSourceTexture = TextureChannelPackerSettings->Settings.aChannelTargetSlot;

        //set temporal texture settings for accesing textures
        TextureCompressionSettings OldCompressionSettings_R = rSourceTexture->CompressionSettings;
        TextureCompressionSettings OldCompressionSettings_G = gSourceTexture->CompressionSettings;
        TextureCompressionSettings OldCompressionSettings_B = bSourceTexture->CompressionSettings;
        TextureCompressionSettings OldCompressionSettings_A = aSourceTexture->CompressionSettings;

        TextureMipGenSettings OldMipGenSettings_R = rSourceTexture->MipGenSettings;
        TextureMipGenSettings OldMipGenSettings_G = gSourceTexture->MipGenSettings;
        TextureMipGenSettings OldMipGenSettings_B = bSourceTexture->MipGenSettings;
        TextureMipGenSettings OldMipGenSettings_A = aSourceTexture->MipGenSettings;

        bool OldSRGB_R = rSourceTexture->SRGB;
        bool OldSRGB_G = gSourceTexture->SRGB;
        bool OldSRGB_B = bSourceTexture->SRGB;
        bool OldSRGB_A = aSourceTexture->SRGB;

        rSourceTexture->CompressionSettings = TextureCompressionSettings::TC_VectorDisplacementmap;
        gSourceTexture->CompressionSettings = TextureCompressionSettings::TC_VectorDisplacementmap;
        bSourceTexture->CompressionSettings = TextureCompressionSettings::TC_VectorDisplacementmap;
        aSourceTexture->CompressionSettings = TextureCompressionSettings::TC_VectorDisplacementmap;

        rSourceTexture->MipGenSettings = TextureMipGenSettings::TMGS_NoMipmaps;
        gSourceTexture->MipGenSettings = TextureMipGenSettings::TMGS_NoMipmaps;
        bSourceTexture->MipGenSettings = TextureMipGenSettings::TMGS_NoMipmaps;
        aSourceTexture->MipGenSettings = TextureMipGenSettings::TMGS_NoMipmaps;

        rSourceTexture->SRGB = false;
        gSourceTexture->SRGB = false;
        bSourceTexture->SRGB = false;
        aSourceTexture->SRGB = false;

        rSourceTexture->UpdateResource();
        gSourceTexture->UpdateResource();
        bSourceTexture->UpdateResource();
        aSourceTexture->UpdateResource();

        //create new texture data buffer
        uint8 *pixels = (uint8 *) malloc(height * width * 4); // x4 because it's RGBA. 4 integers, one for Red, one for Green, one for Blue, one for Alpha

        //set red channel
        const FColor* rSourceImageData = static_cast<const FColor*>( rSourceTexture->PlatformData->Mips[0].BulkData.LockReadOnly());

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                FColor PixelColor = rSourceImageData[y * width + x];
                pixels[y * 4 * width + x * 4 + 2] = GetColorValue(PixelColor, TextureChannelPackerSettings->Settings.rSourceChannel);//PixelColorR.R;
            }
        }

        rSourceTexture->PlatformData->Mips[0].BulkData.Unlock();

        //set green channel
        const FColor* gSourceImageData = static_cast<const FColor*>( gSourceTexture->PlatformData->Mips[0].BulkData.LockReadOnly());

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                FColor PixelColor = gSourceImageData[y * width + x];
                pixels[y * 4 * width + x * 4 + 1] = GetColorValue(PixelColor, TextureChannelPackerSettings->Settings.gSourceChannel);//PixelColorR.R;
            }
        }

        gSourceTexture->PlatformData->Mips[0].BulkData.Unlock();

        //set blue channel
        const FColor* bSourceImageData = static_cast<const FColor*>( bSourceTexture->PlatformData->Mips[0].BulkData.LockReadOnly());

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                FColor PixelColor = bSourceImageData[y * width + x];
                pixels[y * 4 * width + x * 4 + 0] = GetColorValue(PixelColor, TextureChannelPackerSettings->Settings.bSourceChannel);//PixelColorR.R;
            }
        }

        bSourceTexture->PlatformData->Mips[0].BulkData.Unlock();

        //set alpha channel
        const FColor* aSourceImageData = static_cast<const FColor*>( aSourceTexture->PlatformData->Mips[0].BulkData.LockReadOnly());

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                FColor PixelColor = aSourceImageData[y * width + x];
                pixels[y * 4 * width + x * 4 + 3] = GetColorValue(PixelColor, TextureChannelPackerSettings->Settings.aSourceChannel);//PixelColorR.R;
            }
        }

        aSourceTexture->PlatformData->Mips[0].BulkData.Unlock();

        //revert source texture settings
        rSourceTexture->CompressionSettings = OldCompressionSettings_R;
        gSourceTexture->CompressionSettings = OldCompressionSettings_G;
        bSourceTexture->CompressionSettings = OldCompressionSettings_B;
        aSourceTexture->CompressionSettings = OldCompressionSettings_A;

        rSourceTexture->MipGenSettings = OldMipGenSettings_R;
        gSourceTexture->MipGenSettings = OldMipGenSettings_G;
        bSourceTexture->MipGenSettings = OldMipGenSettings_B;
        aSourceTexture->MipGenSettings = OldMipGenSettings_A;

        rSourceTexture->SRGB = OldSRGB_R;
        gSourceTexture->SRGB = OldSRGB_G;
        bSourceTexture->SRGB = OldSRGB_B;
        aSourceTexture->SRGB = OldSRGB_A;

        rSourceTexture->UpdateResource();
        gSourceTexture->UpdateResource();
        bSourceTexture->UpdateResource();
        aSourceTexture->UpdateResource();

        FString pathPackage = *filePath;

        //UE_LOG(LogTemp, Log, TEXT( "pathPackage: %s" ), *pathPackage);
        //UE_LOG(LogTemp, Log, TEXT( "absolutePathPackage: %s" ), *absolutePathPackage);

        UPackage * Package = CreatePackage(nullptr, *pathPackage);
        Package->FullyLoad();

        UTexture2D* Texture = NewObject<UTexture2D>(Package, FName(*FileName), RF_Public | RF_Standalone | RF_MarkAsRootSet);
        Texture->AddToRoot();

        // Texture Settings
        Texture->PlatformData = new FTexturePlatformData();
        Texture->PlatformData->SizeX = width;
        Texture->PlatformData->SizeY = height;
        Texture->PlatformData->PixelFormat = EPixelFormat ::PF_R8G8B8A8;

        // Passing the pixels information to the texture
        FTexture2DMipMap* Mip = new(Texture->PlatformData->Mips) FTexture2DMipMap();

        Mip->SizeX = width;
        Mip->SizeY = height;
        Mip->BulkData.Lock(LOCK_READ_WRITE);
        uint8* TextureData = (uint8 *) Mip->BulkData.Realloc(height * width * sizeof(uint8)*4);
        FMemory::Memcpy(TextureData, pixels, sizeof(uint8) * height * width * 4);
        Mip->BulkData.Unlock();

        Texture->Source.Init(width, height, 1, 1, ETextureSourceFormat::TSF_BGRA8, pixels);

        Texture->UpdateResource();
        Package->MarkPackageDirty();

        FAssetRegistryModule::AssetCreated( Texture );

        FString savedFileName = FPackageName::LongPackageNameToFilename(pathPackage, FPackageName::GetAssetPackageExtension());
        UPackage::SavePackage(Package, nullptr, EObjectFlags::RF_Public | EObjectFlags::RF_Standalone, *savedFileName);

        free(pixels);
        pixels = NULL;

    }
}

void STextureChannelPackerWidget::CreateSettingsView()
{
    // Create a property view
    FPropertyEditorModule& EditModule = FModuleManager::Get().GetModuleChecked<FPropertyEditorModule>("PropertyEditor");

    FDetailsViewArgs DetailsViewArgs;
    DetailsViewArgs.bUpdatesFromSelection = true;
    DetailsViewArgs.bLockable = true;
    DetailsViewArgs.NameAreaSettings = FDetailsViewArgs::ComponentsAndActorsUseNameArea;
    DetailsViewArgs.bCustomNameAreaLocation = false;
    DetailsViewArgs.bCustomFilterAreaLocation = true;
    DetailsViewArgs.DefaultsOnlyVisibility = EEditDefaultsOnlyNodeVisibility::Hide;

    SettingsView = EditModule.CreateDetailView(DetailsViewArgs);
    //SettingsView->SetIsPropertyVisibleDelegate(FIsPropertyVisible::CreateStatic(&Local::IsPropertyVisible, true));
}

uint8 STextureChannelPackerWidget::GetColorValue(FColor color, TextureChannel channel)
{
    int retVal = 0;

    switch(channel)
    {
        case TextureChannel::Red: {
            retVal = color.R;
            break;
        }

        case TextureChannel::Green:
        {
            retVal = color.G;
            break;
        }

        case TextureChannel::Blue:
        {
            retVal = color.B;
            break;
        }

        case TextureChannel::Alpha:
        {
            retVal = color.A;
            break;
        }

    }

    return retVal;
}

#undef LOCTEXT_NAMESPACE

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
