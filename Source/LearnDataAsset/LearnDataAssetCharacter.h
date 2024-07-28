// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "LearnDataAssetCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;

struct FInputActionValue;

UENUM()
enum EMovementState
{
	EWalk,
	ESprint,
	EJog,
};

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class ALearnDataAssetCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

	/** Sprint Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* SprintAction;
	
	/** Walk Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* WalkAction;
	
public:
	ALearnDataAssetCharacter();
	
	/*
	 *Override Replicate Properties function : This function is necessary for registering
	 * replicated variables over the lifetime of the ACTORs existance in the world
	 */ 
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	void Walk(const FInputActionValue& Value);

	void Sprint(const FInputActionValue& Value);

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay() override;

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	// Movement States
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Replicated,Category = "DataRace : Speed Variables")
	float NewWalkSpeed;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Replicated,Category = "DataRace : Speed Variables")
	float SprintSpeed;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Replicated,Category = "DataRace : Speed Variables")
	float JogSpeed;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Replicated,Category = "DataRace : Speed Variables")
	TEnumAsByte<EMovementState> enumVariable;

	// Remote Procedural Call (RPC)
	// Client RPC Function
	UFUNCTION(Client,Reliable)
	void ChangeSpeedClientRPC(EMovementState MovementState);
 
	// Server RPC Function
	UFUNCTION(Server,Reliable)
	void ChangeSpeedServerRPC(EMovementState MovementState);
	


};

