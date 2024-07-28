// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/DataRace_GameMode.h"
#include "Sockets.h"
#include "SocketSubsystem.h"



bool ADataRace_GameMode::TestServerConnection(const FString& ServerAddress, int32 TimeoutInMs)
{
    bool bIsConnected = false;

    if (ISocketSubsystem* SocketSubsystem = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM))
    {
        UE_LOG(LogTemp, Warning, TEXT("GameMode - Line17 : Have Valid SocketSubsystem"))
        TSharedRef<FInternetAddr> InternetAddr = SocketSubsystem->CreateInternetAddr();

        bool bIsValid;
        InternetAddr->SetIp(*ServerAddress, bIsValid);
        InternetAddr->SetPort(7777);  // Use HTTP port for a simple ping, adjust as necessary

        if (bIsValid)
        {
            UE_LOG(LogTemp, Warning, TEXT("GameMode - Line26 : bIsValid is TRUE"))
            if (FSocket* Socket = SocketSubsystem->CreateSocket(NAME_Stream, TEXT("PingSocket"), false))
            {
                UE_LOG(LogTemp, Warning, TEXT("GameMode - Line29 : Hase Valid Socket"))
                Socket->SetNonBlocking(true);
                Socket->SetRecvErr();

                bool bConnected = Socket->Connect(*InternetAddr);
                if (!bConnected)
                {
                    UE_LOG(LogTemp, Warning, TEXT("GameMode - Line36 : We are NOT connected"))
                    // Set a timer to wait for the connection attempt to succeed
                    FDateTime EndTime = FDateTime::UtcNow() + FTimespan::FromMilliseconds(TimeoutInMs);
                    while (FDateTime::UtcNow() < EndTime)
                    {
                        uint32 PendingDataSize;
                        bool bWriteReady = false;
                        
                        // Use Wait for checking the socket status
                        if (Socket->Wait(ESocketWaitConditions::WaitForWrite, FTimespan::FromMilliseconds(1)))
                        {
                            
                            bWriteReady = true;
                        }

                        // Check if there is pending data which means connection is successful
                        if (Socket->HasPendingData(PendingDataSize) && PendingDataSize > 0)
                        {
                            bIsConnected = true;
                            break;
                        }
                    }
                }
                else
                {
                    UE_LOG(LogTemp, Warning, TEXT("GameMode - Line61 : We ARE connected"))
                    bIsConnected = true;
                }

                SocketSubsystem->DestroySocket(Socket);
            }
        }
    }

    return bIsConnected;
}
