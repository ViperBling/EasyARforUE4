// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class EasyARforUE4 : ModuleRules
{
	public EasyARforUE4(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"RenderCore",
				"RHI",
				"InputCore",
				"Projects",
				"Slate"
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);

		if (Target.Platform == UnrealTargetPlatform.Win32 || Target.Platform == UnrealTargetPlatform.Win64)
		{
			string EasyARLibPath = Target.Platform == UnrealTargetPlatform.Win32
				? "ThirdParty/EasyARSense/Windows/x86"
				: "ThirdParty/EasyARSense/Windows/x64";
			string EasyARBinPath = EasyARLibPath;
			CppStandard = CppStandardVersion.Cpp17;
			PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "ThirdParty/EasyARSense/include"));
			PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, EasyARLibPath, "EasyAR.lib"));
			PublicDelayLoadDLLs.Add(Path.Combine(ModuleDirectory, EasyARBinPath, "EasyAR.dll"));

			string EasyAROutBinPath = Target.Platform == UnrealTargetPlatform.Win32
				? "$(PluginDir)/Binaries/ThirdParty/EasyARSense/Win32/EasyAR.dll"
				: "$(PluginDir)/Binaries/ThirdParty/EasyARSense/Win64/EasyAR.dll";
			RuntimeDependencies.Add(EasyAROutBinPath, Path.Combine(ModuleDirectory, EasyARBinPath, "EasyAR.dll"));
		}
		else if (Target.Platform == UnrealTargetPlatform.Android)
		{
			string EasyARUEAndroidPath = "ThirdParty/EasyARSense/Android";
			PrivateIncludePaths.Add(Path.Combine(ModuleDirectory, "ThirdParty/EasyARSense/include"));
			PublicAdditionalLibraries.Add(Path.Combine(EasyARUEAndroidPath, "arm64-v8a/libEasyAR.so"));
			PublicAdditionalLibraries.Add(Path.Combine(EasyARUEAndroidPath, "armeabi-v7a/libEasyAR.so"));
			RuntimeDependencies.Add("$(PluginDir)/Binaries/ThirdParty/EasyARSense/Android/Release/libEasyAR.so");
		}
	}
}
