// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "OpenAPIAuthenticationApi.h"
#include "GameFramework/GameModeBase.h"
#include "Interfaces/IHttpRequest.h"
#include "DatabaseGameModeBase.generated.h"

namespace OpenAPI
{
	class OpenAPIAuthenticationApi;
}

/**
 * 
 */
UCLASS()
class DATABASE_API ADatabaseGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public :

		bool Authenticate();

		OpenAPI::OpenAPIAuthenticationApi* GetAuthenticationApi();
	
		void OnRegisterUserResponse(const OpenAPI::OpenAPIAuthenticationApi::RegisterUserPostResponse& Response);
	
protected :
	
	OpenAPI::OpenAPIAuthenticationApi* AuthenticationApi;
	
	virtual void BeginPlay() override;
};
