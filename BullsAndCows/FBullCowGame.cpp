#include "FBullCowGame.h"



using int32 = int;



FBullCowGame::FBullCowGame() { Reset(); }



int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }



void FBullCowGame::Reset()

{

	constexpr int32 MAX_TRIES = 8;

	const FString HIDDEN_WORD = "planet";



	MyMaxTries = MAX_TRIES;

	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;

	return;

}



bool FBullCowGame::IsGameWon() const

{

	return false;

}



EGuessStatus FBullCowGame::CheckGuessValidity(FString word) const

{
	if (false)
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false)
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (false)
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK; // TODO make actual error
	}
}



// receives a VALID guess, incriments turn, and returns count

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)

{

	// incriment the turn number

	MyCurrentTry++;



	// setup a return variable

	FBullCowCount BullCowCount;



	// loop through all letters in the guess

	int32 HiddenWordLength = MyHiddenWord.length();

	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++)
	{

		// compare letters against the hidden word

		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++)
		{

			// if they match then

			if (Guess[GChar] == MyHiddenWord[MHWChar])
			{

				if (MHWChar == GChar)
				{ // if they're in the same place

					BullCowCount.Bulls++; // incriment bulls

				}

				else
				{

					BullCowCount.Cows++; // must be a cow

				}

			}

		}

	}

	return BullCowCount;

}