using UnrealBuildTool;
using System.Collections.Generic;
public class LearnDataAssetClientTarget : TargetRules
{
	public LearnDataAssetClientTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Client;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;

		ExtraModuleNames.AddRange(new string[] { "LearnDataAsset" });

		//LearnDataAssetTarget.ApplySharedLearnDataAssetClientTargetSettings(this);

		bUseChecksInShipping = true;
	}
}
