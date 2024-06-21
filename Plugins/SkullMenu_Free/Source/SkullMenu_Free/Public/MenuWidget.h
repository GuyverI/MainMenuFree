// Copyright 2023 Skull Software

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuWidget.generated.h"


UENUM(BlueprintType)
enum class ESkullMenu_InGameInputMode : uint8
{
	GameOnly,
	GameAndUi
};

UCLASS()
class SKULLMENU_FREE_API USkullMenu_MenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void RemoveFromParent() override;

	UPROPERTY(EditAnywhere, Category="Skull Menu")
	ESkullMenu_InGameInputMode InGameInputMode = ESkullMenu_InGameInputMode::GameOnly;

protected:
	void NativeConstruct() override;
	void NativeDestruct() override;

	virtual void OnAddedToViewport(UWidget* Widget, ULocalPlayer* LocalPlayer);

	APlayerController* GetPlayerController(ULocalPlayer* LocalPlayer);

private:
	FDelegateHandle OnAddedToViewportDelegateHandle;
	EMouseLockMode MouseLockModeBeforeShowing = EMouseLockMode::DoNotLock;
	bool bWasCursorHiddenDuringCaptureBeforeShowing = false;
	bool bWasCursorShownBefore = false;
};
