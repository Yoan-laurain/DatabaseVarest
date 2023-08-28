#pragma once

#include "GameFramework/SaveGame.h"
#include "SaveGameXenoSurge.generated.h"

UCLASS()
class DATABASE_API USaveGameXenoSurge : public USaveGame
{
	GENERATED_BODY()
	
public:

	FGuid GetApiKey() const { return ApiKey; }
	void SetApiKey(FGuid ApiKey);

private :
	
	FGuid ApiKey;
};