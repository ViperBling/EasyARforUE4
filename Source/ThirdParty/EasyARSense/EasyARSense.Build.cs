// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class EasyARSense : ModuleRules
{
	public EasyARSense(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;
		CppStandard = CppStandardVersion.Cpp17;
		PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "include"));
		if (Target.Platform == UnrealTargetPlatform.Win32 ||
		    Target.Platform == UnrealTargetPlatform.Win64)
		{
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
			RuntimeDependencies.Add(Path.Combine(EasyAROutBinPath, "EasyAR.dll"));
		}
		else if (Target.Platform == UnrealTargetPlatform.Android)
		{
			PublicDelayLoadDLLs.Add(Path.Combine(ModuleDirectory, "Android", "arm64-v8a", "libEasyAR.so"));
			RuntimeDependencies.Add("$(PluginDir)/Binaries/ThirdParty/EasyARSense/Android/arm64-v8a/libEasyAR.so");
		}
	}
}