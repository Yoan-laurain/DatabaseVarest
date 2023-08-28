#include "DatabaseGameModeBase.h"
#include "OpenAPIAuthenticationApi.h"
#include "SaveGameXenoSurge.h"
#include "Kismet/GameplayStatics.h"

void ADatabaseGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	FGuid ApiKey = RetrieveApiKey();

	// TODO : load api key into player 
}

OpenAPI::OpenAPIAuthenticationApi* ADatabaseGameModeBase::GetAuthenticationApi()
{
	if (AuthenticationApi == nullptr)
	{
		AuthenticationApi = new OpenAPI::OpenAPIAuthenticationApi();
	}
	return AuthenticationApi;
}

FGuid ADatabaseGameModeBase::RetrieveApiKey()
{
	if ( UGameplayStatics::DoesSaveGameExist(LocalStorageName, 0) )
	{
		const USaveGameXenoSurge* SaveGame = static_cast<USaveGameXenoSurge*>(UGameplayStatics::LoadGameFromSlot(LocalStorageName, 0));
		if (SaveGame != nullptr)
		{
			return SaveGame->GetApiKey();
		}
	}

	return CreateApiKey();
}

FGuid ADatabaseGameModeBase::CreateApiKey()
{
	USaveGameXenoSurge* SaveGame = static_cast<USaveGameXenoSurge*>(UGameplayStatics::CreateSaveGameObject(USaveGameXenoSurge::StaticClass()));
	
	ensure (SaveGame);
	
	const FGuid Guid = FGuid::NewGuid();
	
	SaveGame->SetApiKey(Guid);

	return Guid;
}