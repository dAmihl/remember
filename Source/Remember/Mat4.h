// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Mat4.generated.h"

UCLASS()
class REMEMBER_API AMat4 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMat4();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintCallable, Category="UtilityFunctions")
	TArray<int32> GetMatrix();
	
	UFUNCTION(BlueprintCallable, Category = "UtilityFunctions")
	AMat4* Transpose();

	UFUNCTION(BlueprintCallable, Category = "UtilityFunctions")
	AMat4* Multiply(AMat4* matB);
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Data")
	TArray<int32> matrixData;
	
};
