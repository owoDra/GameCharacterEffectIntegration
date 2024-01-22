// Copyright (C) 2024 owoDra

#include "CharacterRecipe_AddContextEffectComponent.h"

#include "ContextEffectComponent.h"
#include "ContextEffectLibrary.h"

#include "CharacterInitStateComponent.h"
#include "GCExtLogs.h"

#include "GameFramework/Pawn.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CharacterRecipe_AddContextEffectComponent)


UCharacterRecipe_AddContextEffectComponent::UCharacterRecipe_AddContextEffectComponent()
{
	InstancingPolicy = ECharacterRecipeInstancingPolicy::NonInstanced;
	NetExecutionPolicy = ECharacterRecipeNetExecutionPolicy::ClientOnly;

#if WITH_EDITOR
	StaticClass()->FindPropertyByName(FName{ TEXTVIEW("InstancingPolicy") })->SetPropertyFlags(CPF_DisableEditOnTemplate);
	StaticClass()->FindPropertyByName(FName{ TEXTVIEW("NetExecutionPolicy") })->SetPropertyFlags(CPF_DisableEditOnTemplate);
#endif
}


void UCharacterRecipe_AddContextEffectComponent::StartSetupNonInstanced_Implementation(FCharacterRecipePawnInfo Info) const
{
	auto* Pawn{ Info.Pawn.Get() };

	auto* LoadedComponentClass
	{
		ComponentClass.IsNull() ? nullptr :
		ComponentClass.IsValid() ? ComponentClass.Get() : ComponentClass.LoadSynchronous()
	};

	if (ComponentClass)
	{
		auto* NewCEC{ NewObject<UContextEffectComponent>(Pawn, LoadedComponentClass) };

		UE_LOG(LogGameExt_CharacterRecipe, Log, TEXT("+Component (Name: %s, Class: %s)"), *GetNameSafe(NewCEC), *GetNameSafe(LoadedComponentClass));

		if (!Libraries.IsEmpty())
		{
			UE_LOG(LogGameExt_CharacterRecipe, Log, TEXT("++ContextEffectLibraries"));

			NewCEC->ContextEffectLibraries = Libraries;
		}

		if (!Contexts.IsEmpty())
		{
			UE_LOG(LogGameExt_CharacterRecipe, Log, TEXT("++Contexts"));

			NewCEC->ExtraContexts = Contexts;
		}

		NewCEC->RegisterComponent();
	}
}
