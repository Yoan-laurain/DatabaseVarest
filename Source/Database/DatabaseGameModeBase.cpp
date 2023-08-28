#include "DatabaseGameModeBase.h"

#include "OpenAPIInternalApiApi.h"
#include "OpenAPIInternalApiApiOperations.h"
#include "SaveGameXenoSurge.h"
#include "Kismet/GameplayStatics.h"



void ADatabaseGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	// TODO : load api key into player 
	FGuid ApiKey = RetrieveApiKey();

	OpenAPI::OpenAPIInternalApiApi Api;

	const OpenAPI::OpenAPIInternalApiApi::ObjectRecoltedPostRequest Request;
	OpenAPI::OpenAPIInternalApiApi::FObjectRecoltedPostDelegate Delegate;

	Delegate.BindUObject(this, &ADatabaseGameModeBase::OnRegisterUserResponse);
	
	Api.AddHeaderParam(ApiKeyHeaderName, ApiKey.ToString());
	
	FHttpRequestPtr Result = Api.ObjectRecoltedPost(Request,Delegate);
}

void ADatabaseGameModeBase::OnRegisterUserResponse(
	const OpenAPI::OpenAPIInternalApiApi::ObjectRecoltedPostResponse& ObjectRecoltedPostResponse)
{
	UE_LOG(LogTemp, Warning, TEXT("OnRegisterUserResponse"));
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

	UGameplayStatics::SaveGameToSlot(SaveGame, LocalStorageName, 0);

	return Guid;
}