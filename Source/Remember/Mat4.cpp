// Fill out your copyright notice in the Description page of Project Settings.

#include "Remember.h"
#include "Mat4.h"
#include "time.h"

#define MATRIX_SIZE 4

// Sets default values
AMat4::AMat4()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

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

void AMat4::Transpose() {
	TArray<int32> tmpArray;
	tmpArray.Init(0, MATRIX_SIZE*MATRIX_SIZE);

	//Diagonal
	tmpArray[0] = matrixData[0];
	tmpArray[5] = matrixData[5];
	tmpArray[10] = matrixData[10];
	tmpArray[15] = matrixData[15];

	tmpArray[1] = matrixData[4];
	tmpArray[2] = matrixData[8];
	tmpArray[3] = matrixData[12];

	tmpArray[4] = matrixData[1];
	tmpArray[6] = matrixData[9];
	tmpArray[7] = matrixData[13];
	tmpArray[8] = matrixData[2];
	tmpArray[9] = matrixData[6];
	tmpArray[11] = matrixData[14];
	tmpArray[12] = matrixData[3];
	tmpArray[13] = matrixData[7];
	tmpArray[14] = matrixData[11];

	SetMatrixData(tmpArray);
}

AMat4* AMat4::Multiply(AMat4* matB) {
	TArray<int32> arrMatA = matrixData;
	TArray<int32> arrMatB = matB->GetMatrix();
	TArray<int32> tmpArr;
	tmpArr.Init(0, MATRIX_SIZE * MATRIX_SIZE);

	for (int i = 0; i < MATRIX_SIZE; i++) {
		for (int j = 0; j < MATRIX_SIZE; j++) {
			for (int k = 0; k < MATRIX_SIZE; k++) {
				tmpArr[i * MATRIX_SIZE + j] += arrMatA[i * MATRIX_SIZE + k] * arrMatB[k * MATRIX_SIZE + j];
			}
		}
	}
	SetMatrixData(tmpArr);
	InterpreteArrayData();
	return this;
}

AMat4 * AMat4::TileMatrix(int32 index)
{
	TArray<int32> tileMat;
	tileMat.Init(0, MATRIX_SIZE * MATRIX_SIZE);

	int arrSize = MATRIX_SIZE * MATRIX_SIZE;

	for (int i = 0; i < arrSize; i++) {
		tileMat[i] = matrixData[(index + i) % arrSize];
	}


	AMat4* newMat = (AMat4*) GetWorld()->SpawnActor(AMat4::StaticClass());
	newMat->SetMatrixData(tileMat);
	return newMat;
}

void AMat4::SetMatrixData(TArray<int32> arr) {
	//matrixData.Reset(MATRIX_SIZE*MATRIX_SIZE);
	for (int i = 0; i < MATRIX_SIZE * MATRIX_SIZE; i++) {
		matrixData[i] = arr[i];
	}
}

void AMat4::SetIdentity() {
	TArray<int32> tmpArr;
	tmpArr.Init(0, MATRIX_SIZE * MATRIX_SIZE);
	tmpArr[0] = 1;
	tmpArr[5] = 1;
	tmpArr[10] = 1;
	tmpArr[15] = 1;
	SetMatrixData(tmpArr);
}

void AMat4::InterpreteArrayData() {
	char strArr[33];
	
	for (int i = 0; i < MATRIX_SIZE * MATRIX_SIZE; i++) {
		
		itoa(matrixData[i], strArr, 8);

		

		int qsum = 0;
		int count = 0;
		int val = 0;

		while (strArr[count] != '\0') {
			val = strArr[count] - '0';
			qsum += val;
			count++;
		}

		if (qsum % 5 == 0) {
			matrixData[i] = 4;
		}
		
	}
}

void AMat4::MakeRandomMatrix()
{

	int numberTrapsInFirstLevel = 2;
	srand(time(NULL));

	for (int i = 0; i < MATRIX_SIZE * MATRIX_SIZE; i++) {
		matrixData[i] = rand() % 4;
	}

	int index = 0;
	for (int j = 0; j < numberTrapsInFirstLevel; j++) {
		index = rand() % (MATRIX_SIZE*MATRIX_SIZE);
		matrixData[index] = 4;
	}


}

