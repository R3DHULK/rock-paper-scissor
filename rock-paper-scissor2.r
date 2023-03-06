# Define a function to play rock paper scissors
play_rps <- function() {
  
  # Define the choices
  choices <- c("rock", "paper", "scissors")
  
  # Get the player's choice
  repeat {
    cat("Choose your move (rock, paper, scissors): ")
    player_choice <- tolower(readline())
    if (player_choice %in% choices) {
      break
    } else {
      cat("Invalid choice. Try again.\n")
    }
  }
  
  # Generate the computer's choice
  computer_choice <- sample(choices, 1)
  
  # Print the choices
  cat("You chose", player_choice, "\n")
  cat("Computer chose", computer_choice, "\n")
  
  # Determine the winner
  if (player_choice == computer_choice) {
    cat("It's a tie!\n")
  } else if ((player_choice == "rock" & computer_choice == "scissors") |
             (player_choice == "paper" & computer_choice == "rock") |
             (player_choice == "scissors" & computer_choice == "paper")) {
    cat("You win!\n")
  } else {
    cat("You lose!\n")
  }
}

# Play the game
play_rps()
