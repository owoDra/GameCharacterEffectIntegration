// Copyright (C) 2024 owoDra

#pragma once

#include "CharacterModifier.h"

#include "GameplayTagContainer.h"

#include "CharacterModifier_AddContextEffectComponent.generated.h"

class UContextEffectComponent;
class UContextEffectLibrary;


/**
 * Modifier class to add context effect component to Pawn
 */
UCLASS(meta = (DisplayName = "CM Add Context Effect Component"))
class UCharacterModifier_AddContextEffectComponent final : public UCharacterModifier
{
	GENERATED_BODY()
public:
	UCharacterModifier_AddContextEffectComponent();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "AddContextEffectComponent")
	TSoftClassPtr<UContextEffectComponent> ComponentClass{ nullptr };

	UPROPERTY(EditDefaultsOnly, Category = "AddContextEffectComponent")
	TSet<TSoftObjectPtr<UContextEffectLibrary>> Libraries;

	UPROPERTY(EditDefaultsOnly, Category = "AddContextEffectComponent")
	FGameplayTagContainer Contexts;

protected:
	virtual bool OnApply(APawn* Pawn) const override;

};
