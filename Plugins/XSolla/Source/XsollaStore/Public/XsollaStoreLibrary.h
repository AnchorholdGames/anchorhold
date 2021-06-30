// Copyright 2021 Xsolla Inc. All Rights Reserved.
// @author Vladimir Alyamkin <ufna@ufna.ru>

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "XsollaStoreDataModel.h"
#include "XsollaStoreLibrary.generated.h"

class UXsollaStoreSubsystem;
class UXsollaStoreSettings;
class UDataTable;

UCLASS()
class XSOLLASTORE_API UXsollaStoreLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

public:
	/** Direct access to the store SDK settings. */
	UFUNCTION(BlueprintPure, Category = "Xsolla|Store")
	static UXsollaStoreSettings* GetStoreSettings();

	/** Returns true if cart A is equal to cart B (A == B). */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal (StoreCart)", CompactNodeTitle = "===", ScriptMethod = "Equals", ScriptOperator = "==", Keywords = "== equal"), Category = "Xsolla|Store|Cart")
	static bool Equal_StoreCartStoreCart(const FStoreCart& A, const FStoreCart& B);

	/** Gets currency-format data table. */
	UFUNCTION(BlueprintCallable, Category = "Xsolla|Store")
	static UDataTable* GetCurrencyLibrary();

	/** Formats store price using the currency-format library https://github.com/xsolla/currency-format. */
	UFUNCTION(BlueprintPure, Category = "Xsolla|Store")
	static FString FormatPrice(float Amount, const FString& Currency = TEXT("USD"));

private:
	/** Loaded currency library asset. */
	static UDataTable* CurrencyLibrary;
};
