// Copyright (C) 2024 owoDra

#pragma once

#include "Recipe/CharacterRecipe.h"

#include "GameplayTagContainer.h"

#include "CharacterRecipe_AddContextEffectComponent.generated.h"

class UContextEffectComponent;
class UContextEffectLibrary;


/**
 * Modifier class to add context effect component to Pawn
 */
UCLASS(meta = (DisplayName = "CM Add Context Effect Component"))
class UCharacterRecipe_AddContextEffectComponent final : public UCharacterRecipe
{
	GENERATED_BODY()
public:
	UCharacterRecipe_AddContextEffectComponent();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "AddContextEffectComponent")
	TSoftClassPtr<UContextEffectComponent> ComponentClass{ nullptr };

	UPROPERTY(EditDefaultsOnly, Category = "AddContextEffectComponent")
	TSet<TSoftObjectPtr<UContextEffectLibrary>> Libraries;

	UPROPERTY(EditDefaultsOnly, Category = "AddContextEffectComponent")
	FGameplayTagContainer Contexts;

protected:
	virtual void StartSetupNonInstanced_Implementation(FCharacterRecipePawnInfo Info) const override;

};
