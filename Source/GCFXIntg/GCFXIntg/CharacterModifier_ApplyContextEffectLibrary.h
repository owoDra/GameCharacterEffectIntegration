// Copyright (C) 2024 owoDra

#pragma once

#include "CharacterModifier.h"

#include "GameplayTagContainer.h"

#include "CharacterModifier_ApplyContextEffectLibrary.generated.h"

class UContextEffectLibrary;


/**
 * Modifier class to add context effect libraries to component
 */
UCLASS(meta = (DisplayName = "CM Apply Context Effect Library"))
class UCharacterModifier_ApplyContextEffectLibrary final : public UCharacterModifier
{
	GENERATED_BODY()
public:
	UCharacterModifier_ApplyContextEffectLibrary();

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
	virtual bool OnApply(APawn* Pawn) const override;

};
