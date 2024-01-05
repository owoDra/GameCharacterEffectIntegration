// Copyright (C) 2023 owoDra

using UnrealBuildTool;

public class GCFXIntg : ModuleRules
{
	public GCFXIntg(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(
          new string[]
          {
                ModuleDirectory,
                ModuleDirectory + "/GCFXIntg",
          }
      );


        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine",
                "GameplayTags",
            }
        );


        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "GFCore",
                "GCExt",
                "GFXExt",
            }
        );
    }
}
