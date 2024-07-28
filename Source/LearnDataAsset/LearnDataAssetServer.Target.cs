using UnrealBuildTool;
using System.Collections.Generic;

[SupportedPlatforms(UnrealPlatformClass.Server)]
public class LearnDataAssetServerTarget : TargetRules
{
	public LearnDataAssetServerTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Server;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;

		ExtraModuleNames.AddRange(new string[] { "LearnDataAsset" });

		//LearnDataAssetTarget.ApplySharedLearnDataAssetServerTargetSettings(this);

		bUseChecksInShipping = true;
		
	}
}