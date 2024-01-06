// Copyright (C) 2023 owoDra

#include "CharacterModifier_AddContextEffectComponent.h"

#include "GCFXIntgLogs.h"

#include "ContextEffectComponent.h"
#include "ContextEffectLibrary.h"

#include "GameFramework/Pawn.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CharacterModifier_AddContextEffectComponent)


UCharacterModifier_AddContextEffectComponent::UCharacterModifier_AddContextEffectComponent()
{
	bOnlyApplyOnLocal = false;
	bApplyOnClient = true;
	bApplyOnServer = true;
}


bool UCharacterModifier_AddContextEffectComponent::OnApply(APawn* Pawn) const
{
	const auto bCanApply{ Super::OnApply(Pawn) };

	if (bCanApply)
	{
		auto* LoadedComponentClass
		{
			ComponentClass.IsNull() ? nullptr :
			ComponentClass.IsValid() ? ComponentClass.Get() : ComponentClass.LoadSynchronous()
		};

		if (ComponentClass)
		{
			auto* NewCEC{ NewObject<UContextEffectComponent>(Pawn, LoadedComponentClass) };
			
			UE_LOG(LogGCFXI, Log, TEXT("+Component (Name: %s, Class: %s)"), *GetNameSafe(NewCEC), *GetNameSafe(LoadedComponentClass));

			if (!Libraries.IsEmpty())
			{
				UE_LOG(LogGCFXI, Log, TEXT("++ContextEffectLibraries"));

				NewCEC->ContextEffectLibraries = Libraries;
			}

			if (!Contexts.IsEmpty())
			{
				UE_LOG(LogGCFXI, Log, TEXT("++Contexts"));

				NewCEC->ExtraContexts = Contexts;
			}

			NewCEC->RegisterComponent();
		}
	}

	return bCanApply;
}
