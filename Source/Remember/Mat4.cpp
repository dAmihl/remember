// Fill out your copyright notice in the Description page of Project Settings.

#include "Remember.h"
#include "Mat4.h"

#define MATRIX_SIZE 4

// Sets default values
AMat4::AMat4()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// init matrix
	//matrixData.Init(0, MATRIX_SIZE*MATRIX_SIZE);
	matrixData.Add(1);
	matrixData.Add(3);
	matrixData.Add(1);
	matrixData.Add(2);

	matrixData.Add(1);
	matrixData.Add(1);
	matrixData.Add(2);
	matrixData.Add(1);

	matrixData.Add(1);
	matrixData.Add(1);
	matrixData.Add(1);
	matrixData.Add(2);

	matrixData.Add(1);
	matrixData.Add(1);
	matrixData.Add(1);
	matrixData.Add(1);


}

// Called when the game starts or when spawned
void AMat4::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMat4::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}
TArray<int32> AMat4::GetMatrix()
{
	return matrixData;
}

AMat4* AMat4::Transpose() {
	return this;
}

AMat4* AMat4::Multiply(AMat4* matB) {
	return this;
}

