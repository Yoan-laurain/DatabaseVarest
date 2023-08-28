#pragma once

#include "CoreMinimal.h"
#include "OpenAPIInternalApiApiOperations.h"
#include "GameFramework/GameModeBase.h"
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
	
		FGuid RetrieveApiKey();
		FGuid CreateApiKey();

private :

	FString LocalStorageName = "LocalStorage";
	FString ApiKeyHeaderName = "X-Api-Key";
	
protected :
	void OnRegisterUserResponse(const OpenAPI::OpenAPIInternalApiApi::ObjectRecoltedPostResponse& ObjectRecoltedPostResponse);
	virtual void BeginPlay() override;
};