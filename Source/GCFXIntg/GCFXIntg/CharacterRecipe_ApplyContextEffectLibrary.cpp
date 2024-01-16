// Copyright (C) 2024 owoDra

#include "CharacterRecipe_ApplyContextEffectLibrary.h"

#include "GCFXIntgLogs.h"

#include "ContextEffectComponent.h"
#include "ContextEffectLibrary.h"

#include "CharacterInitStateComponent.h"

#include "GameFramework/Pawn.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CharacterRecipe_ApplyContextEffectLibrary)


UCharacterRecipe_ApplyContextEffectLibrary::UCharacterRecipe_ApplyContextEffectLibrary()
{
	InstancingPolicy = ECharacterRecipeInstancingPolicy::NonInstanced;
	NetExecutionPolicy = ECharacterRecipeNetExecutionPolicy::ClientOnly;
}


void UCharacterRecipe_ApplyContextEffectLibrary::StartSetupNonInstanced_Implementation(FCharacterRecipePawnInfo Info) const
{
	auto* Component{ Info.Pawn->FindComponentByClass<UContextEffectComponent>() };

	if (Component)
	{
		if (bShouldApplyLibraries)
		{
			UE_LOG(LogGCFXI, Log, TEXT("++ContextEffectLibraries"));

			Component->UpdateContextEffectLibraries(Libraries);
		}

		if (bShouldApplyContexts)
		{
			UE_LOG(LogGCFXI, Log, TEXT("++Contexts"));

			Component->UpdateExtraContexts(Contexts);
		}
	}
}
