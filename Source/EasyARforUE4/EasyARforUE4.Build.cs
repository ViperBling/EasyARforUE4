// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class EasyARforUE4 : ModuleRules
{
	public EasyARforUE4(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		bEnableExceptions = true;
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
				// "EasyARforUE4Library",
				"EasyARSense",
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
		CppStandard = CppStandardVersion.Cpp17;
	}
}
