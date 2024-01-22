// Copyright (C) 2024 owoDra

#include "CharacterRecipe_ApplyContextEffectLibrary.h"

#include "ContextEffectComponent.h"
#include "ContextEffectLibrary.h"

#include "CharacterInitStateComponent.h"
#include "GCExtLogs.h"

#include "GameFramework/Pawn.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CharacterRecipe_ApplyContextEffectLibrary)


UCharacterRecipe_ApplyContextEffectLibrary::UCharacterRecipe_ApplyContextEffectLibrary()
{
	InstancingPolicy = ECharacterRecipeInstancingPolicy::NonInstanced;
	NetExecutionPolicy = ECharacterRecipeNetExecutionPolicy::ClientOnly;

#if WITH_EDITOR
	StaticClass()->FindPropertyByName(FName{ TEXTVIEW("InstancingPolicy") })->SetPropertyFlags(CPF_DisableEditOnTemplate);
	StaticClass()->FindPropertyByName(FName{ TEXTVIEW("NetExecutionPolicy") })->SetPropertyFlags(CPF_DisableEditOnTemplate);
#endif
}


void UCharacterRecipe_ApplyContextEffectLibrary::StartSetupNonInstanced_Implementation(FCharacterRecipePawnInfo Info) const
{
	auto* Component{ Info.Pawn->FindComponentByClass<UContextEffectComponent>() };

	if (Component)
	{
		if (bShouldApplyLibraries)
		{
			UE_LOG(LogGameExt_CharacterRecipe, Log, TEXT("++ContextEffectLibraries"));

			Component->UpdateContextEffectLibraries(Libraries);
		}

		if (bShouldApplyContexts)
		{
			UE_LOG(LogGameExt_CharacterRecipe, Log, TEXT("++Contexts"));

			Component->UpdateExtraContexts(Contexts);
		}
	}
}
