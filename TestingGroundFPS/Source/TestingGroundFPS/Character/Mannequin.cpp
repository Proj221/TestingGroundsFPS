// Fill out your copyright notice in the Description page of Project Settings.


#include "Mannequin.h"
#include "Camera/CameraComponent.h"
#include "../Weapon/Gun.h"
#include "Components/CapsuleComponent.h"


// Sets default values
AMannequin::AMannequin()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create an FP_CAMERA_COMP
	FPCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FP_Camera"));
	FPCamera->SetupAttachment(GetCapsuleComponent());
	FPCamera->SetRelativeLocation(FVector(-39.56f, 1.75f, 64.f)); // Position the camera
	FPCamera->bUsePawnControlRotation = true;

	// Create an FP_ARMS_COMP
	FPArms = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FP_Arms"));
	FPArms->SetOnlyOwnerSee(true);
	FPArms->SetupAttachment(FPCamera);
	FPArms->bCastDynamicShadow = false;
	FPArms->CastShadow = false;
	FPArms->SetRelativeRotation(FRotator(1.9f, -19.19f, 5.2f));
	FPArms->SetRelativeLocation(FVector(-0.5f, -4.4f, -155.7f));

	// not sure if it is useful or not.
	// Default offset from the character location for projectiles to spawn
	// GunOffset = FVector(100.0f, 0.0f, 10.0f);

	// Cannot attach gun here as the skeleton is not yet created in the the constructor.
	// need to attach the gun component in the BeginPlay()
}

// Called when the game starts or when spawned
void AMannequin::BeginPlay()
{
	Super::BeginPlay();

	if (GunBlueprint == NULL) {
		UE_LOG(LogTemp, Warning, TEXT("GunBlueprint is missing!"));
		return;
	}
	Gun = GetWorld()->SpawnActor<AGun>(GunBlueprint);

	//Attach gun mesh component to Skeleton, doing it here because the skeleton is not yet created in the constructor
	Gun->AttachToComponent(FPArms, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));
	Gun->AnimInstance = GetMesh()->GetAnimInstance();

	// to make sure if it is really a player is taking control of the mannequin
	if (InputComponent != NULL) {
		InputComponent->BindAction("Fire", IE_Pressed, this, &AMannequin::PullTrigger);
	}
	
}

// Called every frame
void AMannequin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMannequin::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	// if we put input component here, Gun is not set yet therefore it is causing problems.
	// Instead, should be implemented in BeginPlay()
	// PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AMannequin::Fire);

}

void AMannequin::PullTrigger() {
	UE_LOG(LogTemp, Warning, TEXT("Firing!!!"));
	Gun->OnFire();
}

