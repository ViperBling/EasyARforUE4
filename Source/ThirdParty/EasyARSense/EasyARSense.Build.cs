// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class EasyARSense : ModuleRules
{
	public EasyARSense(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;
		CppStandard = CppStandardVersion.Cpp17;
		
		// bUseRTTI = true;
		if (Target.Platform == UnrealTargetPlatform.Win32 ||
		    Target.Platform == UnrealTargetPlatform.Win64)
		{
			PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "include"));
			// Add the import library
			string EasyARLibPath = Target.Platform == UnrealTargetPlatform.Win32
				? Path.Combine(ModuleDirectory, "Windows", "x86")
				: Path.Combine(ModuleDirectory, "Windows", "x64");
			PublicAdditionalLibraries.Add(Path.Combine(EasyARLibPath, "EasyAR.lib"));
		
			// Delay-load the DLL, so we can load it from the right place first
			PublicDelayLoadDLLs.Add("EasyAR.dll");
		
			// Ensure that the DLL is staged along with the executable
			string EasyAROutBinPath = Target.Platform == UnrealTargetPlatform.Win32
				? "$(PluginDir)/Binaries/ThirdParty/EasyARSense/Win32"
				: "$(PluginDir)/Binaries/ThirdParty/EasyARSense/Win64";
			RuntimeDependencies.Add(Path.Combine(EasyAROutBinPath, "EasyAR.dll"), Path.Combine(EasyARLibPath, "EasyAR.dll"));
		}
		else if (Target.Platform == UnrealTargetPlatform.Android)
		{
			PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "include"));
			PublicDelayLoadDLLs.Add(Path.Combine(ModuleDirectory, "Android", "arm64-v8a", "libEasyAR.so"));
			PublicDelayLoadDLLs.Add(Path.Combine(ModuleDirectory, "Android", "armeabi-v7a", "libEasyAR.so"));
			RuntimeDependencies.Add(
				"$(PluginDir)/Binaries/ThirdParty/EasyARSense/Android/arm64-v8a/libEasyAR.so", 
				Path.Combine(ModuleDirectory, "Android", "arm64-v8a", "libEasyAR.so"));
			RuntimeDependencies.Add(
				"$(PluginDir)/Binaries/ThirdParty/EasyARSense/Android/armeabi-v7a/libEasyAR.so", 
				Path.Combine(ModuleDirectory, "Android", "armeabi-v7a", "libEasyAR.so"));
		}
		// else if (Target.Platform == UnrealTargetPlatform.IOS)
		// {
		// 	PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "IOS", "arm64_fat", "easyar.framework", "Headers"));
		// 	PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "IOS", "arm64_fat_static", "easyar.framework", "Headers"));
		// 	PublicDelayLoadDLLs.Add(Path.Combine(ModuleDirectory, "IOS", "arm64_fat", "easyar.framework", "easyar"));
		// 	PublicDelayLoadDLLs.Add(Path.Combine(ModuleDirectory, "IOS", "arm64_fat_static", "easyar.framework", "easyar"));
		// 	
		// }
	}
}