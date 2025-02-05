// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class LearnDataAsset : ModuleRules
{
	public LearnDataAsset(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "Networking", "Sockets", "GameplayAbilities", "GameplayTags", "GameplayTasks" });
		PrivateDependencyModuleNames.AddRange(new string[] { });

		// If you are using Slate UI
		PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// If you are using online features
		PrivateDependencyModuleNames.Add("OnlineSubsystem");
		

	}
}
