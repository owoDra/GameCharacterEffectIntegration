// Copyright (C) 2024 owoDra

#pragma once

#include "Recipe/CharacterRecipe.h"

#include "GameplayTagContainer.h"

#include "CharacterRecipe_ApplyContextEffectLibrary.generated.h"

class UContextEffectLibrary;


/**
 * Modifier class to add context effect libraries to component
 */
UCLASS()
class UCharacterRecipe_ApplyContextEffectLibrary final : public UCharacterRecipe
{
	GENERATED_BODY()
public:
	UCharacterRecipe_ApplyContextEffectLibrary();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "ApplyContextEffectLibrary", meta = (InlineEditConditionToggle))
	bool bShouldApplyLibraries{ true };

	UPROPERTY(EditDefaultsOnly, Category = "ApplyContextEffectLibrary", meta = (EditCondition = "bShouldApplyLibraries"))
	TSet<TSoftObjectPtr<UContextEffectLibrary>> Libraries;

	UPROPERTY(EditDefaultsOnly, Category = "ApplyContextEffectLibrary", meta = (InlineEditConditionToggle))
	bool bShouldApplyContexts{ false };

	UPROPERTY(EditDefaultsOnly, Category = "ApplyContextEffectLibrary", meta = (EditCondition = "bShouldApplyContexts"))
	FGameplayTagContainer Contexts;

protected:
	virtual void StartSetupNonInstanced_Implementation(FCharacterRecipePawnInfo Info) const override;

};
