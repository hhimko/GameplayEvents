// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GameplayEventsEditor : ModuleRules
{
	public GameplayEventsEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", 
			"GameplayEvents"
		});
		
		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"CoreUObject",
			"Engine",
			"Slate",
			"SlateCore",
			"AssetTools",
			"UnrealEd",
			"PropertyEditor",
			"Projects",
			"ToolMenus",
			"GraphEditor"
		});
	}
}
