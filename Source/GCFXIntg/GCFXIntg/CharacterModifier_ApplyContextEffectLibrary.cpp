// Copyright (C) 2024 owoDra

#include "CharacterModifier_ApplyContextEffectLibrary.h"

#include "GCFXIntgLogs.h"

#include "ContextEffectComponent.h"
#include "ContextEffectLibrary.h"

#include "GameFramework/Pawn.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CharacterModifier_ApplyContextEffectLibrary)


UCharacterModifier_ApplyContextEffectLibrary::UCharacterModifier_ApplyContextEffectLibrary()
{
	bOnlyApplyOnLocal = false;
	bApplyOnClient = true;
	bApplyOnServer = true;
}


bool UCharacterModifier_ApplyContextEffectLibrary::OnApply(APawn* Pawn) const
{
	const auto bCanApply{ Super::OnApply(Pawn) };

	if (bCanApply)
	{
		auto* Component{ Pawn->FindComponentByClass<UContextEffectComponent>() };

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

	return bCanApply;
}
