#pragma once

#include "CoreMinimal.h"
#include "OpenAPIAuthenticationApi.h"
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

		OpenAPI::OpenAPIAuthenticationApi* GetAuthenticationApi();

		FGuid RetrieveApiKey();
		FGuid CreateApiKey();

private :

	FString LocalStorageName = "LocalStorage";
	
protected :
	
	OpenAPI::OpenAPIAuthenticationApi* AuthenticationApi;
	
	virtual void BeginPlay() override;
};