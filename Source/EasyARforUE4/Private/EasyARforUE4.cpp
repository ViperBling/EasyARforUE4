// Copyright Epic Games, Inc. All Rights Reserved.

#include "EasyARforUE4.h"
#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FEasyARforUE4Module"

void FEasyARforUE4Module::StartupModule()
{
	
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

// 	// Get the base directory of this plugin
// 	FString BaseDir = IPluginManager::Get().FindPlugin("EasyARforUE4")->GetBaseDir();
//
// 	// Add on the relative location of the third party dll and load it
// 	FString LibraryPath;
// #if PLATFORM_WINDOWS
// 	LibraryPath = FPaths::Combine(*BaseDir, TEXT("Binaries/ThirdParty/EasyARSense/Win64/EasyAR.dll"));
// // #elif PLATFORM_MAC
// //     LibraryPath = FPaths::Combine(*BaseDir, TEXT("Source/ThirdParty/EasyARSense/Mac/Release/libEasyAR.dylib"));
// #elif PLATFORM_ANDROID
// 	LibraryPath = FPaths::Combine(*BaseDir, TEXT("Source/ThirdParty/EasyARSense/Android/Release/libEasyAR.so"));
// #endif // PLATFORM_WINDOWS
//
// 	ExampleLibraryHandle = !LibraryPath.IsEmpty() ? FPlatformProcess::GetDllHandle(*LibraryPath) : nullptr;
//
// 	if (ExampleLibraryHandle)
// 	{
// 		// Call the test function in the third party library that opens a message box
// 		// ExampleLibraryFunction();
// 	}
// 	else
// 	{
// 		FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("ThirdPartyLibraryError", "Failed to load example third party library"));
// 	}
}

void FEasyARforUE4Module::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	// Free the dll handle
	// FPlatformProcess::FreeDllHandle(ExampleLibraryHandle);
	// ExampleLibraryHandle = nullptr;
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FEasyARforUE4Module, EasyARforUE4)
