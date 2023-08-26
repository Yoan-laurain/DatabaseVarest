// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ApiClient : ModuleRules
{
	public ApiClient(ReadOnlyTargetRules Target) : base(Target)
	{
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"HTTP",
				"Json",
			}
		);
		PCHUsage = PCHUsageMode.NoPCHs;
		
	}
}
