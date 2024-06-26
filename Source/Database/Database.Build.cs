// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Database : ModuleRules
{
	public Database(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { "OpenAPI" });

	}
}
