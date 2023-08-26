#include "DatabaseGameModeBase.h"
#include "OpenAPIAuthenticationApi.h"
#include "OpenAPIAuthenticationApiOperations.h"
#include "OpenAPIUserViewModel.h"

bool ADatabaseGameModeBase::Authenticate()
{
	OpenAPI::OpenAPIUserViewModel UserViewModel;

	UserViewModel.Email = "yoan.laurain1@gmail.com";
	UserViewModel.Password = "Tatatutut33!";
    
	OpenAPI::OpenAPIAuthenticationApi::FRegisterUserPostDelegate RegisterUserDelegate;
	RegisterUserDelegate.BindUObject(this, &ADatabaseGameModeBase::OnRegisterUserResponse);

	OpenAPI::OpenAPIAuthenticationApi::RegisterUserPostRequest UserRequest;
	UserRequest.OpenAPIUserViewModel = UserViewModel;

	FHttpRequestPtr request = GetAuthenticationApi()->RegisterUserPost(UserRequest, RegisterUserDelegate);
	
	return true;
}

void ADatabaseGameModeBase::OnRegisterUserResponse(const OpenAPI::OpenAPIAuthenticationApi::RegisterUserPostResponse& Response)
{
	if (Response.IsSuccessful())
	{
		UE_LOG(LogTemp, Warning, TEXT("User registered successfully!"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("User registration failed: %s"), *Response.GetResponseString());
	}
}

void ADatabaseGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	Authenticate();
}

OpenAPI::OpenAPIAuthenticationApi* ADatabaseGameModeBase::GetAuthenticationApi()
{
	if (AuthenticationApi == nullptr)
	{
		AuthenticationApi = new OpenAPI::OpenAPIAuthenticationApi();
	}
	return AuthenticationApi;
}
